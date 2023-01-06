#include<iostream>
#include<window/window.h>
#include<color/color.h>
#include<Imgui/ImguiHelper.h>
#include<Imgui/imgui.h>
int main()
{
	Albacore::Window::create_window();
	while (!Albacore::Window::is_window_closed())
	{
		
		#ifdef _DEBUG
		ImGuiHelper::Begin();
		#endif

		


		Albacore::HexColor HexTest{ 0xFF00FFFF };
		Albacore::clear_background(HexTest);
		Albacore::Window::print_spec("Program Info");
		
		//ImGui::ShowDemoWindow();
		#ifdef  _DEBUG
		ImGuiHelper::End(Albacore::Window::WindowPtr);
		#endif


	    Albacore::Window::update_window();
		
		
	}
}