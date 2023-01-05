#pragma once
/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */
#include<GLFW/glfw3.h>

struct SDL_Window;
typedef void* SDL_GLContext;
union SDL_Event;

struct GLFWwindow;
namespace ImGuiHelper
{
    void Initialize(GLFWwindow*window);
    void FeedEvent();
    void Begin();
    void End(GLFWwindow* window);
    void Shutdown();
}
