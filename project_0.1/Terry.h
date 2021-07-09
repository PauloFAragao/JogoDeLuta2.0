#pragma once
#include "includes.h"
#include "PlayerInput.h"

class Terry
{
public:
	//---construtor---
	Terry(PlayerInput* inputs, bool* gamePause, bool toRight, int x, int y, unsigned short int player, unsigned int* gameTime, bool* gameMatchOver);

	//---destrutor---
	~Terry();

	//---metodos publicos---
	void ProcessPlayer();
	void CheckColisions();
	void PrintPlayer();
	
	void ChangeSideCommand();

	void AdditionalInitializations(bool* opponentAttacking, float* opponentX, float* opponentY, int* opponentColision, int* opponentHurtBoxHead,int* opponentHurtBoxBoddy, int* opponentHurtBoxLegs, int* opponentHitBox);

	float GetX();
	float GetY();
	float* GetXPointer();
	float* GetYPointer();
	float GetSpeedY();
	float GetSpeedX();
	float* GetSpeedXPointer();
	unsigned short int* GetLifePoints();
	float* GetShild();
	unsigned short int* GetSpecialBar();
	unsigned short int* GetSpecialQuantity();
	unsigned int* GetPowTime();
	unsigned short int* GetFrame();
	unsigned short int* GetAction();
	bool* GetPow();
	bool GetToRight();
	bool* GetAttacking();
	bool* GetFreeMove();
	bool GetFlipCharacter();

	int* GetColision();
	int* GetHurtBoxHead();
	int* GetHurtBoxBoddy();
	int* GetHurtBoxLegs();
	int* GetHitBox();

private:

	//---variaveis privadas---

	//objeto da classe PlayerInput
	PlayerInput* inputs;

	//imagem
	ALLEGRO_BITMAP* basicSprites;	//sprite do personagem
	ALLEGRO_BITMAP* effects;		//sprite dos efeitos

	//ALLEGRO_BITMAP* specialAnim;

	//variaveis do personagem
	float x;									//posi��o em X do personagem
	float y;									//posi��o em Y do personagem
	float speedX;								//velocidade no eixo X do personagem
	float speedY;								//velocidade no eixo Y do personagem
	unsigned short int action;					//a��o que o personagem est� executando
	unsigned short int lifePoints;				//quantidade de pontos de vida do personagem
	float shild;								//quantidade de pontos de defesa do personagem
	unsigned short int specialBar;				//quantidade de barra de especial do personagem
	unsigned short int specialQuantity;			//quantidade de especiais do personagem
	unsigned int powTime;						//quanto tempo de pow
	bool pow;									//se o pow est� ativo
	unsigned short int player;					//numero do player
	unsigned short int stun;

	//boxes de colis�o [0]=x [1]=y / [0]=ponto inicial [1]=ponto final
	int colision[2][2];							//box de colis�o do personagem
	int hurtBoxHead[2][2];						//box de colis�o da cabe�a
	int hurtBoxBoddy[2][2];						//box de colis�o do tronco
	int hurtBoxLegs[2][2];						//box de colis�o das pernas
	int hitBox[2][2];							//box de colis�o do ataque

	int* opponentColision;						//box de colis�o do oponente
	int* opponentHurtBoxHead;					//box de colis�o da cabe�a do oponente
	int* opponentHurtBoxBoddy;					//box de colis�o do corpo do oponente
	int* opponentHurtBoxLegs;					//box de colis�o das pernas do oponente
	int* opponentHitBox;						//box de colis�o do ataque do oponente

	//variaveis do oponente
	float* opponentX;							//ponteiro para a variavel X do outro personagem
	float* opponentY;							//ponteiro para a variavel Y do outro personagem
	bool* opponentAttacking;					//ponteiro para a variavel attacking do outro personagem

