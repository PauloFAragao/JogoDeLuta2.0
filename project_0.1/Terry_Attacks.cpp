#include "includes.h"
#include "Terry.h"

/**
*	procedimento responsavel por fazer o processamento de todos os golpes terminados com soco fraco
*/
void Terry::CheckWeakPunch()//A-u (4)
{

	if ( 
		inputs->GetPlayerInputs(player, 4)  &&	//soco fraco
		!inputs->GetPlayerInputs(player, 5) &&	//soco forte
		!inputs->GetPlayerInputs(player, 6) &&	//chute fraco
		!inputs->GetPlayerInputs(player, 7)		//chute forte
		)
	{
		//Power Geyser
		if (CheckChangingTo700Action() && specialQuantity >= 1 && clock() - inputs->GetPlayerBtDownImputs(player, 4, MAS) < BTP && CheckPowerGeyser())
		{
			specialQuantity -= 1;

			ChangeAction(700, true);
			attacking = true;

			if (toRight)
				effectX = x + 214;

			else if (!toRight)
				effectX = x - 64;
		}

		//power Wave
		else if(CheckChangingTo600Action() && clock() - inputs->GetPlayerBtDownImputs(player, 4, MAS) < BTP && CheckPowerWave())
		{
			ChangeAction(600, true);
			attacking = true;
			
			if (toRight)
			{
				effectX = x + 160;
				effectSpeedX = 5;
			}
			else if (!toRight)
			{
				effectX = x - 100;
				effectSpeedX = -5;
			}
		}

		//Burnig Knuckle
		else if (CheckChangingTo660Action() && clock() - inputs->GetPlayerBtDownImputs(player, 4, MAS) < BTP && CheckWeakBurnigKnuckle())
		{
			speedX = 0;
			ChangeAction(660, true);
			attacking = true;
		}

		//Rising Tackle
		else if (CheckChangingTo680Action() && clock() - inputs->GetPlayerBtDownImputs(player, 4, MAS) < BTP && CheckWeakRisingTackle())
		{
			speedX = 0;
			ChangeAction(680, true);
			attacking = true;
		}

		//soco fraco agachado
		else if (CheckChangingTo340Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(340, false);
		}

		//soco fraco pulando
		else if ( y < FLOOR && CheckChangingTo380Action())//não está no chão
		{
			ChangeAction(380, true);
			attacking = true;
		}

		//soco fraco para frente
		else if (CheckChangingTo460Action() &&
				((inputs->GetPlayerInputs(player, 2) && toRight) ||
				(inputs->GetPlayerInputs(player, 0) && !toRight)))
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(460, false);
		}

		//soco fraco
		else if (CheckChangingTo300Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(300, false);
		}

	}

	return;
}

