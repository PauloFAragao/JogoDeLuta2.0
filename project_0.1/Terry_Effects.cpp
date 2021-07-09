#include "includes.h"
#include "Terry.h"


/**
*
*/
void Terry::PowerWaveEffect()
{


	if (!*gamePause) effectX += effectSpeedX;

	if (
		(effectX < X1POS && effectFrame < 12)
		||
		(effectX > X4POS + 75 && effectFrame < 12)
		)
	{
		effectSpeedX = 0;
		effectFrame = 12;
	}

	if (effectFrame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 299, 5512, 83, 86, effectX, FLOOR + 131, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 299, 5512, 83, 86, effectX, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 383, 5512, 82, 86, effectX, FLOOR + 131, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 383, 5512, 82, 86, effectX, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 466, 5513, 83, 85, effectX, FLOOR + +132, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 466, 5513, 83, 85, effectX, FLOOR + +132, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 550, 5512, 82, 86, effectX, FLOOR + 131, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 550, 5512, 82, 86, effectX, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 633, 5512, 76, 86, effectX + 3, FLOOR + 131, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 633, 5512, 76, 86, effectX + 3, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 710, 5512, 75, 85, effectX + 3, FLOOR + 131, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 710, 5512, 75, 85, effectX + 3, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 299, 5512, 83, 86, effectX, FLOOR + 131, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 299, 5512, 83, 86, effectX, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 383, 5512, 82, 86, effectX, FLOOR + 131, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 383, 5512, 82, 86, effectX, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 466, 5513, 83, 85, effectX, FLOOR + 132, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 466, 5513, 83, 85, effectX, FLOOR + 132, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 550, 5512, 82, 86, effectX, FLOOR + 131, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 550, 5512, 82, 86, effectX, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 633, 5512, 76, 86, effectX + 3, FLOOR + 131, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 633, 5512, 76, 86, effectX + 3, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 710, 5512, 75, 85, effectX + 3, FLOOR + 131, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 710, 5512, 75, 85, effectX + 3, FLOOR + 131, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 12)
	{
		effectSpeedX = 0;
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5519, 60, 79, effectX + 7, FLOOR + 138, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5519, 60, 79, effectX + 7, FLOOR + 138, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 13)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 61, 5493, 65, 106, effectX + 15, FLOOR + 111, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 61, 5493, 65, 106, effectX + 15, FLOOR + 111, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 14)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 127, 5492, 54, 105, effectX + 22, FLOOR + 111, 0);//frame 10
		if (!toRight) al_draw_bitmap_region(basicSprites, 127, 5492, 54, 105, effectX + 22, FLOOR + 111, ALLEGRO_FLIP_HORIZONTAL);//frame 10
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 15)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 189, 5493, 54, 105, effectX + 18, FLOOR + 112, 0);//frame 11
		if (!toRight) al_draw_bitmap_region(basicSprites, 189, 5493, 54, 105, effectX + 18, FLOOR + 112, ALLEGRO_FLIP_HORIZONTAL);//frame 11
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 16)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 244, 5497, 54, 101, effectX + 3, FLOOR + 111, 0);//frame 12
		if (!toRight) al_draw_bitmap_region(basicSprites, 244, 5497, 54, 101, effectX + 3, FLOOR + 111, ALLEGRO_FLIP_HORIZONTAL);//frame 12

		//effectActive = false;
		powerWaveActive = false;
		attacking = false;

		return;
	}
}