	//variaveis de comportamento
	bool fastMove;								//variavel que sinaliza se o personagem pode se mover rapido (correr ou pular para tras)
	bool flipCharacter;							//variavel que sinaliza que o personagem deve mudar de lado
	bool toRight;								//define para que lado o personagem est� virado
	bool attacking;								//variavel que sinaliza se o personagem est� realisando algum ataque
	bool freeMove;								//variavei que permite o personagem andar livremente (usada pelo sistema de movimenta��o do cenario no fundo)
	unsigned int jumpDelay;						//variavel que recebe o momento que o comando de pulo foi gerado para diferenciar o pulo alto do pulo baixo
	unsigned int capturedTime;					//variavel que recebe o momento que um comando que precisa ser atrasado para sair � acionado
	unsigned short int lastAction;				//variavel que vai armazenar a ultima a��o realisada pelo personagem quando for necessario executar uma a��o que precisa ter sua execu��o atrasada

	//variaveis relacionadas a anima��o
	unsigned short int frame;					//frame da anima��o que est� sendo executada
	bool animPause;								//variavel que sinaliza que a anima��o tem que ser pausada
	
	unsigned int captureTime;					//variavel que vai receber o tempo para executar a anima��o com a fluencia correta
	bool startAnimation;						//variavel para verificar se a anima��o j� foi iniciada
	bool* gamePause;							//variavel que sinaliza se o jogo foi pausado
	unsigned int* gameTime;						//variavel que guarda o tempo de jogo
	bool* gameMatchOver;						//variavel que sinaliza que a partida acabou

	unsigned int shildTemp;						//variavel que guarda o momento que o escudo sofreu dano
	float shildMemory;							//variavel que guarda a quantidade de escudo que ainda tem no personagem para resetar o tempo necessario para recupera��o
	bool recoverShildCommand;					//variavel que inica o comando para o escudo ser recuperado
	bool recoverShild;							//variavel que indica que o escudo est� sendo recuperado

	//variaveis dos efeitos
	float effectX;								//posi��o em X do efeito
	float effectSpeedX;							//velocidade de movimento do efeito em X
	unsigned short int effectFrame;				//frame da anima��o do efeito ativo
	unsigned int captureTimeForEffect;			//variavel que vai receber o tempo para executar a anima��o do efeito com a fluencia correta
	bool powerWaveActive;						//variavel que sinaliza que o efeito do power wave est� ativo
	bool roundWaveActive;						//variavel que sinaliza que o efeito do round wave esta ativo
	bool powerGeyserActive;						//variavel que sinaliza que o efeito do Power Geyser est� ativo
	bool especialEffectActive;					//variavel que sinaliza que o efeito de brilho do especial est� ativo

	float especialEffectX;						//posi��o em X do efeito do brilho do especial
	float especialEffectY;						//posi��o em Y do efeito do brilho do especial
	unsigned short int especialEffectFrame;		//frame do brilho do especial
	unsigned int cte;							//variavel que vai receber o tempo para executar a anima��o do efeito de especial com a fluencia correta

	float hitEffectX;							//posi��o em X do efeito de hit
	float hitEffectY;							//posi��o em Y do efeito de hit
	unsigned short int hitEffectFrame;			//frame do efetio de hit
	unsigned int cth;							//variavel que vai receber o tempo para executar a anima��o do efeito com a fluencia correta

	//---metodos privados---
	void Move();								//procedimento que processa o movimento do personagem

	void ChangeAction(int value, bool reset);	//procedimento que processa a mudan�a de a��o do personagem

	void ProcessShild();						//procedimento que processa a recupera��o do escudo

	//processamentos dos bot�es de a��o
	void CheckWeakPunch();						//procedimento que verifica o soco fraco
	void CheckStrongPunch();					//procedimento que verifica o soco forte
	void CheckWeakKick();						//procedimento que verifica o chute fraco
	void CheckStrongKick();						//procedimento que verifica o chute forte
	void CheckSpecial();						//procedimento que verifica mais de um bot�o pressionado de uma vez

