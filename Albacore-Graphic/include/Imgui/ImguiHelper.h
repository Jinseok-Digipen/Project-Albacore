#pragma once
/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */
#include<GLFW/glfw3.h>

#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
#endif

struct GLFWwindow;
namespace ImGuiHelper
{
    void ALBACORE_GRAPHIC_DECLSPEC Initialize(GLFWwindow*window);
    
    void ALBACORE_GRAPHIC_DECLSPEC Begin();
    void ALBACORE_GRAPHIC_DECLSPEC End(GLFWwindow* window);
    void ALBACORE_GRAPHIC_DECLSPEC Shutdown();
}
