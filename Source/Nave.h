#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave
{
	Sprite * sprite; //"sprite" contiene la imagen 
	//Las coordenadas (sin w, h, porque ya está definido en el sprite)
	int x;
	int y;
	bool autoMovimiento;//Para que el enemigo tenga su propio movimiento

public:
	void Mover(int posicion);
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y); //Constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void Pintar();
	void Actualizar();

};

#endif