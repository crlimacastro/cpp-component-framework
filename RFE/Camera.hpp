#pragma once

namespace rfe
{
	template <typename T>
	struct Vector3D;

	class RFE_API Camera
	{
	public:
		Camera();

		void BeginDrawing();
		void EndDrawing();
		Vector3D<float> GetPosition() const;
		void SetPosition(Vector3D<float> value);
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
		void Update();
	private:
		Camera3D raylibCamera;
		Mode cameraMode;
	};
}