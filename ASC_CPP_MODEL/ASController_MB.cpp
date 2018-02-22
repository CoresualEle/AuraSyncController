#include "stdafx.h"
#include "ASController_MB.h"

ASController_MB::ASController_MB()
{
	auto hLib = LoadLibraryA("AURA_SDK.dll");

	if (!hLib) return;

	// Load .dll Methods
	reinterpret_cast<FARPROC&>(EnumerateMbController) = GetProcAddress(hLib, "EnumerateMbController");
	reinterpret_cast<FARPROC&>(SetMbMode) = GetProcAddress(hLib, "SetMbMode");
	reinterpret_cast<FARPROC&>(SetMbColor) = GetProcAddress(hLib, "SetMbColor");
	reinterpret_cast<FARPROC&>(GetMbColor) = GetProcAddress(hLib, "GetMbColor");
	reinterpret_cast<FARPROC&>(GetMbLedCount) = GetProcAddress(hLib, "GetMbLedCount");

	// Set up the Controllers
	mbControllerCount = EnumerateMbController(nullptr, 0);
	mbLightController = new MbLightControl[mbControllerCount];
	EnumerateMbController(mbLightController, mbControllerCount);
}

ASController_MB::~ASController_MB()
{
}

void ASController_MB::SetStaticColor(int red_value, int green_value, int blue_value) const
{
	SetMbMode(mbLightController[0], 1);

	auto mbControllerLedCount = GetMbLedCount(mbLightController[0]);

	auto color = new BYTE[mbControllerLedCount * 3];
	ZeroMemory(color, mbControllerLedCount * 3);

	for (size_t i = 0; i < mbControllerLedCount; ++i)
	{
		auto r = i * 3;
		auto g = r + 2;
		auto b = r + 1;

		color[r] = red_value;
		color[g] = green_value;
		color[b] = blue_value;
	}

	SetMbColor(mbLightController[0], color, mbControllerLedCount * 3);

	for (size_t i = 0; i < mbControllerLedCount * 3; ++i)
	{
		color[i] = 0x00;
	}

	GetMbColor(mbLightController[0], color, mbControllerLedCount * 3);

	delete[] color;
}
