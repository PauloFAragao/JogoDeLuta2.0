#include "includes.h"
#include "Interface.h"


//consturtor
Interface::Interface(unsigned short int* p1LifePoints, unsigned short int* p2LifePoints,
	float* p1Shild, float* p2Shild,
	unsigned short int* p1SpecialBar, unsigned short  int* p2SpecialBar,
	unsigned short int* p1SpecialQuantity, unsigned short int* p2SpecialQuantity,
	unsigned int* p1PowTime, unsigned int* p2PowTime,
	bool* p1Pow, bool* p2Pow, unsigned int* gameTime, bool* gamePause, unsigned short int* round,
	bool* uiAnimationFinished, bool* uiAnimationStarted, bool* p1roundWin,
	bool* p2roundWin , bool* gameMatchOver
)
{

	//carregando a imagem
	interfaceSprites = al_load_bitmap("sprites//Interface.bmp");
	if (interfaceSprites == NULL)//verificando se a imagem foi carregada na memoria
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO CARREGAR A INTERFACE", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	al_convert_mask_to_alpha(interfaceSprites, al_map_rgb(255, 0, 255));//definindo a cor que deve ser ignorada

	this->p1LifePoints = p1LifePoints;
	this->p2LifePoints = p2LifePoints;
	this->p1Shild = p1Shild;
	this->p2Shild = p2Shild;
	this->p1SpecialBar = p1SpecialBar;
	this->p2SpecialBar = p2SpecialBar;
	this->p1SpecialQuantity = p1SpecialQuantity;
	this->p2SpecialQuantity = p2SpecialQuantity;
	this->p1PowTime = p1PowTime;
	this->p2PowTime = p2PowTime;
	this->p1Pow = p1Pow;
	this->p2Pow = p2Pow;
	this->gameTime = gameTime;
	this->gamePause = gamePause;
	this->round = round;
	this->p1LifePointsMemory = *p1LifePoints;
	this->p2LifePointsMemory = *p2LifePoints;
	this->uiAnimationStarted = uiAnimationStarted;
	this->uiAnimationFinished = uiAnimationFinished;
	this->gameMatchOver = gameMatchOver;
	this->p1roundWin = p1roundWin;
	this->p2roundWin = p2roundWin;

	frame = 0;
	captureTime = 0;
	textTimer = 0;
	frameT = 0;
	
	roundT = false;
	readyT = false;
	goT = false;
	koT = false;
	winnerT = false;
	timeOverT = false;
	drawGameT = false;
	perfectT = false;
	animacaoStart = false;
}

//destrutor
Interface::~Interface()
{

}

/**
*	função principal
*/
void Interface::BuildInterface()//al_draw_bitmap_region(interfaceSprites, XMin, YMIN, XMax, YMax, X, Y, FLIP);
{

	//---------- player 1 ---------

	//nome do personagem
	al_draw_bitmap_region(interfaceSprites, 723, 0, 112, 20, 178, 87, 0);

	//player 1 frame
	al_draw_bitmap_region(interfaceSprites, 632, 45, 172, 154, PLAYER1FRAME_X, PLAYER1FRAME_Y, 0);

	//barra de vida verde do player 1
	P1LifeBarBuild();

	//barra de escudo do player 1
	p1ShildBarBuild();

	//frame da barra de vida player 1
	al_draw_bitmap_region(interfaceSprites, 0, 0, 415, 55, PLAYER1LIFEBAR_X, PLAYER1LIFEBAR_Y, 0);

	//barra de especial player 1
	if( *p1SpecialQuantity != 5 ) p1SpecialBarBuild();
	else if (*p1SpecialQuantity == 5) BarAnimation(1);

	//frame de especial do player 1 - pow
	if (*p1Pow) 
	{
		//barra de pow do player 1
		p1PowBarBuild();

		al_draw_bitmap_region(interfaceSprites, 297, 57, 295, 72, PLAYER1SPECIALBAR_X, PLAYER1SPECIALBAR_Y, 0); 
	}
	//barra de especial do player 1 - normal
	else al_draw_bitmap_region(interfaceSprites, 0, 57, 295, 72, PLAYER1SPECIALBAR_X, PLAYER1SPECIALBAR_Y, 0);

	//numero da quantidade barras de especial carregadas
	p1SpecialNumberBuild();
	
	if (*p1SpecialQuantity == 5)
	{
		al_draw_bitmap_region(interfaceSprites, 616, 13, 21, 20, 124, 567, 0);//M
		al_draw_bitmap_region(interfaceSprites, 639, 13, 18, 20, 148, 567, 0);//A
		al_draw_bitmap_region(interfaceSprites, 659, 13, 20, 20, 169, 567, 0);//X
		al_draw_bitmap_region(interfaceSprites, 681, 13, 6, 20, 192, 567, 0);//I
		al_draw_bitmap_region(interfaceSprites, 616, 13, 21, 20, 201, 567, 0);//M
		al_draw_bitmap_region(interfaceSprites, 689, 13, 18, 20, 225, 567, 0);//U
		al_draw_bitmap_region(interfaceSprites, 616, 13, 21, 20, 246, 567, 0);//M
	}

	//---------- player 2 ---------

	//nome do personagem
	al_draw_bitmap_region(interfaceSprites, 723, 22, 112, 20, 847, 87, 0);

	//player 2 frame
	al_draw_bitmap_region(interfaceSprites, 632, 45, 172, 154, PLAYER2FRAME_X, PLAYER2FRAME_Y, ALLEGRO_FLIP_HORIZONTAL);

	//barra de vida verde do player 2
	P2LifeBarBuild();

	//barra de escudo do player 2
	p2ShildBarBuild();

	//frame da barra de vida player 2
	al_draw_bitmap_region(interfaceSprites, 0, 0, 415, 55, PLAYER2LIFEBAR_X, PLAYER2LIFEBAR_Y, ALLEGRO_FLIP_HORIZONTAL);

	//barra de especial do player 2
	if (*p2SpecialQuantity != 5) p2SpecialBarBuild();
	else if (*p2SpecialQuantity == 5) BarAnimation(2);


	//barra de especial do player 2 - pow
	if (*p2Pow)
	{ 
		//barra de pow do player 2
		p2PowBarBuild();

		al_draw_bitmap_region(interfaceSprites, 297, 57, 295, 72, PLAYER2SPECIALBAR_X, PLAYER2SPECIALBAR_Y, ALLEGRO_FLIP_HORIZONTAL); 
	}
	//barra de especial do player 2 - normal
	else al_draw_bitmap_region(interfaceSprites, 0, 57, 295, 72, PLAYER2SPECIALBAR_X, PLAYER2SPECIALBAR_Y, ALLEGRO_FLIP_HORIZONTAL);

	//numero da quantidade barras de especial carregadas
	p2SpecialNumberBuild();

	if (*p2SpecialQuantity == 5)
	{
		al_draw_bitmap_region(interfaceSprites, 616, 13, 21, 20, 878, 567, 0);//M
		al_draw_bitmap_region(interfaceSprites, 639, 13, 18, 20, 902, 567, 0);//A
		al_draw_bitmap_region(interfaceSprites, 659, 13, 20, 20, 923, 567, 0);//X
		al_draw_bitmap_region(interfaceSprites, 681, 13, 6, 20, 946, 567, 0);//I
		al_draw_bitmap_region(interfaceSprites, 616, 13, 21, 20, 955, 567, 0);//M
		al_draw_bitmap_region(interfaceSprites, 689, 13, 18, 20, 979, 567, 0);//U
		al_draw_bitmap_region(interfaceSprites, 616, 13, 21, 20, 1000, 567, 0);//M
	}


	//timer do jogo
	if (*gameTime >= 1000)
	{
		timerBuild();
	}
	else //primeira forma de acabar o jogo
	{
		frame = 1;
		Number0Anim(false, 2);
		Number0Anim(true, 2);
		if (!*gameMatchOver)
		{
			timeOverT = true;
			*gameMatchOver = true;
			frameT = 0;
			textTimer = clock();
		}
	}


	if (*uiAnimationStarted)
	{
		if (roundT && RoundTextBuild())
		{
			roundT = false;
			readyT = true;
			frameT = 0;
			textTimer = clock();
		}
		else if (readyT && ReadyTextBuild())
		{
			readyT = false;
			goT = true;
			textTimer = clock();
		}
		else if (goT && GOTextBuild())
		{
			goT = false;
			*uiAnimationFinished = true;
		}
	}

	if (*p1LifePoints <= 0 || *p2LifePoints <= 0)//segunda forma de acabar o jogo
	{
		if (*p1LifePoints <= 0 && *p2LifePoints <= 0)
		{
			*gameMatchOver = true;
			drawGameT = true;

			frameT = 0;
			textTimer = clock();
		}
		else if (*p2LifePoints <= 0)//vitoria do p1
		{
			*p1roundWin = true;
			winnerT = true;

			frameT = 0;
			textTimer = clock();
		}
		else if (*p1LifePoints <= 0)//vitoria do p2
		{
			*p2roundWin = true;
			winnerT = true;

			frameT = 0;
			textTimer = clock();
		}
	}

	if ( *gameMatchOver )
	{
		if (timeOverT && !drawGameT && !winnerT && TimeOverTextBuild())//time over
		{
			
			if (*p1LifePoints == *p2LifePoints)//empate do jogo
			{
				drawGameT = true;

				frameT = 0;
				textTimer = clock();
			}
			else if (*p1LifePoints > * p2LifePoints)//vitoria do player 1
			{
				*p1roundWin = true;
				winnerT = true;

				frameT = 0;
				textTimer = clock();
			}
			else if (*p1LifePoints < *p2LifePoints)//vitoria do player 2
			{
				*p2roundWin = true;
				winnerT = true;

				frameT = 0;
				textTimer = clock();
			}
		}

		else if (drawGameT) 
		{
			DrawGameTextBuild();
		}

		else if (koT && KOTextBuild())
		{
			koT = false;
			winnerT = true;
		}

		else if (winnerT && WinnerTextBuild())
		{
			if ((*p1LifePoints == TERRYLIFEPOINTS || *p2LifePoints == TERRYLIFEPOINTS) && *p1LifePoints != *p2LifePoints)
			{
				perfectT = true;
				frameT = 0;
				textTimer = clock();
			}
		}

		else if(perfectT) PerfectTextBuild();
	}
}

