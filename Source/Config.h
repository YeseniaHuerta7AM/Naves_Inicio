//PARA AGREGAR EL ARCHIVO UNA SOLA VEZ
//#pragma once //Que lo que esté adelante solo lo cargue una vez (solo trabaja en Windows)

//Trabaja con todos:
#ifndef __CONFIG_H__ //Si no está definida la variable, definela
#define __CONFIG_H__

//Código de preprocesamiento
#define WIDTH_SCREEN 640 //WIDTH_SCREEN es el nombre de la variable
#define HEIGHT_SCREEN 480

//Definimos los cuatro bordes de la pantalla
#define BORDE_IZQUIERDO		1<<0//Recorriendo a la izq
#define BORDE_SUPERIOR		1<<1
#define BORDE_DERECHO		1<<2
#define BORDE_INFERIOR		1<<3

#define FPS_LIMIT	30.0f //Límite de frames por segundo
#define FPS_DELAY	1000.0f / FPS_LIMIT 

/****SPRITES****/
//#TIPO_IMAGEN_NOMBRE

#define MODULO_MINAVE_NAVE					0
#define MODULO_MENU_FONDO					1
#define MODULO_ENEMIGO_NAVE					2
#define MODULO_TEXTOS_TITULO				3	
#define MODULO_TEXTOS_MENU_OPCION1				4
#define MODULO_TEXTOS_MENU_OPCION2				5
#define MODULO_TEXTOS_MENU_OPCION1_SELECCIONADO	6
#define MODULO_TEXTOS_MENU_OPCION2_SELECCIONADO	7

#endif