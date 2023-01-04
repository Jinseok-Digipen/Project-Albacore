#include<iostream>
#include<window/window.h>
#include<color/color.h>
int main()
{
	Albacore::Window::create_window();
	while (!Albacore::Window::is_window_closed())
	{
		
		Albacore::HexColor HexTest{ 0xFF00FFFF };
		Albacore::clear_background(HexTest);
		Albacore::Window::update_window();
		
	}
}