/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#pragma once
#include <GLAD/include/glad/glad.h>
#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
#endif
using GLHandle = GLuint;
