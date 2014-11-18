#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave
{
	Sprite * sprite; //"sprite" contiene la imagen 
	//Las coordenadas (sin w, h, porque ya está definido en el sprite)
	int x;
	int y;
	int w;
	int h;
	bool autoMovimiento;//Para que el enemigo tenga su propio movimiento
	int pasoActual; //
	int pasoLimite;
	int module; //Modulo actual

public:
	void MoverX(int posicion);
	void MoverY(int posicion);
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module); //Constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void SetPasoLimite(int pasos);
	int ObtenerPasoActual(); //Para saber en qué paso nos encotramos
	void IncrementarPasoActual();
	void Pintar();
	void Pintar(int module, int x, int y);
	void Actualizar();
	int ObtenerX();
	int ObtenerY();
	int ObtenerW();
	int ObtenerH();
	bool EstaColisionando(Nave * b);
};

#endif