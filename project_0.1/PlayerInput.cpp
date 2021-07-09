#include "includes.h"
#include "PlayerInput.h"

/**
*	Construtor da classe PlayerInput
*/
PlayerInput::PlayerInput()
{
	for (short int a = 0; a < 8; a++)
	{
		p1Buttons[a] = false;
		p2Buttons[a] = false;
		for (short int b = 0; b < 10; b++)
		{
			p1BtDownImputs[a][b] = 0;
			p2BtDownImputs[a][b] = 0;
			p1BtUpImputs[a][b] = 0;
			p2BtUpImputs[a][b] = 0;
		}
	}
}

PlayerInput::~PlayerInput()
{

}

/**
*	Procedimento responsavel por escrever dentro do array o tempo em que o botão foi pressionado
*/
void PlayerInput::WriteBtDownImputs(int playerNumber, int btNumber)
{
	if (playerNumber == 1)//player 1
	{
		for (short int a = 0; a < 10; a++)
		{
			p1BtDownImputs[btNumber][a] = p1BtDownImputs[btNumber][a + 1];
		}
		p1BtDownImputs[btNumber][9] = clock();
	}
	else if (playerNumber == 2)//player 2
	{
		for (short int a = 0; a < 10; a++)
		{
			p2BtDownImputs[btNumber][a] = p2BtDownImputs[btNumber][a + 1];
		}
		p2BtDownImputs[btNumber][9] = clock();

	}
}

/**
*	Procedimento responsavel por escrever dentro do array o tempo em que o botão foi solto
*/
void PlayerInput::WriteBtUpImputs(int playerNumber, int btNumber)
{
	if (playerNumber == 1)//player 1
	{
		for (short int a = 0; a < 10; a++)
		{
			p1BtUpImputs[btNumber][a] = p1BtUpImputs[btNumber][a + 1];
		}
		p1BtUpImputs[btNumber][9] = clock();
	}
	else if (playerNumber == 2)//player 2
	{
		for (short int a = 0; a < 10; a++)
		{
			p2BtUpImputs[btNumber][a] = p2BtUpImputs[btNumber][a + 1];
		}
		p2BtUpImputs[btNumber][9] = clock();
	}
}

/**
*	Procedimento que retorna uma booleana para vericações de botões pressionados
*/
bool PlayerInput::GetPlayerInputs(int playerNumber, int btNumber)
{
	if (playerNumber == 1) return p1Buttons[btNumber];
	else if (playerNumber == 2) return p2Buttons[btNumber];
}
/**
*	procedimento que retorna o momento que um botão foi pressionado
*/
int PlayerInput::GetPlayerBtDownImputs(int playerNumber, int btNumber, int position)
{
	if (playerNumber == 1) return p1BtDownImputs[btNumber][position];
	else if (playerNumber == 2) return p2BtDownImputs[btNumber][position];
}
/**
*	procedimento que retorna o momento que um botão foi solto
*/
int PlayerInput::GetPlayerBtUpImputs(int playerNumber, int btNumber, int position)
{
	if (playerNumber == 1) return p1BtUpImputs[btNumber][position];
	else if (playerNumber == 2) return p2BtUpImputs[btNumber][position];
}