/**
*	função que vai processar e imprimir a barra de vida do player 1 na tela
*/
void Interface::P1LifeBarBuild()
{

	if (*p1LifePoints != p1LifePointsMemory)
	{
		p1LifePointsMemory -= 3;

		if (p1LifePointsMemory < *p1LifePoints) p1LifePointsMemory = *p1LifePoints;

		al_draw_filled_rectangle(
			P1LIFEBAR_X + LIFEBAR_W - 1 * ((((p1LifePointsMemory * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100),
			P1LIFEBAR_Y, P1LIFEBAR_X + LIFEBAR_W, P1LIFEBAR_Y + LIFEBAR_H, al_map_rgb(206, 0, 5));

	}
	
	al_draw_filled_rectangle(
		P1LIFEBAR_X + LIFEBAR_W -1 * ((((*p1LifePoints * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100),
		P1LIFEBAR_Y, P1LIFEBAR_X + LIFEBAR_W, 57, al_map_rgb(107, 226, 143));

	al_draw_filled_rectangle(
		P1LIFEBAR_X + LIFEBAR_W - 1 * ((((*p1LifePoints * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100),
		57, P1LIFEBAR_X + LIFEBAR_W, 72, al_map_rgb(35, 177, 78));

	al_draw_filled_rectangle(
		P1LIFEBAR_X + LIFEBAR_W - 1 * ((((*p1LifePoints * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100),
		72, P1LIFEBAR_X + LIFEBAR_W, 74, al_map_rgb(18, 92, 40));
	
	return;
}
/**
*	função que vai processar e imprimir a barra de vida do player 2 na tela
*/
void Interface::P2LifeBarBuild()
{

	if (*p2LifePoints != p2LifePointsMemory)
	{
		
		p2LifePointsMemory -= 3;

		if (p2LifePointsMemory < *p2LifePoints) p2LifePointsMemory = *p2LifePoints;

		al_draw_filled_rectangle(P2LIFEBAR_X, P2LIFEBAR_Y,
			P2LIFEBAR_X + (((p1LifePointsMemory * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100,
			P2LIFEBAR_Y+LIFEBAR_H, al_map_rgb(206, 0, 5));


	}
	
	al_draw_filled_rectangle(P2LIFEBAR_X, P2LIFEBAR_Y, 
		P2LIFEBAR_X + (((*p1LifePoints * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100,
		57, al_map_rgb(107, 226, 143));

	al_draw_filled_rectangle(P2LIFEBAR_X, 57, 
		P2LIFEBAR_X + (((*p1LifePoints * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100,
		72, al_map_rgb(35, 177, 78));

	al_draw_filled_rectangle(P2LIFEBAR_X, 72, 
		P2LIFEBAR_X + (((*p1LifePoints * 100) / TERRYLIFEPOINTS) * LIFEBAR_W) / 100,
		74, al_map_rgb(18, 92, 40));
	

	return;
}
/**
*	função que vai processar e imprimir a barra de escudo do player 1 na tela
*/
void Interface::p1ShildBarBuild()
{
	
	al_draw_filled_rectangle(
		P1SHILDBAR_X + SHILDBAR_W - 1 * ( ( ( (*p1Shild * 100) / SHILDPOINTS) * SHILDBAR_W) / 100),
		P1SHILDBAR_Y, P1SHILDBAR_X + SHILDBAR_W, P1SHILDBAR_Y + SHILDBAR_H, al_map_rgb(63, 72, 204));

	return;
}
/**
*	função que vai processar e imprimir a barra de escudo do player 2 na tela
*/
void Interface::p2ShildBarBuild()
{

	al_draw_filled_rectangle(P2SHILDBAR_X, P2SHILDBAR_Y,
		P2SHILDBAR_X + (((*p2Shild * 100) / SHILDPOINTS) * SHILDBAR_W) / 100,
		P2SHILDBAR_Y + SHILDBAR_H, al_map_rgb(63, 72, 204));

	return;
}
/**
*	função que vai processar e imprimir a barra de pow do player 1 na tela
*/
void Interface::p1PowBarBuild()
{
	al_draw_filled_rectangle(P1POWBAR_X, P1POWBAR_Y,
		P1POWBAR_X + POWBAR_W  -1* ((((( *p1PowTime - *gameTime )*100)/POWTOTALTIME ) * POWBAR_W) / 100),
		P1POWBAR_Y + POWBAR_H, al_map_rgb(235, 63, 5));

	if (*p1PowTime - *gameTime > POWTOTALTIME) *p1Pow = false;

	return;
}
/**
*	função que vai processar e imprimir a barra de pow do player 2 na tela
*/
void Interface::p2PowBarBuild()
{
	al_draw_filled_rectangle(
		P2POWBAR_X + (((((*p2PowTime - *gameTime) * 100) / POWTOTALTIME) * POWBAR_W) / 100),
		P2POWBAR_Y,P2POWBAR_X + POWBAR_W,P2POWBAR_Y + POWBAR_H, al_map_rgb(235, 63, 5));

	if (*p2PowTime - *gameTime > POWTOTALTIME) *p2Pow = false;

	return;
}
/**
*	função que vai processar e imprimir a barra de especial do player 1 na tela
*/
void Interface::p1SpecialBarBuild()//
{
	switch (*p1SpecialQuantity)
	{
	case 0:
		al_draw_filled_rectangle(P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 
			P1ESPECIALBAR_X +(*p1SpecialBar * ESPECIALBAR_W) / 100,
			P1ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(104, 47, 104)); //Roxo
		break;

	case 1:
		al_draw_filled_rectangle(P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 
			P1ESPECIALBAR_X + (*p1SpecialBar * ESPECIALBAR_W) / 100,
			P1ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(0, 162, 232));	//Azul claro
		break;

	case 2:
		al_draw_filled_rectangle(P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 
			P1ESPECIALBAR_X + (*p1SpecialBar * ESPECIALBAR_W) / 100,
			P1ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(19, 98, 43));	//Verde
		break;

	case 3:
		al_draw_filled_rectangle(P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 
			P1ESPECIALBAR_X + (*p1SpecialBar * ESPECIALBAR_W) / 100,
			P1ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(255, 242, 0));	//Amarelo
		break;

	case 4:
		al_draw_filled_rectangle(P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 
			P1ESPECIALBAR_X + (*p1SpecialBar * ESPECIALBAR_W) / 100,
			P1ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(255, 127, 39));	//Laranja
		break;
	}

	return;
}
/**
*	função que vai processar e imprimir a barra de especial do player 2 na tela
*/
void Interface::p2SpecialBarBuild()
{

	switch (*p2SpecialQuantity)
	{
	case 0:
		al_draw_filled_rectangle(
			P2ESPECIALBAR_X + ESPECIALBAR_W - (*p2SpecialBar * ESPECIALBAR_W) / 100,
			P2ESPECIALBAR_Y, P2ESPECIALBAR_X + ESPECIALBAR_W, P2ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(104, 47, 104));	//Roxo
		break;

	case 1:
		al_draw_filled_rectangle(
			P2ESPECIALBAR_X + ESPECIALBAR_W - (*p2SpecialBar * ESPECIALBAR_W) / 100,
			P2ESPECIALBAR_Y, P2ESPECIALBAR_X + ESPECIALBAR_W, P2ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(0, 162, 232));	//Azul claro

		break;

	case 2:
		al_draw_filled_rectangle(
			P2ESPECIALBAR_X + ESPECIALBAR_W - (*p2SpecialBar * ESPECIALBAR_W) / 100,
			P2ESPECIALBAR_Y, P2ESPECIALBAR_X + ESPECIALBAR_W, P2ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(19, 98, 43));	//Verde

		break;

	case 3:
		al_draw_filled_rectangle(
			P2ESPECIALBAR_X + ESPECIALBAR_W - (*p2SpecialBar * ESPECIALBAR_W) / 100,
			P2ESPECIALBAR_Y, P2ESPECIALBAR_X + ESPECIALBAR_W, P2ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(255, 242, 0));	//Amarelo

		break;

	case 4:
		al_draw_filled_rectangle(
			P2ESPECIALBAR_X + ESPECIALBAR_W - (*p2SpecialBar * ESPECIALBAR_W) / 100,
			P2ESPECIALBAR_Y, P2ESPECIALBAR_X + ESPECIALBAR_W, P2ESPECIALBAR_Y + ESPECIALBAR_H, al_map_rgb(255, 127, 39));	//Laranja
		break;

	}

	return;
}
/**
*	função que vai processar e imprimir o numero da quantidade de especial do player 1 na tela
*/
void Interface::p1SpecialNumberBuild()
{
	switch ( *p1SpecialQuantity )
	{

	case 0:
		al_draw_bitmap_region(interfaceSprites, 428, 3, 24, 53, SPECIALNUMBERP1_X, SPECIALNUMBER_Y, 0);//zero
		break;

	case 1:
		al_draw_bitmap_region(interfaceSprites, 453, 3, 16, 53, SPECIALNUMBERP1_X, SPECIALNUMBER_Y, 0);//1
		break;

	case 2:
		al_draw_bitmap_region(interfaceSprites, 470, 3, 24, 53, SPECIALNUMBERP1_X, SPECIALNUMBER_Y, 0);//2
		break;

	case 3:
		al_draw_bitmap_region(interfaceSprites, 495, 3, 24, 53, SPECIALNUMBERP1_X, SPECIALNUMBER_Y, 0);//3
		break;

	case 4:
		al_draw_bitmap_region(interfaceSprites, 520, 3, 24, 53, SPECIALNUMBERP1_X-1, SPECIALNUMBER_Y, 0);//4
		break;

	case 5:
		al_draw_bitmap_region(interfaceSprites, 545, 3, 24, 53, SPECIALNUMBERP1_X, SPECIALNUMBER_Y, 0);//5
		break;

	}
	return;
}
/**
*	função que vai processar e imprimir o numero da quantidade de especial do player 2 na tela
*/
void Interface::p2SpecialNumberBuild()
{
	switch (*p2SpecialQuantity)
	{

	case 0:
		al_draw_bitmap_region(interfaceSprites, 428, 3, 24, 53, SPECIALNUMBERP2_X+4, SPECIALNUMBER_Y, 0);//zero
		break;

	case 1:
		al_draw_bitmap_region(interfaceSprites, 453, 3, 16, 53, SPECIALNUMBERP2_X+4, SPECIALNUMBER_Y, 0);//1
		break;

	case 2:
		al_draw_bitmap_region(interfaceSprites, 470, 3, 24, 53, SPECIALNUMBERP2_X+4, SPECIALNUMBER_Y, 0);//2
		break;

	case 3:
		al_draw_bitmap_region(interfaceSprites, 495, 3, 24, 53, SPECIALNUMBERP2_X+4, SPECIALNUMBER_Y, 0);//3
		break;

	case 4:
		al_draw_bitmap_region(interfaceSprites, 520, 3, 24, 53, SPECIALNUMBERP2_X+3, SPECIALNUMBER_Y, 0);//4
		break;

	case 5:
		al_draw_bitmap_region(interfaceSprites, 545, 3, 24, 53, SPECIALNUMBERP2_X+4, SPECIALNUMBER_Y, 0);//5
		break;

	}

	return;
}
/**
*	função que vai processar e imprimir o timer
*/
void Interface::timerBuild()
{
	//faltam menos que 10 segundos para o tempo acabar
	if (*gameTime <= 11000 && *gameTime > 100 && !*gamePause)
	{
		if (*gameTime <= 6000)FrameControl(false);
		else FrameControl(true);
	}
	//else if(*gameTime < 100) frame = 1;
	else if (!*gamePause)
		frame = 0;

	//unidade
	if (*gameTime % 10000 < 999 && *gameTime % 10000 >= 0) // qualquer numero terminado em 0
	{
		if (*gameTime % 10000 > 950) Number0Anim(false, 0); 
		else if (*gameTime % 10000 > 900) Number0Anim(false, 1); 
		else if (*gameTime % 10000 > 850) Number0Anim(false, 2); 
		else Number0Anim(false, 3);
	}
	else if (*gameTime % 10000 < 1999 && *gameTime % 10000 >= 1000)//qualquer numero terminado em 1
	{
		if (*gameTime % 10000 > 1950) Number1Anim(false, 0);
		else if (*gameTime % 10000 > 1900) Number1Anim(false, 1);
		else if (*gameTime % 10000 > 1850) Number1Anim(false, 2);
		else Number1Anim(false, 3);
	}
	else if (*gameTime % 10000 < 2999 && *gameTime % 10000 >= 2000)//qualquer numero terminado em 2
	{
		if (*gameTime % 10000 > 2950) Number2Anim(false, 0);
		else if (*gameTime % 10000 > 2900) Number2Anim(false, 1);
		else if (*gameTime % 10000 > 2850) Number2Anim(false, 2);
		else Number2Anim(false, 3);
	}
	else if (*gameTime % 10000 < 3999 && *gameTime % 10000 >= 3000)//qualquer numero terminado em 3
	{
		if (*gameTime % 10000 > 3950) Number3Anim(false, 0);
		else if (*gameTime % 10000 > 3900) Number3Anim(false, 1);
		else if (*gameTime % 10000 > 3850) Number3Anim(false, 2);
		else Number3Anim(false, 3);
	}
	else if (*gameTime % 10000 < 4999 && *gameTime % 10000 >= 4000)//qualquer numero terminado em 4
	{
		if (*gameTime % 10000 > 4950) Number4Anim(false, 0);
		else if (*gameTime % 10000 > 4900)Number4Anim(false, 1);
		else if (*gameTime % 10000 > 4850) Number4Anim(false, 2);
		else Number4Anim(false, 3);
	}
	else if (*gameTime % 10000 < 5999 && *gameTime % 10000 >= 5000)//qualquer numero terminado em 5
	{
		if (*gameTime % 10000 > 5950) Number5Anim(false, 0);
		else if (*gameTime % 10000 > 5900) Number5Anim(false, 1);
		else if (*gameTime % 10000 > 5850) Number5Anim(false, 2);
		else Number5Anim(false, 3);
	}
	else if (*gameTime % 10000 < 6999 && *gameTime % 10000 >= 6000)//qualquer numero terminado em 6
	{
		if (*gameTime % 10000 > 6950) Number6Anim(false, 0);
		else if (*gameTime % 10000 > 6900) Number6Anim(false, 1);
		else if (*gameTime % 10000 > 6850) Number6Anim(false, 2);
		else Number6Anim(false, 3);
	}
	else if (*gameTime % 10000 < 7999 && *gameTime % 10000 >= 7000)//qualquer numero terminado em 7
	{
		if (*gameTime % 10000 > 7950) Number7Anim(false, 0);
		else if (*gameTime % 10000 > 7900) Number7Anim(false, 1);
		else if (*gameTime % 10000 > 7850) Number7Anim(false, 2);
		else Number7Anim(false, 3);
	}
	else if (*gameTime % 10000 < 8999 && *gameTime % 10000 >= 8000)//qualquer numero terminado em 8
	{
		if (*gameTime % 10000 > 8950) Number8Anim(false, 0);
		else if (*gameTime % 10000 > 8900) Number8Anim(false, 1);
		else if (*gameTime % 10000 > 8850) Number8Anim(false, 2);
		else Number8Anim(false, 3);
	}
	else if (*gameTime % 10000 < 9999 && *gameTime % 10000 >= 9000)//qualquer numero terminado em 9
	{
		if (*gameTime % 10000 > 9950) Number9Anim(false, 0);
		else if (*gameTime % 10000 > 9900) Number9Anim(false, 1);
		else if (*gameTime % 10000 > 9850) Number9Anim(false, 2);
		else Number9Anim(false, 3);
	}

	//dezena
	if (*gameTime > 90000)
	{
		if (*gameTime > 99950) Number9Anim(true, 0);
		else if (*gameTime > 99900) Number9Anim(true, 1);
		else if (*gameTime > 99850) Number9Anim(true, 2);
		else Number9Anim(true, 3);
	}
	else if (*gameTime > 80000)
	{
		if (*gameTime > 89950) Number8Anim(true, 0);
		else if (*gameTime > 89900) Number8Anim(true, 1);
		else if (*gameTime > 89850) Number8Anim(true, 2);
		else Number8Anim(true, 3);
	}
	else if (*gameTime > 70000)
	{
		if (*gameTime > 79950) Number7Anim(true, 0);
		else if (*gameTime > 79900) Number7Anim(true, 1);
		else if (*gameTime > 79850) Number7Anim(true, 2);
		else Number7Anim(true, 3);
	}
	else if (*gameTime >= 60000)
	{
		if (*gameTime > 69950) Number6Anim(true, 0);
		else if (*gameTime > 69900) Number6Anim(true, 1);
		else if (*gameTime > 69850) Number6Anim(true, 2);
		else Number6Anim(true, 3);
	}
	else if (*gameTime >= 50000)
	{
		if (*gameTime > 59950) Number5Anim(true, 0);
		else if (*gameTime > 59900 ) Number5Anim(true, 1);
		else if (*gameTime > 59850) Number5Anim(true, 2);
		else Number5Anim(true, 3);
	}
	else if (*gameTime >= 40000)
	{
		if (*gameTime> 49950) Number4Anim(true, 0);
		else if (*gameTime > 49900) Number4Anim(true, 1);
		else if (*gameTime> 49850) Number4Anim(true, 2);
		else Number4Anim(true, 3);
	}
	else if (*gameTime >= 30000)
	{
		if (*gameTime > 39950) Number3Anim(true, 0);
		else if (*gameTime > 39900) Number3Anim(true, 1);
		else if (*gameTime > 39850) Number3Anim(true, 2);
		else Number3Anim(true, 3);
	}
	else if (*gameTime >= 20000)
	{
		if (*gameTime > 29950) Number2Anim(true, 0);
		else if (*gameTime > 29900) Number2Anim(true, 1);
		else if (*gameTime > 29850) Number2Anim(true, 2);
		else Number2Anim(true, 3);
	}
	else if (*gameTime >= 10000)
	{
		if (*gameTime > 19950) Number1Anim(true, 0);
		else if (*gameTime > 19900) Number1Anim(true, 1);
		else if (*gameTime > 19850) Number1Anim(true, 2);
		else Number1Anim(true, 3);
	}
	else if (*gameTime < 9999)
	{
		if (*gameTime > 9950) Number0Anim(true, 0);
		else if (*gameTime > 9900) Number0Anim(true, 1);
		else if (*gameTime > 9850) Number0Anim(true, 2);
		else Number0Anim(true, 3);
	}

	return;
}
/**
*	função que vai processar a troca de frames
*/
void Interface::FrameControl(bool value)
{
	if (frame == 0)
	{
		if (value && clock() - captureTime > TBF + 115) { frame = 1; captureTime = clock(); }
		else if (!value && clock() - captureTime > TBF + 15) { frame = 1; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (value && clock() - captureTime > TBF + 115) { frame = 0; captureTime = clock(); }
		else if (!value && clock() - captureTime > TBF + 15) { frame = 0; captureTime = clock(); }
		return;
	}
}

/**
*	função que controla a animação do numero 0
*/
void Interface::Number0Anim(bool value, int numberFrame)//animação do numero 0
{
	if (numberFrame == 0)//frame 0
	{
		if (frame == 0)//normal frame
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 0, 131, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 0, 131, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)//red frame
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 35, 131, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 35, 131, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	if (numberFrame == 1)//frame 1
	{
		if (frame == 0)//normal frame
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 70, 133, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 70, 133, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)//red frame
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 103, 133, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 103, 133, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	if (numberFrame == 2)//frame 2
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 136, 135, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 136, 135, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 167, 135, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 167, 135, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	if (numberFrame == 3)//frame 3
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 198, 137, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 198, 137, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 227, 137, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 227, 137, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 1
*/
void Interface::Number1Anim(bool value, int numberFrame)//animação do numero 1
{

	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 256, 131, 15, 65, TIMER1POS_X + 9, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 256, 131, 15, 65, TIMER2POS_X + 9, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 273, 131, 15, 65, TIMER1POS_X + 9, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 273, 131, 15, 65, TIMER2POS_X + 9, TIMERPOS_Y, 0);
			return;
		}
	}
	if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 290, 133, 13, 63, TIMER1POS_X + 11, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 290, 133, 13, 63, TIMER2POS_X + 11, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 305, 133, 13, 63, TIMER1POS_X + 11, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 305, 133, 13, 63, TIMER2POS_X + 11, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 320, 135, 11, 61, TIMER1POS_X + 13, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 320, 135, 11, 61, TIMER2POS_X + 13, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 333, 135, 11, 61, TIMER1POS_X + 13, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 333, 135, 11, 61, TIMER2POS_X + 13, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 346, 137, 9, 59, TIMER1POS_X + 15, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 346, 137, 9, 59, TIMER2POS_X + 15, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 357, 137, 9, 59, TIMER1POS_X + 15, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 357, 137, 9, 59, TIMER2POS_X + 15, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 2
*/
void Interface::Number2Anim(bool value, int numberFrame)//animação do numero 2
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 368, 131, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 368, 131, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 404, 131, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 404, 131, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 440, 133, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 440, 133, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 474, 133, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 474, 133, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 508, 135, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 508, 135, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 540, 135, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 540, 135, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 572, 137, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 572, 137, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 602, 137, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 602, 137, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 3
*/
void Interface::Number3Anim(bool value, int numberFrame)//animação do numero 3
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 0, 198, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 0, 198, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 35, 198, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 35, 198, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 70, 200, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 70, 200, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 103, 200, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 103, 200, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 136, 202, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 136, 202, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 167, 202, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 167, 202, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 198, 204, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 198, 204, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 227, 204, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 227, 204, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 4
*/
void Interface::Number4Anim(bool value, int numberFrame)//animação do numero 4
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 291, 198, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 291, 198, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 256, 198, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 256, 198, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 359, 200, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 359, 200, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 326, 200, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 326, 200, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 423, 202, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 423, 202, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 392, 202, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 392, 202, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 483, 204, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 483, 204, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 454, 204, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 454, 204, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 5
*/
void Interface::Number5Anim(bool value, int numberFrame)//animação do numero 5
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 548, 198, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 548, 198, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 512, 198, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 512, 198, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 618, 200, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 618, 200, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 584, 200, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 584, 200, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 684, 202, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 684, 202, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 652, 202, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 652, 202, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 746, 204, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 746, 204, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 716, 204, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 716, 204, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 6
*/
void Interface::Number6Anim(bool value, int numberFrame)//animação do numero 6
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 36, 265, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 36, 265, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 0, 265, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 0, 265, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 106, 267, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 106, 267, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 72, 267, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 72, 267, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 172, 269, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 172, 269, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
				return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 140, 269, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 140, 269, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 234, 271, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 234, 271, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 204, 271, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 204, 271, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 7
*/
void Interface::Number7Anim(bool value, int numberFrame)//animação do numero 7
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 299, 265, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 299, 265, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 264, 265, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 264, 265, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 367, 267, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 367, 267, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 334, 267, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 334, 267, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 431, 269, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 431, 269, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 400, 269, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 400, 269, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 491, 271, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 491, 271, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 462, 271, 27, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 462, 271, 27, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 8
*/
void Interface::Number8Anim(bool value, int numberFrame)//animação do numero 8
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 555, 265, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 555, 265, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 520, 265, 33, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 520, 265, 33, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 623, 267, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 623, 267, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 590, 267, 31, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 590, 267, 31, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 687, 269, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 687, 269, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 656, 269, 29, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 656, 269, 29, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 746, 271, 26, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 746, 271, 26, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 718, 271, 26, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 718, 271, 26, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}
/**
*	função que controla a animação do numero 9
*/
void Interface::Number9Anim(bool value, int numberFrame)//animação do numero 9
{
	if (numberFrame == 0)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 841, 265, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 841, 265, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 877, 265, 34, 65, TIMER1POS_X, TIMERPOS_Y, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 877, 265, 34, 65, TIMER2POS_X, TIMERPOS_Y, 0);
			return;
		}
	}
	else if (numberFrame == 1)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 773, 267, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 773, 267, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 807, 267, 32, 63, TIMER1POS_X + 1, TIMERPOS_Y + 1, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 807, 267, 32, 63, TIMER2POS_X + 1, TIMERPOS_Y + 1, 0);
			return;
		}
	}
	else if (numberFrame == 2)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 835, 202, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 835, 202, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 867, 202, 30, 61, TIMER1POS_X + 2, TIMERPOS_Y + 2, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 867, 202, 30, 61, TIMER2POS_X + 2, TIMERPOS_Y + 2, 0);
			return;
		}
	}
	else if (numberFrame == 3)
	{
		if (frame == 0)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 775, 204, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 775, 204, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
		if (frame == 1)
		{
			if (value) al_draw_bitmap_region(interfaceSprites, 805, 204, 28, 59, TIMER1POS_X + 3, TIMERPOS_Y + 3, 0);
			else if (!value) al_draw_bitmap_region(interfaceSprites, 805, 204, 28, 59, TIMER2POS_X + 3, TIMERPOS_Y + 3, 0);
			return;
		}
	}
}

/**
* função que vai processar e imprimir na tela o texto do round
*/
bool Interface::RoundTextBuild()
{
	if (frameT == 0 )
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 400, 250, 0);//R
		if(*round == 1) 
			al_draw_bitmap_region(interfaceSprites, 5, 444, 25, 94, 672, 258, 0);//1 - frame 0

		else if (*round == 2)
			al_draw_bitmap_region(interfaceSprites, 184, 444, 31, 94, 672, 258, 0);//2 - frame 0

		else if (*round == 3) 
			al_draw_bitmap_region(interfaceSprites, 369, 444, 31, 94, 672, 258, 0);//3 - frame 0
		
		else if (*round == 4) 
			al_draw_bitmap_region(interfaceSprites, 554, 444, 31, 94, 672, 258, 0);//4 - frame 0
		
		else if (*round == 5) 
			al_draw_bitmap_region(interfaceSprites, 740, 444, 31, 94, 672, 258, 0);//5 - frame 0
		
		if ( clock() - textTimer > TBF+45 ) { frameT ++; textTimer = clock(); }
		return false ;
	}
	if (frameT == 1)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 400, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 449, 250, 0);//O
		if (*round == 1)
			al_draw_bitmap_region(interfaceSprites, 39, 442, 26, 96, 671, 256, 0);//1 - frame 1
		else if (*round == 2) 
			al_draw_bitmap_region(interfaceSprites, 217, 442, 33, 96, 671, 256, 0);//2 - frame 1
		else if (*round == 3) 
			al_draw_bitmap_region(interfaceSprites, 402, 442, 33, 96, 671, 256, 0);//3 - frame 1
		else if (*round == 4) 
			al_draw_bitmap_region(interfaceSprites, 588, 442, 33, 96, 671, 256, 0);//4 - frame 1
		else if (*round == 5) 
			al_draw_bitmap_region(interfaceSprites, 773, 442, 33, 96, 671, 256, 0);//5 - frame 1
		if (clock() - textTimer > TBF+45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 2)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 400, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 449, 250, 0);//O
		al_draw_bitmap_region(interfaceSprites, 260, 332, 39, 102, 499, 250, 0);//U
		if (*round == 1) 
			al_draw_bitmap_region(interfaceSprites, 74, 440, 28, 98, 669, 254, 0);//1 - frame 2
		else if (*round == 2)  
			al_draw_bitmap_region(interfaceSprites, 252, 440, 35, 98, 669, 254, 0);//2 - frame 2
		else if (*round == 3)  
			al_draw_bitmap_region(interfaceSprites, 437, 440, 35, 98, 669, 254, 0);//3 - frame 2
		else if (*round == 4) 
			al_draw_bitmap_region(interfaceSprites, 623, 440, 35, 98, 669, 254, 0);//4 - frame 2
		else if (*round == 5)  
			al_draw_bitmap_region(interfaceSprites, 808, 440, 35, 98, 669, 254, 0);//5 - frame 2
		if (clock() - textTimer > TBF+45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 3)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 400, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 449, 250, 0);//O
		al_draw_bitmap_region(interfaceSprites, 260, 332, 39, 102, 499, 250, 0);//U
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 548, 250, 0);//N
		if (*round == 1) 
			al_draw_bitmap_region(interfaceSprites, 112, 438, 29, 100, 667, 252, 0);//1 - frame 3
		else if (*round == 2)
			al_draw_bitmap_region(interfaceSprites, 289, 438, 37, 100, 667, 252, 0);//2 - frame 3
		else if (*round == 3)
			al_draw_bitmap_region(interfaceSprites, 473, 438, 37, 100, 667, 252, 0);//3 - frame 3
		else if (*round == 4)
			al_draw_bitmap_region(interfaceSprites, 660, 438, 37, 100, 667, 252, 0);//4 - frame 3
		else if (*round == 5)
			al_draw_bitmap_region(interfaceSprites, 740, 334, 37, 100, 667, 252, 0);//5 - frame 3
		if (clock() - textTimer > TBF+45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 4)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 400, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 449, 250, 0);//O
		al_draw_bitmap_region(interfaceSprites, 260, 332, 39, 102, 499, 250, 0);//U
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 548, 250, 0);//N
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 597, 250, 0);//D
		if (*round == 1) 
			al_draw_bitmap_region(interfaceSprites, 151, 436, 31, 102, 665, 250, 0);//1 - frame 4
		else if (*round == 2)
			al_draw_bitmap_region(interfaceSprites, 328, 436, 39, 102, 665, 250, 0);//1 - frame 4
		else if (*round == 3)
			al_draw_bitmap_region(interfaceSprites, 513, 436, 39, 102, 665, 250, 0);//1 - frame 4
		else if (*round == 4)
			al_draw_bitmap_region(interfaceSprites, 699, 436, 39, 102, 665, 250, 0);//1 - frame 4
		else if (*round == 5)
			al_draw_bitmap_region(interfaceSprites, 779, 332, 39, 102, 665, 250, 0);//1 - frame 4
		if (clock() - textTimer > TBF+1000) { frameT ++ ; textTimer = clock(); }
		return false;
	}
	if (frameT == 5) return true;
	
}
/**
*	função que vai processar e imprimir na tela o texto de ready
*/
bool Interface::ReadyTextBuild()
{
	if (frameT == 0)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 464, 250, 0);//R
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 1)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 464, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 513, 250, 0);//E
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 2)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 464, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 513, 250, 0);//E
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 562, 250, 0);//A
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 3)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 464, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 513, 250, 0);//E
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 562, 250, 0);//A
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 611, 250, 0);//D
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 4)
	{
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 464, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 513, 250, 0);//E
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 562, 250, 0);//A
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 611, 250, 0);//D
		al_draw_bitmap_region(interfaceSprites, 424, 332, 38, 102, 660, 250, 0);//Y
		if (clock() - textTimer > TBF + 1000) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 5) return true;
}
/**
*	função que vai processar e imprimir na tela o texto de GO
*/
bool Interface::GOTextBuild()
{

	if (clock() - textTimer < 500)
	{
		al_draw_bitmap_region(interfaceSprites, 504, 332, 38, 102,
			((((clock() - textTimer) * 100) / 500) * 537) / 100,
			250, 0);

		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102,
			1140 - 1 * (((((clock() - textTimer) * 100) / 500) * 587) / 100),
			250, 0);
		return false;

	}
	else if (clock() - textTimer < 2000)
	{
		al_draw_bitmap_region(interfaceSprites, 504, 332, 38, 102, 537, 250, 0);
		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 587, 250, 0);
		return false;
	}
	else return true;

}
/**
*	função que vai processar e imprimir na tela o texto de K. O.
*/
bool Interface::KOTextBuild()
{
	if (clock() - textTimer < 500)
	{

		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102,
			((((clock() - textTimer) * 100) / 500) * 527) / 100,
			250, 0);//K

		al_draw_bitmap_region(interfaceSprites, 708, 422, 12, 12,
			(((((clock() - textTimer) * 100) / 500) * 527) / 100) + 43,
			340, 0);//.


		al_draw_bitmap_region(interfaceSprites, 667, 332, 39, 102,
			1140 - 1 * (((((clock() - textTimer) * 100) / 500) * 592) / 100),
			250, 0);//O
		al_draw_bitmap_region(interfaceSprites, 708, 422, 12, 12,
			(1140 - 1 * (((((clock() - textTimer) * 100) / 500) * 592) / 100)) + 42,
			340, 0);//.
		return false;
	}
	else if (clock() - textTimer < 2000)
	{
		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 527, 250, 0);//K
		al_draw_bitmap_region(interfaceSprites, 708, 422, 12, 12, 570, 340, 0);//.

		al_draw_bitmap_region(interfaceSprites, 667, 332, 39, 102, 592, 250, 0);//O
		al_draw_bitmap_region(interfaceSprites, 708, 422, 12, 12, 634, 340, 0);//.
		return false;
	}
	else return true;
}
/**
*	função que vai processar e imprimir na tela o texto de Time Over
*/
bool Interface::TimeOverTextBuild()
{
	if (frameT == 0)
	{
		al_draw_bitmap_region(interfaceSprites, 0, 332, 40, 102, 500, 180, 0);//T
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 631, 292, 0);//R
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 1)
	{
		al_draw_bitmap_region(interfaceSprites, 0, 332, 40, 102, 500, 180, 0);//T
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 550, 180, 0);//I
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 583, 292, 0);//E
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 631, 292, 0);//R
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 2)
	{
		al_draw_bitmap_region(interfaceSprites, 0, 332, 40, 102, 500, 180, 0);//T
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 550, 180, 0);//I
		al_draw_bitmap_region(interfaceSprites, 56, 332, 38, 102, 572, 180, 0);//M
		al_draw_bitmap_region(interfaceSprites, 179, 332, 38, 102, 538, 292, 0);//V
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 583, 292, 0);//E
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 631, 292, 0);//R
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 3)
	{
		al_draw_bitmap_region(interfaceSprites, 0, 332, 40, 102, 500, 180, 0);//T
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 550, 180, 0);//I
		al_draw_bitmap_region(interfaceSprites, 56, 332, 38, 102, 572, 180, 0);//M
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 620, 180, 0);//E

		al_draw_bitmap_region(interfaceSprites, 137, 332, 40, 102, 488, 292, 0);//O
		al_draw_bitmap_region(interfaceSprites, 179, 332, 38, 102, 538, 292, 0);//V
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 583, 292, 0);//E
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 631, 292, 0);//R
		if (clock() - textTimer > TBF + 1000) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 4) return true;
}
/**
*	função que vai processar e imprimir na tela o texto de Draw Game
*/
void  Interface::DrawGameTextBuild()
{


	if (frameT == 0)
	{
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 400, 250, 0);//D
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 734, 250, 0);//E
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return;
	}
	if (frameT == 1)
	{
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 400, 250, 0);//D
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 444, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 56, 332, 38, 102, 691, 250, 0);//M
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 734, 250, 0);//E
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return;
	}
	if (frameT == 2)
	{
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 400, 250, 0);//D
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 444, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 488, 250, 0);//A
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 648, 250, 0);//A
		al_draw_bitmap_region(interfaceSprites, 56, 332, 38, 102, 691, 250, 0);//M
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 734, 250, 0);//E
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return;
	}
	if (frameT == 3)
	{
		al_draw_bitmap_region(interfaceSprites, 342, 332, 39, 102, 400, 250, 0);//D
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 444, 250, 0);//R
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 488, 250, 0);//A
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 532, 250, 0);//W
		al_draw_bitmap_region(interfaceSprites, 504, 332, 38, 102, 600, 250, 0);//G
		al_draw_bitmap_region(interfaceSprites, 383, 332, 39, 102, 648, 250, 0);//A
		al_draw_bitmap_region(interfaceSprites, 56, 332, 38, 102, 691, 250, 0);//M
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 734, 250, 0);//E
		//if (clock() - textTimer > TBF + 1000) { frameT = 0; textTimer = clock(); }
		return;
	}
}
/**
*	função que vai processar e imprimir na tela o texto de Winner
*/
bool Interface::WinnerTextBuild()
{
	if (frameT == 0)
	{
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 524, 250, 0);//I
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 541, 250, 0);//N
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 585, 250, 0);//N
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 629, 250, 0);//E
		al_draw_bitmap_region(interfaceSprites, 219, 332, 39, 102, 673, 250, 0);//R
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 1)
	{
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 524, 250, 0);//I
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 541, 250, 0);//N
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 585, 250, 0);//N
		al_draw_bitmap_region(interfaceSprites, 96, 332, 39, 102, 629, 250, 0);//E

		if(*p1roundWin) al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 50, 175, 0);//W

		else if(*p2roundWin)al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 935, 175, 0);//W

		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 2)
	{
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 524, 250, 0);//I
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 541, 250, 0);//N
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 585, 250, 0);//N

		if (*p1roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 50, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 79, 175, 0);//I
		}
		else if (*p2roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W
			al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 524, 250, 0);//I
		}

		
		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 3)
	{
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 524, 250, 0);//I
		al_draw_bitmap_region(interfaceSprites, 301, 332, 39, 102, 541, 250, 0);//N

		if (*p1roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 50, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 79, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 92, 175, 0);//N
		}
		else if (*p2roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 935, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 964, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 977, 175, 0);//N
		}
		

		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 4)
	{
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W
		al_draw_bitmap_region(interfaceSprites, 42, 332, 12, 102, 524, 250, 0);//I

		if (*p1roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 50, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 79, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 92, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 121, 175, 0);//N
		}
		else if (*p2roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 935, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 964, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 977, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 1006, 175, 0);//N
		}
		

		if (clock() - textTimer > TBF + 45) { frameT ++; textTimer = clock(); }
		return false;
	}
	if (frameT == 5)
	{
		al_draw_bitmap_region(interfaceSprites, 464, 332, 38, 102, 481, 250, 0);//W

		if (*p1roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 50, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 79, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 92, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 121, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 849, 135, 24, 58, 150, 175, 0);//E
		}
		else if (*p2roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 935, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 964, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 977, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 1006, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 849, 135, 24, 58, 1035, 175, 0);//E
		}
		

		if (clock() - textTimer > TBF + 45) { frameT++; textTimer = clock(); }
		return false;
	}
	if (frameT == 6)
	{
		if (*p1roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 50, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 79, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 92, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 121, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 849, 135, 24, 58, 150, 175, 0);//E
			al_draw_bitmap_region(interfaceSprites, 875, 135, 26, 58, 179, 175, 0);//R
		}
		else if (*p2roundWin)
		{
			al_draw_bitmap_region(interfaceSprites, 867, 75, 24, 58, 935, 175, 0);//W
			al_draw_bitmap_region(interfaceSprites, 893, 75, 8, 58, 964, 175, 0);//I
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 977, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 823, 135, 24, 58, 1006, 175, 0);//N
			al_draw_bitmap_region(interfaceSprites, 849, 135, 24, 58, 1035, 175, 0);//E
			al_draw_bitmap_region(interfaceSprites, 875, 135, 26, 58, 1064, 175, 0);//R
		}

		//if (clock() - textTimer > TBF + 1000) { frameT=0; textTimer = clock(); }
		return false;
	}
	if (frameT == 7) return true;

}
/**
*	função que vai processar e imprimir na tela o texto de Perfect
*/
void Interface::PerfectTextBuild()
{
	if (frameT == 0)
	{
		al_draw_bitmap_region(interfaceSprites, 0, 600, 26, 58, 555, 250, 0);//frame 0
		if (clock() - textTimer > TBF + 55) { frameT++; textTimer = clock(); }
		return;
	}
	if (frameT == 1)
	{
		al_draw_bitmap_region(interfaceSprites, 28, 600, 83, 58, 545, 250, 0);//frame 1
		if (clock() - textTimer > TBF + 55) { frameT++; textTimer = clock(); }
		return ;
	}
	if (frameT == 2)
	{
		al_draw_bitmap_region(interfaceSprites, 113, 600, 118, 58, 509, 250, 0);//frame 2
		if (clock() - textTimer > TBF + 55) { frameT++; textTimer = clock(); }
		return ;
	}
	if (frameT == 3)
	{
		al_draw_bitmap_region(interfaceSprites, 233, 600, 173, 58, 479, 250, 0);//frame 3
		if (clock() - textTimer > TBF + 55) { frameT++; textTimer = clock(); }
		return ;
	}
	if (frameT == 4)
	{
		al_draw_bitmap_region(interfaceSprites, 408, 600, 191, 58, 470, 250, 0);//frame 4
		//if (clock() - textTimer > TBF + 1000) { frameT=0; textTimer = clock(); }
		return ;
	}
	//if (frameT == 7) return true;
}

