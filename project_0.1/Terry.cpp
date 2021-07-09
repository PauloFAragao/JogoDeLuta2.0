#include "includes.h"
#include "Terry.h"

/**
* Construtor da classe
* Recebe como argumentos: 
*	PlayerInput* inputs - ponteiro para a classe que verifica os imputs do jogador
*	bool* gamePause - ponteiro para a variavel que indica se o jogo sofreu um pause
*	bool toRight - lado inicial que o personagem tem que estar virado
*	int x - posição inicial do personagem em X
*	int y - posição inicial do personagem em Y
*	unsigned short int player - numero do personagem
*	unsigned int* gameTime - ponteiro para o tempo da partida
*	bool* gameMatchOver - ponteiro para a variavel que controla se o jogo acabou
* 
* o construtor carrega os sprites do personagem;
* inicializa as variaveis;
* 
*/
Terry::Terry(PlayerInput* inputs, bool* gamePause, bool toRight, int x, int y, unsigned short int player, unsigned int* gameTime, bool* gameMatchOver)
{
	//carregando a imagens
	basicSprites = al_load_bitmap("sprites//TerrySprites.bmp");
	effects = al_load_bitmap("sprites//Effects.png");
	//specialAnim = al_load_bitmap("sprites//SpecialAnim.bmp");
	if (basicSprites == NULL || effects == NULL/*|| specialAnim == NULL*/)//verificando se a imagem foi carregada na memoria
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO CARREGAR ARQUIVOS DO PERSONAGEM", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//definindo a cor que deve ser ignorada
	al_convert_mask_to_alpha(basicSprites, al_map_rgb(255, 0, 255));
	//al_convert_mask_to_alpha(specialAnim, al_map_rgb(255, 0, 255));

	//inicializando variaveis

	this->inputs = inputs;
	this->player = player;
	this->x = x;
	this->y = y;
	this->toRight = toRight;
	this->gamePause = gamePause;
	this->gameTime = gameTime;
	this->gameMatchOver = gameMatchOver;

	speedX = 0;
	speedY = 0;
	action = 0;
	lifePoints = TERRYLIFEPOINTS;
	shild = SHILDPOINTS;
	specialBar = 0;
	specialQuantity = 5;
	powTime = 0;
	pow = false;
	stun = 0;
	frame = 0;
	animPause = false;
	captureTime = 0;
	startAnimation = true;
	fastMove = true;
	flipCharacter = false;
	attacking = false;
	freeMove = false;
	jumpDelay = 0;
	lastAction = 0;
	capturedTime = 0;
	shildTemp = 0;
	shildMemory = SHILDPOINTS;
	recoverShild = false;
	recoverShildCommand = false;
	
	effectX = 0;
	effectSpeedX = 0;
	effectFrame = 0;
	captureTimeForEffect = 0;
	powerWaveActive = false;
	roundWaveActive = false;
	powerGeyserActive = false;

	especialEffectX = 0;
	especialEffectY = 0;
	especialEffectActive = false;
	cte = 0;

	hitEffectX = 0;
	hitEffectY = 0;
	hitEffectFrame = 0;
	cth = 0;

	opponentX = 0;
	opponentY = 0;
	opponentAttacking = 0;

	especialEffectFrame = 0;

	colision[0][0] = 0;
	colision[0][1] = 0;
	colision[1][0] = 0;
	colision[1][1] = 0;

	hurtBoxHead[0][0] = 0;
	hurtBoxHead[0][1] = 0;
	hurtBoxHead[1][0] = 0;
	hurtBoxHead[1][1] = 0;

	hurtBoxBoddy[0][0] = 0;
	hurtBoxBoddy[0][1] = 0;
	hurtBoxBoddy[1][0] = 0;
	hurtBoxBoddy[1][1] = 0;

	hurtBoxLegs[0][0] = 0;
	hurtBoxLegs[0][1] = 0;
	hurtBoxLegs[1][0] = 0;
	hurtBoxLegs[1][1] = 0;

	hitBox[0][0] = 0;
	hitBox[0][1] = 0;
	hitBox[1][0] = 0;
	hitBox[1][1] = 0;
}

/**
* inicializações adinionais que não puderam ser colocadas no contrutor
*/
void Terry::AdditionalInitializations(bool* opponentAttacking, float* opponentX, float* opponentY, int* opponentColision, int* opponentHurtBoxHead, int* opponentHurtBoxBoddy, int* opponentHurtBoxLegs, int* opponentHitBox)
{
	this->opponentX = opponentX;
	this->opponentY = opponentY;
	this->opponentAttacking = opponentAttacking;

	this->opponentColision = opponentColision;
	this->opponentHurtBoxBoddy = opponentHurtBoxHead;
	this->opponentHurtBoxBoddy = opponentHurtBoxBoddy;
	this->opponentHurtBoxLegs = opponentHurtBoxLegs;
	this->opponentHitBox = opponentHitBox;
}

