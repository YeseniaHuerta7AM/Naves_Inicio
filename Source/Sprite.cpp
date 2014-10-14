

#include "Sprite.h"
#include <SDL.h>

//Constructor
Sprite::Sprite(SDL_Surface * screen)//Recibimos la imagen como parametro
{

	this->screen = screen;//This es la clase en la que estamos actualmente. Le decimos que screen es un puntero
	//Paso el screen que voy a dar de alta a mi clase
}

//Destructor
Sprite::~Sprite()
{
	SDL_FreeSurface(imagen);
}

void Sprite::CargarImagen(char * path)
{
	imagen = SDL_LoadBMP(path);//Agregamos la imagen a nuestra variable
}

/*void Sprite::PintarModulo(int nombre, int x, int y, int w, int h)
{
	SDL_Rect src;
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
	SDL_BlitSurface(imagen, &src, screen, NULL);
}*/

void Sprite::PintarModulo(int nombre, int x, int y)
{
	SDL_Rect src;
	src.x = spriteDef.modulos[nombre].x;
	src.y = spriteDef.modulos[nombre].y;
	src.w = spriteDef.modulos[nombre].w;
	src.h = spriteDef.modulos[nombre].h;
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_BlitSurface(imagen, &src, screen, &dest);
}

int Sprite::WidthModule(int module)
{
	return spriteDef.modulos[module].w;
}

int Sprite::HeightModule(int module)
{
	return spriteDef.modulos[module].h;
}