	bool CheckPowerWave();						//procedimento que verifica se o jogador usou a sequencia certa para soltar um Power Wave
	bool CheckRoundWave();						//procedimento que verifica se o jogador usou a sequencia certa para soltar um Round Wave
	bool CheckWeakCrackShoot();					//procedimento que verifica se o jogador usou a sequencia certa para soltar um Crack Shoot fraco
	bool CheckStrongCrackShoot();				//procedimento que verifica se o jogador usou a sequencia certa para soltar um Crack Shoot forte
	bool CheckWeakPowerDunk();					//procedimento que verifica se o jogador usou a sequencia certa para soltar um Power Dunk
	bool CheckStrongPowerDunk();				//procedimento que verifica se o jogador usou a sequencia certa para soltar um Power Dunk
	bool CheckWeakBurnigKnuckle();				//procedimento que verifica se o jogador usou a sequencia certa para soltar um Burnig Knuckle
	bool CheckStrongBurnigKnuckle();			//procedimento que verifica se o jogador usou a sequencia certa para soltar um Burnig Knuckle
	bool CheckWeakRisingTackle();				//procedimento que verifica se o jogador usou a sequencia certa para soltar um Rising Tackle
	bool CheckStrongRisingTackle();				//procedimento que verifica se o jogador usou a sequencia certa para soltar um Rising Tackle
	bool CheckPowerGeyser();					//procedimento que verifica se o jogador usou a sequencia certa para soltar um Power Geyser
	bool CheckBusterWolf();						//procedimento que verifica se o jogador usou a sequencia certa para soltar um Buster Wolf

	//verificadores - verificam se a a��o pode ser executada
	bool JumpCheck();
	bool CheckChangingTo10Action();
	bool CheckChangingTo20Action();
	bool CheckChangingTo30Action();
	bool CheckChangingTo40Action();
	bool CheckChangingTo50Action();
	bool CheckChangingTo60Action();
	bool CheckChangingTo70Action();
	bool CheckChangingTo80Action();
	bool CheckChangingTo90Action();
	bool CheckChangingTo100Action();
	bool CheckChangingTo110Action();
	bool CheckChangingTo120Action();
	bool CheckChangingTo123Action();
	bool CheckChangingTo130Action();
	bool CheckChangingTo140Action();
	bool CheckChangingTo150Action();
	bool CheckChangingTo160Action();
	bool CheckChangingTo170Action();
	//ataques basicos
	bool CheckChangingTo300Action();
	bool CheckChangingTo310Action();
	bool CheckChangingTo320Action();
	bool CheckChangingTo330Action();
	bool CheckChangingTo340Action();
	bool CheckChangingTo350Action();
	bool CheckChangingTo360Action();
	bool CheckChangingTo370Action();
	bool CheckChangingTo380Action();
	bool CheckChangingTo390Action();
	bool CheckChangingTo400Action();
	bool CheckChangingTo410Action();
	bool CheckChangingTo420Action();
	bool CheckChangingTo430Action();
	bool CheckChangingTo440Action();
	bool CheckChangingTo450Action();
	bool CheckChangingTo460Action();
	bool CheckChangingTo470Action();
	//ataques de comando
	bool CheckChangingTo600Action();
	bool CheckChangingTo610Action();
	bool CheckChangingTo620Action();
	bool CheckChangingTo630Action();
	bool CheckChangingTo640Action();
	bool CheckChangingTo650Action();
	bool CheckChangingTo660Action();
	bool CheckChangingTo670Action();
	bool CheckChangingTo680Action();
	bool CheckChangingTo690Action();
	bool CheckChangingTo700Action();
	bool CheckChangingTo710Action();

