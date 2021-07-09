#include "Scenario.h"
#include "includes.h"

/**
*
*/
Scenario::Scenario(float* p1X, float* p2X, float* p1SpeedX, float* p2SpeedX, bool* p1FreeMove, bool* p2FreeMove)
{
	scenarioSprite = al_load_bitmap("sprites//scenario.bmp");
	if (scenarioSprite == NULL)//verificando se a imagem foi carregada na memoria
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO CARREGAR AS IMAGENS", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		//return;
	}

	this->p1X = p1X;
	this->p2X = p2X;
	this->p1SpeedX = p1SpeedX;
	this->p2SpeedX = p2SpeedX;
	this->p1FreeMove = p1FreeMove;
	this->p2FreeMove = p2FreeMove;

	scenarioX = -462;

}

/**
*
*/
Scenario::~Scenario()
{
	al_destroy_bitmap(scenarioSprite);
}

/**
* Procedimento que imprime o cenario na tela do jogo
*/
void Scenario::PrintScenario(ALLEGRO_EVENT* ev)
{

	//evita problema de flutuabilidade de quantidade de frames na tela
	if (ev->type == ALLEGRO_EVENT_TIMER)
	{
		MoveScenario();
	}

	//imprimindo o cenario na tela do jogo
	al_draw_bitmap_region(scenarioSprite, 0, 0, 2012, 630, scenarioX, 0, 0);
}

