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
	float x;									//posição em X do personagem
	float y;									//posição em Y do personagem
	float speedX;								//velocidade no eixo X do personagem
	float speedY;								//velocidade no eixo Y do personagem
	unsigned short int action;					//ação que o personagem está executando
	unsigned short int lifePoints;				//quantidade de pontos de vida do personagem
	float shild;								//quantidade de pontos de defesa do personagem
	unsigned short int specialBar;				//quantidade de barra de especial do personagem
	unsigned short int specialQuantity;			//quantidade de especiais do personagem
	unsigned int powTime;						//quanto tempo de pow
	bool pow;									//se o pow está ativo
	unsigned short int player;					//numero do player
	unsigned short int stun;

	//boxes de colisão [0]=x [1]=y / [0]=ponto inicial [1]=ponto final
	int colision[2][2];							//box de colisão do personagem
	int hurtBoxHead[2][2];						//box de colisão da cabeça
	int hurtBoxBoddy[2][2];						//box de colisão do tronco
	int hurtBoxLegs[2][2];						//box de colisão das pernas
	int hitBox[2][2];							//box de colisão do ataque

	int* opponentColision;						//box de colisão do oponente
	int* opponentHurtBoxHead;					//box de colisão da cabeça do oponente
	int* opponentHurtBoxBoddy;					//box de colisão do corpo do oponente
	int* opponentHurtBoxLegs;					//box de colisão das pernas do oponente
	int* opponentHitBox;						//box de colisão do ataque do oponente

	//variaveis do oponente
	float* opponentX;							//ponteiro para a variavel X do outro personagem
	float* opponentY;							//ponteiro para a variavel Y do outro personagem
	bool* opponentAttacking;					//ponteiro para a variavel attacking do outro personagem

	//variaveis de comportamento
	bool fastMove;								//variavel que sinaliza se o personagem pode se mover rapido (correr ou pular para tras)
	bool flipCharacter;							//variavel que sinaliza que o personagem deve mudar de lado
	bool toRight;								//define para que lado o personagem está virado
	bool attacking;								//variavel que sinaliza se o personagem está realisando algum ataque
	bool freeMove;								//variavei que permite o personagem andar livremente (usada pelo sistema de movimentação do cenario no fundo)
	unsigned int jumpDelay;						//variavel que recebe o momento que o comando de pulo foi gerado para diferenciar o pulo alto do pulo baixo
	unsigned int capturedTime;					//variavel que recebe o momento que um comando que precisa ser atrasado para sair é acionado
	unsigned short int lastAction;				//variavel que vai armazenar a ultima ação realisada pelo personagem quando for necessario executar uma ação que precisa ter sua execução atrasada

	//variaveis relacionadas a animação
	unsigned short int frame;					//frame da animação que está sendo executada
	bool animPause;								//variavel que sinaliza que a animação tem que ser pausada
	
	unsigned int captureTime;					//variavel que vai receber o tempo para executar a animação com a fluencia correta
	bool startAnimation;						//variavel para verificar se a animação já foi iniciada
	bool* gamePause;							//variavel que sinaliza se o jogo foi pausado
	unsigned int* gameTime;						//variavel que guarda o tempo de jogo
	bool* gameMatchOver;						//variavel que sinaliza que a partida acabou

	unsigned int shildTemp;						//variavel que guarda o momento que o escudo sofreu dano
	float shildMemory;							//variavel que guarda a quantidade de escudo que ainda tem no personagem para resetar o tempo necessario para recuperação
	bool recoverShildCommand;					//variavel que inica o comando para o escudo ser recuperado
	bool recoverShild;							//variavel que indica que o escudo está sendo recuperado

	//variaveis dos efeitos
	float effectX;								//posição em X do efeito
	float effectSpeedX;							//velocidade de movimento do efeito em X
	unsigned short int effectFrame;				//frame da animação do efeito ativo
	unsigned int captureTimeForEffect;			//variavel que vai receber o tempo para executar a animação do efeito com a fluencia correta
	bool powerWaveActive;						//variavel que sinaliza que o efeito do power wave está ativo
	bool roundWaveActive;						//variavel que sinaliza que o efeito do round wave esta ativo
	bool powerGeyserActive;						//variavel que sinaliza que o efeito do Power Geyser está ativo
	bool especialEffectActive;					//variavel que sinaliza que o efeito de brilho do especial está ativo

	float especialEffectX;						//posição em X do efeito do brilho do especial
	float especialEffectY;						//posição em Y do efeito do brilho do especial
	unsigned short int especialEffectFrame;		//frame do brilho do especial
	unsigned int cte;							//variavel que vai receber o tempo para executar a animação do efeito de especial com a fluencia correta

	float hitEffectX;							//posição em X do efeito de hit
	float hitEffectY;							//posição em Y do efeito de hit
	unsigned short int hitEffectFrame;			//frame do efetio de hit
	unsigned int cth;							//variavel que vai receber o tempo para executar a animação do efeito com a fluencia correta

	//---metodos privados---
	void Move();								//procedimento que processa o movimento do personagem

	void ChangeAction(int value, bool reset);	//procedimento que processa a mudança de ação do personagem

	void ProcessShild();						//procedimento que processa a recuperação do escudo

	//processamentos dos botões de ação
	void CheckWeakPunch();						//procedimento que verifica o soco fraco
	void CheckStrongPunch();					//procedimento que verifica o soco forte
	void CheckWeakKick();						//procedimento que verifica o chute fraco
	void CheckStrongKick();						//procedimento que verifica o chute forte
	void CheckSpecial();						//procedimento que verifica mais de um botão pressionado de uma vez

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

	//verificadores - verificam se a ação pode ser executada
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

	//processamento das ações
	void ProcessIdle();								//ação 00 - animação 00
	void ProcessCrouchung();						//ação 10 - animação 01
	void ProcessCrouchedIdle();						//ação 11 - animação 02
	void ProcessRaiseCrouched();					//ação 12 - animação 03
	void ProcessWalk();								//ação 20 - animação 04
	void ProcessWalkBack();							//ação 30 - animação 05
	void ProcessJumpCommand();						//ação 40 - animação Ultima que foi exacutada (00)
	void ProcessFrontalDiagonalJumpCommand();		//ação 60 - animação Ultima que foi executada (00, 04, 12)
	void ProcessBackDiagonalJumpCommand();			//ação 80 - animação Ultima que foi executada (00, 05)
	void ProcessRising();							//ação 41/51/61/81 - animação 06
	void ProcessEndOfClimp();						//ação 42 - animação 07
	void ProcessFalling();							//ação 43 - animação 08
	void ProcessFall();								//ação 44 - animação 09
	void ProcessRising_SBDiagonalJump();			//ação 71 - animação 10
	void ProcessRisong_SBDiagonalJump();			//ação 91 - animação 11
	void ProcessRum();								//ação 100 - animação 12
	void ProcessSlide();							//ação 101 - animação 13
	void ProcessJumpBack();							//ação 110 - animação 14
	void ProcessJumpBackFall();						//ação 111 - animação 15
	void ProcessDefending();						//ação 120 - animação 16
	void ProcessDefence();							//ação 121 - animação 17
	void ProcessTakingDamage();						//ação 122 - animação 18
	void ProcessDefendExit();						//ação 123 - animação 19
	void ProcessCrouchedDefending();				//ação 130 - animação 20
	void ProcessCrouchedDefence();					//ação 131 - animação 21
	void ProcessCrouchedTakingDamage();				//ação 132 - animação 22
	void ProcessCrouchedDefendExit();				//ação 133 - animação 23
	void processFrontRollingCommand();				//ação 140 - animação Ultima que foi exacutada (00, 20, 160, 310, 330)
	void ProcessFrontRolling();						//ação 141 - animação 24
	void ProcessFrontRollingEnd();					//ação 142 - animação 25
	void ProcessBackRollingCommand();				//ação 150 - animação Ultima que foi exacutada (00, 30, 160, 310, 330)
	void ProcessBackRolling();						//ação 151 - animação 26
	void ProcessBackRollingEnd();					//ação 152 - animação 27
	void ProcessChangeSide();						//ação 160 - animação 28
	void ProcessChangeSideCrouched();				//ação 170 - animação 29

	void ProcessActivePow();						//ação 180 - animação 73
	void ProcessRecover();							//ação 190 - animação 74
	void ProcessTaunt();							//ação 200 - animação 74
	void ProcessStuned();							//ação 210 - animação 75

	//ataques basicos
	void ProcessWeakPunchPreparation();				//ação 300 - animação Ultima que foi exacutada
	void ProcessWeakPunch();						//ação 301 - animação 30
	void ProcessStrongPunchPreparation();			//ação 310 - animação Ultima que foi exacutada
	void ProcessStrongPunch();						//ação 311 - animação 31
	void ProcessWeakKickPreparation();				//ação 320 - animação Ultima que foi exacutada
	void ProcessWeakKick();							//ação 321 - animação 32
	void ProcessStrongKickPreparation();			//ação 330 - animação Ultima que foi exacutada
	void ProcessStrongKickStart();					//ação 331 - animação 33
	void ProcessStrongKick();						//ação 332 - animação 34
	void ProcessStrongKickEnd();					//ação 333 - animação 35
	void ProcessCrouchedWeakPunchPreparation();		//ação 340 - animação Ultima que foi exacutada
	void ProcessCrouchedWeakPunch();				//ação 341 - animação 36
	void ProcessCrouchedStrongPunchPreparation();	//ação 350 - animação Ultima que foi exacutada
	void ProcessCrouchedStrongPunch();				//ação 351 - animação 37
	void ProcessCrouchedWeakKickPreparation();		//ação 360 - animação Ultima que foi exacutada
	void ProcessCrouchedWeakKick();					//ação 361 - animação 38
	void ProcessCrouchedStrongKickPreparation();	//ação 370 - animação Ultima que foi exacutada
	void ProcessCrouchedStrongKick();				//ação 371 - animação 39
	void ProcessJumpingWeakPunch();					//ação 380 - animação 40
	void ProcessJumpingStrongPunch();				//ação 390 - animação 41
	void ProcessJumpingWeakKick();					//ação 400 - animação 42
	void ProcessJumpingStrongKick();				//ação 410 - animação 43
	void ProcessGluedStrongPunchPreparation();		//ação 420 - animação Ultima que foi exacutada
	void ProcessGluedStrongPunch();					//ação 421 - animação 44
	void ProcessGluedStrongKickPreparation();		//ação 430 - animação Ultima que foi exacutada
	void ProcessGluedStrongKick();					//ação 431 - animação 45
	void ProcessSpecialAttackStart();				//ação 440 - animação 46
	void ProcessSpecialAttack();					//ação 441 - animação 47
	void ProcessSpecialAttackEnd();					//ação 442 - animação 48
	void ProcessJumpingSpecialAttack();				//ação 450 - animação 49
	void ProcessWeakPunchForwardPreparation();		//ação 460 - animação Ultima que foi exacutada
	void ProcessWeakPunchForward();					//ação 461 - animação 50
	void ProcessRisingUpper();						//ação 470 - animação 51
	//ataques de comando
	void ProcessPowerWave();						//ação 600 - animação 52
	void ProcessRoundWave();						//ação 610 - animação 53
	void ProcessWeakCrackShoot();					//ação 620 - animação 54
	void ProcessWeakCrackShootJumping();			//ação 621 - animação 55
	void ProcessStrongCrackShoot();					//ação 630 - animação 56
	void ProcessStrongCrackShootJumping();			//ação 631 - animação 57
	void ProcessWeakPowerDunkStart();				//ação 640 - animação 58
	void ProcessWeakPowerDunkJumping();				//ação 641 - animação 59
	void ProcessWeakPowerDunkFalling();				//ação 642 - animação 60
	void ProcessStrongPowerDunkStart();				//ação 650 - animação 61
	void ProcessStrongPowerDunkJumping();			//ação 651 - animação 62
	void ProcessStrongPowerDunkFalling();			//ação 652 - animação 63
	void ProcessWeakBurnigKnuckleStart();			//ação 660 - animação 64
	void ProcessWeakBurnigKnuckle();				//ação 661 - animação 65
	void ProcessStrongBurnigKnuckleStart();			//ação 670 - animação 66
	void ProcessStrongBurnigKnuckle();				//ação 671 - animação 67
	void ProcessWeakRisingTackleStart();			//ação 680 - animação 68
	void ProcessWeakRisingTackle();					//ação 681 - animação 69
	void ProcessWeakRisingTackleFall();				//ação 682 - animação 70
	void ProcessStrongRisingTackleStart();			//ação 690 - animação 71
	void ProcessStrongRisingTackle();				//ação 691 - animação 72
	void ProcessStrongRisingTackleFall();			//ação 692 - animação 73
	void ProcessPowerGeyser();						//ação 700 - animação 74
	void ProcessBusterWolfStart();					//ação 710 - animação 75
	void ProcessBusterWolf();						//ação 711 - animação 76
	void ProcessBusterWolfEnd();					//ação 712 - animação 77
	void ProcessBusterWolfFail();					//ação 713 - animação 78

	//void ProcessRecover();

	//resumo para evitar reescrever o mesmo fragmento de codigo
	void ProcessJumpFragment();

	//animações
	void Idle();								//animação 0
	void Crouching();							//animação 1
	void CrouchedIdle();						//animação 2
	void RaiseCrouched();						//animação 3
	void Walk();								//animação 4
	void WalkBack();							//animação 5
	void Jump_Rising();							//animação 6
	void Jump_EndOfClimp();						//animação 7
	void Jump_Falling();						//animação 8
	void Jump_Fall();							//animação 9
	void FrontalDiagonalJump();					//animação 10
	void BackDiagonalJump();					//animação 11
	void Rum();									//animação 12
	void Slide();								//animação 13
	void JumpingBack();							//animação 14
	void JumpBackFall();						//animação 15
	void Defending();							//animação 16
	void Defence();								//animação 17
	void DTakingDamage();						//animação 18
	void DefenceExit();							//animação 19
	void CrouchedDefending();					//animação 20
	void CrouchedDefence();						//animação 21
	void CrouchedDTakingDamage();				//animação 22
	void CrouchedDefenceExit();					//animação 23
	void FrontRolling();						//animação 24
	void FrontRollingEnd();						//animação 25
	void BackRolling();							//animação 26
	void BackRollingEnd();						//animação 27
	void ChangeSide();							//animação 28
	void ChangeSideCrouched();					//animação 29

	void ActivePow();							//animação 73
	void Recover();								//animação 74
	void Taunt();								//animação 74
	void Stuned();								//animação 75
	
	//ataques basicos
	void WeakPunch();							//animação 30
	void StrongPunch();							//animação 31
	void WeakKick();							//animação 32
	void StrongKickStart();						//animação 33
	void StrongKick();							//animação 34
	void StrongKickEnd();						//animação 35
	void CrouchedWeakPunch();					//animação 36
	void CrouchedStrongPunch();					//animação 37
	void CrouchedWeakKick();					//animação 38
	void CrouchedStrongKick();					//animação 39
	void JumpingWeakPunch();					//animação 40
	void JumpingStrongPunch();					//animação 41
	void JumpingWeakKick();						//animação 42
	void JumpingStrongKick();					//animação 43
	void GluedStrongPunch();					//animação 44
	void GluedStrongKick();						//animação 45
	void SpecialAttackStart();					//animação 46
	void SpecialAttack();						//animação 47
	void SpecialAttackEnd();					//animação 48
	void JumpingSpecialAttack();				//animação 49
	void WeakPunchForward();					//animação 50
	void RisingUpper();							//animação 51
	//ataques de comando
	void PowerWave();							//animação 52
	void RoundWave();							//animação 53
	void CrackShoot();							//animação 54 - 56
	void CrackShootJumping();					//animação 55 - 57
	void PowerDunkStart();						//animação 58 - 61
	void PowerDunkJumping();					//animação 59 - 62
	void WeakPowerDunkFalling();				//animação 60
	void StrongPowerDunkFalling();				//animação 63
	void WeakBurnigKnuckleStart();				//animação 64
	void StrongBurnigKnuckleStart();			//animação 66
	void BurnigKnuckle();						//animação 65 - 67	
	void RisingTackleStart();					//animação 68 - 71
	void RisingTackle();						//animação 69 - 72
	void RisingTackleFall();					//animação 70 - 73
	void PowerGeyser();							//animação 74
	void BusterWolfStart();						//animação 75
	void BusterWolf();							//animação 76
	void BusterWolfEnd();						//animação 77
	void BusterWolfFail();						//animação 78
	//animações de pulo apos uma ação de ataque
	void RisingAfterAtaque();					//animação 6
	void EndOfClimpAfterAtaque();				//animação 7
	void FallingAfterAtaque();					//animação 8
	void FallForRecover();						//animação 9

	//efeitos
	void PowerWaveEffect();						//efeito 01
	void RoundWaveEffect();						//efeito 02
	void PowerGeyserEffect();					//efeito 03

	void EspecialEffect();						//efeito de brilho do especial

	void HitEffect();							//efeito do hit

	//void CharacterSpecialAnim();				//efeito de fundo quando o personagem dá o especial

};

