#pragma once
#include "includes.h"

class PlayerInput
{
public:
	//construtor
	PlayerInput();

	//destrutor
	~PlayerInput();

	//metodos puplicos------------------------------------------------------------------
	bool GetPlayerInputs(int playerNumber, int btNumber);
	int GetPlayerBtDownImputs(int playerNumber, int btNumber, int position);
	int GetPlayerBtUpImputs(int playerNumber, int btNumber, int position);

	void PlayerInputsMain(ALLEGRO_EVENT* ev);

private:

	//variaveis privadas------------------------------------------------------------------

	//player 1
	bool p1Buttons[8];
	int p1BtDownImputs[8][10];
	int p1BtUpImputs[8][10];

	//player 2
	bool p2Buttons[8];
	int p2BtDownImputs[8][10];
	int p2BtUpImputs[8][10];

	//metodos privados------------------------------------------------------------------
	void WriteBtDownImputs(int playerNumber, int btNumber);
	void WriteBtUpImputs(int playerNumber, int btNumber);

};
