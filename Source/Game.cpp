#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

//NOTA: EL JUEGO SE LIMITA PARA QUE CORRA IGUAL EN TODAS LAS MÁQUINAS

CGame::CGame()
{
	tiempoFrameInicial = 0;
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	delete nave;
	 //delete *keys;
	delete *enemigoArreglo;
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
	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);


	nave = new Nave(screen, "../Data/MiNave.bmp", (WIDTH_SCREEN / 2), (HEIGHT_SCREEN - 80), MODULO_MINAVE_NAVE);
	menu = new Nave(screen, "../Data/Fondo.bmp", 0, 0, MODULO_MENU_FONDO);
	textos = new Nave(screen, "../Data/Texto.bmp", 0, 0, -1);

	for (int i = 0; i < 10; i++)
	{
		enemigoArreglo[i] = new Nave(screen, "../Data/enemigo.bmp", i*60, 0, MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);
	}

	tick = 0;
	opcionSeleccionada = MODULO_TEXTOS_MENU_OPCION1;
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

			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_MENU:
			menu->Pintar(); //Pinta el fondo del menú
			textos->Pintar(MODULO_TEXTOS_TITULO, 275, 150); //Pinta los textos del menú
			textos->Pintar(MODULO_TEXTOS_MENU_OPCION1, 265, 190);
			textos->Pintar(MODULO_TEXTOS_MENU_OPCION2, 278, 230);
			//textos->Pintar(MODULO_TEXTOS_MENU_OPCION1_SELECCIONADO, 380, 190);
			//textos->Pintar(MODULO_TEXTOS_MENU_OPCION2_SELECCIONADO, 393, 230);
			Menu();
			//estado = ESTADO_JUGANDO;
			break;

		case Estado::ESTADO_JUGANDO:
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Actualizar();
			}

			MoverEnemigo();
			
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				if (!EsLimitePantalla(nave, BORDE_DERECHO)) //Si no está dentro del límite de la pantalla, no mover (! para negarlo)
					nave->MoverX(5);
			}

			if (keys[SDLK_LEFT])
			{
				if (!EsLimitePantalla(nave, BORDE_IZQUIERDO))
					nave->MoverX(-5);
			}

			/*if (keys[SDLK_UP])
			{
				if (!EsLimitePantalla(nave, BORDE_SUPERIOR))
					nave->MoverY(-5);
			}

			if (keys[SDLK_DOWN])
			{
				if (!EsLimitePantalla(nave, BORDE_INFERIOR))
					nave->MoverY(5);
			}*/

			nave->Pintar();

			for (int i = 0; i < 10; i++)

				enemigoArreglo[i]->Pintar();

			//Los 3 casos siguientes son el primero aplicado a las demás direcciones
			break;
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
		SDL_Flip(screen); //La memoria principal no tiene nada hasta que llega aquí. Aquí se pinta 
		
		//Calculando FPS
		tiempoFrameFinal = SDL_GetTicks();
		while (tiempoFrameFinal < (tiempoFrameInicial + FPS_DELAY))
			tiempoFrameFinal = SDL_GetTicks();
		SDL_Delay(2); //Hacer una pausa de 1 milisegundo en el sistema para tener un procesador no tan ocupado


		printf("Frames: %d Tiempo: %d Tiempo promedio: %f Tiempo por frame: %d FPS: %f\n", tick, SDL_GetTicks(), (float)SDL_GetTicks() / (float)tick, tiempoFrameFinal - tiempoFrameInicial, 1000.0f / (float)(tiempoFrameFinal - tiempoFrameInicial));
		tiempoFrameInicial = tiempoFrameFinal;//Marcamos el inicio
		tick++;
    }
	return true;
}

bool CGame::EsLimitePantalla(Nave * objeto, int bandera) //Aquí definimos el método
{
	if (bandera & BORDE_IZQUIERDO)
		if (objeto->ObtenerX() <= 0)//Vamos a hacer cuatro comparaciones, una por cada lado de la pantalla
			return true;

	if (bandera & BORDE_SUPERIOR)
		if (objeto->ObtenerY() <= 0)
		return true;

	if (bandera & BORDE_DERECHO)
		if (objeto->ObtenerX() >= WIDTH_SCREEN - objeto->ObtenerW()) //Si sale del ancho de la pantalla. Restamos el módulo
		return true;

	if (bandera & BORDE_INFERIOR)
		if (objeto->ObtenerY() >= HEIGHT_SCREEN - objeto->ObtenerH()) //Si sale de lo alto de la pantalla
		return true;
	return false; //Si nada de lo anterior se comprueba, permanecemos dentro de los límites
}

void CGame::MoverEnemigo()
{
	for (int i = 0; i < 10; i++)
	{
		//--------------------PASO 0--------------------//
		if (enemigoArreglo[i]->ObtenerPasoActual() == 0)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_DERECHO))
				enemigoArreglo[i]->MoverX(5); //Derecha
			else
			{
				enemigoArreglo[i]->IncrementarPasoActual();
				enemigoArreglo[i]->IncrementarPasoActual();
			}

		//--------------------PASO 1--------------------//
		if (enemigoArreglo[i]->ObtenerPasoActual() == 1)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_INFERIOR))
				enemigoArreglo[i]->MoverY(5); //Abajo 
			else
			{
				enemigoArreglo[i]->IncrementarPasoActual();
				enemigoArreglo[i]->IncrementarPasoActual();
			}

		//--------------------PASO 2--------------------//
		if (enemigoArreglo[i]->ObtenerPasoActual() == 2)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_IZQUIERDO))
				enemigoArreglo[i]->MoverX(-5); //Izquierda
			else
			{
				enemigoArreglo[i]->IncrementarPasoActual();
				enemigoArreglo[i]->IncrementarPasoActual();
			}

		//--------------------PASO 3--------------------//
		if (enemigoArreglo[i]->ObtenerPasoActual() == 3)
			if (!EsLimitePantalla(enemigoArreglo[i], BORDE_INFERIOR))
				enemigoArreglo[i]->MoverY(5); //Abajo
			else
			{
				enemigoArreglo[i]->IncrementarPasoActual();
				enemigoArreglo[i]->IncrementarPasoActual();
			}
	}
	
}

void CGame::Menu()
{
	for (int i = MODULO_TEXTOS_MENU_OPCION1, j = 0; i < MODULO_TEXTOS_MENU_OPCION2; i++, j++)
	{
		if (i == opcionSeleccionada)
			textos->Pintar(i+2, 265, 190+(j*80));
		else
			textos->Pintar(i, 265, 190 + (j * 80));
	}
}
 