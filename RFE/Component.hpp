#pragma once

namespace rfe
{
	class Entity;
	// Inherit to create your own GetEntity()->components
	// Overrides:
	// protected OnLoad() -> Called once when the scene loads (after Scene OnLoad())
	// protected OnEnable() -> Called every time the component is enabled
	// protected OnStart() -> Called once, the first time it is on the Scene enabled
	// protected OnUpdate() -> Called on Scene Update before any draws
	// protected OnDraw3D() -> Called between 3D Camera drawing calls
	// protected OnDraw3DDebug() -> Called between 3D Camera draing calls (only in Debug builds)
	// protected OnDraw2D() -> Called between 2D Camera drawing calls
	// protected OnDraw2DDebug() -> Called between 2D Camera draing calls (only in Debug builds)
	// protected OnDrawScreen() -> Called between pixel drawing calls straight to the screen
	// protected OnDrawScreenDebug() -> Called between pixel drawing calls straight to the screen (only in Debug builds)
	// protected OnPostDrawUpdate() -> Called on Screne Update after draws
	// protected OnDisable() -> Called every time the component is disabled
	// protected OnUnload() -> Called once when the scene Unloads
	class RFE_API Component
	{
	public:
		friend class Entity;
	public:
		Component() = default;

		std::shared_ptr<Entity> GetEntity();
		bool GetEnabled() const;
		void SetEnabled(bool value);
		void Update();
		void Draw3D();
		void Draw2D();
		void DrawScreen();
		void PostDrawUpdate();

		// Callbacks
	protected:
		virtual void OnLoad() {}
		virtual void OnStart() {}
		virtual void OnEnable() {}
		virtual void OnDisable() {}
		virtual void OnUpdate() {}
		virtual void OnDraw3D() {}
		virtual void OnDraw3DDebug() {}
		virtual void OnDraw2D() {}
		virtual void OnDraw2DDebug() {}
		virtual void OnDrawScreen() {}
		virtual void OnDrawScreenDebug() {}
		virtual void OnPostDrawUpdate() {}
		virtual void OnUnload() {}

	private:
		Component(const Component& other) = delete;
		Component(const Component&& other) noexcept = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) noexcept = delete;

		std::weak_ptr<Entity> entity;
		bool enabled = true;
		bool started = false;

		void Load();
		void Start();
		void Unload();
	};

}