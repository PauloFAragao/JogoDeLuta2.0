#include "includes.h"
#include "Terry.h"

/**
* função que faz o tratamento da ação 00
** zera a velocidade do personagem em X
*/
void Terry::ProcessIdle()//ação 00 - animação 00
{
	if (speedX != 0) speedX = 0;

	//--------------------ação de se agachar-------------------------------
	if (inputs->GetPlayerInputs(player, 1) && CheckChangingTo10Action())
		ChangeAction(10, true);

	//--------------------movimentação-------Horizontal--------------------
	if (inputs->GetPlayerInputs(player, 2) && !inputs->GetPlayerInputs(player, 0) && !inputs->GetPlayerInputs(player, 1) && y >= FLOOR)
	{
		//se o direcional para direita foi pressionado 2x rapidamente e se o personagem pode se mover rapidamente
		if (inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) < 100 && fastMove )//processamento para o personagem correr      
		{
			//se o personagem está virado para a direita e se a ação de corrida pode ser executada
			if (toRight && CheckChangingTo100Action())//correndo
				ChangeAction(100, true);

			//se o personagem estiver virado para a esquerda e se a ação de pulo para tras pode ser executada
			else if (!toRight && CheckChangingTo110Action() && clock() - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP)//pulando para tras
			{
				fastMove = false;
				speedX = RUNSPEED + 2;
				speedY = -10;
				ChangeAction(110, true);
			}
		}

		//se o personagem está virado para a direita, e o botão para a esquerda não está pressionado e se a ação de andar pode ser executada
		else if (toRight && CheckChangingTo20Action())//andando
			ChangeAction(20, true);

		//se o oponente está atacando e se o personagem está virado para a esquerda
		else if (*opponentAttacking && !toRight)//ação de se defender
		{
			if (CheckChangingTo120Action()) ChangeAction(120, true);
		}

		//se o personagem está virado para a esquerda, se o direcional para a esquerda não está pressionado, se a ação de andar para tras pode ser executada e se o oponente não está atacando
		else if (!toRight && CheckChangingTo30Action() && !*opponentAttacking)//andando para tras
			ChangeAction(30, true);

	}
	else if (inputs->GetPlayerInputs(player, 0) && !inputs->GetPlayerInputs(player, 2) && !inputs->GetPlayerInputs(player, 1) && y >= FLOOR)
	{
		//se o direcional para esquerda foi pressionado 2x rapidamente e se o personagem pode se mover rapidamente
		if (inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) < 100 && fastMove)//processamento para o personagem correr
		{
			//se o personagem está virado para a esquerda e se a ação de corrida pode ser executada
			if (!toRight && CheckChangingTo100Action())//correndo
				ChangeAction(100, true);

			//se o personagem estiver virado para a direita e se a ação de pulo para tras pode ser executada
			else if (toRight && CheckChangingTo110Action() && clock() - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP)//pulando para tras
			{
				fastMove = false;
				speedX = -(RUNSPEED + 2);
				speedY = -10;
				ChangeAction(110, true);
			}
		}

		//se o personagem está virado para a esquerda, e o botão para a direita não está pressionado e se a ação de andar pode ser executada
		else if (!toRight && CheckChangingTo20Action())//andando
			ChangeAction(20, true);

		//se o oponente está atacando e se o personagem está virado para a direita
		else if (*opponentAttacking && toRight)//ação de se defender
		{
			if (CheckChangingTo120Action()) ChangeAction(120, true);

		}

		//se o personagem está virado para a direita, se o direcional para a direita não está pressionado, se a ação de andar para tras pode ser executada e se o oponente não está atacando
		else if (toRight && CheckChangingTo30Action() && !*opponentAttacking)//andando para tras
			ChangeAction(30, true);
	}

	//---------------------------Taunt---------------------------
	//implementar taunt aqui - ação 200

	//--------------------movimentação-------Vertical----------------------
	ProcessJumpFragment();

	return;
}

/**
* função que faz o tratamento da ação 10
*/
void Terry::ProcessCrouchung()//ação 10 - animação 01
{
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(11, true);
	}
}
/**
* função que faz o tratamento da ação 11
*/
void Terry::ProcessCrouchedIdle()//ação 11 - animação 02
{

	if ((*opponentAttacking && toRight && inputs->GetPlayerInputs(player, 0) && CheckChangingTo130Action()) ||
		(*opponentAttacking && !toRight && inputs->GetPlayerInputs(player, 2) && CheckChangingTo130Action()))
		ChangeAction(130, true);

	if (!inputs->GetPlayerInputs(player, 1))
		ChangeAction(12, true);

}
/**
* função que faz o tratamento da ação 12
*/
void Terry::ProcessRaiseCrouched()//ação 12 - animação 03
{
	if (inputs->GetPlayerInputs(player, 1) && CheckChangingTo10Action())
		ChangeAction(10, false);

	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
}

