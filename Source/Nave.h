#ifndef __NAVE_H__
#define __NAVE_H__
#include "Objeto.h"
#include "Config.h"

class Nave
{
	Objeto * nave;
	Objeto * bala[MAXIMO_DE_BALAS];
	Objeto * balaNueva[MAXIMO_DE_BALAS];//*
	int balasVisibles;
	bool visible;
	bool colision; //�sta variable la pondremos en true cuando simulemos una colisi�n

public:
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	void Pintar(int tipoNave);
	void Disparar(int tipoNave, int balas);
	void AutoDisparar(int balas);
	
	void MoverIzquierda(int velocidad);
	void MoverDerecha(int velocidad);
	void MoverArriba(int velocidad);
	void MoverAbajo(int velocidad);

	void setVisible(bool visible);
	bool estaColisionandoConBala(Nave * nave);
	void simularColision(bool colision);
	void CrearNuevo();


	Objeto * GetNaveObjeto(); //Objeto tener Nave objeto
};

#endif