/**
* Destrutor da classe
* usa o comando de destruir bitmap na variavel basicSprites
*/
Terry::~Terry()
{
	al_destroy_bitmap(basicSprites);

}

/**
*	função que processa as ações do player
*/
void Terry::ProcessPlayer()
{	

	if (!*gamePause /*&& !*gameMatchOver*/)//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< aqui trava os inputs do jogador quando a partida acaba
	{//função que controla a recuperação do escudo
		if (shild != SHILDPOINTS) ProcessShild();

		//--------------------ataques------------------------------------------
		CheckSpecial();
		CheckWeakPunch();
		CheckStrongPunch();
		CheckWeakKick();
		CheckStrongKick();

		//processos das ações----------
		switch (action)
		{
		case 0://Idle-0
			ProcessIdle();
			break;

		case 10://Crouching-1
			ProcessCrouchung();
			break;

		case 11://Crouched Idle-2
			ProcessCrouchedIdle();
			break;

		case 12://Raise Crouched-3
			ProcessRaiseCrouched();
			break;

		case 20://Walk-4
			ProcessWalk();
			break;

		case 30://Walk Back-5
			ProcessWalkBack();
			break;

		case 40://Jump - Rising-6
			ProcessJumpCommand();
			break;

		case 60://Jump - 
			ProcessFrontalDiagonalJumpCommand();
			break;

		case 80://Jump - 
			ProcessBackDiagonalJumpCommand();
			break;

		case 41:
		case 45:
		case 51:
		case 61:
		case 81:
			ProcessRising();
			break;

		case 42://Jump - End Of Climp-7
		case 46:
			ProcessEndOfClimp();
			break;

		case 43://Jump - Falling-8
		case 47:
		case 48:
			ProcessFalling();
			break;

		case 44://Jump - Fall-9
		case 49:
			ProcessFall();
			break;

		case 71://Frontal Diagonal Jump-10
			ProcessRising_SBDiagonalJump();
			break;

		case 91://Back Diagonal Jump-11
			ProcessRisong_SBDiagonalJump();
			break;

		case 100://Run-12
			ProcessRum();
			break;

		case 101://Run - Slide-13
			ProcessSlide();
			break;

		case 110://Jumping Back-14
			ProcessJumpBack();
			break;

		case 111://Jumping Back - Fall-15
			ProcessJumpBackFall();
			break;

		case 120://Defending-16
			ProcessDefending();
			break;

		case 121://Defence-17
			ProcessDefence();
			break;

		case 122://Taking Damage-18
			ProcessTakingDamage();
			break;

		case 123://Defence Exit-19
			ProcessDefendExit();
			break;

		case 130://Crouched - Defending-20
			ProcessCrouchedDefending();
			break;

		case 131://Crouched - Defence-21
			ProcessCrouchedDefence();
			break;

		case 132://Crouched - Taking Damage-22
			ProcessCrouchedTakingDamage();
			break;

		case 133://Crouched - Defence Exit-23
			ProcessCrouchedDefendExit();
			break;

		case 140://Front Rolling - Command
			processFrontRollingCommand();
			break;

		case 141://Front Rolling-24
			ProcessFrontRolling();
			break;

		case 142://Front Rolling-25
			ProcessFrontRollingEnd();
			break;

		case 150://Back Rolling - Command
			ProcessBackRollingCommand();
			break;

		case 151://Back Rolling-26
			ProcessBackRolling();
			break;

		case 152://Back Rolling-27
			ProcessBackRollingEnd();
			break;

		case 160://Change Side-28
			ProcessChangeSide();
			break;

		case 170://Change Side Crouched-29
			ProcessChangeSideCrouched();
			break;

		case 180:
			ProcessActivePow();
			break;

		case 190:
			ProcessRecover();
			break;

		case 200:
			ProcessTaunt();
			break;

		case 210:
			ProcessStuned();
			break;

		case 300://Weak punch preparation
			ProcessWeakPunchPreparation();
			break;

		case 301://Weak punch-30
			ProcessWeakPunch();
			break;

		case 310://Strong punch preparation
			ProcessStrongPunchPreparation();
			break;

		case 311://Strong punch-31
			ProcessStrongPunch();
			break;

		case 320://Weak kick preparation
			ProcessWeakKickPreparation();
			break;

		case 321://Weak kick - 32
			ProcessWeakKick();
			break;

		case 330://Strong kick Preparation
			ProcessStrongKickPreparation();
			break;

		case 331://Strong kick Start - 33
			ProcessStrongKickStart();
			break;

		case 332://Strong kick - 34
			ProcessStrongKick();
			break;

		case 333://Strong kick End- 35
			ProcessStrongKickEnd();
			break;

		case 340://Crouched Weak Punch
			ProcessCrouchedWeakPunchPreparation();
			break;

		case 341://Crouched Weak Punch - 36
			ProcessCrouchedWeakPunch();
			break;

		case 350://Crouched Strong Punch
			ProcessCrouchedStrongPunchPreparation();
			break;

		case 351://Crouched Strong Punch - 36
			ProcessCrouchedStrongPunch();
			break;

		case 360://Crouched Weak Kick
			ProcessCrouchedWeakKickPreparation();
			break;

		case 361://Crouched Weak Kick - 36
			ProcessCrouchedWeakKick();
			break;

		case 370://Crouched Strong Kick
			ProcessCrouchedStrongKickPreparation();
			break;

		case 371://Crouched Strong Kick - 36
			ProcessCrouchedStrongKick();
			break;

		case 380://Jumping Weak Punch- 40
			ProcessJumpingWeakPunch();
			break;

		case 390://Jumping Strong Punch- 41
			ProcessJumpingStrongPunch();
			break;

		case 400://Jumping Weak kick- 42
			ProcessJumpingWeakKick();
			break;

		case 410://Jumping Strong kick - 43
			ProcessJumpingStrongKick();
			break;

		case 420://Gluted Strong punch preparation
			ProcessGluedStrongPunchPreparation();
			break;

		case 421://Gluted Strong punch - 44
			ProcessGluedStrongPunch();
			break;

		case 430://Gluted Strong kick preparation
			ProcessGluedStrongKickPreparation();
			break;

		case 431://Gluted Strong kick - 45
			ProcessGluedStrongKick();
			break;

		case 440://Special Attack Start - 46
			ProcessSpecialAttackStart();
			break;

		case 441://Special Attack - 47
			ProcessSpecialAttack();
			break;

		case 442://Special Attack End - 48
			ProcessSpecialAttackEnd();
			break;

		case 450://Jumping Special Attack - 49
			ProcessJumpingSpecialAttack();
			break;

		case 460://Weak punch forward preparation
			ProcessWeakPunchForwardPreparation();
			break;

		case 461://Weak punch forward-50
			ProcessWeakPunchForward();
			break;

		case 470://Rissing Upper - 51
			ProcessRisingUpper();
			break;

		case 600://Power Wave - 52
			ProcessPowerWave();
			break;

		case 610://Round Wave - 53
			ProcessRoundWave();
			break;

		case 620://Weak Crack Shoot - 54
			ProcessWeakCrackShoot();
			break;

		case 621://Weak Crack Shoot Jumping - 55
			ProcessWeakCrackShootJumping();
			break;

		case 630://Strong Crack Shoot - 56
			ProcessStrongCrackShoot();
			break;

		case 631://Strong Crack Shoot Jumping - 57
			ProcessStrongCrackShootJumping();
			break;


		case 640://Weak Power Dunk Start - 58
			ProcessWeakPowerDunkStart();
			break;
		case 641://Weak Power Weak Dunk Jumping - 59
			ProcessWeakPowerDunkJumping();
			break;
		case 642://Weak Power Weak Dunk Falling - 60
			ProcessWeakPowerDunkFalling();
			break;


		case 650://Strong Power Dunk Start - 58
			ProcessStrongPowerDunkStart();
			break;
		case 651://Strong Power Strong Dunk Jumping - 59 
			ProcessStrongPowerDunkJumping();
			break;
		case 652://Strong Power Strong Dunk Falling - 61
			ProcessStrongPowerDunkFalling();
			break;


		case 660://Weak Burnig Knuckle Start - 62
			ProcessWeakBurnigKnuckleStart();
			break;
		case 661://Weak Burnig Knuckle - 63
			ProcessWeakBurnigKnuckle();
			break;

		case 670://Strong Burnig Knuckle Start - 64
			ProcessStrongBurnigKnuckleStart();
			break;
		case 671://Strong Burnig Knuckle - 63
			ProcessStrongBurnigKnuckle();
			break;


		case 680://Weak Rising Tackle Start - 65
			ProcessWeakRisingTackleStart();
			break;
		case 681://Weak Rising Tackle - 66
			ProcessWeakRisingTackle();
			break;
		case 682://Weak Rising Tackle Fall - 67
			ProcessWeakRisingTackleFall();
			break;


		case 690://Strong Rising Tackle Start - 65
			ProcessStrongRisingTackleStart();
			break;
		case 691://Strong Rising Tackle - 66
			ProcessStrongRisingTackle();
			break;
		case 692://Strong Rising Tackle Fall - 67
			ProcessStrongRisingTackleFall();
			break;

		case 700://Power Geyser - 
			ProcessPowerGeyser();
			break;

		case 710://Buster Wolf Start - 
			ProcessBusterWolfStart();
			break;

		case 711://Buster Wolf - 
			ProcessBusterWolf();
			break;

		case 712://Buster Wolf End - 
			ProcessBusterWolfEnd();
			break;

		case 713://Buster Wolf Fail - 
			ProcessBusterWolfFail();
			break;

		default:

			return;
		}

		Move();//procedimendo que processa o movimendo do personagem

		if (flipCharacter)
		{
			if (CheckChangingTo160Action()) ChangeAction(160, true);
			if (CheckChangingTo170Action()) ChangeAction(170, true);
		}
	}
	return;
}