/**
* função que faz o tratamento da ação 20
** vericica para qual lado o personagem está virado e se o botão para frente (dependendo do lado) está pressionado
** então zera a velocidade do personagem e muda ação para 0 (idle)
*/
void Terry::ProcessWalk()//ação 20 - animação 04
{
	//--------------------movimentação-------Vertical--------------------
	ProcessJumpFragment();

	//velocidade
	if (toRight && inputs->GetPlayerInputs(player, 2)) speedX = WALKSPEED;
	else if (!toRight && inputs->GetPlayerInputs(player, 0)) speedX = -WALKSPEED;

	//se o personagem estiver virado para a direita e o direcional para a direita não estiver pressionado
	if (toRight && !inputs->GetPlayerInputs(player, 2) || inputs->GetPlayerInputs(player, 1))
	{
		speedX = 0;			//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a animação para idle
		return;
	}

	//se o personagem estiver virado para a esquerda e o direcional para a esquerda não estiver pressionado
	if (!toRight && !inputs->GetPlayerInputs(player, 0) || inputs->GetPlayerInputs(player, 1))
	{
		speedX = 0;			//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a animação para idle
		return;
	}

	return;
}

/**
* função que faz o tratamento da ação 30
** vericica para qual lado o personagem está virado e se o botão para tras (dependendo do lado) está pressionado
** então zera a velocidade do personagem e muda ação para 0 (idle)
*/
void Terry::ProcessWalkBack()//ação 30 - animação 05
{
	//--------------------movimentação-------Vertical--------------------
	ProcessJumpFragment();

	//velocidade
	if (toRight && inputs->GetPlayerInputs(player, 0)) speedX = -WALKSPEED;
	else if (!toRight && inputs->GetPlayerInputs(player, 2))speedX = WALKSPEED;

	//ação de se defender
	if (*opponentAttacking)
	{
		if (CheckChangingTo120Action()) ChangeAction(120, true);
	}

	//se o personagem estiver virado para a direita e o direcional para a esquerda não estiver pressionado
	if (!toRight && !inputs->GetPlayerInputs(player, 2) || inputs->GetPlayerInputs(player, 1) )
	{
		speedX = 0;				//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a animação para idle
		return;
	}

	//se o personagem estiver virado para a esquerda e o direcional para a direita não estiver pressionado
	if (toRight && !inputs->GetPlayerInputs(player, 0) || inputs->GetPlayerInputs(player, 1) )
	{
		speedX = 0;				//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a animação para idle
		return;
	}

	return;
}

/**
* função que faz o tratamento da ação 40
*/
void Terry::ProcessJumpCommand()//ação 40 - animação Ultima que foi exacutada (00)
{
	if (clock() - jumpDelay > 120)
	{
		if (inputs->GetPlayerBtDownImputs(player, 3, 9) - inputs->GetPlayerBtUpImputs(player, 3, 9) > 120 || (inputs->GetPlayerInputs(player, 3) && inputs->GetPlayerBtUpImputs(player, 3, 9) - jumpDelay < 0))//pulo forte 
		{
			ChangeAction(51, true);
			speedY = SJUMPFORCE;
		}
		else//pulo fraco
		{
			ChangeAction(41, true);
			speedY = JUMPFORCE;
		}
	}
}

/**
* função que faz o tratamento da ação 60
*/
void Terry::ProcessFrontalDiagonalJumpCommand()//ação 60 - animação Ultima que foi executada (00, 04, 12)
{
	if (clock() - jumpDelay > 120)
	{
		if (inputs->GetPlayerBtDownImputs(player, 3, 9) - inputs->GetPlayerBtUpImputs(player, 3, 9) > 120 || (inputs->GetPlayerInputs(player, 3) && inputs->GetPlayerBtUpImputs(player, 3, 9) - jumpDelay < 0))//pulo forte 
		{
			ChangeAction(71, true);

			speedY = SJUMPFORCE - 2;

			if (!toRight) speedX = -(WALKSPEED + 2);
			else speedX = WALKSPEED + 4;

		}
		else//pulo fraco
		{
			ChangeAction(61, true);

			speedY = JUMPFORCE;

			if (!toRight) speedX = -(WALKSPEED + 2);
			else speedX = WALKSPEED + 4;
		}
	}
}

