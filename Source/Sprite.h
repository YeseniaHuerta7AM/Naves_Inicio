#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SDL.h>
#include "SpriteDef.h"

class  Sprite
{
	SDL_Surface * imagen; //Imagen (a manipular) cargada del Sprite
	SDL_Surface * screen;//Pantalla donde vamos a imprimir
	SpriteDef spriteDef;//Definiciones de Sprites
public:
	Sprite(SDL_Surface * screen);//Aquí recibimos nuestra pantalla para poderla dibujar (Constructor)
	~Sprite();//Destructor, se manda llamar con Delete
	void CargarImagen(char * path);//Aquí se carga la imagen
	//void PintarModulo(int nombre, int x, int y, int w, int h);
	void PintarModulo(int nombre, int x, int y);
	int WidthModule(int module);
	int HeightModule(int module);
};

#endif