/**
*	função que processa as colisões e movimenta o player se necessario
*/
void Terry::CheckColisions()
{
	switch (action)
	{
	case 0://Idle-0
		break;

	case 10://Crouching-1
		break;

	case 11://Crouched Idle-2
		break;

	case 12://Raise Crouched-3
		break;

	case 20://Walk-4
		break;

	case 30://Walk Back-5
		break;

	case 40://Jump - Rising-6
		break;

	case 41:
		break;

	case 42://Jump - End Of Climp-7
		break;

	case 43://Jump - Falling-8
		break;

	case 44://Jump - Fall-9
		break;

	case 51:
		break;

	case 61:
		break;

	case 71://Frontal Diagonal Jump-10
		break;

	case 81:
		break;

	case 60://Jump - 
		break;

	case 80://Jump - 
		break;

	case 91://Back Diagonal Jump-11
		break;

	case 100://Run-12
		break;

	case 101://Run - Slide-13
		break;

	case 110://Jumping Back-14
		break;

	case 111://Jumping Back - Fall-15
		break;

	case 120://Defending-16
		break;

	case 121://Defence-17
		break;

	case 122://Taking Damage-18
		break;

	case 123://Defence Exit-19
		break;

	case 130://Crouched - Defending-20
		break;

	case 131://Crouched - Defence-21
		break;

	case 132://Crouched - Taking Damage-22
		break;

	case 133://Crouched - Defence Exit-23
		break;

	case 140://Front Rolling - Command
		break;

	case 141://Front Rolling-24
		break;

	case 142://Front Rolling-25
		break;

	case 150://Back Rolling - Command
		break;

	case 151://Back Rolling-26
		break;

	case 152://Back Rolling-27
		break;

	case 160://Change Side-28
		break;

	case 170://Change Side Crouched-29
		break;

	case 300://Weak punch preparation
		break;

	case 301://Weak punch-30
		break;

	case 310://Strong punch preparation
		break;

	case 311://Strong punch-31
		break;

	case 320://Weak kick preparation
		break;

	case 321://Weak kick - 32
		break;

	case 330://Strong kick Preparation
		break;

	case 331://Strong kick Start - 33
		break;

	case 332://Strong kick - 34
		break;

	case 333://Strong kick End- 35
		break;

	case 340://Crouched Weak Punch
		break;

	case 341://Crouched Weak Punch - 36
		break;

	case 350://Crouched Strong Punch
		break;

	case 351://Crouched Strong Punch - 36
		break;

	case 360://Crouched Weak Kick
		break;

	case 361://Crouched Weak Kick - 36
		break;

	case 370://Crouched Strong Kick
		break;

	case 371://Crouched Strong Kick - 36
		break;

	case 380://Jumping Weak Punch- 40
		break;

	case 390://Jumping Strong Punch- 41
		break;

	case 400://Jumping Weak kick- 42
		break;

	case 410://Jumping Strong kick - 43
		break;

	case 420://Gluted Strong punch preparation
		break;

	case 421://Gluted Strong punch - 44
		break;

	case 430://Gluted Strong kick preparation
		break;

	case 431://Gluted Strong kick - 45
		break;

	case 440://Special Attack Start - 46
		break;

	case 441://Special Attack - 47
		break;

	case 442://Special Attack End - 48
		break;

	case 450://Jumping Special Attack - 49
		break;

	case 460://Weak punch forward preparation
		break;

	case 461://Weak punch forward-50
		break;

	case 470://Rissing Upper - 51
		break;

	case 600://Power Wave - 52
		break;

	case 610://Round Wave - 53
		break;

	case 620://Weak Crack Shoot - 54
		break;

	case 621://Weak Crack Shoot Jumping - 55
		break;

	case 630://Strong Crack Shoot - 56
		break;

	case 631://Strong Crack Shoot Jumping - 57
		break;

	case 640://Weak Power Dunk Start - 58
		break;

	case 641://Weak Power Weak Dunk Jumping - 59
		break;

	case 642://Weak Power Weak Dunk Falling - 60
		break;

	case 650://Strong Power Dunk Start
		break;

	case 651://Strong Power Strong Dunk Jumping
		break;

	case 652://Strong Power Strong Dunk Falling
		break;

	case 660://Weak Burnig Knuckle Start
		break;

	case 661://Weak Burnig Knuckle
		break;

	case 670://Strong Burnig Knuckle Start
		break;

	case 671://Strong Burnig Knuckle
		break;

	case 680://Weak Rising Tackle Start
		break;

	case 681://Weak Rising Tackle
		break;

	case 682://Weak Rising Tackle Fall
		break;

	case 690://Strong Rising Tackle Start
		break;

	case 691://Strong Rising Tackle
		break;

	case 692://Strong Rising Tackle Fall
		break;

	default:
		return;

	}
	return;
}

