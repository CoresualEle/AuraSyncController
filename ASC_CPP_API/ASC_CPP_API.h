#pragma once

#ifdef ASCCPPAPI_EXPORTS
#define ASC_CPP_API __declspec(dllexport)
#else
#define ASC_CPP_API __declspec(dllimport)
#endif

struct ColorData;

extern "C" ASC_CPP_API void Mb_SetStaticColor(ColorData *colorData);