#ifndef __SPRITEDEF_H__
#define __SPRITEDEF_H__

class SpriteDef
{
public:
	struct Modulos
	{
		int id;
		int x;
		int y;
		int w;
		int h;
	};

	Modulos modulos [1]; //1 indica el n�mero de m�dulos que debemos tener definidos en nuestro archivo .cpp
	SpriteDef();
};

#endif