/**
*	função que imprime o personagem na tela
*/
void Terry::PrintPlayer()
{

	//animações
	switch (action)
	{
	case 0://Idle-0
		Idle();
		break;

	case 10://Crouching-1
		Crouching();
		break;

	case 11://Crouched Idle-2
		CrouchedIdle();
		break;

	case 12://Raise Crouched-3
		RaiseCrouched();
		break;

	case 20://Walk-4
		Walk();
		break;

	case 30://Walk Back-5
		WalkBack();
		break;

	case 40://Jump Command
		if (lastAction == 0) Idle();
		break;

	case 60://Weak Frontal Diagonal Jump Command
		if (lastAction == 0) Idle();
		else if (lastAction == 20) Walk();
		else if (lastAction == 100) Rum();
		break;

	case 80://Weak Back Diagonal Jump Command
		if (lastAction == 0) Idle();
		else if (lastAction == 30) WalkBack();
		break;

	case 41://Jump - Rising
	case 45:
	case 51://Strong Jump - Rising
	case 61://Weak Frontal Diagonal Jump - Rising
	case 81://Weak Back Diagonal Jump - Rising
		Jump_Rising();
		break;

	case 42://Jump - End Of Climp-7
	case 46:
		Jump_EndOfClimp();
		break;

	case 43://Jump - Falling-8
	case 47:
	case 48:
		Jump_Falling();
		break;

	case 44://Jump - Fall-9
	case 49:
		Jump_Fall();
		break;

	case 71://Frontal Diagonal Jump-10
		FrontalDiagonalJump();
		break;

	case 91://Back Diagonal Jump-11
		BackDiagonalJump();
		break;

	case 100://Run-12
		Rum();
		break;

	case 101://Run - Slide-13
		Slide();
		break;

	case 110://Jumping Back-14
		JumpingBack();
		break;

	case 111://Jumping Back - Fall-15
		JumpBackFall();
		break;

	case 120://Defending-16
		Defending();
		break;

	case 121://Defence-17
		Defence();
		break;

	case 122://Taking Damage-18
		DTakingDamage();
		break;

	case 123://Defence Exit-19
		DefenceExit();
		break;

	case 130://Crouched - Defending-20
		CrouchedDefending();
		break;

	case 131://Crouched - Defence-21
		CrouchedDefence();
		break;

	case 132://Crouched - Taking Damage-22
		CrouchedDTakingDamage();
		break;

	case 133://Crouched - Defence Exit-23
		CrouchedDefenceExit();
		break;

	case 140://Front Rolling Command
		if (lastAction == 0) Idle();
		else if (lastAction == 20) Walk();
		else if (lastAction == 160) ChangeSide();
		//else if (lastAction == 310) ;//cancelar o soco - problema
		//else if (lastAction == 330) ;//cancelar o chute - problema
		break;

	case 141://Front Rolling-24
		FrontRolling();
		break;

	case 142://Front Rolling-25
		FrontRollingEnd();
		break;

	case 150://Back Rolling Command
		if (lastAction == 0) Idle();
		else if (lastAction == 30) WalkBack();
		else if (lastAction == 160) ChangeSide();
		//else if (lastAction == 310) ;//cancelar o soco - problema
		//else if (lastAction == 330) ;//cancelar o chute - problema
		break;

	case 151://Back Rolling-26
		BackRolling();
		break;

	case 152://Back Rolling-27
		BackRollingEnd();
		break;

	case 160://Change Side-28
		ChangeSide();
		break;

	case 170://Change Side Crouched-29
		ChangeSideCrouched();
		break;

	case 180:
		ActivePow();
		break;

	case 190:
	case 200:
		Recover();
		break;

	case 210:
		Stuned();
		break;

	case 300://Weak punch command
	case 310://Strong punch command
	case 320://Weak kick Start
	case 330://Strong kick Start
	case 420://Gluted Strong punch preparation
	case 430://Gluted Strong kick preparation
	case 460://Weak punch forward command

		if (lastAction == 0) Idle();
		else if (lastAction == 20) Walk();
		else if (lastAction == 30) WalkBack();
		else if (lastAction == 100) Rum();
		else if (lastAction == 160) ChangeSide();
		break;

	case 340://Crouched Weak Punch
	case 350://Crouched Strong Punch
	case 360://Crouched Weak Kick
	case 370://Crouched Strong Kick
		if (lastAction == 10) Crouching();
		else if (lastAction == 11) CrouchedIdle();
		else if (lastAction == 170) ChangeSideCrouched();
		break;

	case 301://Weak punch-30
		WeakPunch();
		break;

	case 311://Strong punch-31
		StrongPunch();
		break;

	case 321://Weak kick - 32
		WeakKick();
		break;

	case 331://Strong kick Start - 33
		StrongKickStart();
		break;

	case 332://Strong kick - 34
		StrongKick();
		break;

	case 333://Strong kick End - 35
		StrongKickEnd();
		break;

	case 341://Crouched Weak Punch - 36
		CrouchedWeakPunch();
		break;

	case 351://Crouched Strong Punch - 37
		CrouchedStrongPunch();
		break;

	case 361://Crouched Weak Kick - 38
		CrouchedWeakKick();
		break;

	case 371://Crouched Strong Kick - 39
		CrouchedStrongKick();
		break;

	case 380://Jumping Weak Punch - 40
		JumpingWeakPunch();
		break;

	case 390://Jumping Strong Punch - 41
		JumpingStrongPunch();
		break;

	case 400://Jumping Weak kick - 42
		JumpingWeakKick();
		break;

	case 410://Jumping Strong kick - 43
		JumpingStrongKick();
		break;

	case 421://Gluted Strong punch - 44
		GluedStrongPunch();
		break;

	case 431://Gluted Strong kick - 45
		GluedStrongKick();
		break;

	case 440://Special Attack Start - 46
		SpecialAttackStart();
		break;

	case 441://Special Attack - 47
		SpecialAttack();
		break;

	case 442://Special Attack End - 48
		SpecialAttackEnd();
		break;

	case 450://Jumping Special Attack - 49
		JumpingSpecialAttack();
		break;

	case 461://Strong punch - 50
		WeakPunchForward();
		break;

	case 470://Rissing Upper - 51
		RisingUpper();
		break;

	case 600://Power Wave - 52
		PowerWave();
		break;

	case 610://Round Wave - 53
		RoundWave();
		break;

	case 620://Weak Crack Shoot - 54
	case 630://Strong Crack Shoot - 56
		CrackShoot();
		break;

	case 621://Weak Crack Shoot Jumping - 55
	case 631://Strong Crack Shoot Jumping - 57
		CrackShootJumping();
		break;

	case 640://Weak Power Dunk Start - 58
	case 650://Strong Power Dunk Start - 58
		PowerDunkStart();
		break;

	case 641://Weak Power Dunk Jumping - 59
	case 651://Strong Power Dunk Jumping - 59
		PowerDunkJumping();
		break;

	case 642://Weak Power Dunk Falling - 60
		WeakPowerDunkFalling();
		break;

	case 652://Strong Power Dunk Falling - 61
		StrongPowerDunkFalling();
		break;

	case 660://Weak Burnig Knuckle Start - 62
		WeakBurnigKnuckleStart();
		break;

	case 670://Strong Burnig Knuckle Start - 64
		StrongBurnigKnuckleStart();
		break;

	case 661://Weak Burnig Knuckle - 63
	case 671://Strong Burnig Knuckle - 63
		BurnigKnuckle();
		break;

	case 680://Weak Rising Tackle Start - 65
	case 690://Strong Rising Tackle Start - 65
		RisingTackleStart();
		break;

	case 681://Weak Rising Tackle - 66
	case 691://Strong Rising Tackle - 66
		RisingTackle();
		break;

	case 682://Weak Rising Tackle Fall - 67
	case 692://Strong Rising Tackle Fall - 67
		RisingTackleFall();
		break;

	case 700://Power Geyser - 
		PowerGeyser();
		break;

	case 710://Buster Wolf Start - 
		BusterWolfStart();
		break;

	case 711://Buster Wolf - 
		BusterWolf();
		break;

	case 712://Buster Wolf End - 
		BusterWolfEnd();
		break;

	case 713://Buster Wolf Fail - 
		BusterWolfFail();
		break;

	default:
		return;

	}

	//if (effectActive)
	//{
		if (powerWaveActive)
			PowerWaveEffect();

		if (roundWaveActive)
			RoundWaveEffect();

		if (powerGeyserActive)
			PowerGeyserEffect();

		if(especialEffectActive)
			EspecialEffect();
	//}
}