/**
* função que faz o tratamento da ação 80
*/
void Terry::ProcessBackDiagonalJumpCommand()//ação 80 - animação Ultima que foi executada (00, 05)
{
	if (clock() - jumpDelay > 120)
	{
		if (inputs->GetPlayerBtDownImputs(player, 3, 9) - inputs->GetPlayerBtUpImputs(player, 3, 9) > 120 || (inputs->GetPlayerInputs(player, 3) && inputs->GetPlayerBtUpImputs(player, 3, 9) - jumpDelay < 0))//pulo forte 
		{
			ChangeAction(91, true);

			speedY = SJUMPFORCE - 2;

			if (!toRight) speedX = WALKSPEED + 2;
			else speedX = -(WALKSPEED + 4);

		}
		else//pulo fraco
		{
			ChangeAction(81, true);

			speedY = JUMPFORCE;

			if (!toRight) speedX = WALKSPEED + 2;
			else speedX = -(WALKSPEED + 4);
		}
	}
}


/**
* função que faz o tratamento da ação 41, 51, 61, 81
** verifica se a velocidade de subida está diminudindo (se a força de subida está acabando)
** então muda ação para 42 (endOfClimp)
*/
void Terry::ProcessRising()//ação 41 & ação 51 & ação 61 & ação 81 - animação 06
{
	if (action == 45 && speedY > -4) ChangeAction(46, true);
	else if (speedY > -4) ChangeAction(42, true);

	return;
}
/**
* função que faz o tratamento da ação 42
** verifica se a velocidade de decida está maior que 5 (o personagem está ganhando velocidade enquanto cai)
** então muda a ação para 43 (falling)
*/
void Terry::ProcessEndOfClimp()//ação 42 - animação 07
{
	if (action == 46 && speedY > 5) ChangeAction(47, true);
	else if (speedY > 5) ChangeAction(43, true);

	return;
}
/**
* função que faz o tratamento da ação 43
** verifica se o personagem chegou ao chão
** então muda a ação para 44 (fall)
*/
void Terry::ProcessFalling()//ação 43 - animação 08
{
	if (y >= FLOOR)
	{
		if(action == 48) ChangeAction(49, true);//queda que vai mudar para recover
		else ChangeAction(44, true);

		speedX = 0;			//zera a velocidade
		return;
	}

	return;
}
/**
* função que faz o tratamento da ação 44
** verifica se o frame 3 já foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 3 e o tempo atual é maior que o tempo padrão entre os frames -10)
** então muda a ação para 0 (idle)
*/
void Terry::ProcessFall()//ação 44 - animação 09
{
	//aqui a animação deve ser completamente executada e depois mudar para a animação idle
	if (frame == 3 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		if(action == 49) ChangeAction(190, true);//muda para recover
		else ChangeAction(0, true);	//muda a ação
		return;
	}
	return;
}

/**
* função que faz o tratamento da ação 71
** verifica se o frame 8 já foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 8 e o tempo atual é maior que o tempo padrão entre os frames -10)
** então muda a ação para 0 (idle)
*/
void Terry::ProcessRising_SBDiagonalJump()//ação 71 - animação 10
{
	//aqui a animação deve ser completamente executada e depois mudar para a animação idle
	if (y >= FLOOR || (frame == 8 && !*gamePause && clock() - captureTime > TBF + 10 && y >= FLOOR))
	{
		ChangeAction(0, true);	//muda a ação
		return;
	}
	return;

}

/**
* função que faz o tratamento da ação 91
** verifica se o frame 7 já foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 7 e o tempo atual é maior que o tempo padrão entre os frames -10)
** então muda a ação para 0 (idle)
*/
void Terry::ProcessRisong_SBDiagonalJump()//ação 91 - animação 11
{
	//aqui a animação deve ser completamente executada e depois mudar para a animação idle
	if (y >= FLOOR || (frame == 7 && !*gamePause && clock() - captureTime > TBF + 20 && y >= FLOOR))
	{
		ChangeAction(0, true);	//muda a ação
		return;
	}
	return;
}

/**
* função que faz o tratamento da ação 100
** vericica para qual lado o personagem está virado e se o botão para frente (dependendo do lado) está pressionado
** então zera a velocidade do personagem e muda ação para 101 (slide)
*/
void Terry::ProcessRum()//ação 100 - animação 12
{
	//velocidade
	if (toRight && inputs->GetPlayerInputs(player, 2))  speedX = RUNSPEED;
	else if (!toRight && inputs->GetPlayerInputs(player, 0)) speedX = -RUNSPEED;

	//se o personagem estiver virado para a direita e o direcional para a direita não estiver pressionado
	if (toRight && !inputs->GetPlayerInputs(player, 2))
	{
		ChangeAction(101, true);	//muda a ação para slide
		return;
	}

	//se o personagem estiver virado para a esquerda e o direcional para a esquerda não estiver pressionado
	if (!toRight && !inputs->GetPlayerInputs(player, 0))
	{
		ChangeAction(101, true);	//muda a ação para slide
		return;
	}

	return;
}

