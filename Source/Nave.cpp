#include "Nave.h"
#include "config.h"

//Vamos a pasarle un arreglo de caracteres por la ruta de la imagen
Nave::Nave(SDL_Surface * screen, char * rutaImagen)
{
	//"Sprite" es el tipo de dato. "sprite" es el nombre
	sprite = new Sprite(screen);//Le pasamos la pantalla que se va a ir al Sprite como una copia para poder dibujar la nave
	sprite->CargarImagen(rutaImagen);
	x = (WIDTH_SCREEN / 2) - (sprite->WidthModule(0)/2);
	y = (HEIGHT_SCREEN - 80) - (sprite->HeightModule(0));
}

void Nave::Pintar()
{
	sprite->PintarModulo(0, x, y);
}

void Nave::Mover(int posicion)
{
	x += posicion;
}
