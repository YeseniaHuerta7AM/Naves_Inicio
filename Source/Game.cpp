#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

void CGame::Iniciando(){}
bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();
			{
				nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Descargas/cuadro.jpg", "rb"));
				SDL_Rect fuente;
				fuente.x = 80;
				fuente.y = 105;
				fuente.w = 325;
				fuente.h = 19;

				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = fuente.w;
				destino.h = fuente.h;

				SDL_BlitSurface(nave, &fuente, screen, &destino);
			}
			estado = Estado::ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:
			break;
		case Estado::ESTADO_JUGANDO:	
			break;
		case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
				break;
		case Estado::ESTADO_FINALIZANDO:
			break;
		};
    }
	return true;
}
