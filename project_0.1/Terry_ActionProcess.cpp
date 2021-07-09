#include "includes.h"
#include "Terry.h"

/**
* fun��o que faz o tratamento da a��o 00
** zera a velocidade do personagem em X
*/
void Terry::ProcessIdle()//a��o 00 - anima��o 00
{
	if (speedX != 0) speedX = 0;

	//--------------------a��o de se agachar-------------------------------
	if (inputs->GetPlayerInputs(player, 1) && CheckChangingTo10Action())
		ChangeAction(10, true);

	//--------------------movimenta��o-------Horizontal--------------------
	if (inputs->GetPlayerInputs(player, 2) && !inputs->GetPlayerInputs(player, 0) && !inputs->GetPlayerInputs(player, 1) && y >= FLOOR)
	{
		//se o direcional para direita foi pressionado 2x rapidamente e se o personagem pode se mover rapidamente
		if (inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) < 100 && fastMove )//processamento para o personagem correr      
		{
			//se o personagem est� virado para a direita e se a a��o de corrida pode ser executada
			if (toRight && CheckChangingTo100Action())//correndo
				ChangeAction(100, true);

			//se o personagem estiver virado para a esquerda e se a a��o de pulo para tras pode ser executada
			else if (!toRight && CheckChangingTo110Action() && clock() - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP)//pulando para tras
			{
				fastMove = false;
				speedX = RUNSPEED + 2;
				speedY = -10;
				ChangeAction(110, true);
			}
		}

		//se o personagem est� virado para a direita, e o bot�o para a esquerda n�o est� pressionado e se a a��o de andar pode ser executada
		else if (toRight && CheckChangingTo20Action())//andando
			ChangeAction(20, true);

		//se o oponente est� atacando e se o personagem est� virado para a esquerda
		else if (*opponentAttacking && !toRight)//a��o de se defender
		{
			if (CheckChangingTo120Action()) ChangeAction(120, true);
		}

		//se o personagem est� virado para a esquerda, se o direcional para a esquerda n�o est� pressionado, se a a��o de andar para tras pode ser executada e se o oponente n�o est� atacando
		else if (!toRight && CheckChangingTo30Action() && !*opponentAttacking)//andando para tras
			ChangeAction(30, true);

	}
	else if (inputs->GetPlayerInputs(player, 0) && !inputs->GetPlayerInputs(player, 2) && !inputs->GetPlayerInputs(player, 1) && y >= FLOOR)
	{
		//se o direcional para esquerda foi pressionado 2x rapidamente e se o personagem pode se mover rapidamente
		if (inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) < 100 && fastMove)//processamento para o personagem correr
		{
			//se o personagem est� virado para a esquerda e se a a��o de corrida pode ser executada
			if (!toRight && CheckChangingTo100Action())//correndo
				ChangeAction(100, true);

			//se o personagem estiver virado para a direita e se a a��o de pulo para tras pode ser executada
			else if (toRight && CheckChangingTo110Action() && clock() - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP)//pulando para tras
			{
				fastMove = false;
				speedX = -(RUNSPEED + 2);
				speedY = -10;
				ChangeAction(110, true);
			}
		}

		//se o personagem est� virado para a esquerda, e o bot�o para a direita n�o est� pressionado e se a a��o de andar pode ser executada
		else if (!toRight && CheckChangingTo20Action())//andando
			ChangeAction(20, true);

		//se o oponente est� atacando e se o personagem est� virado para a direita
		else if (*opponentAttacking && toRight)//a��o de se defender
		{
			if (CheckChangingTo120Action()) ChangeAction(120, true);

		}

		//se o personagem est� virado para a direita, se o direcional para a direita n�o est� pressionado, se a a��o de andar para tras pode ser executada e se o oponente n�o est� atacando
		else if (toRight && CheckChangingTo30Action() && !*opponentAttacking)//andando para tras
			ChangeAction(30, true);
	}

	//---------------------------Taunt---------------------------
	//implementar taunt aqui - a��o 200

	//--------------------movimenta��o-------Vertical----------------------
	ProcessJumpFragment();

	return;
}