/**
* função que faz o tratamento da ação 101
** verifica para qual lado o personagem está virado e se a velocidade no eixo X é diferente de 0
** então diminui a velocidade do personagem no eixo X
** então verifica se a velocidade ficou contraria a direção que o personagem está virado
** então zera a velocidade de movimento no eixo X e muda a ação para 0 (idle)
*/
void Terry::ProcessSlide()//ação 101 - animação 13
{
	//se o personagem estiver virado para a direita e a velocidade for diferente de zero
	if (toRight && speedX != 0)
	{
		speedX -= 0.8;	//desaselera o personagem
		//se a velocidade se tornar maior
		if (speedX <= 0)
		{
			speedX = 0;				//zera a velocidade
			ChangeAction(0, true);	//muda a ação para idle
		}
		return;
	}
	//se o personagem estiver virado para a esquerda e a velocidade for diferente de zero
	if (!toRight && speedX != 0)
	{
		speedX += 0.8;	//desaselera o personagem
		//se a velocidade se tornar maior que zero
		if (speedX >= 0)
		{
			speedX = 0;			//zera a velicidade
			ChangeAction(0, true);	//muda a ação para idle
		}
		return;
	}

	return;
}

/**
* função que faz o tratamento da ação 110
** verifica se o personagem tocou o chão
** então muda a ação para 111 (jumpBackFall)
*/
void Terry::ProcessJumpBack()//ação 110 - animação 14
{
	//se o personagem tocou no chão
	if (y >= FLOOR)
		ChangeAction(111, true);

	return;
}

/**
* função que faz o tratamento da ação 111
** verifica se o frame 1 já foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 1 e o tempo atual é maior que o tempo padrão entre os frames)
** então verfica se o botão para tras ainda esta sendo pressionado e muda a velocidade de movimentação e a acão para 30 (walkBack)
** senão então verifica para qual lado o personagem está virado e se a velocidade é igual a zero
** então diminui a velocidade em 1.2
** então verifica se a velocidade ficou contraria a direção que o personagem está virado e zera a velocidade e muda a ação para 0 (idle)
*/
void Terry::ProcessJumpBackFall()//ação 111 - animação 15
{
	/*
	//caso o jogador esteje pressionado para tras
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)//se o frame é igual a 1 e se o tempo entre o momento que esse frame começou a ser executado e o tempo atual é maior que 85
	{
		//se o personagem está virado para a direita e se o direcional para a esquerda ainda está sendo pressionado
		if (toRight && inputs->GetPlayerInputs(player, 0))//continua antando para tras
		{
			speedX = -WALKSPEED;		//muda da velocidade para a velocidade de andar
			ChangeAction(30, true);		//muda a ação para walkBack
			return;
		}
		//se o personagem está virado para a esquerda e se o direcional para a direita ainda está sendo pressionado
		else if (inputs->GetPlayerInputs(player, 2) && !toRight)
		{
			speedX = WALKSPEED;
			ChangeAction(30, true);
			return;
		}
	}*/

	//----------desaceleração---------------

		//se o personagem está virado para a direita e a velocidade é diferente de zero
	 if (toRight && speedX != 0)
	{
		speedX += 1.2;	//desacelera o personagem
		//se a velocidade se tornou maior que zero
		if (speedX > 0.5)
		{
			speedX = 0;				//zera a velocidade
			ChangeAction(0, true);	//muda a ação para zero
		}
		return;
	}
	//se o personagem está virado para a esquerda e a velocidade é diferente de zero
	else if (!toRight && speedX != 0)
	{
		speedX -= 1.2;
		if (speedX < 0.5)
		{
			speedX = 0;				//zera a velocidade
			ChangeAction(0, true);	//muda a ação para zero
		}
		return;
	}

	return;
}

