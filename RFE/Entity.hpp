#pragma once

#include "Component.hpp"

namespace rfe
{
	// Private constructor to avoid Stack allocation. Create Entity with static rfe::Entity::Create()
	// Handle Entities with std::shared_ptr<Entity>
	class RFE_API Entity : public std::enable_shared_from_this<Entity>
	{
	public:
		friend class Scene;
		friend class Component;
	public:
		static std::shared_ptr<Entity> Create();

		bool GetEnabled() const;
		void SetEnabled(bool value);

		std::string GetName() const;
		void SetName(const std::string value);

		std::shared_ptr<Entity> GetParent() const;
		void SetParent(std::shared_ptr<Entity> entity);
		void AddChild(std::shared_ptr<Entity> entity);
		void RemoveChild(std::shared_ptr<Entity> entity);
		void ClearChildren();

		static void Destroy(std::shared_ptr<Entity> entity);

		// Component Logic
	public:
		// Adds a Component of type T and returns it
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			auto component = std::make_shared<T>();
			component->entity = shared_from_this();

			std::string componentName = typeid(T).name();
			if (!components.contains(componentName))
			{
				components.emplace(componentName, std::make_shared<std::vector<std::shared_ptr<Component>>>());
			}
			components.at(componentName)->push_back(component);

			return component;
		}

		// Removes the first Component of type T and returns it
		template <typename T>
		std::shared_ptr<T> RemoveComponent()
		{
			std::string componentName = typeid(T).name();
			if (components.contains(componentName) && components.at(componentName)->size() > 0)
			{
				auto& component = *components.at(componentName)->begin();
				components.at(componentName)->erase(components.at(componentName)->begin());
				return component;
			}

			return nullptr;
		}

		// Removes all Components of type T
		template <typename T>
		void RemoveComponents()
		{
			std::string componentName = typeid(T).name();
			if (components.contains(componentName))
			{
				components.at(componentName)->clear();
			}
		}

		// Removes all Components
		void ClearComponents()
		{
			components.clear();
		}

		// Gets the first Component of type T or nullptr if none
		template <typename T>
		std::shared_ptr<T> GetComponent() const
		{
			std::string componentName = typeid(T).name();
			if (components.contains(componentName) && components.at(componentName)->size() > 0)
			{
				return std::dynamic_pointer_cast<T>(*components.at(componentName)->begin());
			}

			return nullptr;
		}

		// Breadth First Search of first Component of type in Entity and its children
		template <typename T>
		std::shared_ptr<T> GetComponentInChildren() const
		{
			std::string componentName = typeid(T).name();
			std::queue<shared_ptr<T>> next;
			next.push(shared_from_this());

			while (!next.empty())
			{
				auto& entity = next.front();
				next.pop();

				if (entity.components.contains(componentName) && entity.components.at(componentName)->size() > 0)
				{
					return std::dynamic_pointer_cast<T>(*entity.components.at(componentName)->begin());
				}

				for (auto& child : entity.children)
				{
					next.push(child);
				}
			}

			return nullptr;
		}

		// Gets the first Component found of type in Entity and its parents
		template <typename T>
		const std::shared_ptr<T> GetComponentInParent() const
		{
			std::string componentName = typeid(T).name();

			if (components.contains(componentName) && components.at(componentName)->size() > 0)
			{
				return std::dynamic_pointer_cast<T>(*components.at(componentName)->begin());
			}

			if (parent)
			{
				return parent->GetComponentInParent<T>();
			}

			return nullptr;
		}

		// Gets all Components of type T
		template <typename T>
		std::shared_ptr<std::vector<std::shared_ptr<T>>> GetComponents() const
		{
			std::string componentName = typeid(T).name();
			if (components.contains(componentName))
			{
				return std::dynamic_pointer_cast<std::vector<std::shared_ptr<T>>>(components.at(componentName));
			}
			else
			{
				return std::make_shared<std::vector<std::shared_ptr<T>>>();
			}
		}

		// Gets all Components found of type in Entity and its children
		template <typename T>
		std::shared_ptr<std::vector<std::shared_ptr<T>>> GetComponentsInChildren() const
		{
			std::string componentName = typeid(T).name();
			std::shared_ptr<std::vector<std::shared_ptr<T>>> out = std::make_shared<std::vector<std::shared_ptr<T>>>();
			std::queue<shared_ptr<T>> next;
			next.push(shared_from_this());

			while (!next.empty())
			{
				auto& entity = next.front();
				next.pop();

				if (entity.components.contains(componentName))
				{
					out->insert(entity.components.at(componentName).begin(), entity.components.at(componentName).end());
				}

				for (auto& child : entity.children)
				{
					next.push(child);
				}
			}

			return out;
		}

		// Gets all Components found of type in Entity and its parents
		template <typename T>
		std::shared_ptr<std::vector<std::shared_ptr<T>>> GetComponentsInParent() const
		{
			std::string componentName = typeid(T).name();
			std::shared_ptr<std::vector<std::shared_ptr<T>>> out = std::make_shared<std::vector<std::shared_ptr<T>>>();

			if (components.contains(componentName))
			{
				out->insert(components.at(componentName).begin(), components.at(componentName).end());
			}

			if (parent)
			{
				auto parentComponents = parent->GetComponentsInParent<T>();
				out->insert(parentComponents->begin(), parentComponents->end());
			}

			return out;
		}

	private:
		Entity() = default;
		Entity(const Entity& other) = delete;
		Entity(const Entity&& other) noexcept = delete;
		Entity& operator=(const Entity& other) = delete;
		Entity& operator=(Entity&& other) noexcept = delete;

		bool enabled = true;
		std::string name = "Entity";
		std::weak_ptr<Entity> parent;
		std::unordered_set<std::shared_ptr<Entity>> children;
		std::unordered_map<std::string, std::shared_ptr<std::vector<std::shared_ptr<Component>>>> components;

		void Load();
		void Start();
		void Update();
		void Draw3D();
		void Draw2D();
		void DrawScreen();
		void PostDrawUpdate();
		void Unload();
	};
}