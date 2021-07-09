#include "includes.h"
#include "Game.h"
#include "Interface.h"

/**
* Construtor da classe game
*/
Game::Game()
{
	StartGame();

	//inicializando variaveis
	endGame = false;
	
	if (DEBUGMODE)
	{
		gameStart = true;
		gamePause = false;
		uiAnimationStarted = true;
		uiAnimationFinished = true;
	}
	else 
	{
		gameStart = false;
		gamePause = true;
		uiAnimationStarted = false;
		uiAnimationFinished = false;
	}
	gameMatchOver = false;

	key_Space = false;

	p1roundWin = false;
	p2roundWin = false;

	gameTime = MATCHTIME;
	gameStartTime = 0;
	gamePauseTime = 0;

	lastFrame = 0;

	round = 1;

	frontPlayer = true;

	inputs = new PlayerInput();

	p1 = new Terry(inputs, &gamePause, true, P1X, FLOOR, 1 , &gameTime, &gameMatchOver);
	p2 = new Terry(inputs, &gamePause, false, P2X, FLOOR, 2, &gameTime, &gameMatchOver);

	p1->AdditionalInitializations(p2->GetAttacking(), p2->GetXPointer(), p2->GetYPointer(), p2->GetColision(), p2->GetHurtBoxHead(), p2->GetHurtBoxBoddy(), p2->GetHurtBoxLegs(), p2->GetHitBox());
	p2->AdditionalInitializations(p1->GetAttacking(), p1->GetXPointer(), p1->GetYPointer(), p1->GetColision(), p1->GetHurtBoxHead(), p1->GetHurtBoxBoddy(), p1->GetHurtBoxLegs(), p1->GetHitBox());

	scenario = new Scenario(p1->GetXPointer(), p2->GetXPointer(), p1->GetSpeedXPointer(), p2->GetSpeedXPointer(),p1->GetFreeMove(), p2->GetFreeMove());

	hud = new Interface(
						p1->GetLifePoints(), p2->GetLifePoints(),
						p1->GetShild(), p2->GetShild(),
						p1->GetSpecialBar(), p2->GetSpecialBar(),
						p1->GetSpecialQuantity(), p2->GetSpecialQuantity(),
						p1->GetPowTime(), p2->GetPowTime(),
						p1->GetPow(), p2->GetPow(), &gameTime, &gamePause, &round,
						&uiAnimationFinished, &uiAnimationStarted, &p1roundWin, &p2roundWin,
						&gameMatchOver
						);

}

