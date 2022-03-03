#pragma once

class CubeDrawer : public rfe::Component
{
public:
	std::shared_ptr<rfe::Transform> transform;
	std::shared_ptr<rfe::CameraComponent> camera;
protected:
	void OnLoad() override
	{
		if (!transform)
		{
			transform = GetEntity()->GetComponent<rfe::Transform>();
		}
	}
	void OnUpdate() override
	{
		BeginMode3D(camera->camera);
		auto position = Vector3{ transform->position.x, transform->position.y , transform->position.z };
		DrawCube(position, 2.0f, 2.0f, 2.0f, RED);
		EndMode3D();
	}
};

