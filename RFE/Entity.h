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
			component->entity = this;
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
				c->entity = nullptr;
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
			next.push(std::shared_ptr<Entity>(this));

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
			/*auto it = std::find_if(components.begin(), components.end(), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			if (it != components.end())
			{
				return std::make_shared<T>(*it);
			}

			if (parent)
			{
				return parent->GetComponentInParent<T>();
			}
			else
			{
				return nullptr;
			}*/

			return nullptr;
		}

		// Gets all Components found of type
		template <typename T>
		const std::unordered_set<std::shared_ptr<T>> GetComponents() const
		{
			std::unordered_set<std::shared_ptr<T>> out;
			/*std::copy_if(components.begin(), components.begin(), std::back_inserter(out), [](auto& c)
				{ return dynamic_cast<T&>(*c); });*/
			return out;
		}

		// Gets all Components found of type in Entity and its children
		template <typename T>
		const std::unordered_set<std::shared_ptr<T>> GetComponentsInChildren() const
		{
			std::unordered_set<std::shared_ptr<T>> out;
			/*std::copy_if(components.begin(), components.begin(), std::back_inserter(out), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			for (auto& child : children)
			{
				auto &childComponents = child->GetComponentsInChildren<T>();
				out.insert(childComponents.begin(), childComponents.end());
			}*/

			return out;
		}

		// Gets all Components found of type in Entity and its parents
		template <typename T>
		const std::unordered_set<std::shared_ptr<T>> GetComponentsInParent() const
		{
			std::unordered_set<std::shared_ptr<T>> out;
			/*std::copy_if(components.begin(), components.begin(), std::back_inserter(out), [](auto& c)
				{ return dynamic_cast<T&>(*c); });

			if (parent)
			{
				auto &parentComponents = parent->GetComponentsInParent<T>();
				out.insert(parentComponents.begin(), parentComponents.end());
			}*/

			return out;
		}

	private:
		bool enabled = true;
		std::shared_ptr<Entity> parent = nullptr;
		std::unordered_set<std::shared_ptr<Entity>> children;
		std::vector<std::shared_ptr<Component>> components;

		void Load();
		void Start();
		void Update();
	};
}