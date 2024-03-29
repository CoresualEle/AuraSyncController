// ASC_CPP_API.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "ASC_CPP_API.h"

#pragma pack(push, 1)

struct ColorData
{
	int r;
	int g;
	int b;
};

#pragma pack(pop)

extern "C" ASC_CPP_API void Mb_SetStaticColor(ColorData *colorData)
{
	auto mbController = ASController_MB();

	mbController.SetStaticColor(colorData->r, colorData->g, colorData->b);

	//delete mbController;
}