/**
* Procedimento que movimenta o cenario
*/
void Scenario::MoveScenario()
{
	*p1FreeMove = false;
	*p2FreeMove = false;

	//o personagem 1 est� na esquerda e o personagem 2 est� na direita
	if (*p1X < *p2X)
	{
		//o personagem 1 est� se movendo para a esquerda
		if (*p1SpeedX < 0)
		{
			//o personagem 1 est� na posi��o X2 ou antes, o personagem 2 est� antes da posi��o X3 e o cenario n�o chegou ao fim
			if (*p1X <= X2POS && *p2X < X3POS && scenarioX < 0)
			{
				//se a proxima posi��o do cenario for maior que zero coloca a posi��o do cenario igual a zero
				if (scenarioX - *p1SpeedX > 0) scenarioX = 0;
				else
				{
					scenarioX -= *p1SpeedX; //move o cenario
					//se a proxima possi��o do segundo personagem for maior que x3 coloca a posi��o do segundo personagem igual a x3
					if (*p2X - *p1SpeedX > X3POS) *p2X = X3POS;
					//se n�o move ele normalmente
					else *p2X -= *p1SpeedX;
				}
			}
			//o personagem 1 est� na posi��o X1 ou antes, o personagem 2 est� antes da posi��o X4 e o cenario n�o chegou ao fim
			else if (*p1X <= X1POS && *p2X < X4POS && scenarioX < 0)
			{
				//se a proxima posi��o do cenario for menor que zero coloca a posi��o do cenario igual a zero
				if (scenarioX - *p1SpeedX > 0) scenarioX = 0;
				else
				{
					scenarioX -= *p1SpeedX;
					//se a proxima possi��o do segundo personagem for maior que x4 coloca a posi��o do segundo personagem igual a x4
					if (*p2X - *p1SpeedX > X4POS) *p2X = X4POS;
					//se n�o move ele normalmente
					else *p2X -= *p1SpeedX;
				}
			}
		}

		//o personagem 2 est� se movendo para a direita
		if (*p2SpeedX > 0)
		{
			if (*p2X >= X3POS && *p1X > X2POS && scenarioX > -872)
			{
				//se a proxima posi��o do cenario for menor que -872 coloca a posi��o do cenario igual a -872
				if (scenarioX - *p2SpeedX < -872) scenarioX = -872;
				else
				{
					scenarioX -= *p2SpeedX; //move o cenario
					//se a proxima possi��o do segundo personagem for menor que x3 coloca a posi��o do segundo personagem igual a x2
					if (*p1X - *p2SpeedX < X2POS) *p1X = X2POS;
					//se n�o move ele normalmente
					else *p1X -= *p2SpeedX;
				}
			}
			else if (*p2X >= X4POS && *p1X > X1POS && scenarioX > -872)
			{
				//se a proxima posi��o do cenario for maior que -872 coloca a posi��o do cenario igual a -872
				if (scenarioX - *p2SpeedX < -872) scenarioX = -872;
				else
				{
					scenarioX -= *p2SpeedX;
					//se a proxima possi��o do segundo personagem for maior que x3 coloca a posi��o do segundo personagem igual a x3
					if (*p1X - *p2SpeedX > X4POS) *p1X = X1POS;
					//se n�o move ele normalmente
					else *p1X -= *p2SpeedX;
				}
			}
		}

		//se o cenario j� tiver atingido o limite maximo
		if (scenarioX == 0) *p1FreeMove = true;
		//se o p2 estiver na posi��o X3
		else if (*p2X >= X3POS) *p1FreeMove = true;
		//se o p1 estiver antes da posi��o X1
		else if (*p1X < X2POS) *p1FreeMove = true;


		//se o cenario j� tiver atingido o limite maximo
		if (scenarioX == -872) *p2FreeMove = true;
		//se o p2 estiver na posi��o X2
		else if (*p1X <= X2POS) *p2FreeMove = true;
		//se o p1 estiver depois da posi��o X3
		else if (*p2X > X3POS) *p2FreeMove = true;

	}
	//personagem 1 est� na direita e o personagem 2 est� na esquerda
	else if (*p1X > * p2X)
	{
		//o personagem 1 est� se movendo para a direita
		if (*p1SpeedX > 0)
		{
			//se o personagem 1 est� na posi��o X3 ou depois,se o personagem 2 est� depois da posi��o X2 e o cenario n�o chegou ao fim
			if (*p1X >= X3POS && *p2X > X2POS && scenarioX > -872)
			{
				//se a proxima posi��o do cenario for menor que -872 coloca a posi��o do cenario igual a -872
				if (scenarioX - *p1SpeedX < -872) scenarioX = -872;
				else
				{
					scenarioX -= *p1SpeedX; //move o cenario
					//se a proxima possi��o do segundo personagem for menor que x3 coloca a posi��o do segundo personagem igual a x2
					if (*p2X - *p1SpeedX < X2POS) *p2X = X2POS;
					//se n�o move ele normalmente
					else *p2X -= *p1SpeedX;
				}
			}
			//se o personagem 1 est� na posi��o X4 ou depois, se o personagem 2 est� depois da posi��o X1 e o cenario n�o chegou ao fim
			else if (*p1X >= X4POS && *p2X > X1POS && scenarioX > -872)
			{
				//se a proxima posi��o do cenario for maior que -872 coloca a posi��o do cenario igual a -872
				if (scenarioX - *p1SpeedX < -872) scenarioX = -872;
				else
				{
					scenarioX -= *p1SpeedX;
					//se a proxima possi��o do segundo personagem for maior que x3 coloca a posi��o do segundo personagem igual a x3
					if (*p2X - *p1SpeedX > X4POS) *p2X = X1POS;
					//se n�o move ele normalmente
					else *p2X -= *p1SpeedX;
				}
			}
		}

		//se o personagem 2 est� se movendo para a esquerda
		if (*p2SpeedX < 0)
		{
			//se o personagem 2 est� na posi��o X2 ou antes, se o personagem 1 est� antes da posi��o X3 e o cenario chegou ao fim
			if (*p2X <= X2POS && *p1X < X3POS && scenarioX < 0)
			{
				//se a proxima posi��o do cenario for maior que zero coloca a posi��o do cenario igual a zero
				if (scenarioX - *p2SpeedX > 0) scenarioX = 0;
				else
				{
					scenarioX -= *p2SpeedX; //move o cenario
					//se a proxima possi��o do segundo personagem for maior que x3 coloca a posi��o do segundo personagem igual a x3
					if (*p1X - *p2SpeedX > X3POS) *p1X = X3POS;
					//se n�o move ele normalmente
					else *p1X -= *p2SpeedX;
				}
			}
			//se o personagem 2 est� na posi��o X1 ou antes, se o personagem 1 est� antes da posi��o X4 e o cenario chegou ao fim
			else if (*p2X <= X1POS && *p1X < X4POS && scenarioX < 0)
			{
				//se a proxima posi��o do cenario for menor que zero coloca a posi��o do cenario igual a zero
				if (scenarioX - *p2SpeedX > 0) scenarioX = 0;
				else
				{
					scenarioX -= *p2SpeedX;
					//se a proxima possi��o do segundo personagem for maior que x4 coloca a posi��o do segundo personagem igual a x4
					if (*p1X - *p2SpeedX > X4POS) *p1X = X4POS;
					//se n�o move ele normalmente
					else *p1X -= *p2SpeedX;
				}
			}
		}

		//se o cenario j� tiver atingido o limite maximo
		if (scenarioX == -872) *p1FreeMove = true;
		//se o p2 estiver na posi��o X2
		else if (*p2X <= X2POS) *p1FreeMove = true;
		//se o p1 estiver depois da posi��o X3
		else if (*p1X > X3POS) *p1FreeMove = true;

		//se o cenario j� tiver atingido o limite maximo
		if (scenarioX == 0) *p2FreeMove = true;
		//se o p2 estiver na posi��o X3
		else if (*p1X >= X3POS) *p2FreeMove = true;
		//se o p1 estiver antes da posi��o X1
		else if (*p2X < X2POS) *p2FreeMove = true;

	}
	//se os 2 personages estiverem na nesma posi��o
	else if (*p1X == *p2X)
	{
		//se os personagens estiverem na posi��o X1 e o personagem 2 estiver se movendo para a esquerda e o cenario n�o tiver chegado ao fim
		if (*p1X == X1POS && *p2SpeedX < 0 && scenarioX < 0)
		{
			//se a proxima vez que o cenario vai se mover for fazer o cenario passar de 0, coloca o cenario em 0
			if (scenarioX - *p2SpeedX > 0) scenarioX = 0;
			else
			{
				scenarioX -= *p2SpeedX;	//movimenta o cenario
				*p1X -= *p2SpeedX / 2;	//movimenta o personagem 1
			}
		}
		//se os personagens estiverem na posi��o X4 e o personagem 1 estiver se movendo para a direita e o cenario n�o tiver chegado ao fim
		else if (*p2X == X4POS && *p1SpeedX > 0 && scenarioX > -872)
		{
			//se a proxima vez que o cenario vai se mover for fazer o cenario passar de -872, coloca o cenario em 872
			if (scenarioX - *p1SpeedX < -872) scenarioX = -872;
			else
			{
				scenarioX -= *p1SpeedX;	//movimenta o cenario
				*p2X -= *p1SpeedX / 2;	//movimenta o personagem 2
			}
		}
		//se os personagens estiverem em X2 e o personagem 2 est� se movendo para a esquerda
		else if (*p1X == X2POS && *p2SpeedX < 0)
		{
			scenarioX -= *p2SpeedX;	//movimenta o cenario
			*p1X -= *p2SpeedX;		//movimenta o personagem 2
		}
		//se os personagens estiverem em X3 e o personagem 1 est� se movendo para a direita
		else if (*p2X == X3POS && *p1SpeedX > 0)	
		{
			scenarioX -= *p1SpeedX;	//movimenta o cenario
			*p2X -= *p1SpeedX;		//movimenta o personagem 1
		}
		
	}

	//se os personagens est�o antes de X2 ou depois de X3
	if ((*p1X < X2POS && *p2X < X2POS) || (*p1X > X3POS && *p2X > X3POS))
	{
		*p1FreeMove = true;
		*p2FreeMove = true;
	}

}

//gets
float Scenario::GetX()
{
	return scenarioX;
}
