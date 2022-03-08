#pragma once

class CallbacksTester : public rfe::Component
{
protected:
	void OnLoad() override
	{
		RFE_LOG_INFO(GetEntity()->GetName() + " called OnLoad()");
	}

	void OnStart() override
	{
		RFE_LOG_INFO(GetEntity()->GetName() + " called OnStart()");
	}

	void OnEnable() override
	{
		RFE_LOG_INFO(GetEntity()->GetName() + " called OnEnable()");
	}

	void OnDisable() override
	{
		RFE_LOG_INFO(GetEntity()->GetName() + " called OnDisable()");
	}

	void OnUpdate() override
	{
		 RFE_LOG_INFO(GetEntity()->GetName() + " called OnUpdate()");
	}

	void OnUnload() override
	{
		RFE_LOG_INFO(GetEntity()->GetName() + " called OnUnload()");
	}
};