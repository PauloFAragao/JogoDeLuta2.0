#pragma once

#include "includes.h"
#include "PlayerInput.h"
#include "Terry.h"
#include "Interface.h"
#include "Scenario.h"

class Game
{
public:
	//construtor
	Game();
	//destrutor
	~Game();

//metodos publicos
	void MainGame();

private:

//variaveis privadas
	//fila de eventos
	ALLEGRO_EVENT_QUEUE* eventQueue;
	//timer
	ALLEGRO_TIMER* timer;
	//display
	ALLEGRO_DISPLAY* display;
	//font
	ALLEGRO_FONT* fonte;

	//objeto dos peronagens
	Terry* p1;
	Terry* p2;

	//objeto da classe PlayerInput
	PlayerInput* inputs;

	//objeto do senario
	Scenario* scenario;

	//objeto da interface
	Interface* hud;

	bool endGame;									//Booleana que fecha o jogo saindo do loop principal
	bool gamePause;									//Booleana que indica que o jogo foi pausado
	bool gameStart;									//Booleana que indica que o jogo começou
	bool gameMatchOver;								//indica que a partida acabou

	bool uiAnimationStarted;						//booleana que indica que a animação da interface já iniciou
	bool uiAnimationFinished;						//booleana que indica que a animação da interface já acabou

	bool key_Space;									//Booleana ant loop

	unsigned int gameTime;							//Guarda o tempo do jogo
	unsigned int gameStartTime;						//Guarda o tempo em que o jogo começou
	unsigned int gamePauseTime;						//Guarda quanto tempo o jogo ficou pausado

	unsigned short int round;						//numero do round

	//variaveis que marcam a vitoria
	bool p1roundWin;
	bool p2roundWin;

	//contador de fps improvisado
	int lastFrame;

	//player que vai ser impresso na frente
	bool frontPlayer;

//metodos privados

	void StartGame();
	void VerifySides();
	void GameTimeControl(ALLEGRO_EVENT* ev);

};

