#pragma once

#include "stdafx.h"

class ASController_MB
{
	EnumerateMbControllerFunc EnumerateMbController;
	SetMbModeFunc SetMbMode;
	SetMbColorFunc SetMbColor;
	GetMbColorFunc GetMbColor;
	GetMbLedCountFunc GetMbLedCount;

	DWORD mbControllerCount;
	MbLightControl* mbLightController;
public:

	ASController_MB();
	~ASController_MB();

	void SetStaticColor(int red_value, int green_value, int blue_value) const;
};