/**
*
*/
void Terry::RoundWaveEffect()
{
	if (effectFrame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 359, 5872, 43, 50, effectX + 25, FLOOR + 165, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 359, 5872, 43, 50, effectX + 25, FLOOR + 165, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTimeForEffect > TBF-45) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 404, 5872, 49, 17, effectX + 23.5, FLOOR + 201, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 404, 5872, 49, 17, effectX + 23.5, FLOOR + 201, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 454, 5872, 60, 27, effectX + 18, FLOOR + 191, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 454, 5872, 60, 27, effectX + 18, FLOOR + 191, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 515, 5864, 85, 51, effectX + 9, FLOOR + 168, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 515, 5864, 85, 51, effectX + 9, FLOOR + 168, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 601, 5861, 125, 87, effectX, FLOOR + 135, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 601, 5861, 125, 87, effectX, FLOOR + 135, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 727, 5859, 133, 113, effectX - 12, FLOOR + 113, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 727, 5859, 133, 113, effectX - 12, FLOOR + 113, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 861, 5859, 137, 116, effectX - 16, FLOOR + 113, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 861, 5859, 137, 116, effectX - 16, FLOOR + 113, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 359, 5924, 137, 115, effectX - 16.5, FLOOR + 112.5, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 359, 5924, 137, 115, effectX - 16.5, FLOOR + 112.5, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 498, 5959, 134, 101, effectX - 16, FLOOR + 125, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 498, 5959, 134, 101, effectX - 16, FLOOR + 125, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 636, 5985, 135, 79, effectX - 15.5, FLOOR + 149, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 636, 5985, 135, 79, effectX - 15.5, FLOOR + 149, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 775, 5988, 135, 77, effectX - 15, FLOOR + 150.5, 0);//frame 10
		if (!toRight) al_draw_bitmap_region(basicSprites, 775, 5988, 135, 77, effectX - 15, FLOOR + 150.5, ALLEGRO_FLIP_HORIZONTAL);//frame 10
		if (!*gamePause && clock() - captureTimeForEffect > TBF) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 915, 5988, 81, 62, effectX + 38, FLOOR + 150, 0);//frame 11
		if (!toRight) al_draw_bitmap_region(basicSprites, 915, 5988, 81, 62, effectX + 38, FLOOR + 150, ALLEGRO_FLIP_HORIZONTAL);//frame 11
		
		//effectActive = false;
		roundWaveActive = false;
		attacking = false;

		return;
	}

	return;
}

/**
*	
*/
void Terry::PowerGeyserEffect()
{
	if (effectFrame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 7741, 30, 14, effectX, 545, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 7741, 30, 14, effectX, 545, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 31, 7741, 70, 92, effectX-3.5, 467, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 31, 7741, 70, 92, effectX-37, 467, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 102, 7741, 93, 122, effectX-10, 437, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 102, 7741, 93, 122, effectX-52.5, 437, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 196, 7741, 130, 177, effectX-23, 382, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 196, 7741, 130, 177, effectX-78, 382, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 327, 7741, 137, 183, effectX-30.5, 377, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 327, 7741, 137, 183, effectX-81, 377, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 465, 7741, 151, 187, effectX-44, 374.5, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 465, 7741, 151, 187, effectX-83, 374.5, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 617, 7741, 153, 191, effectX-47.5, 372, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 617, 7741, 153, 191, effectX-80, 372, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 771, 7741, 150, 179, effectX-48, 384, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 771, 7741, 150, 179, effectX-74.5, 384, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 922, 7741, 133, 171, effectX-36, 393, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 922, 7741, 133, 171, effectX-70.5, 393, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1056, 7741, 136, 166, effectX-42.5, 400.5, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1056, 7741, 136, 166, effectX-65, 400.5, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1193, 7741, 136, 167, effectX-47, 402, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1193, 7741, 136, 167, effectX-60, 402, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1330, 7741, 136, 165, effectX-50.5, 406, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1330, 7741, 136, 165, effectX-57, 406, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 12)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1467, 7741, 135, 164, effectX-52, 408, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1467, 7741, 135, 164, effectX-55.5, 408, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 20) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 13)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1603, 7741, 130, 163, effectX-48, 412, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1603, 7741, 130, 163, effectX-55.5, 412, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 35) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 14)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1734, 7741, 129, 158, effectX-45.5, 411, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1734, 7741, 129, 158, effectX-55.5, 411, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 35) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 15)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1864, 7741, 87, 67, effectX-46.5, 495, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1864, 7741, 87, 67, effectX-11-5, 495, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 45) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 16)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1952, 7741, 44, 52, effectX-7.5, 507, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1952, 7741, 44, 52, effectX-4, 507, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 45) { effectFrame++; captureTimeForEffect = clock(); }
		return;
	}
	if (effectFrame == 17)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 2010, 7741, 26, 41, effectX+4, 518, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 2010, 7741, 26, 41, effectX+1.5, 518, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && clock() - captureTimeForEffect > TBF - 45)
		{
			powerGeyserActive = false;
			attacking = false;
		}
		return;
	}
	return;
}