/**
* fun��o que faz o tratamento da a��o 10
*/
void Terry::ProcessCrouchung()//a��o 10 - anima��o 01
{
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(11, true);
	}
}
/**
* fun��o que faz o tratamento da a��o 11
*/
void Terry::ProcessCrouchedIdle()//a��o 11 - anima��o 02
{

	if ((*opponentAttacking && toRight && inputs->GetPlayerInputs(player, 0) && CheckChangingTo130Action()) ||
		(*opponentAttacking && !toRight && inputs->GetPlayerInputs(player, 2) && CheckChangingTo130Action()))
		ChangeAction(130, true);

	if (!inputs->GetPlayerInputs(player, 1))
		ChangeAction(12, true);

}
/**
* fun��o que faz o tratamento da a��o 12
*/
void Terry::ProcessRaiseCrouched()//a��o 12 - anima��o 03
{
	if (inputs->GetPlayerInputs(player, 1) && CheckChangingTo10Action())
		ChangeAction(10, false);

	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)
	{
		ChangeAction(0, true);
	}
}

/**
* fun��o que faz o tratamento da a��o 20
** vericica para qual lado o personagem est� virado e se o bot�o para frente (dependendo do lado) est� pressionado
** ent�o zera a velocidade do personagem e muda a��o para 0 (idle)
*/
void Terry::ProcessWalk()//a��o 20 - anima��o 04
{
	//--------------------movimenta��o-------Vertical--------------------
	ProcessJumpFragment();

	//velocidade
	if (toRight && inputs->GetPlayerInputs(player, 2)) speedX = WALKSPEED;
	else if (!toRight && inputs->GetPlayerInputs(player, 0)) speedX = -WALKSPEED;

	//se o personagem estiver virado para a direita e o direcional para a direita n�o estiver pressionado
	if (toRight && !inputs->GetPlayerInputs(player, 2) || inputs->GetPlayerInputs(player, 1))
	{
		speedX = 0;			//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a anima��o para idle
		return;
	}

	//se o personagem estiver virado para a esquerda e o direcional para a esquerda n�o estiver pressionado
	if (!toRight && !inputs->GetPlayerInputs(player, 0) || inputs->GetPlayerInputs(player, 1))
	{
		speedX = 0;			//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a anima��o para idle
		return;
	}

	return;
}

/**
* fun��o que faz o tratamento da a��o 30
** vericica para qual lado o personagem est� virado e se o bot�o para tras (dependendo do lado) est� pressionado
** ent�o zera a velocidade do personagem e muda a��o para 0 (idle)
*/
void Terry::ProcessWalkBack()//a��o 30 - anima��o 05
{
	//--------------------movimenta��o-------Vertical--------------------
	ProcessJumpFragment();

	//velocidade
	if (toRight && inputs->GetPlayerInputs(player, 0)) speedX = -WALKSPEED;
	else if (!toRight && inputs->GetPlayerInputs(player, 2))speedX = WALKSPEED;

	//a��o de se defender
	if (*opponentAttacking)
	{
		if (CheckChangingTo120Action()) ChangeAction(120, true);
	}

	//se o personagem estiver virado para a direita e o direcional para a esquerda n�o estiver pressionado
	if (!toRight && !inputs->GetPlayerInputs(player, 2) || inputs->GetPlayerInputs(player, 1) )
	{
		speedX = 0;				//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a anima��o para idle
		return;
	}

	//se o personagem estiver virado para a esquerda e o direcional para a direita n�o estiver pressionado
	if (toRight && !inputs->GetPlayerInputs(player, 0) || inputs->GetPlayerInputs(player, 1) )
	{
		speedX = 0;				//zera a velocidade do personagem
		ChangeAction(0, true);	//muda a anima��o para idle
		return;
	}

	return;
}

