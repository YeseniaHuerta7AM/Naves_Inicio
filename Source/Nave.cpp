#include "Nave.h"
//#include "config.h"

//Vamos a pasarle un arreglo de caracteres por la ruta de la imagen
Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y)
{
	//"Sprite" es el tipo de dato. "sprite" es el nombre
	sprite = new Sprite(screen);//Le pasamos la pantalla que se va a ir al Sprite como una copia para poder dibujar la nave
	sprite->CargarImagen(rutaImagen);

	this->x = x;
	this->y = y;
	autoMovimiento = false; //Toda nave que construyamos no va a tener automovimiento
}

void Nave::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;//Clase
}

void Nave::Actualizar()
{
	if (autoMovimiento)
	{
		Mover(1);
	}
}

void Nave::Pintar()
{
	sprite->PintarModulo(0, x, y);
}

void Nave::Mover(int posicion)
{
	x += posicion;
}