/**
* função que processa o escudo do personagem, regenerando lentamente algum tempo depois do personagem ter sofrido dano no escudo
*/
void Terry::ProcessShild()
{
	//verifica se a quantidade de escudo está menor que a quantidade final e gera um comando para a recuperação do escudo
	if (shild < SHILDPOINTS && !recoverShildCommand && !recoverShild)
	{
		recoverShildCommand = true;
		shildTemp = *gameTime;
		shildMemory = shild;
	}

	//verifica que o tempo para recuperar já termeniou e manda começar a recuperar
	if (recoverShildCommand && !recoverShild && shildTemp - *gameTime > 1500)
	{
		recoverShildCommand = false;
		recoverShild = true;
	}

	//verifica se com um comando de recuperação ativo ou durante a recuperação o personagem sofreu dano no escudo
	if (shildMemory != shild)
	{

		if (recoverShildCommand && shildTemp - *gameTime > 1500)
		{
			shildTemp = *gameTime;
			shildMemory = shild;
		}
		else if (recoverShild)
		{
			recoverShild = false;
			recoverShildCommand = true;
			shildTemp = *gameTime;
			shildMemory = shild;
		}

	}

	//recupera a quantidade de escudo
	if (recoverShild)
	{
		shild += 0.3;
		shildMemory = shild;
		if (shild >= SHILDPOINTS)
		{
			recoverShild = false;
			shild = SHILDPOINTS;
			shildMemory = SHILDPOINTS;
		}
	}
}

