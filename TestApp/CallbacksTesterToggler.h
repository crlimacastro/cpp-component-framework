#pragma once

class CallbacksTesterToggler : public rfe::Component
{
public:
	std::shared_ptr<CallbacksTester> callbacksTester;
protected:
	void OnLoad() override
	{
		if (!callbacksTester)
		{
			callbacksTester = GetEntity()->GetComponent<CallbacksTester>();
		}
	}
	void OnUpdate() override
	{
		if (IsKeyPressed(KEY_GRAVE))
		{
			callbacksTester->SetEnabled(!callbacksTester->GetEnabled());
		}
	}
};