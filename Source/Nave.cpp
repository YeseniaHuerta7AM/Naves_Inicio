#include "Nave.h"
//#include "config.h"

//Vamos a pasarle un arreglo de caracteres por la ruta de la imagen
Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module)
{
	this->module = module;
	//"Sprite" es el tipo de dato. "sprite" es el nombre
	sprite = new Sprite(screen);//Le pasamos la pantalla que se va a ir al Sprite como una copia para poder dibujar la nave
	sprite->CargarImagen(rutaImagen);

	w = sprite->WidthModule(this->module);
	h = sprite->HeightModule(this->module);

	this->x = x;
	this->y = y;
	autoMovimiento = false; //Toda nave que construyamos no va a tener automovimiento

	pasoActual = 0;
	pasoLimite = -1;
}

void Nave::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;//Clase
}

void Nave::Actualizar()
{
	if (autoMovimiento)
	{
		MoverX(1);
	}

	if (pasoLimite > 0)
	{
		//pasoActual++; //Cada momento vamos a estar incrementando el pasoActual
		if (pasoActual >= pasoLimite)
			pasoActual = 0; //Cuando sea mayor, vamos a reiniciarlo a 0
	}

	/////
	if (autoMovimiento)
	{
		MoverY(1);
	}

	if (pasoLimite > 0)
	{
		//pasoActual++; //Cada momento vamos a estar incrementando el pasoActual
		if (pasoActual >= pasoLimite)
			pasoActual = 0; //Cuando sea mayor, vamos a reiniciarlo a 0
	}
	/////
}

void Nave::Pintar()
{
	sprite->PintarModulo(module, x, y);
}

void Nave::Pintar(int module, int x, int y)
{
	sprite->PintarModulo(module, x, y);
}

void Nave::MoverX(int posicion)
{
	x += posicion;
}

void Nave::MoverY(int posicion)
{
	y += posicion;
}

int Nave::ObtenerX()
{
	return x;
}

int Nave::ObtenerY()
{
	return y;
}

int Nave::ObtenerW()
{
	return w;
}

int Nave::ObtenerH()
{
	return h;
}

void Nave::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}

int Nave::ObtenerPasoActual()
{
	return pasoActual;
}

void Nave::IncrementarPasoActual()
{
	pasoActual++;
}

bool Nave::EstaColisionando(Nave * b)
{
	return false;
}
