#include "Objeto.h"
//#include "config.h"

//Vamos a pasarle un arreglo de caracteres por la ruta de la imagen
Objeto::Objeto(SDL_Surface * screen, char * rutaImagen, int x, int y, int module)
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

	isVisible = true; //Todo es visible
}

void Objeto::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;//Clase
}

void Objeto::Actualizar()
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

void Objeto::Pintar()
{
	if (isVisible) //Si isVisible es llega a ser falso, que no se pinte
		sprite->PintarModulo(module, x, y);
}

void Objeto::Pintar(int module, int x, int y)
{
	if (isVisible)
		sprite->PintarModulo(module, x, y);
}

void Objeto::MoverX(int posicion)
{
	x += posicion;
}

void Objeto::SetVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

void Objeto::MoverY(int posicion)
{
	y += posicion;
}

int Objeto::ObtenerX()
{
	return x;
}

int Objeto::ObtenerY()
{
	return y;
}

int Objeto::ObtenerW()
{
	return w;
}

int Objeto::ObtenerH()
{
	return h;
}

void Objeto::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}

int Objeto::ObtenerPasoActual()
{
	return pasoActual;
}

void Objeto::IncrementarPasoActual()
{
	pasoActual++;
}

bool Objeto::EstaColisionando(Objeto * b)
{
	return false;
}

void Objeto::PonerEn(int x, int y)
{
	this->x = x;
	this->y = y;
}