	//processamento das a��es
	void ProcessIdle();								//a��o 00 - anima��o 00
	void ProcessCrouchung();						//a��o 10 - anima��o 01
	void ProcessCrouchedIdle();						//a��o 11 - anima��o 02
	void ProcessRaiseCrouched();					//a��o 12 - anima��o 03
	void ProcessWalk();								//a��o 20 - anima��o 04
	void ProcessWalkBack();							//a��o 30 - anima��o 05
	void ProcessJumpCommand();						//a��o 40 - anima��o Ultima que foi exacutada (00)
	void ProcessFrontalDiagonalJumpCommand();		//a��o 60 - anima��o Ultima que foi executada (00, 04, 12)
	void ProcessBackDiagonalJumpCommand();			//a��o 80 - anima��o Ultima que foi executada (00, 05)
	void ProcessRising();							//a��o 41/51/61/81 - anima��o 06
	void ProcessEndOfClimp();						//a��o 42 - anima��o 07
	void ProcessFalling();							//a��o 43 - anima��o 08
	void ProcessFall();								//a��o 44 - anima��o 09
	void ProcessRising_SBDiagonalJump();			//a��o 71 - anima��o 10
	void ProcessRisong_SBDiagonalJump();			//a��o 91 - anima��o 11
	void ProcessRum();								//a��o 100 - anima��o 12
	void ProcessSlide();							//a��o 101 - anima��o 13
	void ProcessJumpBack();							//a��o 110 - anima��o 14
	void ProcessJumpBackFall();						//a��o 111 - anima��o 15
	void ProcessDefending();						//a��o 120 - anima��o 16
	void ProcessDefence();							//a��o 121 - anima��o 17
	void ProcessTakingDamage();						//a��o 122 - anima��o 18
	void ProcessDefendExit();						//a��o 123 - anima��o 19
	void ProcessCrouchedDefending();				//a��o 130 - anima��o 20
	void ProcessCrouchedDefence();					//a��o 131 - anima��o 21
	void ProcessCrouchedTakingDamage();				//a��o 132 - anima��o 22
	void ProcessCrouchedDefendExit();				//a��o 133 - anima��o 23
	void processFrontRollingCommand();				//a��o 140 - anima��o Ultima que foi exacutada (00, 20, 160, 310, 330)
	void ProcessFrontRolling();						//a��o 141 - anima��o 24
	void ProcessFrontRollingEnd();					//a��o 142 - anima��o 25
	void ProcessBackRollingCommand();				//a��o 150 - anima��o Ultima que foi exacutada (00, 30, 160, 310, 330)
	void ProcessBackRolling();						//a��o 151 - anima��o 26
	void ProcessBackRollingEnd();					//a��o 152 - anima��o 27
	void ProcessChangeSide();						//a��o 160 - anima��o 28
	void ProcessChangeSideCrouched();				//a��o 170 - anima��o 29

	void ProcessActivePow();						//a��o 180 - anima��o 73
	void ProcessRecover();							//a��o 190 - anima��o 74
	void ProcessTaunt();							//a��o 200 - anima��o 74
	void ProcessStuned();							//a��o 210 - anima��o 75

