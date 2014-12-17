#pragma once
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"
#include "Stage.h"
class CGame
{
public:
	enum Estado
	{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_PRE_JUGANDO,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

private:
	void Iniciando();
	void Menu();
	void MoverEnemigo();
	bool EsLimitePantalla(Objeto * objeto, int bandera); //Límite de pantalla, utilizamos un puntero
	//La bandera me va a recibir un numero entero, pero lo va a trabajar como binario
	int opcionSeleccionada;
	Uint8 * keys;//Esta variable nos servriá para ver si determinadas teclas están o no pulsadas
	SDL_Event event;//La variable event de tipo evento de SDL nos servirá para monitorizar el

	SDL_Surface * screen;
	Nave * nave;
	Nave * enemigoArreglo[10];
	Stage nivel[4]; //Es un arreglo de 4 (escenarios)
	void InicializandoStage();
	int NivelActual;
	Objeto * menu; //Fondo del menú
	Objeto * textos; //Textos del juego
	Objeto * fondo; //Fondo del juego

	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;
	Estado estado;

	int vida;
	int enemigosEliminados;
};