/**
* Destrutor da classe game
*/
Game::~Game()
{
	al_destroy_event_queue(eventQueue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_font(fonte);

	delete inputs;
	delete p1;
	delete p2;
	delete scenario;
	delete hud;
}

/**
*	Procedimento onde todo do allegro é iniciado
*/
void Game::StartGame()
{
	//inicando allegro e verificando se houve sucesso
	if (!al_init())
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO INICIAR A ALLEGRO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//criando a janela e verificando se houve sucesso
	display = al_create_display(WIDTH, HEIGHT);
	if (!display)
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO CRIAR O DISPLAY!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//instalando o teclado
	if (!al_install_keyboard())
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO INSTALAR O KEYBOARD!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//inicializando addon de imagens
	if (!al_init_image_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO INICIAR O ADDON ALLEGRO_IMAGE!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//inicializando addon de fontes
	if (!al_init_font_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO INICIAR O ADDON ALLEGRO_FONT!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//inicializando addon de textos
	if (!al_init_ttf_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO INICIAR O ADDON ALLEGRO_TFF!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}
	//inicializando addon das primitivas
	if (!al_init_primitives_addon())
	{
		al_show_native_message_box(NULL, "AVISO", "ERRO!", "ERRO AO INICIAR O ADDON ALLEGRO_PRIMITIVES!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//inicando o timer
	timer = al_create_timer(1.0 / FPS);
	al_start_timer(timer);

	//criando a fila de eventos
	eventQueue = al_create_event_queue();

	//Registro de sources
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	//setando o titulo da janela
	al_set_window_title(display, "Fighting Game");

	//carregando a fonte
	fonte = al_load_font("arial.ttf", 14, NULL);

}

/**
*	Procedimento principal do jogo
*/
void Game::MainGame()
{

	while (!endGame)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(eventQueue, &ev);

		//fechar o jogo
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) endGame = true;

		//pause do jogo
		//if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE) gamePause = !gamePause;

		//função que manda os personagens trocarem de lado
		VerifySides();

		//controle do tempo e do pause do jogo
		GameTimeControl(&ev);

		//objeto que imprime o cenario
		scenario->PrintScenario(&ev);

		//objeto que controla os inputs dos jogadores
		inputs->PlayerInputsMain( &ev );

		//processando as ações dos personagens
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			p1->ProcessPlayer();
			p2->ProcessPlayer();
		}
		
		//imprimindo os personagens
		if (frontPlayer) //o player 1 vai ser impresso na frente
		{
			p2->PrintPlayer();//player 2
			p1->PrintPlayer();//player 1
		}
		else//o player 2 vai ser impresso na frente
		{
			p1->PrintPlayer();//player 1
			p2->PrintPlayer();//player 2
		}

		//objeto que imprime a interface
		hud->BuildInterface();

		//------------------Mensagens na tela---------------------
		if(DEBUGMODE)
		{

			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 415, NULL, "B0P 9:%d 8:%d ", inputs->GetPlayerBtDownImputs(1, 0, 9), inputs->GetPlayerBtDownImputs(1, 0, 8));
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 430, NULL, "B0S 9:%d 8:%d ", inputs->GetPlayerBtUpImputs(1, 0, 9), inputs->GetPlayerBtUpImputs(1, 0, 8));

			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 445, NULL, "B1P 9:%d 8:%d ", inputs->GetPlayerBtDownImputs(1, 1, 9), inputs->GetPlayerBtDownImputs(1, 1, 8));
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 460, NULL, "B1S 9:%d 8:%d ", inputs->GetPlayerBtUpImputs(1, 1, 9), inputs->GetPlayerBtUpImputs(1, 1, 8));

			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 475, NULL, "B2P 9:%d 8:%d", inputs->GetPlayerBtDownImputs(1, 2, 9), inputs->GetPlayerBtDownImputs(1, 2, 8));
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 490, NULL, "B2S 9:%d 8:%d", inputs->GetPlayerBtUpImputs(1, 2, 9), inputs->GetPlayerBtUpImputs(1, 2, 8));

			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 510, NULL, "BCP 9:%d ", inputs->GetPlayerBtDownImputs(1, 6, 9));
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 525, NULL, "BCS 9:%d ", inputs->GetPlayerBtUpImputs(1, 6, 9));

			//tempo de execução
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 450, 5, NULL, "Tempo de execucao: %d", clock());
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 450, 20, NULL, "Tempo de Jogo: %d", gameTime);

			//posição do cenario
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 450, 600, NULL, "scenarioX: %f ", scenario->GetX());

			//----------------- player 1 -----------------
			//frame da animação
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 155, NULL, "Frame da animacao: %d", *p1->GetFrame() );
			//ação executada pelo player 1
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 170, NULL, "action: %d", *p1->GetAction());
			//velocidade e posição em X
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 185, NULL, "SpeedX: %f x: %f", p1->GetSpeedX(), p1->GetX());
			//velocidade e posição em Y
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 5, 200, NULL, "SpeedY: %f y: %f", p1->GetSpeedY(), p1->GetY());

			//atacando
			if (*p1->GetAttacking()) al_draw_text(fonte, al_map_rgb(194, 244, 23), 5, 215, NULL, "esta Atacando");
			else al_draw_text(fonte, al_map_rgb(32, 252, 20), 5, 215, NULL, "Nao esta Atacando");

			//----------------- player 2 -----------------
			//frame da animação
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 900, 155, NULL, "Frame da animacao: %d", *p2->GetFrame());
			//ação executada pelo player 1
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 900, 170, NULL, "action: %d", *p2->GetAction());
			//velocidade e posição em X
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 900, 185, NULL, "SpeedX: %f x: %f", p2->GetSpeedX(), p2->GetX());
			//velocidade e posição em Y
			al_draw_textf(fonte, al_map_rgb(255, 0, 0), 900, 200, NULL, "SpeedY: %f y: %f", p2->GetSpeedY(), p2->GetY());

			//atacando
			if (*p2->GetAttacking()) al_draw_text(fonte, al_map_rgb(194, 244, 23), 900, 215, NULL, "esta Atacando");
			else al_draw_text(fonte, al_map_rgb(32, 252, 20), 900, 215, NULL, "Nao esta Atacando");

		}

		//pause do jogo
		if (gamePause && gameStart) al_draw_text(fonte, al_map_rgb(255, 0, 0), 500, 250, NULL, "Game Paused");
		if (!uiAnimationStarted)  al_draw_text(fonte, al_map_rgb(255, 0, 0), 420, 300, NULL, "Pressione o Espaco para Iniciar o Jogo");

		//contador de fps do jogo
		if (clock() - lastFrame != 0) al_draw_textf(fonte, al_map_rgb(255, 0, 0), 1, 1, NULL, "Fps: %d", 1000 / (clock() - lastFrame));

		al_flip_display();

		//cor de fundo
		al_clear_to_color(al_map_rgb(0, 0, 0));

		lastFrame = clock();

	}
}