	//ataques basicos
	void ProcessWeakPunchPreparation();				//a��o 300 - anima��o Ultima que foi exacutada
	void ProcessWeakPunch();						//a��o 301 - anima��o 30
	void ProcessStrongPunchPreparation();			//a��o 310 - anima��o Ultima que foi exacutada
	void ProcessStrongPunch();						//a��o 311 - anima��o 31
	void ProcessWeakKickPreparation();				//a��o 320 - anima��o Ultima que foi exacutada
	void ProcessWeakKick();							//a��o 321 - anima��o 32
	void ProcessStrongKickPreparation();			//a��o 330 - anima��o Ultima que foi exacutada
	void ProcessStrongKickStart();					//a��o 331 - anima��o 33
	void ProcessStrongKick();						//a��o 332 - anima��o 34
	void ProcessStrongKickEnd();					//a��o 333 - anima��o 35
	void ProcessCrouchedWeakPunchPreparation();		//a��o 340 - anima��o Ultima que foi exacutada
	void ProcessCrouchedWeakPunch();				//a��o 341 - anima��o 36
	void ProcessCrouchedStrongPunchPreparation();	//a��o 350 - anima��o Ultima que foi exacutada
	void ProcessCrouchedStrongPunch();				//a��o 351 - anima��o 37
	void ProcessCrouchedWeakKickPreparation();		//a��o 360 - anima��o Ultima que foi exacutada
	void ProcessCrouchedWeakKick();					//a��o 361 - anima��o 38
	void ProcessCrouchedStrongKickPreparation();	//a��o 370 - anima��o Ultima que foi exacutada
	void ProcessCrouchedStrongKick();				//a��o 371 - anima��o 39
	void ProcessJumpingWeakPunch();					//a��o 380 - anima��o 40
	void ProcessJumpingStrongPunch();				//a��o 390 - anima��o 41
	void ProcessJumpingWeakKick();					//a��o 400 - anima��o 42
	void ProcessJumpingStrongKick();				//a��o 410 - anima��o 43
	void ProcessGluedStrongPunchPreparation();		//a��o 420 - anima��o Ultima que foi exacutada
	void ProcessGluedStrongPunch();					//a��o 421 - anima��o 44
	void ProcessGluedStrongKickPreparation();		//a��o 430 - anima��o Ultima que foi exacutada
	void ProcessGluedStrongKick();					//a��o 431 - anima��o 45
	void ProcessSpecialAttackStart();				//a��o 440 - anima��o 46
	void ProcessSpecialAttack();					//a��o 441 - anima��o 47
	void ProcessSpecialAttackEnd();					//a��o 442 - anima��o 48
	void ProcessJumpingSpecialAttack();				//a��o 450 - anima��o 49
	void ProcessWeakPunchForwardPreparation();		//a��o 460 - anima��o Ultima que foi exacutada
	void ProcessWeakPunchForward();					//a��o 461 - anima��o 50
	void ProcessRisingUpper();						//a��o 470 - anima��o 51
	//ataques de comando
	void ProcessPowerWave();						//a��o 600 - anima��o 52
	void ProcessRoundWave();						//a��o 610 - anima��o 53
	void ProcessWeakCrackShoot();					//a��o 620 - anima��o 54
	void ProcessWeakCrackShootJumping();			//a��o 621 - anima��o 55
	void ProcessStrongCrackShoot();					//a��o 630 - anima��o 56
	void ProcessStrongCrackShootJumping();			//a��o 631 - anima��o 57
	void ProcessWeakPowerDunkStart();				//a��o 640 - anima��o 58
	void ProcessWeakPowerDunkJumping();				//a��o 641 - anima��o 59
	void ProcessWeakPowerDunkFalling();				//a��o 642 - anima��o 60
	void ProcessStrongPowerDunkStart();				//a��o 650 - anima��o 61
	void ProcessStrongPowerDunkJumping();			//a��o 651 - anima��o 62
	void ProcessStrongPowerDunkFalling();			//a��o 652 - anima��o 63
	void ProcessWeakBurnigKnuckleStart();			//a��o 660 - anima��o 64
	void ProcessWeakBurnigKnuckle();				//a��o 661 - anima��o 65
	void ProcessStrongBurnigKnuckleStart();			//a��o 670 - anima��o 66
	void ProcessStrongBurnigKnuckle();				//a��o 671 - anima��o 67
	void ProcessWeakRisingTackleStart();			//a��o 680 - anima��o 68
	void ProcessWeakRisingTackle();					//a��o 681 - anima��o 69
	void ProcessWeakRisingTackleFall();				//a��o 682 - anima��o 70
	void ProcessStrongRisingTackleStart();			//a��o 690 - anima��o 71
	void ProcessStrongRisingTackle();				//a��o 691 - anima��o 72
	void ProcessStrongRisingTackleFall();			//a��o 692 - anima��o 73
	void ProcessPowerGeyser();						//a��o 700 - anima��o 74
	void ProcessBusterWolfStart();					//a��o 710 - anima��o 75
	void ProcessBusterWolf();						//a��o 711 - anima��o 76
	void ProcessBusterWolfEnd();					//a��o 712 - anima��o 77
	void ProcessBusterWolfFail();					//a��o 713 - anima��o 78

	//void ProcessRecover();

	//resumo para evitar reescrever o mesmo fragmento de codigo
	void ProcessJumpFragment();

