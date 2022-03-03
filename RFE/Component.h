#pragma once

namespace rfe
{
	class Entity;

	// Inherit to create your own GetEntity()->components
	// Overrides:
	// protected OnLoad() -> Called once when the scene loads (after Scene OnLoad())
	// protected OnStart() -> Called once the first time it is on the Scene enabled (after Component OnLoad() and Scene OnStart())
	// protected OnEnable() -> Called every time the component is enabled
	// protected OnDisable() -> Called every time the component is disabled
	// protected OnUpdate() -> Called on Scene Update
	// protected OnUnload() -> Called once when the scene Unloads
	class RFE_API Component
	{
	public:
		friend class Entity;
	public:
		Component() = default;

		std::shared_ptr<Entity> GetEntity() const;
		bool GetEnabled() const;
		void SetEnabled(bool value);
		void Update();

		// Callbacks
	protected:
		virtual void OnLoad() {}
		virtual void OnStart() {}
		virtual void OnEnable() {}
		virtual void OnDisable() {}
		virtual void OnUpdate() {}
		virtual void OnUnload() {}

	private:
		std::weak_ptr<Entity> entity;
		bool enabled = true;
		bool started = false;

		void Load();
		void Start();
		void Unload();
	};

}