#pragma once
#include "includes.h"

class Interface
{

public:
	//consturtor
	Interface(	unsigned short int* p1LifePoints,		unsigned short int* p2LifePoints,
				float* p1Shild,							float* p2Shild,
				unsigned short int* p1SpecialBar,		unsigned short  int* p2SpecialBar, 
				unsigned short int* p1SpecialQuantity,	unsigned short int* p2SpecialQuantity,
				unsigned int* p1PowTime,				unsigned int* p2PowTime,
				bool* p1Pow,							bool* p2Pow,
				unsigned int* gameTime, bool* gamePause, unsigned short int* round, 			
				bool* uiAnimationFinished, bool* uiAnimationStarted, bool* p1roundWin,
				bool* p2roundWin, bool* gameMatchOver);

	//destrutor
	~Interface();

	//fun��es publicas
	void BuildInterface();

	void setRoundT(bool value);
	bool getRoundT();

private:
	//variaveis privadas

	//imagem
	ALLEGRO_BITMAP* interfaceSprites;

	//ponteiro para variaveis dos personagens
	unsigned short int* p1LifePoints;				//quantidade de pontos de vida do personagem 1
	unsigned short int* p2LifePoints;				//quantidade de pontos de vida do personagem 2
	float* p1Shild;					//quantidade de pontos de defesa do personagem 1
	float* p2Shild;					//quantidade de pontos de defesa do personagem 2
	unsigned short int* p1SpecialBar;				//quantidade de barra de especial do personagem 1
	unsigned short int* p2SpecialBar;				//quantidade de barra de especial do personagem 2
	unsigned short int* p1SpecialQuantity;			//quantidade de especiais do personagem 1
	unsigned short int* p2SpecialQuantity;			//quantidade de especiais do personagem 2
	unsigned int* p1PowTime;						//quanto tempo de pow do personagem 1
	unsigned int* p2PowTime;						//quanto tempo de pow do personagem 2
	bool* p1Pow;									//se o pow est� ativo do personagem 1
	bool* p2Pow;

	//informa��es do jogo
	bool* gamePause;								//vairavel que indiga se o jogo foi pausado
	unsigned short int* round;						//ponteiro para o numero do round
	bool* gameMatchOver;								//indica que a partida acabou

	bool* p1roundWin;								//o vencedor da partida foi o player 1
	bool* p2roundWin;								//o vencedor da partida foi o player 2

	bool* uiAnimationStarted;						//ponteiro para a variavel que indica o inicio da anima��o
	bool* uiAnimationFinished;						//ponteiro para a variavel que indica que o timer pode come�ar a rodar

	//tempo do jogo
	unsigned int* gameTime;

	//anima��es
	unsigned int captureTime;						//variavel que vai receber o tempo para executar a anima��o com a fluencia correta
	unsigned short int frame;						//frame da anima��o do timer 
	unsigned int textTimer;							//variavel que vai receber o tempo para executar a anima��o do texto na tela
	unsigned short int frameT;						//frame da anima��o do texto
	unsigned int animationBarTime;					//variavel que vai receber o tempo para executar a anima��o da barra de pow
	unsigned short int frameBar;					//frame da anima��o da barra

	bool roundT;
	bool readyT;
	bool goT;
	bool koT;
	bool winnerT;
	bool timeOverT;
	bool drawGameT;
	bool perfectT;
	bool animacaoStart;

	//memoria
	unsigned short int p1LifePointsMemory;			//variavel para animar a barra vermelha
	unsigned short int p2LifePointsMemory;			//variavel para animar a barra vermelha

	//fun��es privadas

	void P1LifeBarBuild();							//fun��o que vai construir a barra de vida do player 1
	void P2LifeBarBuild();							//fun��o que vai construir a barra de vida do player 2

	void p1ShildBarBuild();							//fun��o que vai construir a barra de escudo do player 1
	void p2ShildBarBuild();							//fun��o que vai construir a barra de escudo do player 2

	void p1PowBarBuild();							//fun��o que vai construir a barra de pow do player 1
	void p2PowBarBuild();							//fun��o que vai construir a barra de pow do player 2

	void p1SpecialBarBuild();						//fun��o que vai construir a barra de especial do player 1
	void p2SpecialBarBuild();						//fun��o que vai construir a barra de especial do player 2

	void p1SpecialNumberBuild();					//fun��o que vai imprimir o numero de quantidade de especiais do player 1
	void p2SpecialNumberBuild();					//fun��o que vai imprimir o numero de quantidade de especiais do player 2

	void timerBuild();								//fun��o que vai processar o timer do jogo
	
	void FrameControl(bool value);
	void Number0Anim(bool value, int numberFrame);
	void Number1Anim(bool value, int numberFrame);
	void Number2Anim(bool value, int numberFrame);
	void Number3Anim(bool value, int numberFrame);
	void Number4Anim(bool value, int numberFrame);
	void Number5Anim(bool value, int numberFrame);
	void Number6Anim(bool value, int numberFrame);
	void Number7Anim(bool value, int numberFrame);
	void Number8Anim(bool value, int numberFrame);
	void Number9Anim(bool value, int numberFrame);

	bool RoundTextBuild();
	bool ReadyTextBuild();
	bool GOTextBuild();
	bool KOTextBuild();
	bool TimeOverTextBuild();
	void DrawGameTextBuild();
	bool WinnerTextBuild();
	void PerfectTextBuild();

	void BarAnimation(int player);
};