/**
* fun��o que faz o tratamento da a��o 40
*/
void Terry::ProcessJumpCommand()//a��o 40 - anima��o Ultima que foi exacutada (00)
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
* fun��o que faz o tratamento da a��o 60
*/
void Terry::ProcessFrontalDiagonalJumpCommand()//a��o 60 - anima��o Ultima que foi executada (00, 04, 12)
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
* fun��o que faz o tratamento da a��o 80
*/
void Terry::ProcessBackDiagonalJumpCommand()//a��o 80 - anima��o Ultima que foi executada (00, 05)
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
* fun��o que faz o tratamento da a��o 41, 51, 61, 81
** verifica se a velocidade de subida est� diminudindo (se a for�a de subida est� acabando)
** ent�o muda a��o para 42 (endOfClimp)
*/
void Terry::ProcessRising()//a��o 41 & a��o 51 & a��o 61 & a��o 81 - anima��o 06
{
	if (action == 45 && speedY > -4) ChangeAction(46, true);
	else if (speedY > -4) ChangeAction(42, true);

	return;
}
/**
* fun��o que faz o tratamento da a��o 42
** verifica se a velocidade de decida est� maior que 5 (o personagem est� ganhando velocidade enquanto cai)
** ent�o muda a a��o para 43 (falling)
*/
void Terry::ProcessEndOfClimp()//a��o 42 - anima��o 07
{
	if (action == 46 && speedY > 5) ChangeAction(47, true);
	else if (speedY > 5) ChangeAction(43, true);

	return;
}
/**
* fun��o que faz o tratamento da a��o 43
** verifica se o personagem chegou ao ch�o
** ent�o muda a a��o para 44 (fall)
*/
void Terry::ProcessFalling()//a��o 43 - anima��o 08
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
* fun��o que faz o tratamento da a��o 44
** verifica se o frame 3 j� foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 3 e o tempo atual � maior que o tempo padr�o entre os frames -10)
** ent�o muda a a��o para 0 (idle)
*/
void Terry::ProcessFall()//a��o 44 - anima��o 09
{
	//aqui a anima��o deve ser completamente executada e depois mudar para a anima��o idle
	if (frame == 3 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		if(action == 49) ChangeAction(190, true);//muda para recover
		else ChangeAction(0, true);	//muda a a��o
		return;
	}
	return;
}

/**
* fun��o que faz o tratamento da a��o 71
** verifica se o frame 8 j� foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 8 e o tempo atual � maior que o tempo padr�o entre os frames -10)
** ent�o muda a a��o para 0 (idle)
*/
void Terry::ProcessRising_SBDiagonalJump()//a��o 71 - anima��o 10
{
	//aqui a anima��o deve ser completamente executada e depois mudar para a anima��o idle
	if (y >= FLOOR || (frame == 8 && !*gamePause && clock() - captureTime > TBF + 10 && y >= FLOOR))
	{
		ChangeAction(0, true);	//muda a a��o
		return;
	}
	return;

}

/**
* fun��o que faz o tratamento da a��o 91
** verifica se o frame 7 j� foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 7 e o tempo atual � maior que o tempo padr�o entre os frames -10)
** ent�o muda a a��o para 0 (idle)
*/
void Terry::ProcessRisong_SBDiagonalJump()//a��o 91 - anima��o 11
{
	//aqui a anima��o deve ser completamente executada e depois mudar para a anima��o idle
	if (y >= FLOOR || (frame == 7 && !*gamePause && clock() - captureTime > TBF + 20 && y >= FLOOR))
	{
		ChangeAction(0, true);	//muda a a��o
		return;
	}
	return;
}

/**
* fun��o que faz o tratamento da a��o 100
** vericica para qual lado o personagem est� virado e se o bot�o para frente (dependendo do lado) est� pressionado
** ent�o zera a velocidade do personagem e muda a��o para 101 (slide)
*/
void Terry::ProcessRum()//a��o 100 - anima��o 12
{
	//velocidade
	if (toRight && inputs->GetPlayerInputs(player, 2))  speedX = RUNSPEED;
	else if (!toRight && inputs->GetPlayerInputs(player, 0)) speedX = -RUNSPEED;

	//se o personagem estiver virado para a direita e o direcional para a direita n�o estiver pressionado
	if (toRight && !inputs->GetPlayerInputs(player, 2))
	{
		ChangeAction(101, true);	//muda a a��o para slide
		return;
	}

	//se o personagem estiver virado para a esquerda e o direcional para a esquerda n�o estiver pressionado
	if (!toRight && !inputs->GetPlayerInputs(player, 0))
	{
		ChangeAction(101, true);	//muda a a��o para slide
		return;
	}

	return;
}

/**
* fun��o que faz o tratamento da a��o 101
** verifica para qual lado o personagem est� virado e se a velocidade no eixo X � diferente de 0
** ent�o diminui a velocidade do personagem no eixo X
** ent�o verifica se a velocidade ficou contraria a dire��o que o personagem est� virado
** ent�o zera a velocidade de movimento no eixo X e muda a a��o para 0 (idle)
*/
void Terry::ProcessSlide()//a��o 101 - anima��o 13
{
	//se o personagem estiver virado para a direita e a velocidade for diferente de zero
	if (toRight && speedX != 0)
	{
		speedX -= 0.8;	//desaselera o personagem
		//se a velocidade se tornar maior
		if (speedX <= 0)
		{
			speedX = 0;				//zera a velocidade
			ChangeAction(0, true);	//muda a a��o para idle
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
			ChangeAction(0, true);	//muda a a��o para idle
		}
		return;
	}

	return;
}