/*
*	Procedimento que muda o lado dos jogadores
*/
void Game::VerifySides()
{
	//o personagem 1 está na esquerda e o personagem 2 está na direita
	if ( p1->GetX() < p2->GetX() )
	{
		//controle do p1
		if (!p1->GetToRight() && !p1->GetFlipCharacter()) //o personagem 1 está virado para a esquerda e não tem um comando interno para virar para a direita
			p1->ChangeSideCommand();

		//controle do p2
		if (p2->GetToRight() && !p2->GetFlipCharacter()) //o personagem 2 está virado para a direita e não tem um comando interno para virar para a esquerda
			p2->ChangeSideCommand();
	}
	//o personagem 1 está na direita e o personagem 2 está na esquerda
	else if (p2->GetX() < p1->GetX())
	{
		//controle do p1
		if (p1->GetToRight() && !p1->GetFlipCharacter())
			p1->ChangeSideCommand();

		//controle do p2
		if (!p2->GetToRight() && !p2->GetFlipCharacter())
			p2->ChangeSideCommand();
	}
	return;
}

/**
*	Procedimento que processa o pause e o timer do jogo
*/
void Game::GameTimeControl(ALLEGRO_EVENT* ev)
{
	//iniciar o jogo
	if ( !uiAnimationFinished && !gameStart && ev->keyboard.keycode == ALLEGRO_KEY_SPACE )
	{
		uiAnimationStarted = true;
		hud->setRoundT(true);
		key_Space = true;
	}

	//a animação da interface terminou o jogo pode começar
	if ( uiAnimationFinished && !gameStart)
	{
		gamePause = false;
 		gameStart = true;
		gameStartTime = clock();
		gamePauseTime = 0;
	}

	//pausar o jogo
	if (!key_Space && !gamePause  && gameStart && ev->keyboard.keycode == ALLEGRO_KEY_SPACE)
	{
		gamePauseTime = clock();
		gamePause = true;
		key_Space = true;
	}

	//sair do pause
	if (!key_Space && gamePause && ev->keyboard.keycode == ALLEGRO_KEY_SPACE)
	{
		gameStartTime += (clock() - gamePauseTime);
		gamePause = false;
		key_Space = true;
	}

	//tira o loop do espaço
	if (key_Space && ev->type == ALLEGRO_EVENT_KEY_UP && ev->keyboard.keycode == ALLEGRO_KEY_SPACE)
	{
		key_Space = false;
	}
	
	//timer
	if ( gameStart && !gamePause && (MATCHTIME - (clock() -(int) gameStartTime) ) > 0 )
		gameTime = (MATCHTIME - (clock() - gameStartTime));

	else if (!gamePause && gameStart)
		gameTime = 0;

	return;
}





/*
	
	enviar como informações adicionais para os objetos:
		ponteiro para Array de int colisionX [2][2]
		ponteiro para Array de int hitBox [2][2]
		ponteiro para Array de int hurtBoxHead [2][2]
		ponteiro para Array de int hurtBoxBoddy [2][2]
		ponteiro para Array de int hurtBoxLegs [2][2]

	MainGame() - processos dos 2 personagens
		
		verificar o frame e atualizar as hurtBoxes - preciso pensar direito onde isso vai entrar

		verificar ação e processar ela
			
			walk/(dash)/run - verificar colisão com o outro personagem

			(generico) ataque (nos frames ativos) - verificar colisão com as hurt boxes do oponente

	MainGame() - impressão dos 2 personagens


	-classe terry
		int colisionX [2][2]
		int hitBox [2][2]

		int hurtBoxHead [2][2]
		int hurtBoxBoddy [2][2]
		int hurtBoxLegs [2][2]

*/