/**
* função que faz o tratamento da ação 120
*/
void Terry::ProcessDefending()//ação 120 - animação 16
{
	speedX = 0;

	if (toRight && !inputs->GetPlayerInputs(player, 0))
	{
		if (frame == 0) frame = 2;
		if (frame == 2) frame = 0;
		ChangeAction(123, true);
		return;
	}

	else if (!toRight && !inputs->GetPlayerInputs(player, 2))
	{
		if (frame == 0) frame = 2;
		if (frame == 2) frame = 0;
		ChangeAction(123, true);
		return;
	}

	//fim da animação
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
		ChangeAction(121, true);
	return;
}
/**
* função que faz o tratamento da ação 121
*/
void Terry::ProcessDefence()//ação 121 - animação 17
{
	if (toRight && !inputs->GetPlayerInputs(player, 0))
		ChangeAction(123, true);

	else if (!toRight && !inputs->GetPlayerInputs(player, 2))
		ChangeAction(123, true);

	return;
}
/**
* função que faz o tratamento da ação 122
*/
void Terry::ProcessTakingDamage()//ação 122 - animação 18
{
	return;
}
/**
* função que faz o tratamento da ação 123
*/
void Terry::ProcessDefendExit()//ação 123 - animação 19
{
	//ação de se defender
	if (*opponentAttacking)
	{
		if (toRight && inputs->GetPlayerInputs(player, 0))
		{
			if (frame == 0) frame = 2;
			if (frame == 2) frame = 0;
			ChangeAction(120, true);
			return;
		}

		else if (!toRight && inputs->GetPlayerInputs(player, 2))
		{
			if (frame == 0) frame = 2;
			if (frame == 2) frame = 0;
			ChangeAction(120, true);
			return;
		}
	}

	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
		ChangeAction(0, true);

	return;
}

/**
* função que faz o tratamento da ação 130
*/
void Terry::ProcessCrouchedDefending()//ação 130 - animação 20
{
	if (toRight && !inputs->GetPlayerInputs(player, 0))
	{
		if (frame == 0) frame = 2;
		if (frame == 2) frame = 0;
		ChangeAction(133, true);
		return;
	}

	else if (!toRight && !inputs->GetPlayerInputs(player, 2))
	{
		if (frame == 0) frame = 2;
		if (frame == 2) frame = 0;
		ChangeAction(133, true);
		return;
	}

	//fim da animação
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
		ChangeAction(131, true);
	return;
}
/**
* função que faz o tratamento da ação 131
*/
void Terry::ProcessCrouchedDefence()//ação 131 - animação 21
{
	if (toRight && !inputs->GetPlayerInputs(player, 0))
		ChangeAction(133, true);

	else if (!toRight && !inputs->GetPlayerInputs(player, 2))
		ChangeAction(133, true);

	return;
}
/**
* função que faz o tratamento da ação 132
*/
void Terry::ProcessCrouchedTakingDamage()//ação 132 - animação 22
{
	return;
}
/**
* função que faz o tratamento da ação 133
*/
void Terry::ProcessCrouchedDefendExit()//ação 133 - animação 23
{
	//ação de se defender
	if (*opponentAttacking)
	{
		if (toRight && inputs->GetPlayerInputs(player, 0))
		{
			if (frame == 0) frame = 2;
			if (frame == 2) frame = 0;
			ChangeAction(130, true);
			return;
		}

		else if (!toRight && inputs->GetPlayerInputs(player, 2))
		{
			if (frame == 0) frame = 2;
			if (frame == 2) frame = 0;
			ChangeAction(130, true);
			return;
		}
	}

	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
		ChangeAction(11, true);

	return;
}

/**
* função que faz o tratamento da ação 140
*/
void Terry::processFrontRollingCommand()//ação 140
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(141, true);

		if (toRight) speedX = RUNSPEED;
		else speedX = -RUNSPEED;
	}
	return;
}

/**
* função que faz o tratamento da ação 141
*/
void Terry::ProcessFrontRolling()//ação 141 - animação 24
{
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF - 10)
	{
		ChangeAction(142, true);
		speedX = 0;
	}
	return;
}
/**
* função que faz o tratamento da ação 142
*/
void Terry::ProcessFrontRollingEnd()//ação 142 - animação 25
{
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
* função que faz o tratamento da ação 150
*/
void Terry::ProcessBackRollingCommand()//ação 150
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(151, true);

		if (toRight) speedX = -RUNSPEED;
		else speedX = RUNSPEED;
	}
	return;
}

/**
* função que faz o tratamento da ação 151
*/
void Terry::ProcessBackRolling()//ação 151 - animação 26
{
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF - 10)
	{
		speedX = 0;
		ChangeAction(152, true);

		speedX = 0;

	}
	return;
}

/**
* função que faz o tratamento da ação 152
*/
void Terry::ProcessBackRollingEnd()//ação 152 - animação 27
{
	if (frame == 8 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
* função que faz o tratamento da ação 160
*/
void Terry::ProcessChangeSide()//ação 160 - animação 28
{
	speedX = 0;
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(0, true);
		toRight = !toRight;
		flipCharacter = false;
	}
	return;
}

/**
* função que faz o tratamento da ação 170
*/
void Terry::ProcessChangeSideCrouched()//ação 170 - animação 29
{
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(11, true);
		toRight = !toRight;
		flipCharacter = false;
	}
	return;
}

