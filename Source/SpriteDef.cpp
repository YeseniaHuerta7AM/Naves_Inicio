#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef()//Creamos una clase aparte por s� queremos cambiarle algo a los pixeles
{
	//Definimos c�mo van a estar los m�dulos
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = MODULO_MENU_FONDO;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;

	modulos[2].id = MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 54;
	modulos[2].h = 61;

	modulos[3].id = MODULO_TEXTOS_TITULO;
	modulos[3].x = 119; 
	modulos[3].y = 20; 
	modulos[3].w = 76; 
	modulos[3].h = 34;

	modulos[4].id = MODULO_TEXTOS_MENU_OPCION1;
	modulos[4].x = 108; 
	modulos[4].y = 54; 
	modulos[4].w = 97; 
	modulos[4].h = 34; 

	modulos[5].id = MODULO_TEXTOS_MENU_OPCION2;
	modulos[5].x = 122; 
	modulos[5].y = 88; 
	modulos[5].w = 69; 
	modulos[5].h = 32; 

	modulos[6].id = MODULO_TEXTOS_MENU_OPCION1_SELECCIONADO;
	modulos[6].x = 206;
	modulos[6].y = 53; 
	modulos[6].w = 99; 
	modulos[6].h = 33; 

	modulos[7].id = MODULO_TEXTOS_MENU_OPCION2_SELECCIONADO;
	modulos[7].x = 218; 
	modulos[7].y = 86; 
	modulos[7].w = 74; 
	modulos[7].h = 36;

	modulos[8].id = MODULO_BALAS_BALA;
	modulos[8].x = 0;
	modulos[8].y = 0;
	modulos[8].w = 5;
	modulos[8].h = 5;
}