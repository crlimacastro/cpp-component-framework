#pragma once

class FPSToggler : public rfe::Component
{
public:
	std::shared_ptr<FPSDrawer> fpsDrawer;
protected:
	void OnLoad() override
	{
		if (!fpsDrawer)
		{
			fpsDrawer = GetEntity()->GetComponent<FPSDrawer>();
		}
	}
	void OnUpdate() override
	{
		if (IsKeyPressed(KEY_GRAVE))
		{
			fpsDrawer->SetEnabled(!fpsDrawer->GetEnabled());
		}
	}
};