/**
* Função que faz a verificação dos pulos laterais
*/
void Terry::ProcessJumpFragment()
{
	if (inputs->GetPlayerInputs(player, 3) && y >= FLOOR && JumpCheck())
	{
		speedX = 0;//zerando a velocidade em x do personagem
		//se o direcional para esquerda está pessionado e o direcional para a direita não está pressionado
		if (inputs->GetPlayerInputs(player, 0) && !inputs->GetPlayerInputs(player, 2))
		{
			//se o personagem está virado para a direita e se a ação Weak Back Diagonal Jump pode ser executada
			if (toRight && CheckChangingTo80Action())
			{
				ChangeAction(80, false);			//muda a ação para Weak Back Diagonal Jump
				jumpDelay = clock();
			}

			//se o personagem está virado para a direita e se a ação Weak Frontal Diagonal Jump pode ser executada
			else if (!toRight && CheckChangingTo60Action())
			{
				ChangeAction(60, false);			//muda a ação para Weak Frontal Diagonal Jump
				jumpDelay = clock();
			}
		}
		//se o direcional para direita está pessionado e o direcional para a esquerda não está pressionado
		else if (inputs->GetPlayerInputs(player, 2) && !inputs->GetPlayerInputs(player, 0))
		{
			//se o personagem está virado para a direita e se a ação Weak Frontal Diagonal Jump pode ser executada
			if (toRight && CheckChangingTo60Action())
			{
				ChangeAction(60, false);			//muda a ação para Weak Frontal Diagonal Jump
				jumpDelay = clock();
			}

			//se o personagem está virado para a direita e se a ação Weak Back Diagonal Jump pode ser executada
			else if (!toRight && CheckChangingTo80Action())
			{
				ChangeAction(80, false);			//muda a ação para Weak Back Diagonal Jump
				jumpDelay = clock();
			}
		}
		//se a ação jump pode ser executada
		else if (CheckChangingTo40Action())
		{
			ChangeAction(40, false);
			jumpDelay = clock();
		}

	}
	return;
}

