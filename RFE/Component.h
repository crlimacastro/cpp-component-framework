#pragma once

namespace rfe
{
	// Inherit to create your own Components
	// You may override either of the following protected virtual methods to define functionality
	// OnLoad()		Called once when the scene loads
	// OnStart()	Called on scene load if the component/entity was enabled on Scene Load or the first time the component is enabled
	// OnEnable()	Called every time the component is enabled
	// OnDisable()	Called every time the compoenent is disabled
	// OnUpdate()	Called on Scene Update
	class RFE_API Component
	{
	public:
		friend class Entity;
	public:
		Component() = default;

		Entity *GetEntity() const;
		bool GetEnabled() const;
		void SetEnabled(bool value);
		void Update();

		// Callbacks
	protected:
		virtual void OnLoad() {};
		virtual void OnStart() {};
		virtual void OnEnable() {};
		virtual void OnDisable() {};
		virtual void OnUpdate() {};

	private:
		Entity *entity = nullptr;
		bool enabled = true;
		bool started = false;

		void Load();
		void Start();
	};

}