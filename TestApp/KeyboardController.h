#pragma once

class KeyboardController : public rfe::Component
{
public:
	std::shared_ptr<rfe::Transform> transform;
	float speed = 10.0f;
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
		auto newPosition = transform->position;

		if (IsKeyDown(KEY_W))
		{
			newPosition.y += speed * rfe::Time::GetDeltaTime();
		}
		if (IsKeyDown(KEY_A))
		{
			newPosition.x -= speed * rfe::Time::GetDeltaTime();
		}
		if (IsKeyDown(KEY_S))
		{
			newPosition.y -= speed * rfe::Time::GetDeltaTime();
		}
		if (IsKeyDown(KEY_D))
		{
			newPosition.x += speed * rfe::Time::GetDeltaTime();
		}

		transform->position = newPosition;
	}
};

