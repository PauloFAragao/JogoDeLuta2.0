#pragma once
#include "includes.h"

class Scenario
{
public:

	//construtor
	Scenario(float* p1X, float* p2X, float* p1SpeedX, float* p2SpeedX, bool* p1FreeMove, bool* p2FreeMove);

	//destrutor
	~Scenario();

	//Metodos Publicas
	void PrintScenario(ALLEGRO_EVENT* ev);

	float GetX();

private:
	//Variaveis Privadas

	//variavel que vai carregar o sprite do scenario
	ALLEGRO_BITMAP* scenarioSprite;

	//ponteiros para as variaveis dos personagens
	float* p1X;
	float* p2X;
	float* p1SpeedX;
	float* p2SpeedX;
	bool* p1FreeMove;
	bool* p2FreeMove;

	float scenarioX;

	//Metodos Privados
	void MoveScenario();

};