/**
*	Procedimento resposavel por processar a movimentação do personagem nos dois eixos
*/
void Terry::Move( )
{
	//--------------------------------------processamento da movimentação na horizontal----------------------------------------
	
	//resetando a permição para o personagem usar os fastMoves (corrida e pulo para tras)

	if (!fastMove)
	{
		if ( (toRight && !inputs->GetPlayerInputs(player, 0)) || (!toRight && !inputs->GetPlayerInputs(player, 2)) ) fastMove = true;
	}

	//movimentação do personagem (verificando os limites do cenario)
	if (x + speedX > X4POS)
		x = X4POS;

	else if (x + speedX > X3POS && !freeMove)
		x = X3POS;

	else if (x + speedX < X2POS && !freeMove)
		x = X2POS;

	else if (x + speedX < X1POS)
		x = X1POS;

	else
		x += speedX;

	//-------------------------processamento da movimentação na vertical-----------------------------

	//ação da gravidade
	speedY += GRAVITY;

	if (y >= FLOOR && speedY > 0)//colisão com o chão
	{
		speedY = 0;
		y = FLOOR;
	}

	y += speedY;//movimenta o personagem
}


/**
*	Procedimento que muda as ações do player, faz alguns processos de verificação e salva a ação anterior
*	Recebe como argumentos:
*		int value - ação que deve ser mudada
*		bool reset - se deve resetar o frame da animação ou não
*/
void Terry::ChangeAction(int value, bool reset)
{
	if (reset)
	{
		captureTime = clock();

		frame = 0;
	}
	else 
		lastAction = action;

	//cout << "player: "<< player << " acao atual: " << action << " comando para mudar para acao: " << value <<endl;

	//se for cancelar a ação de mudar de lado muda de lado antes de trocar ação
	if (action == 160 && value != 0)
	{
		toRight = !toRight;
		flipCharacter = false;
	}
	if (action == 170 && value != 0)
	{
		toRight = !toRight;
		flipCharacter = false;
	}

	action = value;

	return;
}