	//anima��es
	void Idle();								//anima��o 0
	void Crouching();							//anima��o 1
	void CrouchedIdle();						//anima��o 2
	void RaiseCrouched();						//anima��o 3
	void Walk();								//anima��o 4
	void WalkBack();							//anima��o 5
	void Jump_Rising();							//anima��o 6
	void Jump_EndOfClimp();						//anima��o 7
	void Jump_Falling();						//anima��o 8
	void Jump_Fall();							//anima��o 9
	void FrontalDiagonalJump();					//anima��o 10
	void BackDiagonalJump();					//anima��o 11
	void Rum();									//anima��o 12
	void Slide();								//anima��o 13
	void JumpingBack();							//anima��o 14
	void JumpBackFall();						//anima��o 15
	void Defending();							//anima��o 16
	void Defence();								//anima��o 17
	void DTakingDamage();						//anima��o 18
	void DefenceExit();							//anima��o 19
	void CrouchedDefending();					//anima��o 20
	void CrouchedDefence();						//anima��o 21
	void CrouchedDTakingDamage();				//anima��o 22
	void CrouchedDefenceExit();					//anima��o 23
	void FrontRolling();						//anima��o 24
	void FrontRollingEnd();						//anima��o 25
	void BackRolling();							//anima��o 26
	void BackRollingEnd();						//anima��o 27
	void ChangeSide();							//anima��o 28
	void ChangeSideCrouched();					//anima��o 29

	void ActivePow();							//anima��o 73
	void Recover();								//anima��o 74
	void Taunt();								//anima��o 74
	void Stuned();								//anima��o 75
	
	//ataques basicos
	void WeakPunch();							//anima��o 30
	void StrongPunch();							//anima��o 31
	void WeakKick();							//anima��o 32
	void StrongKickStart();						//anima��o 33
	void StrongKick();							//anima��o 34
	void StrongKickEnd();						//anima��o 35
	void CrouchedWeakPunch();					//anima��o 36
	void CrouchedStrongPunch();					//anima��o 37
	void CrouchedWeakKick();					//anima��o 38
	void CrouchedStrongKick();					//anima��o 39
	void JumpingWeakPunch();					//anima��o 40
	void JumpingStrongPunch();					//anima��o 41
	void JumpingWeakKick();						//anima��o 42
	void JumpingStrongKick();					//anima��o 43
	void GluedStrongPunch();					//anima��o 44
	void GluedStrongKick();						//anima��o 45
	void SpecialAttackStart();					//anima��o 46
	void SpecialAttack();						//anima��o 47
	void SpecialAttackEnd();					//anima��o 48
	void JumpingSpecialAttack();				//anima��o 49
	void WeakPunchForward();					//anima��o 50
	void RisingUpper();							//anima��o 51
	//ataques de comando
	void PowerWave();							//anima��o 52
	void RoundWave();							//anima��o 53
	void CrackShoot();							//anima��o 54 - 56
	void CrackShootJumping();					//anima��o 55 - 57
	void PowerDunkStart();						//anima��o 58 - 61
	void PowerDunkJumping();					//anima��o 59 - 62
	void WeakPowerDunkFalling();				//anima��o 60
	void StrongPowerDunkFalling();				//anima��o 63
	void WeakBurnigKnuckleStart();				//anima��o 64
	void StrongBurnigKnuckleStart();			//anima��o 66
	void BurnigKnuckle();						//anima��o 65 - 67	
	void RisingTackleStart();					//anima��o 68 - 71
	void RisingTackle();						//anima��o 69 - 72
	void RisingTackleFall();					//anima��o 70 - 73
	void PowerGeyser();							//anima��o 74
	void BusterWolfStart();						//anima��o 75
	void BusterWolf();							//anima��o 76
	void BusterWolfEnd();						//anima��o 77
	void BusterWolfFail();						//anima��o 78
	//anima��es de pulo apos uma a��o de ataque
	void RisingAfterAtaque();					//anima��o 6
	void EndOfClimpAfterAtaque();				//anima��o 7
	void FallingAfterAtaque();					//anima��o 8
	void FallForRecover();						//anima��o 9

	//efeitos
	void PowerWaveEffect();						//efeito 01
	void RoundWaveEffect();						//efeito 02
	void PowerGeyserEffect();					//efeito 03

	void EspecialEffect();						//efeito de brilho do especial

	void HitEffect();							//efeito do hit

	//void CharacterSpecialAnim();				//efeito de fundo quando o personagem d� o especial

};

