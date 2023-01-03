//Name : Jinseok Son
//Date : 1/3/2023 
//Description : Graphic Engine Window File

#pragma once

#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
#endif
namespace Albacore
{
	class Window
	{
	public:
		 static  bool  ALBACORE_GRAPHIC_DECLSPEC create_window();

	

	};
}


#pragma once
