#pragma once

class KeyboardController : public rfe::Component
{
public:
	std::shared_ptr<rfe::Transform> transform;
	float speed = 0.1f;
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
		if (IsKeyDown(KEY_W))
		{
			transform->position.y -= speed;
		}
		if (IsKeyDown(KEY_A))
		{
			transform->position.x -= speed;
		}
		if (IsKeyDown(KEY_S))
		{
			transform->position.y += speed;
		}
		if (IsKeyDown(KEY_D))
		{
			transform->position.x += speed;
		}
	}
};