void Interface::BarAnimation(int player)
{
	if (frameBar == 0)
	{
		if(player == 1) 
			al_draw_bitmap_region(interfaceSprites, 0, 540, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 0

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 0, 540, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 0

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 1)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 225, 540, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 1

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 225, 540, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 1

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 2)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 450, 540, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 2

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 450, 540, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 2

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 3)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 675, 540, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 3

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 675, 540, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 3

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 4)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 0, 560, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 4

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 0, 560, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 4

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 5)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 225, 560, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 5

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 225, 560, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 5

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 6)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 450, 560, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 6

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 450, 560, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 6

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 7)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 675, 560, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 7

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 675, 560, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 7

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 8)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 0, 580, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 8

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 0, 580, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 8

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 9)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 225, 580, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 9

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 225, 580, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 9

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar++; animationBarTime = clock(); }
		return;
	}
	if (frameBar == 10)
	{
		if (player == 1)
			al_draw_bitmap_region(interfaceSprites, 450, 580, 223, 18, P1ESPECIALBAR_X, P1ESPECIALBAR_Y, 0);//frame 10

		else if (player == 2)
			al_draw_bitmap_region(interfaceSprites, 450, 580, 223, 18, P2ESPECIALBAR_X, P2ESPECIALBAR_Y, 0);//frame 10

		if (!*gamePause && clock() - animationBarTime > TBF + 55) { frameBar=0; animationBarTime = clock(); }
		return;
	}
}

