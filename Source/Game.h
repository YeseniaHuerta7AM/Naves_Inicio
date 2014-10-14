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
	
	Uint8 * keys;//Esta variable nos servriá para ver si determinadas teclas están o no pulsadas
	SDL_Event event;//La variable event de tipo evento de SDL nos servirá para monitorizar el

	SDL_Surface * screen;
	Nave * nave;
	Estado estado;
};