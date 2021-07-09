#pragma once
#ifndef INCLUDES_H
#define INCLUDES_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include <iostream>

using namespace std;

//ativa ou desativa o modo debug colocando msgs na tela
#define DEBUGMODE true

//quantidade de quadro por segundo
#define FPS 60											//--- quantidade de frames por segundo

//largura da tela
#define WIDTH 1140										//--- tamanho da tela (largura)
//altura da tela
#define HEIGHT 630										//--- tamanho da tela (altura)

//macros de fisica
#define JUMPFORCE -18									//--- forca do pulo do personagem
#define SJUMPFORCE -20									//--- forca do pulo forte do personagem
#define FALLSPEED 5										//--- velocidade de queda do personagem
#define GRAVITY 0.7f									//--- força da gravidade

//posição do chão
#define FLOOR 340										//--- posição do chão - coordenada em Y 

//posição do fim da cena
#define X1POS -34										//--- final no cenario no canto esquerdo
#define X2POS 138										//--- coordenada em X de onde o personagem não pode passar para mover o cenario no fundo
#define X3POS 828										//--- coordenada em X de onde o personagem não pode passar para mover o cenario no fundo
#define X4POS 1000										//--- final do cenario do canto direito 

//tempo entre os frames da animação
#define TBF 85											//--- tempo padrão entre os frames das animações - padrão 85

#define DELAYTIME 80									//--- tempo de atraso antes de executar uma ação

#define BTP 150											//--- tempo (em ms) padrão maximo entre um botão e outro ser pressionado

#define MAS	9											//---tamanho do array de memoria dos botões pressionados

#define MATCHTIME 99001									//--- tempo de cada partida - 60001/99001

#define SHILDPOINTS 200									//--- quantidade inicias de pontos de escudo de todos os personagens
#define POWTOTALTIME 10001								//--- quantidade de tempo que o pow vai ficar ativo

#define P1X 195											//--- posição X inicial do player 1
#define P2X 779											//--- posição X inicial do player 2

//--------- interface positions ---------
#define LIFEBAR_W 401									//--- largura da barra de vida
#define LIFEBAR_H 19									//--- altura da barra de vida
#define SHILDBAR_W 164									//--- largura da barra de escudo
#define SHILDBAR_H 15									//--- altura da barra de escudo
#define ESPECIALBAR_W 223								//--- largura da barra de especial
#define ESPECIALBAR_H 18								//--- altura da barra de especial
#define POWBAR_W 136									//--- largura da barra de pow
#define POWBAR_H 10										//--- alura da barra de pow

#define TIMER1POS_X 532									//--- posição x do primeiro numero do timer
#define TIMER2POS_X 575									//--- posição x do segundo numero do timer
#define TIMERPOS_Y 42									//--- posição y do segundo numero do timer

#define SPECIALNUMBERP1_X 45							//--- posição x do numero que indica a quantidade de especiais do player 1
#define SPECIALNUMBERP2_X 1072							//--- posição x do numero que indica a quantidade de especiais do player 2
#define SPECIALNUMBER_Y 551								//--- posição y do numero que indica a quantidade de especiais

//player 1
#define PLAYER1FRAME_X 0								//--- posição x do frame do personagem 1
#define PLAYER1FRAME_Y 0								//--- posição y do frame do personagem 1
#define PLAYER1LIFEBAR_X 105							//--- posição x do frame da barra de vida do personagem 1
#define PLAYER1LIFEBAR_Y 48								//--- posição y do frame da barra de vida do personagem 1
#define PLAYER1SPECIALBAR_X 21							//--- posição x do frame da barra de especial do personagem 1
#define PLAYER1SPECIALBAR_Y 541							//--- posição y do frame da barra de especial do personagem 1

#define P1LIFEBAR_X 112									//--- posição x da barra de vida do personagem 1
#define P1LIFEBAR_Y 55									//--- posição y da barra de vida do personagem 1
#define P1SHILDBAR_X 331								//--- posição x da barra de escudo do personagem 1
#define P1SHILDBAR_Y 81									//--- posição y da barra de escudo do personagem 1
#define P1POWBAR_X 68									//--- posição x da barra de pow do personagem 1
#define P1POWBAR_Y 551									//--- posição y da barra de pow do personagem 1
#define P1ESPECIALBAR_X 85								//--- posição x da barra de especial do personagem 1
#define P1ESPECIALBAR_Y 568								//--- posição y da barra de especial do personagem 1

//player 2
#define PLAYER2FRAME_X 968								//--- posição x do frame do personagem 2
#define PLAYER2FRAME_Y 0								//--- posição y do frame do personagem 2
#define PLAYER2LIFEBAR_X 620							//--- posição x do frame da barra de vida do personagem 2
#define PLAYER2LIFEBAR_Y 48								//--- posição y do frame da barra de vida do personagem 2
#define PLAYER2SPECIALBAR_X 828 						//--- posição x do frame da barra de especial do personagem 2
#define PLAYER2SPECIALBAR_Y 541							//--- posição y do frame da barra de especial do personagem 2

#define P2LIFEBAR_X 627									//--- posição x da barra de vida do personagem 2
#define P2LIFEBAR_Y 55									//--- posição y da barra de vida do personagem 2
#define P2SHILDBAR_X 645								//--- posição x da barra de escudo do personagem 2
#define P2SHILDBAR_Y 81									//--- posição y da barra de escudo do personagem 2
#define P2POWBAR_X 940									//--- posição x da barra de pow do personagem 2
#define P2POWBAR_Y 551									//--- posição y da barra de pow do personagem 2
#define P2ESPECIALBAR_X 836								//--- posição x da barra de especial do personagem 2
#define P2ESPECIALBAR_Y 568								//--- posição y da barra de especial do personagem 2

//--------- Ficha do personagem Terry ---------
#define WALKSPEED 5										//--- velocidade da movimentação do personagem em X quando andando
#define RUNSPEED 10										//--- velocidade da movimentação do personagem em X quando correndo
#define TERRYLIFEPOINTS 1000							//--- Quantidade de pontos de vida do personagem


#endif//INCLUDES_H

/*




*/