void Interface::setRoundT( bool value )
{
	this->roundT = value;
}
bool Interface::getRoundT()
{
	return roundT;
}

//al_draw_rectangle(0, 0, 500, 50, al_map_rgb(255, 0, 0), 1);  //essa função cria um retangulo aberto

/*
frame de vida - 0, 0, 415, 55
frame de especial - 0, 57, 295, 72
frame de especial (pow) - 297, 57, 295, 72
frame de personagem- 632, 45, 172, 154

numero 0 (timer)
frame 0 - 0, 131, 33, 65
frame 1 - 35, 131, 33, 65 (red)
frame 2 - 70, 133, 31, 63
frame 3 - 103, 133, 31, 63 (red)
frame 4 - 136, 135, 29, 61
frame 5 - 167, 135, 29, 61 (red)
frame 6 - 198, 137, 27, 59
frame 7 - 227, 137, 27, 59 (red)

numero 1 (timer)
frame 0 - 256, 131, 15, 65
frame 1 - 273, 131, 15, 65 (red)
frame 2 - 290, 133, 13, 63
frame 3 - 305, 133, 13, 63 (red)
frame 4 - 320, 135, 11, 61
frame 5 - 333, 135, 11, 61 (red)
frame 6 - 346, 137, 9, 59
frame 7 - 357, 137, 9, 59 (red)

numero 2 (timer)
frame 0 - 368, 131, 34, 65
frame 1 - 404, 131, 34, 65 (red)
frame 2 - 440, 133, 32, 63
frame 3 - 474, 133, 32, 63 (red)
frame 4 - 508, 135, 30, 61
frame 5 - 540, 135, 30, 61 (red)
frame 6 - 572, 137, 28, 59
frame 7 - 602, 137, 28, 59 (red)

numero 3 (timer)
frame 0 - 0, 198, 33, 65
frame 1 - 35, 198, 33, 65 (red)
frame 2 - 70, 200, 31, 63
frame 3 - 103, 200, 31, 63 (red)
frame 4 - 136, 202, 29, 61
frame 5 - 167, 202, 29, 61 (red)
frame 6 - 198, 204, 27, 59
frame 7 - 227, 204, 27, 59 (red)

numero 4 (timer)
frame 0 - 291, 198, 33, 65
frame 1 - 256, 198, 33, 65 (red)
frame 2 - 359, 200, 31, 63
frame 3 - 326, 200, 31, 63 (red)
frame 4 - 423, 202, 29, 61
frame 5 - 392, 202, 29, 61 (red)
frame 6 - 483, 204, 27, 59
frame 7 - 454, 204, 27, 59 (red)

numero 5 (timer)
frame 0 - 548, 198, 34, 65
frame 1 - 512, 198, 34, 65 (red)
frame 2 - 618, 200, 32, 63
frame 3 - 584, 200, 32, 63 (red)
frame 4 - 684, 202, 30, 61
frame 5 - 652, 202, 30, 61 (red)
frame 6 - 746, 204, 28, 59
frame 7 - 716, 204, 28, 59 (red)

numero 6 (timer)
frame 0 - 36, 265, 34, 65
frame 1 - 0, 265, 64, 65 (red)
frame 2 - 106, 267, 32, 63
frame 3 - 72, 267, 32, 63 (red)
frame 4 - 172, 269, 30, 61
frame 5 - 140, 269, 30, 61 (red)
frame 6 - 234, 271, 28, 59
frame 7 - 204, 271, 28, 59 (red)

numero 7 (timer)
frame 0 - 299, 265, 33, 65
frame 1 - 264, 265, 33, 65 (red)
frame 2 - 367, 267, 31, 63
frame 3 - 334, 267, 31, 63 (red)
frame 4 - 431, 269, 29, 61
frame 5 - 400, 269, 29, 61 (red)
frame 6 - 491, 271, 27, 59
frame 7 - 462, 271, 27, 59 (red)

numero 8 (timer)
frame 0 - 555, 265, 33, 65
frame 1 - 520, 265, 33, 65 (red)
frame 2 - 623, 267, 31, 63
frame 3 - 590, 267, 31, 63 (red)
frame 4 - 687, 269, 29, 61
frame 5 - 656, 269, 29, 61 (red)
frame 6 - 746, 271, 26, 59
frame 7 - 718, 271, 26, 59 (red)

numero 9 (timer)
frame 0 - 841, 265, 34, 65
frame 1 - 877, 265, 34, 65 (red)
frame 2 - 773, 267, 32, 63
frame 3 - 807, 267, 32, 63 (red)
frame 4 - 835, 202, 30, 61
frame 5 - 867, 202, 30, 61 (red)
frame 6 - 775, 204, 28, 59
frame 7 - 805, 204, 28, 59 (red)

numeros do especial
0 - 428, 3, 24, 53
1 - 453, 3, 16, 53
2 - 470, 3, 24, 53
3 - 495, 3, 24, 53
4 - 520, 3, 24, 53
5 - 545, 3, 24, 53

Letra T - 0, 332, 40, 102
Letra I - 42, 332, 12, 102
Letra M - 56, 332, 38, 102
Letra E - 96, 332, 39, 102
Letra O - 137, 332, 40, 102
Letra V - 179, 332, 38, 102
Letra R - 219, 332, 39, 102
Letra U - 260, 332, 39, 102
Letra N - 301, 332, 39, 102
Letra D - 342, 332, 39, 102
Letra A - 383, 332, 39, 102
Letra Y - 424, 332, 38, 102
Letra W - 464, 332, 38, 102
Letra G - 504, 332, 38, 102
Letra P - 544, 332, 39, 102
Letra F - 585, 332, 39, 102
Letra C - 626, 332, 39, 102
Letra K - 667, 332, 39, 102
Ponto - 708, 422, 12, 12

Numeros dos rounds

numero 1
frame 0 - 0, 444, 30, 94
frame 1 - 32, 442, 33, 96
frame 2 - 67, 440, 35, 98
frame 3 - 104, 438, 37, 100
frame 4 - 143, 436, 39, 102

numero 2
frame 0 - 184, 444, 31, 94
frame 1 - 217, 442, 33, 96
frame 2 - 252, 440, 35, 98
frame 3 - 289, 438, 37, 100
frame 4 - 328, 436, 39, 102

numero 3
frame 0 - 369, 444, 31, 94
frame 1 - 402, 442, 33, 96
frame 2 - 437, 440, 35, 98
frame 3 - 473, 438, 37, 100
frame 4 - 513, 436, 39, 102

numero 4
frame 0 - 554, 444, 31, 94
frame 1 - 588, 442, 33, 96
frame 2 - 623, 440, 35, 98
frame 3 - 660, 438, 37, 100
frame 4 - 699, 436, 39, 102

numero 5
frame 0 - 740, 444, 31, 94
frame 1 - 773, 442, 33, 96
frame 2 - 808, 440, 35, 98
frame 3 - 740, 334, 37, 100
frame 4 - 779, 332, 39, 102

animação da barra 5
frame 0 - 0, 540, 223, 18
frame 1 - 225, 540, 223, 18
frame 2 - 450, 540, 223, 18
frame 3 - 675, 540, 223, 18
frame 4 - 0, 560, 223, 18
frame 5 - 225, 560, 223, 18
frame 6 - 450, 560, 223, 18
frame 7 - 675, 560, 223, 18
frame 8 - 0, 580, 223, 18
frame 9 - 225, 580, 223, 18
frame 10 - 450, 580, 223, 18

Maximum
M - 616, 13, 21, 20
A - 639, 13, 18, 20
X - 659, 13, 20, 20
I - 681, 13, 6, 20
U - 689, 13, 18, 20

perfect anim

frame 0 - 0, 600, 26, 58
frame 1 - 28, 600, 83, 58
frame 2 - 133, 600, 118, 58
frame 3 - 223, 600, 173, 58
frame 4 - 408, 600, 191, 58

terry bogard
player 1 - 723, 0, 188, 20
player 2 - 723, 22, 188, 20
*/