#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module) //Game pasa sus parametros a nave
{
	nave = new Objeto(screen, rutaImagen, x, y, module); //Nave pasa sus parametros a Objeto nave
	for (int i = 0; i < MAXIMO_DE_BALAS; i++)
	{
		bala[i] = new Objeto(screen, "../Data/balas.bmp", 0, 0, MODULO_BALAS_BALA);
		bala[i]->SetVisible(false); //La bala va a ser no visible
	}

	for (int i = 0; i < MAXIMO_DE_BALAS; i++) //*
	{
		balaNueva[i] = new Objeto(screen, "../Data/balanueva.bmp", 0, 0, MODULO_BALAS_BALA);
		balaNueva[i]->SetVisible(false); //La bala va a ser no visible
	}

	balasVisibles = 0;
	visible = true;
	colision = false;
}

void Nave::CrearNuevo()
{
	balasVisibles = 0;
	visible = true;
	colision = false;

	for (int i = 0; i < MAXIMO_DE_BALAS; i++)
	{
		bala[i]->SetVisible(false);
	}
	nave->PonerEn(0, 0); //Mover X y Y
}

void Nave::Pintar(int tipoNave)
{
	if (visible)
	{
		nave->Pintar();
		for (int i = 0; i < MAXIMO_DE_BALAS; i++)
		{
			bala[i]->Pintar();
			balaNueva[i]->Pintar();
			//bala[i]->MoverX(2);
			switch (tipoNave)
			{
			case NAVE_PROPIA:
				balaNueva[i]->MoverY(-10); //Código para mover arriba
				break;
			case NAVE_ENEMIGO:
				bala[i]->MoverY(10); //Código para mover abajo
				break;
			}
		}
	}
}

void Nave::Disparar(int tipoNave, int balas)
{
	if (visible) //Solamente va a disparar cuando esté visible
	{
		balaNueva[balasVisibles]->SetVisible(true);
		bala[balasVisibles]->SetVisible(true);
		switch (tipoNave)
		{
		case NAVE_PROPIA:
			balaNueva[balasVisibles]->PonerEn(nave->ObtenerX() + nave->ObtenerW() / 2, nave->ObtenerY());
			break;
		case NAVE_ENEMIGO:
			bala[balasVisibles]->PonerEn(nave->ObtenerX() + nave->ObtenerW() / 2, nave->ObtenerY() + nave->ObtenerH());
			break;
		}

		balasVisibles++;
		if (balasVisibles >= balas)
			balasVisibles = 0;
	}
}

void Nave::MoverIzquierda(int velocidad)
{
	nave->MoverX(-velocidad);
}

void Nave::MoverDerecha(int velocidad)
{
	nave->MoverX(velocidad);
}

void Nave::MoverArriba(int velocidad)
{
	nave->MoverY(-velocidad);
}

void Nave::MoverAbajo(int velocidad)
{
	nave->MoverY(velocidad);
}

Objeto * Nave::GetNaveObjeto()
{
	return nave; //Return nave porque nave es el tipo objeto y con el que quiero hacer la comparación
}

void Nave::AutoDisparar(int balas)
{
	if ((rand() % 100)<1)
		Disparar(NAVE_ENEMIGO, balas);

}

void Nave::setVisible(bool visible)
{
	this->visible = visible;
}

bool Nave::estaColisionandoConBala(Nave * nave) //En éste método vamos a implementar las colisiones
{

	return colision;
}

void Nave::simularColision(bool colision)
{
	this->colision = colision;
}