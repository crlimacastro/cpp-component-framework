#pragma once

namespace rfe
{
	template <typename T>
	struct Vector2D;

	template <typename T>
	struct Vector3D;

	class RFE_API Camera
	{
		// All Cameras
	public:
		void SetPosition(Vector3D<float> value);

		void Update();

		// 3D Camera
	public:
		class RFE_API Context3D
		{
		public:
			friend class Camera;
		public:
			Context3D();

			// Begin Camera 3D drawing mode
			void BeginDrawing();
			// End Camera 3D drawing mode
			void EndDrawing();

			Vector3D<float> GetPosition() const;

			Vector3D<float> GetTarget() const;
			void SetTarget(Vector3D<float> value);
			Vector3D<float> GetUp() const;
			void SetUp(Vector3D<float> value);
			float GetFOV() const;
			void SetFOX(float value);

			enum class Projection {
				Perspective,
				Orthographic
			};
			Projection GetProjection() const;
			void SetProjection(Projection value);
			enum class Mode {
				Custom,
				Free,
				Orbital,
				FirstPerson,
				ThirdPerson,
			};
			Mode GetMode() const;
			void SetMode(Mode value);

			// Get a ray trace from mouse position
			Ray GetMouseRaycast() const;
			// Get camera transform matrix (view matrix)
			Matrix GetMatrix() const;
			// Get the screen space position for a 3d world space position
			Vector2D<float> GetWorldToScreenPoint(Vector3D<float> position) const;
			
		private:
			Camera3D camera3D = { 0 };
			Mode cameraMode = Mode::Custom;
		};

		Context3D context3D;

		// 2D Camera
	public:
		class RFE_API Context2D
		{
		public:
			friend class Camera;
		public:
			Context2D();

			// Begin Camera 2D drawing mode
			void BeginDrawing();
			// End Camera 2D drawing mode
			void EndDrawing();

			Vector2D<float> GetPosition() const;

			float GetRotation() const;
			void SetRotation(float value);
			float GetZoom() const;
			void SetZoom(float value);

			// Get camera 2d transform matrix
			Matrix GetMatrix() const;
			// Get the screen space position for a 2d camera world space position
			Vector2D<float> GetWorldToScreen(Vector2D<float> position) const;
			// Get the world space position for a 2d camera screen space position
			Vector2D<float> GetScreenToWorld(Vector2D<float> position) const;
		private:
			Camera2D camera2D = { 0 };
		};

		Context2D context2D;
	};
}