/**
*	procedimento responsavel por fazer o processamento de todos os golpes terminados com soco forte
*/
void Terry::CheckStrongPunch()//B-j (5)
{
	if (
		!inputs->GetPlayerInputs(player, 4) &&	//soco fraco
		inputs->GetPlayerInputs(player, 5) &&	//soco forte
		!inputs->GetPlayerInputs(player, 6) &&	//chute fraco
		!inputs->GetPlayerInputs(player, 7)		//chute forte
		)
	{
		//Power Geyser
		if (CheckChangingTo700Action() && specialQuantity >= 1 && clock() - inputs->GetPlayerBtDownImputs(player, 5, MAS) < BTP && CheckPowerGeyser())
		{
			specialQuantity -= 1;

			ChangeAction(700, true);
			attacking = true;

			if (toRight)
				effectX = x + 214;

			else if (!toRight)
				effectX = x - 64;
		}

		//Round Wave
		else if (CheckChangingTo610Action() && clock() - inputs->GetPlayerBtDownImputs(player, 5, MAS) < BTP && CheckRoundWave())
		{
			ChangeAction(610, true);
			attacking = true;
						
			if (toRight)
				effectX = x + 175;

			else if (!toRight)
				effectX = x - 100;

		}

		//Burnig Knuckle
		else if (CheckChangingTo670Action() && clock() - inputs->GetPlayerBtDownImputs(player, 5, MAS) < BTP && CheckStrongBurnigKnuckle() )
		{
			speedX = 0;
			ChangeAction(670, true);
			attacking = true;
		}

		//Rising Tackle
		else if (CheckChangingTo680Action() && clock() - inputs->GetPlayerBtDownImputs(player, 5, MAS) < BTP && CheckStrongRisingTackle())
		{
			speedX = 0;
			ChangeAction(690, true);
			attacking = true;
		}

		//rising upper
		else if (CheckChangingTo470Action()
				&&
			((toRight && inputs->GetPlayerInputs(player, 1) && inputs->GetPlayerInputs(player, 2))
				||
			(!toRight && inputs->GetPlayerInputs(player, 0) && inputs->GetPlayerInputs(player, 1))))
		{
			ChangeAction(470, true);
			attacking = true;
		}

		//soco forte agachado
		else if (CheckChangingTo350Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(350, false);
		}


		//soco forte pulando
		else if (y < FLOOR && CheckChangingTo390Action())//não está no chão
		{
			ChangeAction(390, true);
			attacking = true;
		}

		//soco forte grudado
		else if ( (toRight && x - *opponentX >= -150 && CheckChangingTo420Action()) ||
			 (!toRight && x - *opponentX <= 150 && CheckChangingTo420Action()) )
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(420, false);
		}

		//soco forte
		else if (CheckChangingTo310Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(310, false);
		}
	}
	return;
}

/**
*	procedimento responsavel por fazer o processamento de todos os golpes terminados com chute fraco
*/
void Terry::CheckWeakKick()//C-i (6)
{
	if (
		!inputs->GetPlayerInputs(player, 4) &&	//soco fraco
		!inputs->GetPlayerInputs(player, 5) &&	//soco forte
		inputs->GetPlayerInputs(player, 6)  &&	//chute fraco
		!inputs->GetPlayerInputs(player, 7)		//chute forte
		)
	{

		//Buster Wolf
		if (CheckChangingTo710Action() && specialQuantity >= 1 && clock() - inputs->GetPlayerBtDownImputs(player, 6, MAS) < BTP && CheckBusterWolf())
		{
			specialQuantity -= 1;
			speedX = 0;
			ChangeAction(710, true);
			attacking = true;
		}

		//Crack Shoot
		else if (CheckChangingTo620Action() && clock() - inputs->GetPlayerBtDownImputs(player, 6, MAS) < BTP && CheckWeakCrackShoot() )
		{
			speedX = 0;
			ChangeAction(620, true);
			attacking = true;
		}

		//Power Dunk
		else if (CheckChangingTo640Action() && clock() - inputs->GetPlayerBtDownImputs(player, 6, MAS) < BTP && CheckWeakPowerDunk())
		{
			speedX = 0;
			ChangeAction(640, true);
			attacking = true;
		}
		
		//chute fraco agachado
		else if (CheckChangingTo360Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(360, false);
		}

		//chute fraco pulando
		else if (y < FLOOR && CheckChangingTo400Action())//não está no chão
		{
			ChangeAction(400, true);
			attacking = true;
		}

		//chute fraco
		else if (CheckChangingTo320Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(320, false);
		}
	}
	return;
}