/**
*
*/
void Terry::ProcessWeakPunchPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(301, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakPunch()
{
	speedX = 0;
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongPunchPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(311, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongPunch()
{
	speedX = 0;
	if (frame == 7 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakKickPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(321, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakKick()
{
	speedX = 0;
	if (frame == 8 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongKickPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(331, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongKickStart()
{
	speedX = 0;
	if (frame == 3 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(332, true);
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongKick()
{
	if (toRight) speedX = 1.5;
	else if (!toRight) speedX = -1.5;

	if (frame == 2 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(333, true);
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongKickEnd()
{
	speedX = 0;
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedWeakPunchPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(341, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedWeakPunch()
{
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF - 10)
	{
		ChangeAction(11, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedStrongPunchPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(351, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedStrongPunch()
{
	if (frame == 7 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(11, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedWeakKickPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(361, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedWeakKick()
{
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(11, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedStrongKickPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(371, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessCrouchedStrongKick()
{
	if (frame == 8 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(11, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessJumpingWeakPunch()
{

	if (y >= FLOOR)
	{
		ChangeAction(44, true);
		attacking = false;
		speedX = 0;
	}
	else if (frame == 5 && !*gamePause && clock() - captureTime > TBF)
	{
		if (speedY > -4)
		{
			ChangeAction(46, true);
			attacking = false;
		}

		else if (speedY > 5)
		{
			ChangeAction(47, true);
			attacking = false;
		}
	}

	return;
}
/**
*
*/
void Terry::ProcessJumpingStrongPunch()
{

	if (y >= FLOOR)
	{
		ChangeAction(44, true);
		attacking = false;
		speedX = 0;
	}
	else if (frame == 7 && !*gamePause && clock() - captureTime > TBF)
	{
		if (speedY > -4)
		{
			ChangeAction(46, true);
			attacking = false;
		}

		else if (speedY > 5)
		{
			ChangeAction(47, true);
			attacking = false;
		}
	}

	return;
}
/**
*
*/
void Terry::ProcessJumpingWeakKick()
{

	if (y >= FLOOR)
	{
		ChangeAction(44, true);
		attacking = false;
		speedX = 0;
	}
	else if (frame == 6 && !*gamePause && clock() - captureTime > TBF)
	{
		if (speedY > -4)
		{
			ChangeAction(46, true);
			attacking = false;
		}

		else if (speedY > 5)
		{
			ChangeAction(47, true);
			attacking = false;
		}
	}
	return;
}
/**
*
*/
void Terry::ProcessJumpingStrongKick()
{

	if (y >= FLOOR)
	{
		ChangeAction(44, true);
		attacking = false;
		speedX = 0;
	}
	else if (frame == 6 && !*gamePause && clock() - captureTime > TBF)
	{
		if (speedY > -4)
		{
			ChangeAction(46, true);
			attacking = false;
		}

		else if (speedY > 5)
		{
			ChangeAction(47, true);
			attacking = false;
		}
	}
	return;
}
/**
*
*/
void Terry::ProcessGluedStrongPunchPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(421, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessGluedStrongPunch()
{
	speedX = 0;
	if (frame == 7 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessGluedStrongKickPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(431, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessGluedStrongKick()
{
	speedX = 0;
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessSpecialAttackStart()
{
	speedX = 0;
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF)
		ChangeAction(441, true);

	return;
}
/**
*
*/
void Terry::ProcessSpecialAttack()
{
	if (toRight) speedX = WALKSPEED;
	else if (!toRight) speedX = -WALKSPEED;

	if (frame == 4 && !*gamePause && clock() - captureTime > TBF)
		ChangeAction(442, true);

	return;
}
/**
*
*/
void Terry::ProcessSpecialAttackEnd()
{
	speedX = 0;
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessJumpingSpecialAttack()
{

	if (y >= FLOOR)
	{
		ChangeAction(44, true);
		attacking = false;
		speedX = 0;
	}
	else if (frame == 8 && !*gamePause && clock() - captureTime > TBF - 20)
	{
		if (speedY > -4)
		{
			ChangeAction(46, true);
			attacking = false;
		}

		else if (speedY > 5)
		{
			ChangeAction(47, true);
			attacking = false;
		}
	}

	return;
}
/**
*
*/
void Terry::ProcessWeakPunchForwardPreparation()
{
	if (capturedTime - clock() > DELAYTIME)
	{
		ChangeAction(461, true);
		attacking = true;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakPunchForward()
{
	speedX = 0;
	if (frame == 14 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessRisingUpper()
{
	if (frame == 8 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}

/**
*
*/
void Terry::ProcessPowerWave()
{
	speedX = 0;

	if (frame == 3 && !*gamePause)
	{
		captureTimeForEffect = clock();
		effectFrame = 0;
		//effectActive = true;
		powerWaveActive = true;
	}

	if (frame == 7 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
	return;
}
/**
*
*/
void Terry::ProcessRoundWave()
{
	speedX = 0;
	effectSpeedX = 0;

	if (frame == 3 && !*gamePause)
	{
		captureTimeForEffect = clock();
		effectFrame = 0;
		//effectActive = true;
		roundWaveActive = true;
	}

	if (frame == 9 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
*
*/
void Terry::ProcessWeakCrackShoot()
{
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(621, true);

		if (toRight) { speedX = +5; x += 95; }
		else if (!toRight){ speedX = -5; x -= 58; }
	

		speedY = -15;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakCrackShootJumping()
{
	if (frame == 4 && !*gamePause && clock() - captureTime > TBF + 45)
	{
		ChangeAction(48, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongCrackShoot()
{
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF )
	{
		ChangeAction(631, true);

		if (toRight) { speedX = +9; x += 95.5;}

		else if (!toRight) { speedX = -9; x -= 58; }

		speedY = -15;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongCrackShootJumping()
{
	if (frame == 4 && !*gamePause && clock() - captureTime > TBF + 45)
	{
		ChangeAction(48, true);
		attacking = false;
	}
	return;
}
/**
*
*/

void Terry::ProcessWeakPowerDunkStart()
{
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(641, true);

		if (toRight) { speedX = +5; x += 128; }
		else if (!toRight) { speedX = -5; x -= 128; }

		speedY = -18;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakPowerDunkJumping()
{
	if (speedY > -4 && !*gamePause && frame == 3 && clock() - captureTime > TBF)
	{
		ChangeAction(642, true);
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakPowerDunkFalling()
{
	if (y >= FLOOR)
	{
		ChangeAction(44, true);	//muda a ação
		speedX = 0;				//zera a velocidade
		attacking = false;
		return;
	}
	return;
}

/**
*
*/
void Terry::ProcessStrongPowerDunkStart()
{
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(651, true);

		if (toRight) { speedX = +8; x += 128; }
		else if (!toRight) { speedX = -8; x -= 128; }

		speedY = -22;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongPowerDunkJumping()
{
	if (speedY > -4 && !*gamePause && frame == 3 && clock() - captureTime > TBF)
	{
		ChangeAction(652, true);
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongPowerDunkFalling()
{
	if (y >= FLOOR)
	{
		ChangeAction(44, true);	//muda a ação
		speedX = 0;				//zera a velocidade
		attacking = false;
		return;
	}
	return;
}

/**
*
*/
void Terry::ProcessWeakBurnigKnuckleStart()
{
	if (frame == 3 && !*gamePause && clock() - captureTime > TBF-15)
	{
		ChangeAction(661, true);

		if (toRight) { speedX = +6; x += 86; }
		else if (!toRight) { speedX = -6; x -= 88; }
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakBurnigKnuckle()
{
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF-15)
	{
		ChangeAction(101, true);
		attacking = false;
	}
	return;
}

/**
*
*/
void Terry::ProcessStrongBurnigKnuckleStart()
{
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF-15)
	{
		ChangeAction(671, true);

		if (toRight) { speedX = +8; x += 86; }
		else if (!toRight) { speedX = -8; x -= 88; }
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongBurnigKnuckle()
{
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF-15)
	{
		ChangeAction(101, true);
		attacking = false;
	}
	return;
}

/**
*
*/
void Terry::ProcessWeakRisingTackleStart()
{
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF )
	{
		ChangeAction(681, true);

		if (toRight) { speedX = +2; x += 125; }
		else if (!toRight) { speedX = -2; x -= 40;}

		speedY = -18;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakRisingTackle()
{
	if (speedY > -4 && !*gamePause )
	{
		ChangeAction(682, true);

		if (toRight) x -= 10;
		else if (!toRight) x += 10;

		speedX = -1 * speedX;
	}
	return;
}
/**
*
*/
void Terry::ProcessWeakRisingTackleFall()
{
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(48, true);
		attacking = false;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongRisingTackleStart()
{
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(681, true);

		if (toRight) { speedX = +4; x += 125;}
		else if (!toRight) { speedX = -4; x -= 40;}

		speedY = -22;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongRisingTackle()
{
	if (speedY > -4 && !*gamePause)
	{
		ChangeAction(682, true);

		if (toRight) x -= 10;
		else if (!toRight) x += 10;

		speedX = -1 * speedX;
	}
	return;
}
/**
*
*/
void Terry::ProcessStrongRisingTackleFall()
{
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(48, true);
		attacking = false;
	}
	return;
}

/**
*
*/
void Terry::ProcessPowerGeyser()
{
	speedX = 0;
	effectSpeedX = 0;

	if (frame == 3 && !*gamePause && !especialEffectActive)
	{
		if (toRight)
		{
			especialEffectX = x + 60;
			especialEffectY = y - 75;
		}
		else
		{
			especialEffectX = x - 85;
			especialEffectY = y - 75;
		}
		especialEffectFrame = 0;
		especialEffectActive = true;
	}

	if (frame == 6 && !*gamePause)
	{
		captureTimeForEffect = clock();
		effectFrame = 0;
		powerGeyserActive = true;
	}

	if (frame == 12 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
*
*/
void Terry::ProcessBusterWolfStart()
{
	if (frame == 4 && !*gamePause && !especialEffectActive)
	{
		if (toRight)
		{
			especialEffectX = x + 60;
			especialEffectY = y - 75;
		}
		else
		{
			especialEffectX = x - 85;
			especialEffectY = y - 75;
		}
		especialEffectFrame = 0;
		especialEffectActive = true;
	}

	if (frame == 8 && !*gamePause && clock() - captureTime > TBF)
	{
		//mudar velocidade
		if (toRight) { speedX = +8; x += 125; }
		else if (!toRight) { speedX = -8; x -= 40; }

		ChangeAction(711, true);
	}
	return;
}

/**
*
*/
void Terry::ProcessBusterWolf()
{
	if (frame == 12 && !*gamePause && clock() - captureTime > TBF-25)
	{
		ChangeAction(713, true);//falha
		speedX = 0;
		attacking = false;
	}
	return;
}

/**
*
*/
void Terry::ProcessBusterWolfEnd()
{
	if (frame == 18 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
		attacking = false;
	}
	return;
}

/**
*
*/
void Terry::ProcessBusterWolfFail()
{
	if (frame == 4 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(190, true);
	}
	return;
}

/**
*
*/
void Terry::ProcessActivePow()
{
	return;
}

/**
*
*/
void Terry::ProcessRecover()
{
	speedX = 0;
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
*
*/
void Terry::ProcessTaunt()
{
	speedX = 0;
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
*
*/
void Terry::ProcessStuned()
{
	return;
}