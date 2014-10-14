#include "SpriteDef.h"

SpriteDef::SpriteDef()//Creamos una clase aparte por sí queremos cambiarle algo a los pixeles
{
	//Definimos cómo van a estar los módulos
	modulos[0].id = 0;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;
}