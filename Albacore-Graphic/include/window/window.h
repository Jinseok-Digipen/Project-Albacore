//Name : Jinseok Son
//Date : 1/3/2023 
//Description : Graphic Engine Window File
#pragma once
#include<unordered_map>
#include<string>
//#include<GLShader/GLShader.h>
#include<iostream>
#include<check/check.h>
#include<Imgui/ImguiHelper.h>
#include<Imgui/imgui.h>
#include<string>
#include<GLShader/GLShader.h>
#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
#endif
struct GLFWwindow;
namespace Albacore
{
	class Window
	{
	public:
		 
		 static  bool  ALBACORE_GRAPHIC_DECLSPEC create_window();
		 static  void  ALBACORE_GRAPHIC_DECLSPEC update_window();
		 static  bool  ALBACORE_GRAPHIC_DECLSPEC is_window_closed();
		 static  void  ALBACORE_GRAPHIC_DECLSPEC print_spec(std::string windowname);
		
		
		 ALBACORE_GRAPHIC_DECLSPEC ~Window();
		 inline static ALBACORE_GRAPHIC_DECLSPEC GLFWwindow* WindowPtr = nullptr;
	private:
		inline static ALBACORE_GRAPHIC_DECLSPEC  GLShader shader;
		inline static ALBACORE_GRAPHIC_DECLSPEC  std::unordered_map <std::string, std::string>settings_descriptions;
		
	};
}