/**
*	procedimento responsavel por fazer o processamento de todos os golpes terminados com chute forte
*/
void Terry::CheckStrongKick()//D-k (7)
{
	if (
		!inputs->GetPlayerInputs(player, 4) &&	//soco fraco
		!inputs->GetPlayerInputs(player, 5) &&	//soco forte
		!inputs->GetPlayerInputs(player, 6) &&	//chute fraco
		inputs->GetPlayerInputs(player, 7)		//chute forte
		)
	{

		//Buster Wolf
		if (CheckChangingTo710Action() && specialQuantity >= 1 && clock() - inputs->GetPlayerBtDownImputs(player, 7, MAS) < BTP && CheckBusterWolf())
		{
			specialQuantity -= 1;
			speedX = 0;
			ChangeAction(710, true);
			attacking = true;
		}

		//Crack Shoot
		else if (CheckChangingTo630Action() && clock() - inputs->GetPlayerBtDownImputs(player, 7, MAS) < BTP && CheckStrongCrackShoot())
		{
			speedX = 0;
			ChangeAction(630, true);
			attacking = true;
		}

		//Power Dunk
		else if (CheckChangingTo650Action() &&clock() - inputs->GetPlayerBtDownImputs(player, 7, MAS) < BTP && CheckStrongPowerDunk())
		{
			speedX = 0;
			ChangeAction(650, true);
			attacking = true;
		}

		//chute forte agachado
		else if (CheckChangingTo370Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(370, false);
		}

		//chute forte pulando
		else if (y < FLOOR && CheckChangingTo410Action())//não está no chão
		{
			ChangeAction(410, true);
			attacking = true;
		}

		//chute forte grudado
		else if ((toRight && x - *opponentX >= -150 && CheckChangingTo430Action()) ||
			(!toRight && x - *opponentX <= 150 && CheckChangingTo430Action()))
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(430, false);
		}

		//chute forte
		else if (CheckChangingTo330Action())
		{
			lastAction = action;
			capturedTime = clock();
			ChangeAction(330, false);
		}
	}
	return;
}

/**
*	procedimento responsavel por fazer o processamento de todos os golpes terminados mais de um botão
*/
void Terry::CheckSpecial()
{
	
	//rolamento
	if (
		inputs->GetPlayerInputs(player, 4) &&	//soco fraco
		!inputs->GetPlayerInputs(player, 5)  &&	//soco forte
		inputs->GetPlayerInputs(player, 6) &&	//chute fraco
		!inputs->GetPlayerInputs(player, 7)		//chute forte
		)
	{
		//rolamento frontal
		if (CheckChangingTo140Action())
		{
			if (toRight && !inputs->GetPlayerInputs(player, 0))
			{
				capturedTime = clock();
				ChangeAction(140, false);
			}
			else if (!toRight && !inputs->GetPlayerInputs(player, 2))
			{
				capturedTime = clock();
				ChangeAction(140, false);
			}

		}
		else if (CheckChangingTo150Action())
		{
			if (toRight && inputs->GetPlayerInputs(player, 0))
			{
				capturedTime = clock();
				ChangeAction(150, false);
			}
			else if (!toRight && inputs->GetPlayerInputs(player, 2))
			{
				capturedTime = clock();
				ChangeAction(150, false);
			}
		}
	}

	//Special Attack
	if (
		!inputs->GetPlayerInputs(player, 4) &&	//soco fraco
		inputs->GetPlayerInputs(player, 5) &&	//soco forte
		!inputs->GetPlayerInputs(player, 6) &&	//chute fraco
		inputs->GetPlayerInputs(player, 7)		//chute forte
		
		)
	{

		if (y < FLOOR && CheckChangingTo450Action())
		{
			ChangeAction(450, true);
			attacking = true;
		}

		else if (CheckChangingTo440Action())
		{
			ChangeAction(440, true);
			attacking = true;
		}
		
	}

	// estourar barra
	if (
		!inputs->GetPlayerInputs(player, 4) &&	//soco fraco
		inputs->GetPlayerInputs(player, 5) &&	//soco forte
		inputs->GetPlayerInputs(player, 6) &&	//chute fraco
		!inputs->GetPlayerInputs(player, 7)	&&	//chute forte
		specialQuantity > 0 && !pow 
		)
	{
		specialQuantity--;
		pow = true;
		powTime = *gameTime;
	}

	return;
}

