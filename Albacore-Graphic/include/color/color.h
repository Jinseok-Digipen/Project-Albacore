#pragma once
//Name : Jinseok Son
//Date : 1/3/2023 
//Description : Graphic Engine Color related code

#pragma once

#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
#endif

namespace Albacore
{



	struct [[nodiscard]] ALBACORE_GRAPHIC_DECLSPEC Color
	{
	public:
		float red = 0;
		float green = 0;
		float blue = 0;
		float alpha = 255;

	public:
		constexpr Color() noexcept = default;
		explicit constexpr Color(float grey, float alpha = 255) noexcept
			: red(grey), green(grey), blue(grey), alpha(alpha)
		{
		}
		constexpr Color(float red, float green, float blue, float alpha = 255) noexcept
			: red(red), green(green), blue(blue), alpha(alpha)
		{
		}
	};

	class [[nodiscard]] ALBACORE_GRAPHIC_DECLSPEC HexColor
	{
	public:
		unsigned rgba = 0x000000ff;

		constexpr HexColor() noexcept = default;
		constexpr HexColor(unsigned hex) noexcept : rgba(hex) {}
		constexpr HexColor(int hex) noexcept : rgba(static_cast<unsigned>(hex)) {}
		constexpr operator Color() const noexcept
		{
			return Color{ static_cast<float>((rgba & 0xff000000) >> 24),
				static_cast<float>((rgba & 0x00ff0000) >> 16),
				static_cast<float>((rgba & 0x0000ff00) >> 8),
						 static_cast<float>((rgba & 0x000000ff) >> 0) };
		}
	};

	void  ALBACORE_GRAPHIC_DECLSPEC clear_background();
	void  ALBACORE_GRAPHIC_DECLSPEC clear_background(Color color);
	void  ALBACORE_GRAPHIC_DECLSPEC clear_background(HexColor hexcolor);
	void  ALBACORE_GRAPHIC_DECLSPEC clear_background(float grey, float alpha);
	void  ALBACORE_GRAPHIC_DECLSPEC clear_background(float red,float blue, float green, float alpha=255);



}