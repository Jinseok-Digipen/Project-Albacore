
#pragma once

#include<window/window.h>
#include<color/color.h>
#include<Vector/vec2.h>
#include<Vector/vec3.h>
#include<GLVertexBuffer/GLVertexBuffer.h>
#include<GLIndexBuffer/GLIndexBuffer.h>
#include<GLVertexArrayBuffer/GLVertexArray.h>
#include<string>
using color3 = vec3;
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
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

	

	shaders["Basic Shader1"] = GLShader("Basic Shader1", { {GLShader::VERTEX, "Assets/shader/pass_thru_pos2d_clr.vert"}, {GLShader::FRAGMENT, "Assets/shader/basic_vtx_clr_attribute.frag"} });
	shaders["Basic Shader2"] = GLShader("Basic Shader2", { {GLShader::VERTEX, "Assets/shader/idiot.vert"}, {GLShader::FRAGMENT, "Assets/shader/idiot.frag"} });
	current_shader = "Basic Shader1";

	constexpr std::array positions = { vec2{-0.2f, 0.2f}, vec2{-0.2f, 0.6f}, vec2{-0.6f, 0.6f}, vec2{-0.6f, 0.2f} };
	constexpr auto       positions_byte_size = static_cast<long long>(sizeof(vec2) * positions.size());
	constexpr std::array colors = { color3{1, 1, 1}, color3{1, 0, 0}, color3{0, 1, 0}, color3{0, 0, 1} };
	constexpr auto       colors_byte_size = static_cast<long long>(sizeof(color3) * colors.size());
	constexpr auto       buffer_size = positions_byte_size + colors_byte_size;
	GLVertexBuffer       buffer(buffer_size);
	buffer.SetData(std::span(positions));
	buffer.SetData(std::span(colors), positions_byte_size);

	GLAttributeLayout position;
	position.component_type = GLAttributeLayout::Float;
	position.component_dimension = GLAttributeLayout::_2;
	position.normalized = false;
	position.vertex_layout_location = 0;
	position.stride = sizeof(vec2);
	position.offset = 0;
	position.relative_offset = 0;

	GLAttributeLayout color;
	color.component_type = GLAttributeLayout::Float;
	color.component_dimension = GLAttributeLayout::_3;
	color.normalized = false;
	color.vertex_layout_location = 1;
	color.stride = sizeof(color3);
	color.offset = positions_byte_size;
	color.relative_offset = 0;

	GLVertexArray vao;
	vao.AddVertexBuffer(std::move(buffer), { position, color });

	vao.SetPrimitivePattern(GLPrimitive::Triangles);

	constexpr std::array<unsigned, 6> indices = { 0, 1, 2, 2, 3, 0 };
	GLIndexBuffer                     index_buffer(indices);
    vao.SetIndexBuffer(std::move(index_buffer));




	model.push_back(std::move(vao));
	
	for (int i = 0; i < shaders.size(); i++)
	{
		shader_options["Shader option " + std::to_string(i)] = false;
	}
	
	
}

void Albacore::Window::update_window()
{

	Debugger_Count = 0;
	shaders[current_shader].Use();
	model[0].Use();
	GLDrawIndexed(model[0]);
	model[0].Use(false);
	shaders[current_shader].Use(false);


	glfwPollEvents();
	glfwSwapBuffers(WindowPtr);


}

bool Albacore::Window::is_window_closed()
{
	return glfwWindowShouldClose(WindowPtr);
}

void ALBACORE_GRAPHIC_DECLSPEC Albacore::Window::UseDebugger()
{
	if (Debugger_Count == 0)
	{
		Albacore::Window::print_spec("ProgramInfo##");
		Albacore::Window::ShaderSelecter();
		Debugger_Count++;
	}
}

void Albacore::Window::print_spec(std::string window_name)
{
		
	static int number_of_costly_calls = 0;
	

	ImGui::Begin(window_name.c_str());
	{
		ImGui::PushID(number_of_costly_calls);
		//ImGui::LabelText("FPS", "%.1f", timing.fps);

		for (const auto& [label, description] : settings_descriptions)
		{
			ImGui::LabelText(label.c_str(), "%s", description.c_str());
		}
		ImGui::PopID();
	}
	ImGui::End();


	number_of_costly_calls++;

}

void Albacore::Window::ShaderSelecter()
{

	static ImGuiComboFlags flags = 0;
	const char* items[] = { "Basic Shader1","Basic Shader2" };
	static int item_current_idx = 0; // Here we store our selection data as an index.
	const char* combo_preview_value = items[item_current_idx];  // Pass in the preview value visible before opening the combo (it could be anything)
	
	int id = rand() % 10000;

	ImGui::PushID(id);
	ImGui::Begin("Shader Selector##");
	if (ImGui::BeginCombo("ShaderList", combo_preview_value, flags))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			const bool is_selected = (item_current_idx == n);
			if (ImGui::Selectable(items[n], is_selected))
				item_current_idx = n;
			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();


		}
		current_shader = items[item_current_idx];
		ImGui::EndCombo();
	}
	ImGui::End();
	ImGui::PopID();

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
void framebuffer_size_callback([[maybe_unused]] GLFWwindow* window, [[maybe_unused]] int width, [[maybe_unused]] int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


