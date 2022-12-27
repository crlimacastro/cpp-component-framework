#pragma once

namespace rfe
{
	struct v2f;
	struct v3f;

	class RFE_API Camera
	{
		// All Cameras
	public:
		void SetPosition(v3f value);

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

			v3f GetPosition() const;

			v3f GetTarget() const;
			void SetTarget(v3f value);
			v3f GetUp() const;
			void SetUp(v3f value);
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
			v2f GetWorldToScreenPoint(v3f position) const;

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

			v2f GetPosition() const;

			float GetRotation() const;
			void SetRotation(float value);
			float GetZoom() const;
			void SetZoom(float value);

			// Get camera 2d transform matrix
			Matrix GetMatrix() const;
			// Get the screen space position for a 2d camera world space position
			v2f GetWorldToScreen(v2f position) const;
			// Get the world space position for a 2d camera screen space position
			v2f GetScreenToWorld(v2f position) const;
		private:
			Camera2D camera2D = { 0 };
		};

		Context2D context2D;
	};
}