//verificadores - verificam se a ação pode ser executada
bool Terry::JumpCheck()
{
	if (!flipCharacter && action != 80 && action != 60 && action != 40)
		return true;
	else return false;
}
bool Terry::CheckChangingTo10Action()
{
	if (!flipCharacter && (action == 0 || action == 12))
		return true;
	else return false;
}
bool Terry::CheckChangingTo20Action()
{
	if (!flipCharacter && (action == 0 || action == 30 || action == 101 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo30Action()
{
	if (!flipCharacter && (action == 0 || action == 20 || action == 100 || action == 101 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo40Action()
{
	if (!flipCharacter && (action == 0 || action == 12 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo50Action()
{
	if (!flipCharacter && (action == 0 || action == 12 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo60Action()
{
	if (!flipCharacter && (action == 0 || action == 20 || action == 100 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo70Action()
{
	if (!flipCharacter && (action == 0 || action == 20 || action == 100 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo80Action()
{
	if (!flipCharacter && (action == 0 || action == 30 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo90Action()
{
	if (!flipCharacter && (action == 0 || action == 30 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo100Action()
{
	if (!flipCharacter && (action == 0 || action == 20 || action == 101 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo110Action()
{
	if (!flipCharacter && (action == 0 || action == 30 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo120Action()//defensa de pé
{
	if (!flipCharacter && (action == 0 || action == 30 || action == 160))
		return true;
	else return false;
}
bool Terry::CheckChangingTo123Action()
{
	if (!flipCharacter && (action == 120 || action == 121))
		return true;
	else return false;
}
bool Terry::CheckChangingTo130Action()//defesa agachado
{
	if (!flipCharacter && (action == 10 || action == 11 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo140Action()
{
	if (action == 0 || action == 20 || action == 100 || action == 101 || action == 160 || action == 170 || action == 300 || action == 320 )
		return true;
	else return false;
}
bool Terry::CheckChangingTo150Action()
{
	if (action == 0 || action == 30 || action == 300 || action == 320 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo160Action()
{
	if (action == 0)
		return true;
	else return false;
}
bool Terry::CheckChangingTo170Action()
{
	if (action == 11)
		return true;
	else return false;
}
bool Terry::CheckChangingTo300Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160 )
		return true;
	else return false;
}
bool Terry::CheckChangingTo310Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160)
		return true;
	else return false;
}
bool Terry::CheckChangingTo320Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160)
		return true;
	else return false;
}
bool Terry::CheckChangingTo330Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160)
		return true;
	else return false;
}
bool Terry::CheckChangingTo340Action()
{
	if (action == 10 || action == 11  || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo350Action()
{
	if (action == 10 || action == 11 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo360Action()
{
	if (action == 10 || action == 11 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo370Action()
{
	if (action == 10 || action == 11 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo380Action()
{
	if (action == 40 || action == 41 || action == 42 || action == 43 || action == 51 || action == 60 || action == 61 || action == 71 || action == 80 || action == 81 || action == 91)
		return true;
	else return false;
}
bool Terry::CheckChangingTo390Action()
{
	if (action == 40 || action == 41 || action == 42 || action == 43 || action == 51 || action == 60 || action == 61 || action == 71 || action == 80 || action == 81 || action == 91)
		return true;
	else return false;
}
bool Terry::CheckChangingTo400Action()
{
	if (action == 40 || action == 41 || action == 42 || action == 43 || action == 51 || action == 60 || action == 61 || action == 71 || action == 80 || action == 81 || action == 91)
		return true;
	else return false;
}
bool Terry::CheckChangingTo410Action()
{
	if (action == 40 || action == 41 || action == 42 || action == 43 || action == 51 || action == 60 || action == 61 || action == 71 || action == 80 || action == 81 || action == 91)
		return true;
	else return false;
}
bool Terry::CheckChangingTo420Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160)
		return true;
	else return false;
}
bool Terry::CheckChangingTo430Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160)
		return true;
	else return false;
}
bool Terry::CheckChangingTo440Action()
{
	if (action == 0 || action == 20 || action == 30 || action == 100 || action == 160 || action == 310 || action == 330)
		return true;
	else return false;
}
bool Terry::CheckChangingTo450Action()
{
	if (action == 40 || action == 41 || action == 42 || action == 43 || action == 51 || action == 60 || action == 61 || action == 71 || action == 80 || action == 81 || action == 91)
		return true;
	else return false;
}
bool Terry::CheckChangingTo460Action()
{
	if (action == 0 || action == 20 || action == 100 || action == 160)
		return true;
	else return false;
}
bool Terry::CheckChangingTo470Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 160 || action == 170)
		return true;
	else return false;
}

bool Terry::CheckChangingTo600Action()
{
	if (!powerWaveActive && !roundWaveActive && !powerGeyserActive &&
		(action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo610Action()
{
	if (!powerWaveActive && !roundWaveActive && !powerGeyserActive &&
		(action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170))
		return true;
	else return false;
}
bool Terry::CheckChangingTo620Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo630Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo640Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo650Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo660Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo670Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo680Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo690Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo700Action()
{
	if (action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170)
		return true;
	else return false;
}
bool Terry::CheckChangingTo710Action()
{
	if (!powerWaveActive && !roundWaveActive && !powerGeyserActive &&
		(action == 0 || action == 10 || action == 11 || action == 12 || action == 20 || action == 30 || action == 111 || action == 160 || action == 170))
		return true;
	else return false;
}

/**
*	função responsavel por criar o comando para o personagem virar para o outro lado
*/
void Terry::ChangeSideCommand()
{
	this->flipCharacter = true;
	return;
}

//gets
float Terry::GetY()
{
	return this->y;
}
float Terry::GetX()
{
	return this->x;
}
float* Terry::GetXPointer()
{
	return &this->x;
}
float* Terry::GetYPointer()
{
	return &this->y;
}
float Terry::GetSpeedY()
{
	return this->speedY;
}
float Terry::GetSpeedX()
{
	return this->speedX;
}
float* Terry::GetSpeedXPointer()
{
	return &this->speedX;
}
unsigned short int* Terry::GetLifePoints()
{
	return &this->lifePoints;
}
float* Terry::GetShild()
{
	return &this->shild;
}
unsigned short int* Terry::GetSpecialBar()
{
	return &this->specialBar;
}
unsigned short int* Terry::GetSpecialQuantity()
{
	return &this->specialQuantity;
}
unsigned int* Terry::GetPowTime()
{
	return &this->powTime;
}
unsigned short int* Terry::GetFrame()
{
	return &this->frame;
}
unsigned short int* Terry::GetAction()
{
	return &this->action;
}
bool* Terry::GetPow()
{
	return &this->pow;
}
bool Terry::GetToRight()
{
	return this->toRight;
}
bool* Terry::GetAttacking()
{
	return &this->attacking;
}
bool* Terry::GetFreeMove()
{
	return &this->freeMove;
}
bool Terry::GetFlipCharacter()
{
	return this->flipCharacter;
}
int* Terry::GetColision()
{
	return &this->colision[0][0];
}
int* Terry::GetHurtBoxHead()
{
	return &this->hurtBoxHead[0][0];
}
int* Terry::GetHurtBoxBoddy()
{
	return &this->hurtBoxBoddy[0][0];
}
int* Terry::GetHurtBoxLegs()
{
	return &this->hurtBoxLegs[0][0];
}
int* Terry::GetHitBox()
{
	return &this->hitBox[0][0];
}