/**
*
*/
void Terry::EspecialEffect()
{
	if (especialEffectFrame == 0)
	{
		al_draw_bitmap_region(effects, 0, 0, 201, 231, especialEffectX, especialEffectY, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}
	if (especialEffectFrame == 1)
	{
		al_draw_bitmap_region(effects, 208, 0, 168, 194, especialEffectX+40, especialEffectY+16, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}
	if (especialEffectFrame == 2)
	{
		al_draw_bitmap_region(effects, 392, 0, 171, 217, especialEffectX+38, especialEffectY-3, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}
	if (especialEffectFrame == 3)
	{
		al_draw_bitmap_region(effects, 564, 0, 146, 145, especialEffectX+31, especialEffectY+39, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}
	if (especialEffectFrame == 4)
	{
		al_draw_bitmap_region(effects, 720, 0, 152, 154, especialEffectX+25, especialEffectY+35, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}
	if (especialEffectFrame == 5)
	{
		al_draw_bitmap_region(effects, 880, 0, 142, 139, especialEffectX+28, especialEffectY+40, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}	
	if (especialEffectFrame == 6)
	{
		al_draw_bitmap_region(effects, 0, 236, 145, 135, especialEffectX+28, especialEffectY+42, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) { especialEffectFrame++; cte = clock(); }
		return;
	}
	if (especialEffectFrame == 7)
	{
		al_draw_bitmap_region(effects, 153, 236, 123, 138, especialEffectX+25, especialEffectY+39, 0);//frame 
		if (!*gamePause && clock() - cte > TBF - 20) especialEffectActive = false;
		return;
	}
	return;
}


/**
*
*/
void Terry::HitEffect()
{
	return;
}

/*void Terry::CharacterSpecialAnim()
{
	if (characterFrame == 0)
	{
		al_draw_bitmap_region(specialAnim, 0, 0, 1140, 6, 0, 300, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 1)
	{
		al_draw_bitmap_region(specialAnim, 0, 7, 1140, 105, 0, 259, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 2)
	{
		al_draw_bitmap_region(specialAnim, 0, 113, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 3)
	{
		al_draw_bitmap_region(specialAnim, 0, 299, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 4)
	{
		al_draw_bitmap_region(specialAnim, 0, 485, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 5)
	{
		al_draw_bitmap_region(specialAnim, 0, 671, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 6)
	{
		al_draw_bitmap_region(specialAnim, 0, 857, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 7)
	{
		al_draw_bitmap_region(specialAnim, 0, 1043, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 8)
	{
		al_draw_bitmap_region(specialAnim, 0, 1229, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 9)
	{
		al_draw_bitmap_region(specialAnim, 0, 1415, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 10)
	{
		al_draw_bitmap_region(specialAnim, 0, 1601, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 11)
	{
		al_draw_bitmap_region(specialAnim, 0, 1787, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 12)
	{
		al_draw_bitmap_region(specialAnim, 0, 1973, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 13)
	{
		al_draw_bitmap_region(specialAnim, 0, 2159, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 14)
	{
		al_draw_bitmap_region(specialAnim, 0, 2345, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 15)
	{
		al_draw_bitmap_region(specialAnim, 0, 2531, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 16)
	{
		al_draw_bitmap_region(specialAnim, 0, 2717, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 17)
	{
		al_draw_bitmap_region(specialAnim, 0, 2903, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 18)
	{
		al_draw_bitmap_region(specialAnim, 0, 3089, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 19)
	{
		al_draw_bitmap_region(specialAnim, 0, 3275, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 20)
	{
		al_draw_bitmap_region(specialAnim, 0, 3461, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 21)
	{
		al_draw_bitmap_region(specialAnim, 0, 3647, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 22)
	{
		al_draw_bitmap_region(specialAnim, 0, 3833, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 23)
	{
		al_draw_bitmap_region(specialAnim, 0, 4019, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 24)
	{
		al_draw_bitmap_region(specialAnim, 0, 4205, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 25)
	{
		al_draw_bitmap_region(specialAnim, 0, 4391, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 26)
	{
		al_draw_bitmap_region(specialAnim, 0, 4577, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 27)
	{
		al_draw_bitmap_region(specialAnim, 0, 4763, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 28)
	{
		al_draw_bitmap_region(specialAnim, 0, 4949, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 29)
	{
		al_draw_bitmap_region(specialAnim, 0, 5135, 1140, 184, 0, 218, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 30)
	{
		al_draw_bitmap_region(specialAnim, 0, 5321, 1140, 105, 0, 259, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame++; cT = clock(); }
		return;
	}
	if (characterFrame == 31)
	{
		al_draw_bitmap_region(specialAnim, 0, 0, 1140, 6, 0, 300, 0);//frame 
		if (!*gamePause && clock() - cT > TBF) { characterFrame=0; cT = clock(); }
		return;
	}
	return;
}
*/