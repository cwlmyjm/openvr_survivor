#include "hand_controller_component.h"


hand_controller_component::hand_controller_component(uint32_t unObjectId)
{
	m_unObjectId = unObjectId;
	m_handle = vr::VRProperties()->TrackedDeviceToPropertyContainer(m_unObjectId);
}


hand_controller_component::~hand_controller_component()
{

}

#define CreateBool(handle, path) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateBooleanComponent(m_handle, path, &handle);\
	}\
}

#define CreateFloat(handle, path, eType, eUnits) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateScalarComponent(m_handle, path, &handle, eType, eUnits);\
	}\
}

void hand_controller_component::CreateAllInputComponent()
{
	vr::VRInputComponentHandle_t m_InputSystemClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputGripClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputApplication_menuClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerValue = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadX = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadY = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadTouch = vr::k_ulInvalidInputComponentHandle;

	CreateBool(m_InputSystemClick, "/input/system/click");
	CreateBool(m_InputGripClick, "/input/grip/click");
	CreateBool(m_InputApplication_menuClick, "/input/application_menu/click");
	CreateBool(m_InputTriggerClick, "/input/trigger/click");
	CreateFloat(m_InputTriggerValue, "/input/trigger/value", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
	CreateFloat(m_InputTrackpadX, "/input/trackpad/x", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	CreateFloat(m_InputTrackpadY, "/input/trackpad/y", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	CreateBool(m_InputTrackpadClick, "/input/trackpad/click");
	CreateBool(m_InputTrackpadTouch, "/input/trackpad/touch");
}

#define UpdateBool(handle, path) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateBooleanComponent(m_handle, path, &handle);\
	}\
	vr::VRDriverInput()->UpdateBooleanComponent(handle, value, offset);\
}

#define UpdateFloat(handle, path, eType, eUnits) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateScalarComponent(m_handle, path, &handle, eType, eUnits);\
	}\
	vr::VRDriverInput()->UpdateScalarComponent(handle, value, offset);\
}


void hand_controller_component::UpdateInputSystemClick(bool value, float offset)
{
	UpdateBool(m_InputSystemClick, "/input/system/click");
}

void hand_controller_component::UpdateInputGripClick(bool value, float offset)
{
	UpdateBool(m_InputSystemClick, "/input/grip/click");
}

void hand_controller_component::UpdateInputApplication_menuClick(bool value, float offset)
{
	UpdateBool(m_InputSystemClick, "/input/application_menu/click");
}

void hand_controller_component::UpdateInputTriggerClick(bool value, float offset)
{
	UpdateBool(m_InputTriggerClick, "/input/trigger/click");
}

void hand_controller_component::UpdateInputTriggerValue(float value, float offset)
{
	UpdateFloat(m_InputTriggerValue, "/input/trigger/value", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
}

void hand_controller_component::UpdateInputTrackpadX(float value, float offset)
{
	UpdateFloat(m_InputTrackpadX, "/input/trackpad/x", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
}

void hand_controller_component::UpdateInputTrackpadY(float value, float offset)
{
	UpdateFloat(m_InputTrackpadY, "/input/trackpad/y", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
}

void hand_controller_component::UpdateInputTrackpadClick(bool value, float offset)
{
	UpdateBool(m_InputTrackpadClick, "/input/trackpad/click");
}

void hand_controller_component::UpdateInputTrackpadTouch(bool value, float offset)
{
	UpdateBool(m_InputTrackpadTouch, "/input/trackpad/touch");
}
