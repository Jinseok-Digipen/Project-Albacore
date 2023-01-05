#include<window/window.h>
#include<GLAD/include/glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<check/check.h>
#include<Imgui/ImguiHelper.h>
#include<Imgui/imgui.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

bool  Albacore::Window::create_window()
{
    // glfw: initialize and configure
     // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    WindowPtr = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (WindowPtr == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(WindowPtr);
    glfwSetFramebufferSizeCallback(WindowPtr, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

   
    ImGuiHelper::Initialize(WindowPtr);




#ifdef _DEBUG
    
    glCheck(GLubyte const* str_ven = glGetString(GL_VENDOR));
    std::cout << "GL_VENDOR: " << str_ven << '\n';
#endif // _DEBUG


  
    return true;
}

void Albacore::Window::update_window()
{
   
    glfwPollEvents();

    ImGuiHelper::Begin();
    ImGui::ShowDemoWindow();
    ImGuiHelper::End(WindowPtr);


    glfwSwapBuffers(WindowPtr);
    
    
}

bool Albacore::Window::is_window_closed()
{
    return glfwWindowShouldClose(WindowPtr);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback([[maybe_unused]]GLFWwindow* window, [[maybe_unused]]int width, [[maybe_unused]]int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}