/**
*	procedimento que faz a verificação do golpe Power Wave
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckPowerWave()
{
	if (toRight)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 2, MAS))
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 0, MAS))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Round Wave
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckRoundWave()
{
	if (toRight)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 2, MAS))
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 0, MAS))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Crack Shoot fraco
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckWeakCrackShoot()
{
	if (toRight)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 0, MAS))
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 2, MAS))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Crack Shoot forte
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckStrongCrackShoot()
{
	if (toRight)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 0, MAS))
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 2, MAS))
				{
					return true;
				}
			}
		}
	}

	return false;
}

/**
*	procedimento que faz a verificação do golpe Power Dunk fraco
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckWeakPowerDunk()
{
	if (toRight)
	{
		if (//C/Dd[9]-2D[9]
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
			)
		{
			if (//2D[9]-1D[9]
				inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) < BTP
				)
			{
				if (//1D[9]-2U[9] || 2U[8]
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) > 0 &&
						inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) < BTP)
					||
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) > 0 &&
						inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) < BTP)
					)
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (//C/Dd[9]-2D[9]
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
			)
		{
			if (//2D[9]-1D[9]
				inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) < BTP
				)
			{
				if (//1D[9]-2U[9] || 2U[8]
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) > 0 &&
					inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) < BTP)
					||
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) > 0 &&
					inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) < BTP)
					)
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Power Dunk forte
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckStrongPowerDunk()
{
	if (toRight)
	{
		if (//C/Dd[9]-2D[9]
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
			)
		{
			if (//2D[9]-1D[9]
				inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) < BTP
				)
			{
				if (//1D[9]-2U[9] || 2U[8]
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) > 0 &&
						inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) < BTP)
					||
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) > 0 &&
						inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) < BTP)
					)
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (//C/Dd[9]-2D[9]
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
			)
		{
			if (//2D[9]-1D[9]
				inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) < BTP
				)
			{
				if (//1D[9]-2U[9] || 2U[8]
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) > 0 &&
						inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) < BTP)
					||
					(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) > 0 &&
						inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) < BTP)
					)
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Burnig Knuckle fraco
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckWeakBurnigKnuckle()
{
	if (toRight)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 0, MAS))
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 2, MAS))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Burnig Knuckle forte
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckStrongBurnigKnuckle()
{
	if (toRight)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 0, MAS))
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (inputs->GetPlayerBtDownImputs(player, 1, MAS) < inputs->GetPlayerBtDownImputs(player, 2, MAS))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Rising Tackle fraco
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckWeakRisingTackle()
{
	if (
		inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtDownImputs(player, 3, MAS) > -45 &&
		inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtDownImputs(player, 3, MAS) < BTP
		)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 3, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 3, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > BTP)
			{
				return true;
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Rising Tackle forte
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckStrongRisingTackle()
{
	if (
		inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtDownImputs(player, 3, MAS) > -45 &&
		inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtDownImputs(player, 3, MAS) < BTP
		)
	{
		if (
			inputs->GetPlayerBtDownImputs(player, 3, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > -45 &&
			inputs->GetPlayerBtDownImputs(player, 3, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP
			)
		{
			if (inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > BTP)
			{
				return true;
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Power Geyser
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckPowerGeyser()
{
	if (toRight)
	{
		if ( //AD[9]-1U[9] ou BD[9]-1U[9]
			(inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP)
			||
			(inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP)
			)
		{
			if ( //1U[9]-2D[9]
				(inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP)
				||
				(inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) < BTP)
				)
			{
				if (//1D[9]-1U[8]
					(inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
					inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP)
					||
					(inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
					inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP)
					)
				{
					if (//1U[8]-0D[9]
						inputs->GetPlayerBtDownImputs(player, 0, MAS - 1) < inputs->GetPlayerBtDownImputs(player, 1, MAS) ||
						inputs->GetPlayerBtDownImputs(player, 0, MAS - 1) < inputs->GetPlayerBtDownImputs(player, 1, MAS - 1)
						)
					{
						return true;
					}
				}
			}
		}
	}
	else
	{
		if ( //AD[9]-1U[9] ou BD[9]-1U[9]
			(inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
			inputs->GetPlayerBtDownImputs(player, 4, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP)
			||
			(inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
			inputs->GetPlayerBtDownImputs(player, 5, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP)
			)
		{
			if ( //1U[9]-2D[9]
				(inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP)
				||
				(inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) < BTP)
				)
			{
				if (//1D[9]-1U[8]
					(inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
					inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP)
					||
					(inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
					inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP)
					)
				{
					if (//1U[8]-0D[9]
						inputs->GetPlayerBtDownImputs(player, 2, MAS - 1) < inputs->GetPlayerBtDownImputs(player, 1, MAS) ||
						inputs->GetPlayerBtDownImputs(player, 2, MAS - 1) < inputs->GetPlayerBtDownImputs(player, 1, MAS - 1)
						)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

/**
*	procedimento que faz a verificação do golpe Buster Wolf
*	retornando true se a sequencia de inputs estiver certa
*	retornando false se a sequencia de inputs estiver errada
*/
bool Terry::CheckBusterWolf()
{
	if (toRight)
	{
		if (//CD[9]-1U[9]
			(inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP)
			||
			(inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP)
			)
		{
			if (//1U[9]-2D[9]
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 2, MAS) < BTP
				)
			{
				if (//2D[9]-1D[9]
					inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > 0 &&
					inputs->GetPlayerBtDownImputs(player, 2, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) < BTP
					)
				{
					if (//1D[9]-2U[9] ou 1D[9]-2U[8]     2*BTP
						(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) > 0 &&
							inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS) < 2 * BTP)
						||
						(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) > 0 &&
							inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) < 2 * BTP)
						)
					{
						if (//2U[9]-1U[8] ou 2U[8] - 1U[8]    2*BTP
							(inputs->GetPlayerBtUpImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) > 0 &&
								inputs->GetPlayerBtUpImputs(player, 2, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) < 2 * BTP)
							||
							(inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) > 0 &&
								inputs->GetPlayerBtUpImputs(player, 2, MAS - 1) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) < 2 * BTP)
							)
						{
							if (//1U[8]-2D[8]
								inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 2, MAS - 1) > 0 &&
								inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 2, MAS - 1) < BTP
								)
							{
								if (//2D[8]-1D[8]
									inputs->GetPlayerBtDownImputs(player, 2, MAS - 1) > inputs->GetPlayerBtDownImputs(player, 1, MAS - 1)
									)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (//CD[9]-1U[9]
			(inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 6, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP)
			||
			(inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) > 0 &&
				inputs->GetPlayerBtDownImputs(player, 7, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS) < BTP)
			)
		{
			if (//1U[9]-2D[9]
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) > 0 &&
				inputs->GetPlayerBtUpImputs(player, 1, MAS) - inputs->GetPlayerBtDownImputs(player, 0, MAS) < BTP
				)
			{
				if (//2D[9]-1D[9]
					inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) > 0 &&
					inputs->GetPlayerBtDownImputs(player, 0, MAS) - inputs->GetPlayerBtDownImputs(player, 1, MAS) < BTP
					)
				{
					if (//1D[9]-2U[9] ou 1D[9]-2U[8]     2*BTP
						(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) > 0 &&
							inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS) < 2 * BTP)
						||
						(inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) > 0 &&
							inputs->GetPlayerBtDownImputs(player, 1, MAS) - inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) < 2 * BTP)
						)
					{
						if (//2U[9]-1U[8] ou 2U[8] - 1U[8]    2*BTP
							(inputs->GetPlayerBtUpImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) > 0 &&
								inputs->GetPlayerBtUpImputs(player, 0, MAS) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) < 2 * BTP)
							||
							(inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) > 0 &&
								inputs->GetPlayerBtUpImputs(player, 0, MAS - 1) - inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) < 2 * BTP)
							)
						{
							if (//1U[8]-2D[8]
								inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 0, MAS - 1) > 0 &&
								inputs->GetPlayerBtUpImputs(player, 1, MAS - 1) - inputs->GetPlayerBtDownImputs(player, 0, MAS - 1) < BTP
								)
							{
								if (//2D[8]-1D[8]
									inputs->GetPlayerBtDownImputs(player, 0, MAS - 1) > inputs->GetPlayerBtDownImputs(player, 1, MAS - 1)
									)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}