/**
* fun��o que faz o tratamento da a��o 110
** verifica se o personagem tocou o ch�o
** ent�o muda a a��o para 111 (jumpBackFall)
*/
void Terry::ProcessJumpBack()//a��o 110 - anima��o 14
{
	//se o personagem tocou no ch�o
	if (y >= FLOOR)
		ChangeAction(111, true);

	return;
}

/**
* fun��o que faz o tratamento da a��o 111
** verifica se o frame 1 j� foi executado tempo o suficiente (se o tempo entre o frame ter cido trocado para 1 e o tempo atual � maior que o tempo padr�o entre os frames)
** ent�o verfica se o bot�o para tras ainda esta sendo pressionado e muda a velocidade de movimenta��o e a ac�o para 30 (walkBack)
** sen�o ent�o verifica para qual lado o personagem est� virado e se a velocidade � igual a zero
** ent�o diminui a velocidade em 1.2
** ent�o verifica se a velocidade ficou contraria a dire��o que o personagem est� virado e zera a velocidade e muda a a��o para 0 (idle)
*/
void Terry::ProcessJumpBackFall()//a��o 111 - anima��o 15
{
	/*
	//caso o jogador esteje pressionado para tras
	if (frame == 1 && !*gamePause && clock() - captureTime > TBF)//se o frame � igual a 1 e se o tempo entre o momento que esse frame come�ou a ser executado e o tempo atual � maior que 85
	{
		//se o personagem est� virado para a direita e se o direcional para a esquerda ainda est� sendo pressionado
		if (toRight && inputs->GetPlayerInputs(player, 0))//continua antando para tras
		{
			speedX = -WALKSPEED;		//muda da velocidade para a velocidade de andar
			ChangeAction(30, true);		//muda a a��o para walkBack
			return;
		}
		//se o personagem est� virado para a esquerda e se o direcional para a direita ainda est� sendo pressionado
		else if (inputs->GetPlayerInputs(player, 2) && !toRight)
		{
			speedX = WALKSPEED;
			ChangeAction(30, true);
			return;
		}
	}*/

	//----------desacelera��o---------------

		//se o personagem est� virado para a direita e a velocidade � diferente de zero
	 if (toRight && speedX != 0)
	{
		speedX += 1.2;	//desacelera o personagem
		//se a velocidade se tornou maior que zero
		if (speedX > 0.5)
		{
			speedX = 0;				//zera a velocidade
			ChangeAction(0, true);	//muda a a��o para zero
		}
		return;
	}
	//se o personagem est� virado para a esquerda e a velocidade � diferente de zero
	else if (!toRight && speedX != 0)
	{
		speedX -= 1.2;
		if (speedX < 0.5)
		{
			speedX = 0;				//zera a velocidade
			ChangeAction(0, true);	//muda a a��o para zero
		}
		return;
	}

	return;
}

