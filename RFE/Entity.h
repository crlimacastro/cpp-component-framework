#pragma once

#include "Component.h"

namespace rfe
{
	class RFE_API Entity
	{
	public:
		friend class Scene;
	public:
		Entity() = default;

		bool GetEnabled() const;
		void SetEnabled(bool value);

		void SetParent(Entity *entity);
		void AddChild(Entity& entity);
		void RemoveChild(Entity& entity);
		void ClearChildren();

		static void Destroy(const Entity& entity);

		// Component Logic
	public:
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> component = std::make_shared<T>();
			component->entity = this;
			components.insert(component);
			return component;
		}

		// Removes the first Component found of type
		template <typename T>
		std::shared_ptr<T> RemoveComponent()
		{
			auto it = components.erase(std::remove_if(components.begin(), components.end(), [](auto c)
				{ return dynamic_cast<T&>(*c); }),
				components.end());

			if (it != components.end())
			{
				(*it)->entity = nullptr;
				delete* it;
				return *it;
			}

			return nullptr;
		}

		// Removes all Components found of type
		template <typename T>
		void RemoveComponents()
		{
			std::erase_if(components, [](auto& c) { 
				{
					auto isT = dynamic_cast<T&>(*c);
					if (isT)
					{
						c->entity = nullptr;
						delete c;
						return true;
					}

					return false;
				}
				});
		}

		void ClearComponents()
		{
			for (auto& c : components)
			{
				c->entity = nullptr;
			}
			components.clear();
		}

		// Gets the first Component found of type
		template <typename T>
		const std::shared_ptr<T> GetComponent() const
		{
			auto it = std::find_if(components.begin(), components.end(), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			if (it != components.end())
			{
				return *it;
			}

			return nullptr;
		}

		// Breadth First Search of first Component of type in Entity and its children
		template <typename T>
		const std::shared_ptr<T> GetComponentInChildren() const
		{
			std::queue<shared_ptr<T>> next;
			next.push(std::make_shared<Entity>(this));

			while (!next.empty())
			{
				auto& entity = next.front();
				next.pop();

				auto it = std::find_if(components.begin(), components.end(), [](auto& c)
					{ return dynamic_cast<T&>(*c); });

				if (it != components.end())
				{
					return *it;
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
			auto it = std::find_if(components.begin(), components.end(), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			if (it != components.end())
			{
				return *it;
			}

			if (parent)
			{
				return parent->GetComponentInParent<T>();
			}
			else
			{
				return nullptr;
			}
		}

		// Gets all Components found of type
		template <typename T>
		const std::unordered_set<std::shared_ptr<T>> GetComponents() const
		{
			std::unordered_set<std::shared_ptr<T>> out;
			std::copy_if(components.begin(), components.begin(), std::back_inserter(out), [](auto& c)
				{ return dynamic_cast<T&>(*c); });
			return out;
		}

		// Gets all Components found of type in Entity and its children
		template <typename T>
		const std::unordered_set<std::shared_ptr<T>> GetComponentsInChildren() const
		{
			std::unordered_set<std::shared_ptr<T>> out;
			std::copy_if(components.begin(), components.begin(), std::back_inserter(out), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			for (auto& child : children)
			{
				auto &childComponents = child->GetComponentsInChildren<T>();
				out.insert(childComponents.begin(), childComponents.end());
			}

			return out;
		}

		// Gets all Components found of type in Entity and its parents
		template <typename T>
		const std::unordered_set<std::shared_ptr<T>> GetComponentsInParent() const
		{
			std::unordered_set<std::shared_ptr<T>> out;
			std::copy_if(components.begin(), components.begin(), std::back_inserter(out), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			if (parent)
			{
				auto &parentComponents = parent->GetComponentsInParent<T>();
				out.insert(parentComponents.begin(), parentComponents.end());
			}

			return out;
		}

	private:
		bool enabled = true;

		Entity *parent = nullptr;
		std::unordered_set<Entity*> children;
		std::unordered_set<std::shared_ptr<Component>> components;

		void Load();
		void Start();
		void Update();
	};
}