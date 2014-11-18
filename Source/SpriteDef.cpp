#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef()//Creamos una clase aparte por sí queremos cambiarle algo a los pixeles
{
	//Definimos cómo van a estar los módulos
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
	modulos[3].x = 117;
	modulos[3].y = 16;
	modulos[3].w = 78;
	modulos[3].h = 34;

	modulos[4].id = MODULO_TEXTOS_MENU_OPCION1;
	modulos[4].x = 107;
	modulos[4].y = 50;
	modulos[4].w = 100;
	modulos[4].h = 36;

	modulos[5].id = MODULO_TEXTOS_MENU_OPCION2;
	modulos[5].x = 120;
	modulos[5].y = 85;
	modulos[5].w = 76;
	modulos[5].h = 34;

	modulos[6].id = MODULO_TEXTOS_MENU_OPCION1_SELECCIONADO;
	modulos[6].x = 206;
	modulos[6].y = 50;
	modulos[6].w = 100;
	modulos[6].h = 35;

	modulos[7].id = MODULO_TEXTOS_MENU_OPCION2_SELECCIONADO;
	modulos[7].x = 219;
	modulos[7].y = 83;
	modulos[7].w = 75;
	modulos[7].h = 36;
}