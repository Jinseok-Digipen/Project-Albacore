#include"color.h"
#include<GLAD/include/glad/glad.h>
void  Albacore::clear_background()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
}

void  Albacore::clear_background([[maybe_unused]] Color color)
{
	glClearColor(color.red/255.f, color.blue/255.f, color.green/255.f, color.alpha/255.f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Albacore::clear_background([[maybe_unused]] HexColor hexcolor)
{
	glClearColor(static_cast<Color>(hexcolor).red/255.0f, static_cast<Color>(hexcolor).green/255.0f, static_cast<Color>(hexcolor).blue/255.0f, static_cast<Color>(hexcolor).alpha/255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Albacore::clear_background([[maybe_unused]]float grey, [[maybe_unused]]float alpha)
{
	glClearColor(grey/ 255.0f, grey / 255.0f, grey / 255.0f,alpha/255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
}
void Albacore::clear_background([[maybe_unused]] float red, [[maybe_unused]] float green, [[maybe_unused]] float blue, [[maybe_unused]] float alpha)
{
	glClearColor(red / 255.0f, green / 255.0f, green / 255.0f, blue / 255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

