#include<window/window.h>
#include<GLAD/include/glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<check/check.h>
#include<Imgui/ImguiHelper.h>
#include<Imgui/imgui.h>
#include<GLAD/include/glad/glad.h>
#include<string>
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
#ifdef _DEBUG
        ImGuiHelper::Initialize(WindowPtr);
#endif 

        std::string GL_VENDOR_KEY = "GL_VENDOR";
        std::string GL_RENDERER_KEY = "GL_RENDERER";
        std::string GL_VERSION_KEY = "GL_VERSION";
        std::string GL_SHADING_LANGUAGE_VERSION_KEY = "GL_SHADING_LANGUAGE_VERSION";
        std::string GL_MAJOR_VERSION_KEY = "GL_MAJOR_VERSION";
        std::string GL_MINOR_VERSION_KEY = "GL_MINOR_VERSION";
        std::string GL_MAX_ELEMENTS_VERTICES_KEY = "GL_MAX_ELEMENTS_VERTICES";
        std::string GL_MAX_ELEMENTS_INDICES_KEY = "GL_MAX_ELEMENTS_INDICES";
        std::string GL_MAX_TEXTURE_IMAGE_UNITS_KEY = "GL_MAX_TEXTURE_IMAGE_UNITS";
        std::string GL_MAX_TEXTURE_IMAGE_SIZE_KEY = "GL_MAX_TEXTURE_SIZE";
        std::string GL_MAX_VIEWPORT_DIMS_KEY = "GL_MAX_VIEWPORT_DIMS";
        std::string GL_DOUBLEBUFFER_KEY = "GL_DOUBLEBUFFER";

        const GLubyte* GL_VENDOR_V;
        const GLubyte* GL_RENDERER_V;
        const GLubyte* GL_VERSION_V;
        const GLubyte* GL_SHADING_LANGUAGE_VERSION_V;
        GLint GL_MAJOR_VERSION_V;
        GLint GL_MINOR_VERSION_V;
        GLint GL_MAX_ELEMENTS_VERTICES_V;
        GLint GL_MAX_ELEMENTS_INDICES_V;
        GLint GL_MAX_TEXTURE_IMAGE_UNITS_V;
        GLint GL_MAX_TEXTURE_SIZE_V;

        GLboolean GL_DOUBLEBUFFER_V;


        glCheck(GL_VENDOR_V = glGetString(GL_VENDOR));
        settings_descriptions[GL_VENDOR_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_VENDOR_V));
        std::cout << settings_descriptions[GL_VENDOR_KEY] << " " << GL_VENDOR_V << '\n';

        glCheck(GL_RENDERER_V = glGetString(GL_RENDERER));
        settings_descriptions[GL_RENDERER_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_RENDERER_V));
        std::cout << GL_VENDOR_KEY << " " << GL_VENDOR_V << '\n';

        glCheck(GL_VERSION_V = glGetString(GL_VERSION));
        settings_descriptions[GL_VERSION_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_VERSION_V));
        std::cout << GL_VERSION_KEY << " " << GL_VERSION_V << '\n';

        glCheck(GL_SHADING_LANGUAGE_VERSION_V = glGetString(GL_SHADING_LANGUAGE_VERSION));
        settings_descriptions[GL_SHADING_LANGUAGE_VERSION_KEY] = static_cast<std::string>(reinterpret_cast<const char*>(GL_SHADING_LANGUAGE_VERSION_V));
        std::cout << GL_SHADING_LANGUAGE_VERSION_KEY << " " << GL_SHADING_LANGUAGE_VERSION_V << '\n';


        glCheck(glGetIntegerv(GL_MAJOR_VERSION, &GL_MAJOR_VERSION_V));
        settings_descriptions[GL_MAJOR_VERSION_KEY] = std::to_string(GL_MAJOR_VERSION_V);
        std::cout << GL_MAJOR_VERSION_KEY << " " << GL_MAJOR_VERSION_V << '\n';

        glCheck(glGetIntegerv(GL_MINOR_VERSION, &GL_MINOR_VERSION_V));
        settings_descriptions[GL_MINOR_VERSION_KEY] = std::to_string(GL_MINOR_VERSION_V);
        std::cout << GL_MINOR_VERSION_KEY << " " << GL_MINOR_VERSION_V << '\n';

        glCheck(glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &GL_MAX_ELEMENTS_VERTICES_V));
        settings_descriptions[GL_MAX_ELEMENTS_VERTICES_KEY] = std::to_string(GL_MAX_ELEMENTS_VERTICES_V);
        std::cout << GL_MAX_ELEMENTS_VERTICES_KEY << " " << GL_MAX_ELEMENTS_VERTICES_V << '\n';


        glCheck(glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &GL_MAX_ELEMENTS_INDICES_V));
        settings_descriptions[GL_MAX_ELEMENTS_INDICES_KEY] = std::to_string(GL_MAX_ELEMENTS_INDICES_V);
        std::cout << GL_MAX_ELEMENTS_INDICES_KEY << " " << GL_MAX_ELEMENTS_INDICES_V << '\n';


        glCheck(glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &GL_MAX_TEXTURE_IMAGE_UNITS_V));
        settings_descriptions[GL_MAX_TEXTURE_IMAGE_UNITS_KEY] = std::to_string(GL_MAX_TEXTURE_IMAGE_UNITS_V);
        std::cout << GL_MAX_TEXTURE_IMAGE_UNITS_KEY << " " << GL_MAX_TEXTURE_IMAGE_UNITS_V << '\n';

        glCheck(glGetIntegerv(GL_MAX_TEXTURE_SIZE, &GL_MAX_TEXTURE_SIZE_V));
        settings_descriptions[GL_MAX_TEXTURE_IMAGE_SIZE_KEY] = std::to_string(GL_MAX_TEXTURE_SIZE_V);
        std::cout << GL_MAX_TEXTURE_IMAGE_SIZE_KEY << " " << GL_MAX_TEXTURE_SIZE_V << '\n';


        settings_descriptions[GL_MAX_VIEWPORT_DIMS_KEY] = std::to_string(GL_MAX_TEXTURE_SIZE_V) + " X " + std::to_string(GL_MAX_TEXTURE_SIZE_V);


        glCheck(glGetBooleanv(GL_DOUBLEBUFFER, &GL_DOUBLEBUFFER_V));
        if (static_cast<bool>(GL_DOUBLEBUFFER_V) == true)
        {
            settings_descriptions[GL_DOUBLEBUFFER_KEY] = static_cast<std::string>("true");
        }
        else
        {
            settings_descriptions[GL_DOUBLEBUFFER_KEY] = static_cast<std::string>("false");
        }

        std::cout << std::boolalpha << GL_DOUBLEBUFFER_KEY << " " << static_cast<bool>(GL_MAX_TEXTURE_SIZE_V) << '\n';


//#ifdef _DEBUG
//    
//    glCheck(GLubyte const* str_ven = glGetString(GL_VENDOR));
//    std::cout << "GL_VENDOR: " << str_ven << '\n';
//#endif // _DEBUG


  
    return true;
}

void Albacore::Window::update_window()
{
 
    glfwPollEvents();

   
    glfwSwapBuffers(WindowPtr);
   
    
}

bool Albacore::Window::is_window_closed()
{
    return glfwWindowShouldClose(WindowPtr);
}

void Albacore::Window::print_spec(std::string window_name)
{





#ifdef _DEBUG
  
        ImGui::Begin(window_name.c_str());
        {
            //ImGui::LabelText("FPS", "%.1f", timing.fps);

            for (const auto& [label, description] : settings_descriptions)
            {
                ImGui::LabelText(label.c_str(), "%s", description.c_str());
            }
            {
               // ImGui::LabelText("Background Color", "RGB(%.0f,%.0f,%.0f)", background.current_red * 255, background.current_green * 255, background.current_blue * 255);
            }
        }
        ImGui::End();
    
  
#endif // _DEBUG
}



 Albacore::Window::~Window()
{
     
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