/**
* fun��o que faz o tratamento da a��o 120
*/
void Terry::ProcessDefending()//a��o 120 - anima��o 16
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

	//fim da anima��o
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
		ChangeAction(121, true);
	return;
}
/**
* fun��o que faz o tratamento da a��o 121
*/
void Terry::ProcessDefence()//a��o 121 - anima��o 17
{
	if (toRight && !inputs->GetPlayerInputs(player, 0))
		ChangeAction(123, true);

	else if (!toRight && !inputs->GetPlayerInputs(player, 2))
		ChangeAction(123, true);

	return;
}
/**
* fun��o que faz o tratamento da a��o 122
*/
void Terry::ProcessTakingDamage()//a��o 122 - anima��o 18
{
	return;
}
/**
* fun��o que faz o tratamento da a��o 123
*/
void Terry::ProcessDefendExit()//a��o 123 - anima��o 19
{
	//a��o de se defender
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
* fun��o que faz o tratamento da a��o 130
*/
void Terry::ProcessCrouchedDefending()//a��o 130 - anima��o 20
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

	//fim da anima��o
	if (frame == 2 && !*gamePause && clock() - captureTime > TBF - 15)
		ChangeAction(131, true);
	return;
}
/**
* fun��o que faz o tratamento da a��o 131
*/
void Terry::ProcessCrouchedDefence()//a��o 131 - anima��o 21
{
	if (toRight && !inputs->GetPlayerInputs(player, 0))
		ChangeAction(133, true);

	else if (!toRight && !inputs->GetPlayerInputs(player, 2))
		ChangeAction(133, true);

	return;
}
/**
* fun��o que faz o tratamento da a��o 132
*/
void Terry::ProcessCrouchedTakingDamage()//a��o 132 - anima��o 22
{
	return;
}
/**
* fun��o que faz o tratamento da a��o 133
*/
void Terry::ProcessCrouchedDefendExit()//a��o 133 - anima��o 23
{
	//a��o de se defender
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
* fun��o que faz o tratamento da a��o 140
*/
void Terry::processFrontRollingCommand()//a��o 140
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
* fun��o que faz o tratamento da a��o 141
*/
void Terry::ProcessFrontRolling()//a��o 141 - anima��o 24
{
	if (frame == 5 && !*gamePause && clock() - captureTime > TBF - 10)
	{
		ChangeAction(142, true);
		speedX = 0;
	}
	return;
}
/**
* fun��o que faz o tratamento da a��o 142
*/
void Terry::ProcessFrontRollingEnd()//a��o 142 - anima��o 25
{
	if (frame == 6 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
* fun��o que faz o tratamento da a��o 150
*/
void Terry::ProcessBackRollingCommand()//a��o 150
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
* fun��o que faz o tratamento da a��o 151
*/
void Terry::ProcessBackRolling()//a��o 151 - anima��o 26
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
* fun��o que faz o tratamento da a��o 152
*/
void Terry::ProcessBackRollingEnd()//a��o 152 - anima��o 27
{
	if (frame == 8 && !*gamePause && clock() - captureTime > TBF - 15)
	{
		ChangeAction(0, true);
	}
	return;
}

/**
* fun��o que faz o tratamento da a��o 160
*/
void Terry::ProcessChangeSide()//a��o 160 - anima��o 28
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
* fun��o que faz o tratamento da a��o 170
*/
void Terry::ProcessChangeSideCrouched()//a��o 170 - anima��o 29
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
* Fun��o que faz a verifica��o dos pulos laterais
*/
void Terry::ProcessJumpFragment()
{
	if (inputs->GetPlayerInputs(player, 3) && y >= FLOOR && JumpCheck())
	{
		speedX = 0;//zerando a velocidade em x do personagem
		//se o direcional para esquerda est� pessionado e o direcional para a direita n�o est� pressionado
		if (inputs->GetPlayerInputs(player, 0) && !inputs->GetPlayerInputs(player, 2))
		{
			//se o personagem est� virado para a direita e se a a��o Weak Back Diagonal Jump pode ser executada
			if (toRight && CheckChangingTo80Action())
			{
				ChangeAction(80, false);			//muda a a��o para Weak Back Diagonal Jump
				jumpDelay = clock();
			}

			//se o personagem est� virado para a direita e se a a��o Weak Frontal Diagonal Jump pode ser executada
			else if (!toRight && CheckChangingTo60Action())
			{
				ChangeAction(60, false);			//muda a a��o para Weak Frontal Diagonal Jump
				jumpDelay = clock();
			}
		}
		//se o direcional para direita est� pessionado e o direcional para a esquerda n�o est� pressionado
		else if (inputs->GetPlayerInputs(player, 2) && !inputs->GetPlayerInputs(player, 0))
		{
			//se o personagem est� virado para a direita e se a a��o Weak Frontal Diagonal Jump pode ser executada
			if (toRight && CheckChangingTo60Action())
			{
				ChangeAction(60, false);			//muda a a��o para Weak Frontal Diagonal Jump
				jumpDelay = clock();
			}

			//se o personagem est� virado para a direita e se a a��o Weak Back Diagonal Jump pode ser executada
			else if (!toRight && CheckChangingTo80Action())
			{
				ChangeAction(80, false);			//muda a a��o para Weak Back Diagonal Jump
				jumpDelay = clock();
			}
		}
		//se a a��o jump pode ser executada
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
		ChangeAction(44, true);	//muda a a��o
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
		ChangeAction(44, true);	//muda a a��o
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