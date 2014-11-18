#include <SDL_image.h>
#include "Nave.h"
class CGame
{
public:
	enum Estado
	{
		ESTADO_INICIANDO,
		ESTADO_MENU,
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
	bool EsLimitePantalla(Nave * objeto, int bandera); //L�mite de pantalla, utilizamos un puntero
	//La bandera me va a recibir un numero entero, pero lo va a trabajar como binario
	int opcionSeleccionada;
	Uint8 * keys;//Esta variable nos servri� para ver si determinadas teclas est�n o no pulsadas
	SDL_Event event;//La variable event de tipo evento de SDL nos servir� para monitorizar el

	SDL_Surface * screen;
	Nave * nave;
	Nave * enemigoArreglo [10];

	Nave * menu; //Fondo del men�
	Nave * textos; //Textos del juego
	Nave * fondo; //Fondo del juego

	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;
	Estado estado;
};