/**
*	Procedimento que captura os imputs dos jogadores
*/
void PlayerInput::PlayerInputsMain(ALLEGRO_EVENT* ev)
{
	if (ev->type == ALLEGRO_EVENT_KEY_DOWN)//botão pressionado
	{
		switch (ev->keyboard.keycode)
		{
			//p1 imputs
		case ALLEGRO_KEY_A:			//seta para esquerda do player 1
			p1Buttons[0] = true;
			WriteBtDownImputs(1, 0);
			break;
		case ALLEGRO_KEY_S:			//seta para baixo do player 1
			p1Buttons[1] = true;
			WriteBtDownImputs(1, 1);
			break;
		case ALLEGRO_KEY_D:			//seta para direita player 1
			p1Buttons[2] = true;
			WriteBtDownImputs(1, 2);
			break;
		case ALLEGRO_KEY_W:			//seta para cima player 1
			p1Buttons[3] = true;
			WriteBtDownImputs(1, 3);
			break;
		case ALLEGRO_KEY_U:			//soco fraco player 1
			p1Buttons[4] = true;
			WriteBtDownImputs(1, 4);
			break;
		case ALLEGRO_KEY_J:			//soco forte player 1
			p1Buttons[5] = true;
			WriteBtDownImputs(1, 5);
			break;
		case ALLEGRO_KEY_I:			//chute fraco player 1
			p1Buttons[6] = true;
			WriteBtDownImputs(1, 6);
			break;
		case ALLEGRO_KEY_K:			//chute forte player 1
			p1Buttons[7] = true;
			WriteBtDownImputs(1, 7);
			break;

			//p2 imputs
		case ALLEGRO_KEY_LEFT:		//seta para esquerda do player 2
			p2Buttons[0] = true;
			WriteBtDownImputs(2, 0);
			break;
		case ALLEGRO_KEY_DOWN:		//seta para baixo do player 2
			p2Buttons[1] = true;
			WriteBtDownImputs(2, 1);
			break;
		case ALLEGRO_KEY_RIGHT:		//seta para direita do player 2
			p2Buttons[2] = true;
			WriteBtDownImputs(2, 2);
			break;
		case ALLEGRO_KEY_UP:		//seta para cima do player 2
			p2Buttons[3] = true;
			WriteBtDownImputs(2, 3);
			break;
		case ALLEGRO_KEY_PAD_7:		//soco fraco do player 2
			p2Buttons[4] = true;
			WriteBtDownImputs(2, 4);
			break;
		case ALLEGRO_KEY_PAD_4:		//soco forte do player 2
			p2Buttons[5] = true;
			WriteBtDownImputs(2, 5);
			break;
		case ALLEGRO_KEY_PAD_8:		//chute fraco do player 2
			p2Buttons[6] = true;
			WriteBtDownImputs(2, 6);
			break;
		case ALLEGRO_KEY_PAD_5:		//chute forte do player 2
			p2Buttons[7] = true;
			WriteBtDownImputs(2, 7);
			break;
		}
	}

	if (ev->type == ALLEGRO_EVENT_KEY_UP)//botão solto
	{
		switch (ev->keyboard.keycode)
		{
			//p1 imputs
		case ALLEGRO_KEY_A:			//seta para esquerda do player 1
			p1Buttons[0] = false;
			WriteBtUpImputs(1, 0);
			break;
		case ALLEGRO_KEY_S:			//seta para baixo do player 1
			p1Buttons[1] = false;
			WriteBtUpImputs(1, 1);
			break;
		case ALLEGRO_KEY_D:			//seta para direita do player 1
			p1Buttons[2] = false;
			WriteBtUpImputs(1, 2);
			break;
		case ALLEGRO_KEY_W:			//seta para cima do player 1
			p1Buttons[3] = false;
			WriteBtUpImputs(1, 3);
			break;
		case ALLEGRO_KEY_U:			//soco fraco do player 1
			p1Buttons[4] = false;
			WriteBtUpImputs(1, 4);
			break;
		case ALLEGRO_KEY_J:			//soco forte do player 1
			p1Buttons[5] = false;
			WriteBtUpImputs(1, 5);
			break;
		case ALLEGRO_KEY_I:			//chute fraco do player 1
			p1Buttons[6] = false;
			WriteBtUpImputs(1, 6);
			break;
		case ALLEGRO_KEY_K:			//chute forte do player 1
			p1Buttons[7] = false;
			WriteBtUpImputs(1, 7);
			break;

			//p2 imputs
		case ALLEGRO_KEY_LEFT:		//seta para esquerda do player 2
			p2Buttons[0] = false;
			WriteBtUpImputs(2, 0);
			break;
		case ALLEGRO_KEY_DOWN:		//seta para baixo do player 2
			p2Buttons[1] = false;
			WriteBtUpImputs(2, 1);
			break;
		case ALLEGRO_KEY_RIGHT:		//seta para direita do player 2
			p2Buttons[2] = false;
			WriteBtUpImputs(2, 2);
			break;
		case ALLEGRO_KEY_UP:		//seta para cima do player 2
			p2Buttons[3] = false;
			WriteBtUpImputs(2, 3);
			break;
		case ALLEGRO_KEY_PAD_7:		//soco fraco do player 2
			p2Buttons[4] = false;
			WriteBtUpImputs(2, 4);
			break;
		case ALLEGRO_KEY_PAD_4:		//soco forte do player 2
			p2Buttons[5] = false;
			WriteBtUpImputs(2, 5);
			break;
		case ALLEGRO_KEY_PAD_8:		//chute fraco do player 2
			p2Buttons[6] = false;
			WriteBtUpImputs(2, 6);
			break;
		case ALLEGRO_KEY_PAD_5:		//chute forte do player 2
			p2Buttons[7] = false;
			WriteBtUpImputs(2, 7);
			break;

		}
	}

}
