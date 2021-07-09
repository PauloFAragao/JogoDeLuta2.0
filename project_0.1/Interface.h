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

	//funções publicas
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
	bool* p1Pow;									//se o pow está ativo do personagem 1
	bool* p2Pow;

	//informações do jogo
	bool* gamePause;								//vairavel que indiga se o jogo foi pausado
	unsigned short int* round;						//ponteiro para o numero do round
	bool* gameMatchOver;								//indica que a partida acabou

	bool* p1roundWin;								//o vencedor da partida foi o player 1
	bool* p2roundWin;								//o vencedor da partida foi o player 2

	bool* uiAnimationStarted;						//ponteiro para a variavel que indica o inicio da animação
	bool* uiAnimationFinished;						//ponteiro para a variavel que indica que o timer pode começar a rodar

	//tempo do jogo
	unsigned int* gameTime;

	//animações
	unsigned int captureTime;						//variavel que vai receber o tempo para executar a animação com a fluencia correta
	unsigned short int frame;						//frame da animação do timer 
	unsigned int textTimer;							//variavel que vai receber o tempo para executar a animação do texto na tela
	unsigned short int frameT;						//frame da animação do texto
	unsigned int animationBarTime;					//variavel que vai receber o tempo para executar a animação da barra de pow
	unsigned short int frameBar;					//frame da animação da barra

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

	//funções privadas

	void P1LifeBarBuild();							//função que vai construir a barra de vida do player 1
	void P2LifeBarBuild();							//função que vai construir a barra de vida do player 2

	void p1ShildBarBuild();							//função que vai construir a barra de escudo do player 1
	void p2ShildBarBuild();							//função que vai construir a barra de escudo do player 2

	void p1PowBarBuild();							//função que vai construir a barra de pow do player 1
	void p2PowBarBuild();							//função que vai construir a barra de pow do player 2

	void p1SpecialBarBuild();						//função que vai construir a barra de especial do player 1
	void p2SpecialBarBuild();						//função que vai construir a barra de especial do player 2

	void p1SpecialNumberBuild();					//função que vai imprimir o numero de quantidade de especiais do player 1
	void p2SpecialNumberBuild();					//função que vai imprimir o numero de quantidade de especiais do player 2

	void timerBuild();								//função que vai processar o timer do jogo
	
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

