#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	delete(nave);
	SDL_FreeSurface(screen);//Eliminar la pantalla, para que cuando finalice el juego se elimine la memoria
	SDL_Quit();
}

void CGame::Iniciando()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//Cambiamos los numeros por las variables definidas en Config.h
	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_SWSURFACE);
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);
	nave = new Nave(screen, "../Data/MiNave.bmp");

}
bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){		
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();
			//{
				//nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg", "rb"));
				//SDL_Rect fuente;
				//fuente.x = 90;
				//fuente.y = 152;
				//fuente.w = 243;
				//fuente.h = 78;

				//SDL_Rect destino;
				//destino.x = 100;
				//destino.y = 100;
				//destino.w = fuente.w;
				//destino.h = fuente.h;

				//SDL_BlitSurface(nave, &fuente, screen, &destino);
			//}
			estado = ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:
			//nave->PintarModulo(0, 0, 0, 64, 64);//Pintando
			//nave->PintarModulo(0, 100, 100);

			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				nave->Mover(1);
			}

			if (keys[SDLK_LEFT])
			{
				nave->Mover(-1);
			}

			nave->Pintar();
			//Los 3 casos siguientes son el primero aplicado a las demás direcciones

			break;
		case Estado::ESTADO_JUGANDO:	
			break;
		case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
				break;
		case Estado::ESTADO_FINALIZANDO:
			break;
		};

		while (SDL_PollEvent(&event))//Aquí SDL creará una lista de eventos ocurridos
		{
			if (event.type == SDL_QUIT) {salirJuego = true;}//Si se detecta una salida de SDL o...

			if (event.type == SDL_KEYDOWN){}
		}

		//Este código estará provicionalmente aquí 
		SDL_Flip(screen);
    }
	return true;
}
 