#pragma once
#include <openvr_driver.h>

class hand_controller_component
{
private:
	uint32_t m_unObjectId = 0;
	vr::PropertyContainerHandle_t m_handle = vr::k_ulInvalidPropertyContainer;
public:
	hand_controller_component(uint32_t unObjectId);
	~hand_controller_component();
	const uint32_t GetControllerId() { return m_unObjectId; };
	void CreateAllInputComponent();
private:
	vr::VRInputComponentHandle_t m_InputSystemClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputGripClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputApplication_menuClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerValue = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadX = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadY = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadTouch = vr::k_ulInvalidInputComponentHandle;

public:
	void UpdateInputSystemClick(bool value, float offset = 0);
	void UpdateInputGripClick(bool value, float offset = 0);
	void UpdateInputApplication_menuClick(bool value, float offset = 0);
	void UpdateInputTriggerClick(bool value, float offset = 0);
	void UpdateInputTriggerValue(float value, float offset = 0);
	void UpdateInputTrackpadX(float value, float offset = 0);
	void UpdateInputTrackpadY(float value, float offset = 0);
	void UpdateInputTrackpadClick(bool value, float offset = 0);
	void UpdateInputTrackpadTouch(bool value, float offset = 0);

};

