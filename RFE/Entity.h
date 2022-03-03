#pragma once

#include "Component.h"

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
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			auto component = std::make_shared<T>();
			component->entity = shared_from_this();
			components.push_back(component);
			return component;
		}

		// Removes the first Component found of type
		template <typename T>
		std::shared_ptr<T> RemoveComponent()
		{
			for (auto it = components.begin(); it < components.end(); it++)
			{
				if (auto t = std::dynamic_pointer_cast<T>(*it); t != nullptr)
				{
					t->entity = nullptr;
					components.erase(it);
					return t;
				}
			}

			return nullptr;
		}

		// Removes all Components found of type
		template <typename T>
		void RemoveComponents()
		{
			std::erase_if(components, [](auto& c)
				{
					if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
					{
						t->entity = nullptr;
						return true;
					}

					return false;
				});
		}

		void ClearComponents()
		{
			for (auto& c : components)
			{
				c->entity.reset();
			}

			components.clear();
		}

		// Gets the first Component found of type
		template <typename T>
		std::shared_ptr<T> GetComponent() const
		{
			for (auto& c : components)
			{
				if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
				{
					return t;
				}
			}

			return nullptr;
		}

		// Breadth First Search of first Component of type in Entity and its children
		template <typename T>
		const std::shared_ptr<T> GetComponentInChildren() const
		{
			std::queue<shared_ptr<T>> next;
			next.push(shared_from_this());

			while (!next.empty())
			{
				auto& entity = next.front();
				next.pop();

				for (auto& c : entity.components)
				{
					if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
					{
						return t;
					}
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
			for (auto& c : components)
			{
				if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
				{
					return t;
				}
			}

			if (parent)
			{
				return parent->GetComponentInParent<T>();
			}

			return nullptr;
		}

		// Gets all Components found of type
		template <typename T>
		const std::vector<std::shared_ptr<T>> GetComponents() const
		{
			std::vector<std::shared_ptr<T>> out;

			for (auto& c : components)
			{
				if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
				{
					out.push_back(t);
				}
			}

			return out;
		}

		// Gets all Components found of type in Entity and its children
		template <typename T>
		const std::vector<std::shared_ptr<T>> GetComponentsInChildren() const
		{
			std::vector<std::shared_ptr<T>> out;

			std::queue<shared_ptr<T>> next;
			next.push(shared_from_this());

			while (!next.empty())
			{
				auto& entity = next.front();
				next.pop();

				for (auto& c : entity.components)
				{
					if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
					{
						out.push_back(t);
					}
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
		const std::vector<std::shared_ptr<T>> GetComponentsInParent() const
		{
			std::vector<std::shared_ptr<T>> out;

			for (auto& c : components)
			{
				if (auto t = std::dynamic_pointer_cast<T>(c); t != nullptr)
				{
					out.push_back(t);
				}
			}

			if (parent)
			{
				return parent->GetComponentInParent<T>();
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
		std::vector<std::shared_ptr<Component>> components;

		void Load();
		void Start();
		void Update();
		void Unload();
	};
}