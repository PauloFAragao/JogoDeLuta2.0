#include "includes.h"
#include "Terry.h"

/**
* função que controla frame a frame a animação idle
*/
void Terry::Idle()//animação 00
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 0, 169, 217, x + 1, y, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 0, 169, 217, x - 1, y, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 170, 0, 171, 217, x, y, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 170, 0, 171, 217, x - 2, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 342, 0, 169, 216, x, y + 1, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 342, 0, 169, 216, x, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 512, 0, 169, 216, x, y + 1, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 512, 0, 169, 216, x, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 682, 0, 169, 216, x, y + 1, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 682, 0, 169, 216, x, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 852, 0, 169, 215, x, y + 2, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 852, 0, 169, 215, x, y + 2, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1022, 0, 169, 215, x, y + 2, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1022, 0, 169, 215, x, y + 2, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1192, 0, 169, 216, x, y + 1, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1192, 0, 169, 216, x, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 2218, 169, 217, x, y + 1, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 2218, 169, 217, x, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF) { frame = 0; captureTime = clock(); }
		return;
	}
}
/**
* função que controla frame a frame a animação Crouching
*/
void Terry::Crouching()//animação 01
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1362, 0, 174, 206, x + 1, y + 10, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1362, 0, 174, 206, x + 1, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1537, 0, 167, 176, x + 1 , y + 39, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1537, 0, 167, 176, x + 1 , y + 39, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Idle
*/
void Terry::CrouchedIdle()//animação 02
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1705, 0, 166, 158, x + 2.5, y + 56, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1705, 0, 166, 158, x + 2.5, y + 56, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1872, 0, 166, 159, x + 2.5, y + 55, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1872, 0, 166, 159, x + 2.5, y + 55, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 218, 166, 158, x + 2.5, y + 56, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 218, 166, 158, x + 2.5, y + 56, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 167, 218, 166, 157, x + 2.5, y + 57, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 167, 218, 166, 157, x + 2.5, y + 57, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 334, 218, 166, 157, x + 2.5, y + 57, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 334, 218, 166, 157, x + 2.5, y + 57, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 501, 218, 166, 158, x + 2.5, y + 56, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 501, 218, 166, 158, x + 2.5, y + 56, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame = 0; captureTime = clock(); }
		return;
	}
}
/**
* função que controla frame a frame a animação Raise Crouched
*/
void Terry::RaiseCrouched()//animação 03
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1537, 0, 167, 176, x + 1, y + 39, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1537, 0, 167, 176, x + 1, y + 39, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1362, 0, 174, 206, x + 1, y + 10, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1362, 0, 174, 206, x + 1, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		return;
	}
}
/**
* função que controla frame a frame a animação Walk
*/
void Terry::Walk()//animação 04
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 668, 218, 156, 231, x + 22.55, y - 15.25, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 668, 218, 156, 231, x + 22.55, y - 15.25, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 825, 218, 138, 231, x + 37.35, y - 14.95, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 825, 218, 138, 231, x + 37.35, y - 14.95, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 964, 218, 130, 236, x + 42.9, y - 19.95, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 964, 218, 130, 236, x + 42.9, y - 19.95, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1095, 218, 121, 252, x + 42.9, y - 35.95, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1095, 218, 121, 252, x + 42.9, y - 35.95, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1217, 218, 139, 251, x + 29.95, y - 34.95, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1217, 218, 139, 251, x + 29.95, y - 34.95, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1357, 218, 155, 238, x + 11.1, y - 21.95, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1357, 218, 155, 238, x + 11.1, y - 21.95, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1513, 218, 167, 213, x + 0.1, y + 3.05, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1513, 218, 167, 213, x + 0.1, y + 3.05, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1681, 218, 169, 211, x - 0.7, y + 5.05, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1681, 218, 169, 211, x - 0.7, y + 5.05, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1851, 218, 172, 244, x + 7.55, y - 8.1, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1851, 218, 172, 244, x + 7.55, y - 8.1, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF + 25) { frame = 0; captureTime = clock(); }
		return;
	}
}
/**
* função que controla frame a frame a animação Walk Back
*/
void Terry::WalkBack()//animação 05
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 471, 175, 221, x + 14, y - 5.1, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 471, 175, 221, x + 14, y - 5.1, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 176, 471, 172, 227, x + 12.2, y - 11.3, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 176, 471, 172, 227, x + 12.2, y - 11.3, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 349, 471, 147, 233, x + 10.8, y - 17.3, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 349, 471, 147, 233, x + 10.8, y - 17.3, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 497, 471, 108, 235, x + 7.55, y - 19.4, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 497, 471, 108, 235, x + 7.55, y - 19.4, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 606, 471, 101, 239, x + 29.15, y - 23.4, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 606, 471, 101, 239, x + 29.15, y - 23.4, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 708, 471, 108, 239, x + 22.15, y - 23.4, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 708, 471, 108, 239, x + 22.15, y - 23.4, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 817, 471, 125, 238, x + 16.7, y - 22.7, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 817, 471, 125, 238, x + 16.7, y - 22.7, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 943, 471, 157, 235, x, y - 19.35, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 943, 471, 157, 235, x, y - 19.35, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1101, 471, 162, 229, x + 2.8, y - 13.35, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1101, 471, 162, 229, x + 2.8, y - 13.35, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF) { frame = 0; captureTime = clock(); }
		return;
	}

}
/**
* função que controla frame a frame a animação Jump Rising
*/
void Terry::Jump_Rising()//animação 06
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1264, 471, 105, 307, x + 54, y - 90, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1264, 471, 105, 307, x + 54, y - 90, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		return;
	}
}
/**
* função que controla frame a frame a animação Jump End Of Climp
*/
void Terry::Jump_EndOfClimp()//animação 07
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1370, 471, 129, 256, x + 35, y - 65.75, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1370, 471, 129, 256, x + 35, y - 65.75, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1500, 471, 121, 232, x + 43.5, y - 94.05, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1500, 471, 121, 232, x + 43.5, y - 94.05, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		return;
	}
}
/**
* função que controla frame a frame a animação Jump Falling
*/
void Terry::Jump_Falling()//animação 08
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1622, 471, 126, 271, x + 43.45, y - 91.75, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1622, 471, 126, 271, x + 43.45, y - 91.75, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1749, 471, 133, 297, x + 40.2, y - 89.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1749, 471, 133, 297, x + 40.2, y - 89.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		return;
	}
}
/**
* função que controla frame a frame a animação Jump Fall
*/
void Terry::Jump_Fall()//animação 09
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1883, 471, 160, 250, x + 7.4, y - 33.2, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1883, 471, 160, 250, x + 7.4, y - 33.2, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 779, 169, 214, x - 3.05, y + 3, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 779, 169, 214, x - 3.05, y + 3, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 363, 779, 174, 206, x, y + 10.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 363, 779, 174, 206, x, y + 10.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 179, 779, 173, 209, x, y + 8, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 179, 779, 173, 209, x, y + 8, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		return;
	}
}
/**
* função que controla frame a frame a animação Frontal Diagonal Jump
*/
void Terry::FrontalDiagonalJump()//animação 10
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 548, 779, 164, 232, x + 26.65, y - 15.9, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 548, 779, 164, 232, x + 26.65, y - 15.9, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 722, 779, 218, 204, x, y, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 722, 779, 218, 204, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 951, 779, 212, 118, x + 10.2, y + 48.15, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 951, 779, 212, 118, x + 10.2, y + 48.15, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1174, 779, 110, 184, x + 52.2, y + 23.55, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1174, 779, 110, 184, x + 52.2, y + 23.55, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1295, 779, 117, 201, x + 42.6, y + 6.55, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1295, 779, 117, 201, x + 42.6, y + 6.55, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1423, 779, 172, 127, x, y + 40.95, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1423, 779, 172, 127, x, y + 40.95, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1606, 779, 233, 104, x - 30.75, y + 15.35, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1606, 779, 233, 104, x - 30.75, y + 15.35, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1850, 779, 189, 209, x - 6.65, y - 45.05, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1850, 779, 189, 209, x - 6.65, y - 45.05, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF + 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 1012, 134, 285, x + 12.8, y - 69.7, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 1012, 134, 285, x + 12.8, y - 69.7, ALLEGRO_FLIP_HORIZONTAL);//frame 8

		return;
	}
}
/**
* função que controla frame a frame a animação Back Diagonal Jump
*/
void Terry::BackDiagonalJump()//animação 11
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 135, 1012, 192, 223, x - 14.85, y - 11.85, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 135, 1012, 192, 223, x - 14.85, y - 11.85, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 328, 1012, 213, 111, x - 12.3, y + 26.35, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 328, 1012, 213, 111, x - 12.3, y + 26.35, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 542, 1012, 173, 118, x, y + 19.35, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 542, 1012, 173, 118, x, y + 19.35, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 716, 1012, 151, 159, x + 5.15, y + 3.6, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 716, 1012, 151, 159, x + 5.15, y + 3.6, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 868, 1012, 108, 168, x + 24.55, y + 8.2, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 868, 1012, 108, 168, x + 24.55, y + 8.2, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 977, 1012, 173, 150, x, y + 22.55, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 977, 1012, 173, 150, x, y + 22.55, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1151, 1012, 207, 139, x, y + 14.85, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1151, 1012, 207, 139, x, y + 14.85, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF + 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1359, 1012, 179, 227, x + 16.4, y - 15.35, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1359, 1012, 179, 227, x + 16.4, y - 15.35, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}

}
/**
* função que controla frame a frame a animação Rum
*/
void Terry::Rum()//animação 12
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1539, 1012, 198, 215, x, y + 0.35, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1539, 1012, 198, 215, x, y + 0.35, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1738, 1012, 203, 201, x - 3.5, y + 14.35, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1738, 1012, 203, 201, x - 3.5, y + 14.35, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 1298, 233, 196, x, y + 19.6, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 1298, 233, 196, x, y + 19.6, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 234, 1298, 255, 197, x, y + 18.9, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 234, 1298, 255, 197, x, y + 18.9, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 490, 1298, 206, 185, x, y + 30.8, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 490, 1298, 206, 185, x, y + 30.8, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 697, 1298, 201, 193, x, y + 22.75, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 697, 1298, 201, 193, x, y + 22.75, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 899, 1298, 222, 205, x, y + 10.85, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 899, 1298, 222, 205, x, y + 10.85, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1122, 1298, 252, 203, x, y + 12.25, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1122, 1298, 252, 203, x, y + 12.25, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1375, 1298, 206, 184, x, y + 31.15, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1375, 1298, 206, 184, x, y + 31.15, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF) { frame = 1; captureTime = clock(); }
		return;
	}
}
/**
* função que controla frame a frame a animação Slide
*/
void Terry::Slide()//animação 13
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1591, 1298, 201, 194, x, y + 22.4, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1591, 1298, 201, 194, x, y + 22.4, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1803, 1298, 194, 195, x, y + 21, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1803, 1298, 194, 195, x, y + 21, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 1504, 182, 201, x, y + 15.05, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 1504, 182, 201, x, y + 15.05, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 183, 1504, 175, 207, x, y + 8.75, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 183, 1504, 175, 207, x, y + 8.75, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		return;
	}
}
/**
* função que controla frame a frame a animação Jumping Back
*/
void Terry::JumpingBack()//animação 14
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 359, 1504, 121, 227, x, y - 11.2, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 359, 1504, 121, 227, x, y - 11.2, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 481, 1504, 150, 232, x, y - 16, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 481, 1504, 150, 232, x, y - 16, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 632, 1504, 143, 236, x, y - 20, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 632, 1504, 143, 236, x, y - 20, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}
}
/**
* função que controla frame a frame a animação JumpBack Fall
*/
void Terry::JumpBackFall()//animação 15
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 776, 1504, 169, 218, x, y - 2.4, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 776, 1504, 169, 218, x, y - 2.4, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 946, 1504, 166, 223, x, y - 7.6, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 946, 1504, 166, 223, x, y - 7.6, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		return;
	}
}
/**
* função que controla frame a frame a animação Defending
*/
void Terry::Defending()//animação 16
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1113, 1504, 169, 220, x - 2, y - 4, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1113, 1504, 169, 220, x - 2, y - 4, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1283, 1504, 169, 221, x - 0.8, y - 5.2, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1283, 1504, 169, 221, x - 0.8, y - 5.2, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1453, 1504, 169, 224, x - 1.6, y - 8, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1453, 1504, 169, 224, x - 1.6, y - 8, ALLEGRO_FLIP_HORIZONTAL);//frame 2

		return;
	}
}
/**
* função que controla frame a frame a animação Defence
*/
void Terry::Defence()//animação 17
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1623, 1504, 172, 230, x - 5.6, y - 14, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1623, 1504, 172, 230, x - 5.6, y - 14, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		return;
	}
}
/**
* função que controla frame a frame a animação Defence Taking Damage
*/
void Terry::DTakingDamage()//animação 18
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1623, 1504, 172, 230, x - 5.4, y - 13.7, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1623, 1504, 172, 230, x - 5.4, y - 13.7, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 6.25, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 6.25, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 22.25, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 22.25, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1623, 1504, 172, 230, x - 5.4, y - 13.7, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1623, 1504, 172, 230, x - 5.4, y - 13.7, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 6.25, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 6.25, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 22.25, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1796, 1504, 172, 228, x - 10.85, y - 22.25, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame = 0; captureTime = clock(); }
		return;
	}

}
/**
* função que controla frame a frame a animação Defence Exit
*/
void Terry::DefenceExit()//animação 19
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1453, 1504, 169, 224, x - 1.6, y - 8, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1453, 1504, 169, 224, x - 1.6, y - 8, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1283, 1504, 169, 221, x - 0.8, y - 5.2, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1283, 1504, 169, 221, x - 0.8, y - 5.2, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1113, 1504, 169, 220, x - 2, y - 4, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1113, 1504, 169, 220, x - 2, y - 4, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Defending
*/
void Terry::CrouchedDefending()//animação 20
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 1741, 167, 160, x, y + 54, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 1741, 167, 160, x, y + 54, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 168, 1741, 166, 161, x, y + 52.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 168, 1741, 166, 161, x, y + 52.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 335, 1741, 165, 162, x, y + 52, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 335, 1741, 165, 162, x, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}

}
/**
* função que controla frame a frame a animação Crouched Defence
*/
void Terry::CrouchedDefence()//animação 21
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 501, 1741, 165, 171, x + 0.8, y + 42.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 501, 1741, 165, 171, x + 0.8, y + 42.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Defence Taking Damage
*/
void Terry::CrouchedDTakingDamage()//animação 22
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 501, 1741, 165, 171, x, y + 45, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 501, 1741, 172, 171, x, y + 45, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 50, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 50, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 37.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 37.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 501, 1741, 165, 171, x, y + 45, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 501, 1741, 172, 171, x, y + 45, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 50, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 50, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 37.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 667, 1741, 172, 171, x - 12.9, y + 37.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame = 0; captureTime = clock(); }
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Defence Exit
*/
void Terry::CrouchedDefenceExit()//animação 23
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 335, 1741, 165, 162, x, y + 52, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 335, 1741, 165, 162, x, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 168, 1741, 166, 161, x, y + 52.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 168, 1741, 166, 161, x, y + 52.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 1741, 167, 160, x, y + 54, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 1741, 167, 160, x, y + 54, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}
}
/**
* função que controla frame a frame a animação Front Rolling
*/
void Terry::FrontRolling()//animação 24
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 850, 1741, 149, 258, x + 34.4, y - 42.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 850, 1741, 149, 258, x + 34.4, y - 42.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1010, 1741, 218, 204, x - 13.45, y - 7.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1010, 1741, 218, 204, x - 13.45, y - 7.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1239, 1741, 210, 170, x - 17.95, y + 45.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1239, 1741, 210, 170, x - 17.95, y + 45.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1470, 1741, 169, 232, x, y + 16.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1470, 1741, 169, 232, x, y + 16.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1670, 1741, 154, 241, x, y - 25.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1670, 1741, 154, 241, x, y - 25.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1845, 1741, 128, 201, x, y + 14.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1845, 1741, 128, 201, x, y + 14.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5

		return;
	}

}
/**
* função que controla frame a frame a animação Front Rolling End
*/
void Terry::FrontRollingEnd()//animação 25
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 2000, 202, 202, x - 15.35, y + 63, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 2000, 202, 202, x - 15.35, y + 63, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 203, 2000, 223, 116, x - 33.3, y + 105, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 203, 2000, 223, 116, x - 33.3, y + 105, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 427, 2000, 200, 134, x - 16.05, y + 93, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 427, 2000, 200, 134, x - 16.05, y + 93, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 628, 2000, 173, 149, x - 1.85, y + 69.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 628, 2000, 173, 149, x - 1.85, y + 69.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 802, 2000, 159, 152, x + 8.35, y + 59.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 802, 2000, 159, 152, x + 8.35, y + 59.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 962, 2000, 167, 176, x, y + 36, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 962, 2000, 167, 176, x, y + 36, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1130, 2000, 174, 206, x, y + 9, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1130, 2000, 174, 206, x, y + 9, ALLEGRO_FLIP_HORIZONTAL);//frame 6

		return;
	}

}
/**
* função que controla frame a frame a animação Back Rolling
*/
void Terry::BackRolling()//animação 26
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 850, 1741, 149, 258, x + 34.4, y - 42.55, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 850, 1741, 149, 258, x + 34.4, y - 42.55, 0);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1010, 1741, 218, 204, x - 13.45, y - 7.7, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1010, 1741, 218, 204, x - 13.45, y - 7.7, 0);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1239, 1741, 210, 170, x - 17.95, y + 45.45, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1239, 1741, 210, 170, x - 17.95, y + 45.45, 0);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1470, 1741, 169, 232, x, y + 16.55, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1470, 1741, 169, 232, x, y + 16.55, 0);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1670, 1741, 154, 241, x, y - 25.55, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1670, 1741, 154, 241, x, y - 25.55, 0);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1845, 1741, 128, 201, x, y + 14.45, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1845, 1741, 128, 201, x, y + 14.45, 0);//frame 5
		return;
	}
}
/**
* função que controla frame a frame a animação Back Rolling End
*/
void Terry::BackRollingEnd()//animação 26
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 2000, 202, 202, x - 15.35, y + 62.7, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 2000, 202, 202, x - 15.35, y + 62.7, 0);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 203, 2000, 223, 116, x - 33.3, y + 104.95, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 203, 2000, 223, 116, x - 33.3, y + 104.95, 0);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 427, 2000, 200, 134, x - 16.05, y + 92.8, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 427, 2000, 200, 134, x - 16.05, y + 92.8, 0);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 628, 2000, 173, 149, x - 1.85, y + 69.35, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 628, 2000, 173, 149, x - 1.85, y + 69.35, 0);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 802, 2000, 159, 152, x + 8.35, y + 59.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 802, 2000, 159, 152, x + 8.35, y + 59.5, 0);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1488, 2000, 165, 154, x + 1.3, y + 59.15, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1488, 2000, 165, 154, x + 1.3, y + 59.15, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 802, 2000, 159, 152, x + 8.35, y + 59.5, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 802, 2000, 159, 152, x + 8.35, y + 59.5, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 962, 2000, 167, 176, x, y + 36.15, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 962, 2000, 167, 176, x, y + 36.15, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1130, 2000, 174, 206, x, y + 8.95, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1130, 2000, 174, 206, x, y + 8.95, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		return;
	}
}
/**
* função que controla frame a frame a animação Change Side
*/
void Terry::ChangeSide()//animação 27
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1666, 2000, 165, 217, x, y + 2.4, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1666, 2000, 165, 217, x, y + 2.4, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1848, 2000, 163, 216, x, y - 2.4, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1848, 2000, 163, 216, x, y - 2.4, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1666, 2000, 165, 217, x, y + 2.4, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1666, 2000, 165, 217, x, y + 2.4, 0);//frame 2
		return;
	}
}
/**
* função que controla frame a frame a animação Change Side Crouched 
*/
void Terry::ChangeSideCrouched()//animação 28
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1305, 2000, 166, 155, x + 1.95, y + 58.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1305, 2000, 166, 155, x + 1.95, y + 58.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1488, 2000, 165, 154, x + 1.3, y + 59.15, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1488, 2000, 165, 154, x + 1.3, y + 59.15, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight) al_draw_bitmap_region(basicSprites, 1305, 2000, 166, 155, x + 1.95, y + 58.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!toRight)  al_draw_bitmap_region(basicSprites, 1305, 2000, 166, 155, x + 1.95, y + 58.5, 0);//frame 2
		return;
	}
}



/**
* função que controla frame a frame a animação Weak Punch
*/
void Terry::WeakPunch()//animação 30
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 170, 2218, 170, 214, x + 1.5, y + 3.25, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 170, 2218, 170, 214, x - 2.5, y + 3.25, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 341, 2218, 185, 214, x + 0.5, y + 3.25, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 341, 2218, 185, 214, x - 17.15, y + 3.25, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 527, 2218, 241, 212, x + 1.8, y + 6.25, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 527, 2218, 241, 212, x - 74, y + 6.25, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 769, 2218, 234, 211, x + 1.8, y + 7.25, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 769, 2218, 234, 211, x - 67, y + 7.25, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1004, 2218, 203, 212, x + 1.65, y + 5.25, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1004, 2218, 203, 212, x - 35.6, y + 5.25, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1208, 2218, 174, 212, x + 1.65, y + 5.25, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1208, 2218, 174, 212, x - 7, y + 5.25, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		return;
	}
}
/**
* função que controla frame a frame a animação Strong Punch
*/
void Terry::StrongPunch()//animação 31
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 2671, 175, 221, x - 2.9, y - 4, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 2671, 175, 221, x - 2.85, y - 4, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 176, 2671, 183, 219, x - 7.8, y - 2, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 176, 2671, 183, 219, x - 6.35, y - 2, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 360, 2671, 288, 213, x - 6.05, y + 4, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 360, 2671, 288, 213, x - 113.35, y + 4, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 649, 2671, 286, 216, x - 8.85, y + 1.75, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 649, 2671, 286, 216, x - 108.40, y + 1.75, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 936, 2671, 282, 214, x - 9.75, y + 3, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 936, 2671, 282, 214, x - 103.2, y + 3, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1219, 2671, 259, 219, x - 11.95, y - 1, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1219, 2671, 259, 219, x - 77.70, y - 1, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1479, 2671, 206, 218, x - 10, y, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1479, 2671, 206, 218, x - 27, y, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1686, 2671, 174, 216, x - 1.5, y + 1, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1686, 2671, 174, 216, x - 4.45, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Weak Kick
*/
void Terry::WeakKick()//animação 32
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1529, 2893, 168, 220, x + 1, y - 4, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1529, 2893, 168, 220, x + 1.5, y - 4, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1712, 2893, 167, 229, x + 2, y - 11.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1712, 2893, 167, 229, x + 0.5, y - 11.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1901, 2893, 141, 236, x + 35.5, y - 22.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1901, 2893, 141, 236, x - 7.5, y - 22.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 3129, 249, 238, x + 27.5, y - 25, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 3129, 249, 238, x - 108, y - 25, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 250, 3129, 225, 242, x + 53, y - 30, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 250, 3129, 225, 242, x - 109, y - 30, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 486, 3129, 152, 241, x + 55, y - 29, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 486, 3129, 152, 241, x - 38.5, y - 29, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 639, 3129, 115, 224, x + 52, y - 12, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 639, 3129, 115, 224, x + 2, y - 12, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 795, 3129, 148, 222, x + 20, y - 8, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 795, 3129, 148, 222, x + 1.5, y - 8, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 964, 3129, 168, 222, x - 0.5, y - 5, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 964, 3129, 168, 222, x + 1.5, y - 5, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Strong Kick Start
*/
void Terry::StrongKickStart()//animação 33
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1153, 3129, 146, 228, x - 13.5, y - 11, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1153, 3129, 146, 228, x + 35, y - 11, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1335, 3129, 116, 227, x - 31.5, y - 15.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1335, 3129, 116, 227, x + 84.5, y - 15.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1484, 3129, 124, 228, x - 55, y - 21, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1484, 3129, 124, 228, x + 98.5, y - 21, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1651, 3129, 119, 212, x - 35, y - 5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1651, 3129, 119, 212, x + 84, y - 5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		return;
	}
}
/**
* função que controla frame a frame a animação Strong Kick
*/
void Terry::StrongKick()//animação 34
{

	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1788, 3129, 258, 235, x - 43, y - 26.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1788, 3129, 258, 235, x - 49.5, y - 26.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 3372, 243, 241, x - 38, y - 32, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 3372, 243, 241, x - 40, y - 32, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 248, 3372, 182, 222, x - 20, y - 11, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 248, 3372, 182, 222, x + 6, y - 11, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}

}
/**
* função que controla frame a frame a animação Strong Kick End
*/
void Terry::StrongKickEnd()//animação 35
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 434, 3372, 160, 206, x - 13, y + 5.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 434, 3372, 160, 206, x + 23, y + 5.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 597, 3372, 155, 202, x, y + 14, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 597, 3372, 155, 202, x + 13, y + 14, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 761, 3372, 157, 218, x, y - 2, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 761, 3372, 157, 218, x + 11, y - 2, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Weak Punch
*/
void Terry::CrouchedWeakPunch()//animação 36
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 845, 4692, 176, 162, x - 1.5, y + 53, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 845, 4692, 176, 162, x - 7.5, y + 53, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1028, 4692, 167, 164, x - 1.5, y + 51, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1028, 4692, 167, 164, x + 0.5, y + 51, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1203, 4692, 228, 163, x - 0.5, y + 52, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1203, 4692, 228, 163, x - 60, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1437, 4692, 227, 163, x - 1, y + 52, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1437, 4692, 227, 163, x - 59.5, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1680, 4692, 186, 163, x - 1.5, y + 52, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1680, 4692, 186, 163, x - 18.5, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 10) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1879, 4692, 167, 158, x - 0.5, y + 56, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1879, 4692, 167, 158, x - 0.5, y + 56, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Strong Punch
*/
void Terry::CrouchedStrongPunch()//animação 37
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 4955, 174, 172, x - 2, y + 43, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 4955, 174, 172, x - 6.5, y + 43, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 195, 4955, 178, 174, x - 7, y + 40, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 195, 4955, 178, 174, x - 5, y + 40, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 384, 4955, 189, 170, x - 10, y + 44, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 384, 4955, 189, 170, x - 13.5, y + 44, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 584, 4955, 269, 163, x - 7, y + 52, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 584, 4955, 269, 163, x - 96.5, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 860, 4955, 267, 166, x - 6.5, y + 49, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 860, 4955, 267, 166, x - 95.5, y + 49, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1132, 4955, 206, 166, x - 4, y + 50.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1132, 4955, 206, 166, x - 37.5, y + 50.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1349, 4955, 164, 162, x - 0.5, y + 53.5, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1349, 4955, 164, 162, x, y + 53.5, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1524, 4955, 165, 161, x + 0.5, y + 54, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1524, 4955, 165, 161, x, y + 54, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Weak Kick
*/
void Terry::CrouchedWeakKick()//animação 38
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1701, 4955, 167, 158, x, y + 56, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1701, 4955, 167, 158, x - 0.5, y + 56, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1883, 4955, 165, 161, x + 1, y + 53, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1883, 4955, 165, 161, x + 0.5, y + 53, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5130, 232, 161, x + 1.5, y + 52, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5130, 232, 161, x - 67.5, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 233, 5130, 230, 163, x + 1.5, y + 50, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 233, 5130, 230, 163, x - 65, y + 50, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 464, 5130, 186, 163, x, y + 50, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 464, 5130, 186, 163, x - 20, y + 50, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 651, 5130, 175, 160, x - 0.5, y + 54, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 651, 5130, 175, 160, x - 8.5, y + 54, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 827, 5130, 167, 159, x, y + 54, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 827, 5130, 167, 159, x - 0.5, y + 54, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		return;
	}
}
/**
* função que controla frame a frame a animação Crouched Strong Kick
*/
void Terry::CrouchedStrongKick()//animação 39
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 995, 5130, 169, 165, x + 3, y + 49, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 995, 5130, 169, 165, x - 3, y + 49, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1165, 5130, 143, 159, x + 44.5, y + 55, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1165, 5130, 143, 159, x - 21, y + 55, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1309, 5130, 157, 153, x + 56, y + 62, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1309, 5130, 157, 153, x - 46.5, y + 62, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1467, 5130, 284, 171, x + 39, y + 43, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1467, 5130, 284, 171, x - 155, y + 43, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1752, 5130, 283, 163, x + 46, y + 52, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1752, 5130, 283, 163, x - 160.5, y + 52, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5302, 214, 148, x + 51, y + 67, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5302, 214, 148, x - 93, y + 67, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 215, 5302, 120, 158, x + 45.5, y + 58.5, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 215, 5302, 120, 158, x, y + 58.5, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 336, 5302, 152, 158, x + 14, y + 57, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 336, 5302, 152, 158, x, y + 57, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 489, 5302, 167, 158, x + 1, y + 56, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 489, 5302, 167, 158, x, y + 56, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		return;
	}
}
/**
* função que controla frame a frame a animação Jumping Weak Punch
*/
void Terry::JumpingWeakPunch()//animação 40
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 390, 3870, 109, 265, x + 50, y - 79.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 390, 3870, 109, 265, x + 52.5, y - 79.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 516, 3870, 112, 296, x + 47.5, y - 94, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 516, 3870, 122, 296, x + 52, y - 94, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 638, 3870, 152, 239, x + 37.5, y - 20.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 638, 3870, 152, 239, x, y - 20.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 800, 3870, 152, 245, x + 26.5, y - 20.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 800, 3870, 152, 245, x + 25.5, y - 20.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 974, 3870, 139, 246, x + 43, y - 27.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 974, 3870, 139, 246, x + 26.5, y - 27.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1114, 3870, 122, 249, x + 46.5, y - 61, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1114, 3870, 122, 249, x + 41, y - 61, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		return;
	}
}
/**
* função que controla frame a frame a animação Jumping Strong Punch
*/
void Terry::JumpingStrongPunch()//animação 41
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1237, 3870, 130, 244, x + 29, y - 47.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1237, 3870, 130, 244, x + 54, y - 47.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1368, 3870, 127, 250, x + 28.5, y - 48, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1368, 3870, 127, 250, x + 55.5, y - 48, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1496, 3870, 134, 235, x + 24.5, y - 42.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1496, 3870, 134, 235, x + 54, y - 42.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1631, 3870, 208, 177, x + 20.5, y - 30.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1631, 3870, 208, 177, x - 15.5, y - 30.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1840, 3870, 208, 180, x + 15.5, y - 29.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1840, 3870, 208, 180, x - 12.5, y - 29.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 4167, 164, 191, x + 33, y - 35.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 4167, 164, 191, x + 14.5, y - 35.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 165, 4167, 138, 211, x + 49, y - 45, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 165, 4167, 138, 211, x + 23.5, y - 45, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 306, 4167, 126, 268, x + 56, y - 70.5, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 306, 4167, 126, 268, x + 30, y - 70.5, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Jumping Weak Kick
*/
void Terry::JumpingWeakKick()//animação 42
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 437, 4167, 126, 222, x + 29, y - 49.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 437, 4167, 126, 222, x + 58, y - 49.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 566, 4167, 122, 245, x + 16, y - 54, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 566, 4167, 122, 245, x + 69.5, y - 54, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 692, 4167, 146, 239, x + 9, y - 42, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 692, 4167, 146, 239, x + 54, y - 42, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 847, 4167, 238, 211, x, y - 30, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 847, 4167, 238, 211, x - 28.5, y - 30, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1093, 4167, 233, 205, x, y - 30, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1093, 4167, 233, 205, x - 28.5, y - 30, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1332, 4167, 195, 197, x + 14.5, y - 28.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1332, 4167, 195, 197, x - 7, y - 28.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1528, 4167, 114, 203, x + 43.5, y - 25, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1528, 4167, 114, 203, x + 45.5, y - 25, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		return;
	}
}
/**
* função que controla frame a frame a animação Jumping Strong Kick
*/
void Terry::JumpingStrongKick()//animação 43
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1787, 4167, 101, 245, x + 3.5, y - 58.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1787, 4167, 101, 245, x + 108, y - 58.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1899, 4167, 149, 247, x + 28, y - 53, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1899, 4167, 149, 247, x + 34, y - 53, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 4436, 228, 185, x + 10.5, y - 49, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 4436, 228, 185, x - 27.5, y - 49, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 229, 4436, 229, 209, x + 5.5, y - 66.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 229, 4436, 229, 209, x - 22, y - 66.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 459, 4436, 210, 215, x + 11.5, y - 52.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 459, 4436, 210, 215, x - 11.5, y - 52.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 670, 4436, 164, 238, x + 31.5, y - 51, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 670, 4436, 164, 238, x + 15.5, y - 51, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 839, 4436, 136, 238, x + 46, y - 56, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 839, 4436, 136, 238, x + 31, y - 56, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Glued Strong Punch
*/
void Terry::GluedStrongPunch()//animação 44
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1861, 2671, 175, 213, x - 8.4, y + 5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1861, 2671, 175, 213, x + 1, y + 5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 2893, 213, 216, x - 13, y + 1, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 2893, 213, 216, x - 32, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 214, 2893, 247, 219, x - 8, y - 1, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 214, 2893, 247, 219, x - 71, y - 1, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 462, 2893, 236, 219, x - 9.5, y - 1, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 462, 2893, 236, 219, x - 59, y - 1, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 699, 2893, 205, 215, x - 13, y + 2, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 699, 2893, 205, 215, x - 25, y + 2, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 923, 2893, 189, 215, x - 11, y + 1, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 923, 2893, 189, 215, x - 8.5, y + 1, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1133, 2893, 172, 216, x - 6, y, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1133, 2893, 172, 216, x + 1.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1331, 2893, 178, 220, x - 3.5, y - 3, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1331, 2893, 178, 220, x - 7.5, y - 3, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Glued Strong Kick
*/
void Terry::GluedStrongKick()//animação 45
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 931, 3372, 141, 238, x + 37, y - 26, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 931, 3372, 141, 238, x - 9.5, y - 26, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1078, 3372, 254, 246, x + 10, y - 33, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1078, 3372, 254, 246, x - 96, y - 33, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1340, 3372, 233, 260, x + 11, y - 48, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1340, 3372, 233, 260, x - 76, y - 48, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1583, 3372, 245, 253, x + 4, y - 41, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1583, 3372, 245, 253, x - 81, y - 41, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1836, 3372, 204, 237, x + 23.5, y - 25, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1836, 3372, 204, 237, x - 60, y - 25, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 3633, 140, 231, x + 48.5, y - 19, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 3633, 140, 231, x - 21, y - 19, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 141, 3633, 155, 221, x + 16, y - 9, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 141, 3633, 155, 221, x - 3, y - 9, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		return;
	}
}
/**
* função que controla frame a frame a animação Special Attack Start
*/
void Terry::SpecialAttackStart()//animação 46
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 307, 3633, 115, 225, x - 59, y - 9, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 307, 3633, 115, 225, x + 110.5, y - 9, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 432, 3633, 183, 236, x - 17.5, y - 20, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 432, 3633, 183, 236, x + 2, y - 20, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 623, 3633, 192, 235, x, y - 18, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 623, 3633, 192, 235, x - 23, y - 18, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}

}
/**
* função que controla frame a frame a animação Special Attack
*/
void Terry::SpecialAttack()//animação 47
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 840, 3633, 220, 198, x - 1, y + 18.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 840, 3633, 220, 198, x - 51, y + 18.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1072, 3633, 243, 190, x, y + 27, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1072, 3633, 243, 190, x - 74.5, y + 27, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1318, 3633, 245, 191, x, y + 25, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1318, 3633, 245, 191, x - 76, y + 25, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1564, 3633, 249, 191, x - 0.5, y + 25.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1564, 3633, 249, 191, x - 81, y + 25.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1815, 3633, 218, 195, x - 1, y + 22.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1815, 3633, 218, 195, x - 49, y + 22.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		return;
	}
}
/**
* função que controla frame a frame a animação Special Attack End
*/
void Terry::SpecialAttackEnd()//animação 48
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 3870, 191, 205, x, y + 11, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 3870, 191, 205, x - 22.5, y + 11, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 194, 3870, 172, 209, x - 0.5, y + 8, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 194, 3870, 172, 209, x - 3.5, y + 8, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		return;
	}
}
/**
* função que controla frame a frame a animação Jumping Special Attack
*/
void Terry::JumpingSpecialAttack()//animação 49
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 980, 4436, 167, 245, x + 12.5, y - 59, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 980, 4436, 167, 245, x + 40, y - 59, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1148, 4436, 212, 227, x - 28.5, y - 47.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1148, 4436, 212, 227, x + 31, y - 47.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1365, 4436, 202, 198, x - 15.5, y - 30.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1365, 4436, 202, 198, x + 24, y - 30.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1582, 4436, 174, 255, x + 3, y - 50.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1582, 4436, 174, 255, x + 36.5, y - 50.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1775, 4436, 244, 255, x - 28, y - 74, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1775, 4436, 244, 255, x - 3, y - 74, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 4692, 242, 262, x - 23, y - 78.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 4692, 242, 262, x - 5, y - 78.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 251, 4692, 242, 253, x - 17, y - 69.5, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 251, 4692, 242, 253, x - 10, y - 69.5, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 497, 4692, 212, 241, x + 16.5, y - 61.5, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 497, 4692, 212, 241, x - 16, y - 61.5, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 711, 4692, 131, 249, x + 40.5, y - 72, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 711, 4692, 131, 249, x + 41.5, y - 72, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		return;
	}
}
/**
* função que controla frame a frame a animação Weak Punch Forward
*/
void Terry::WeakPunchForward()//animação 50
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1383, 2218, 164, 226, x + 2.75, y - 8, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1383, 2218, 164, 226, x + 0.65, y - 8, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1548, 2218, 133, 223, x + 56.7, y - 4, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1548, 2218, 133, 223, x - 25.95, y - 4, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1682, 2218, 136, 218, x + 88.85, y - 3, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1682, 2218, 136, 218, x - 61.25, y - 3, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1819, 2218, 192, 224, x + 134.7, y - 9.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1819, 2218, 192, 224, x - 158.50, y - 9.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 2445, 241, 224, x + 130.45, y - 6, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 2445, 241, 224, x - 202.10, y - 6, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 242, 2445, 239, 225, x + 131, y - 7.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 242, 2445, 239, 225, x - 201.05, y - 7.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 482, 2445, 190, 209, x + 129, y + 7, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 482, 2445, 190, 209, x - 150, y + 7, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 687, 2445, 189, 206, x + 129, y + 11, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 687, 2445, 189, 206, x - 149, y + 11, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 888, 2445, 187, 211, x + 124, y + 6, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 888, 2445, 187, 211, x - 142, y + 6, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1108, 2445, 106, 220, x + 125, y - 4, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 1108, 2445, 106, 220, x - 62, y - 4, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1253, 2445, 93, 219, x + 105, y - 1, 0);//frame 10
		if (!toRight) al_draw_bitmap_region(basicSprites, 1253, 2445, 93, 219, x - 30, y - 1, ALLEGRO_FLIP_HORIZONTAL);//frame 10
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1358, 2445, 126, 214, x + 52, y + 5, 0);//frame 11
		if (!toRight) al_draw_bitmap_region(basicSprites, 1358, 2445, 126, 214, x - 9.5, y + 5, ALLEGRO_FLIP_HORIZONTAL);//frame 11
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 12)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1491, 2445, 172, 208, x, y + 10, 0);//frame 12
		if (!toRight) al_draw_bitmap_region(basicSprites, 1491, 2445, 172, 208, x, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 12
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 13)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1677, 2445, 167, 212, x + 2, y + 6, 0);//frame 13
		if (!toRight) al_draw_bitmap_region(basicSprites, 1677, 2445, 167, 212, x, y + 6, ALLEGRO_FLIP_HORIZONTAL);//frame 13
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 14)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1858, 2445, 172, 215, x + 1, y + 3, 0);//frame 14
		if (!toRight) al_draw_bitmap_region(basicSprites, 1858, 2445, 172, 215, x - 5, y + 3, ALLEGRO_FLIP_HORIZONTAL);//frame 14
		return;
	}
}
/**
* função que controla frame a frame a animação Rising Upper
*/
void Terry::RisingUpper()//animação 51
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 697, 5302, 202, 199, x-4.5, y+19, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 697, 5302, 202, 199, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF-25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 911, 5302, 177, 210, x - 2, y + 8, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 911, 5302, 177, 210, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF-25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1120, 5302, 194, 210, x - 1, y + 3, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 911, 5302, 177, 210, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF-25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1327, 5302, 166, 303, x - 0.5, y - 86, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1327, 5302, 166, 303, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF-25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1512, 5302, 166, 299, x, y - 81, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1512, 5302, 166, 299, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1691, 5302, 168, 294, x - 2, y - 77, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1691, 5302, 168, 294, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1870, 5302, 168, 262, x - 2, y - 44, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1870, 5302, 168, 262, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5607, 168, 237, x - 2, y - 20, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5607, 168, 237, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 173, 5607, 168, 235, x - 2, y - 18, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 173, 5607, 168, 235, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		return;
	}
}

/**
* função que controla frame a frame a animação Power Wave
*/
void Terry::PowerWave()//animação 52
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 691, 5607, 194, 213, x - 7.5, y + 3.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 691, 5607, 194, 213, x - 18, y + 3.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 888, 5607, 239, 207, x - 11.5, y + 10, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 888, 5607, 239, 207, x - 59, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1130, 5607, 238, 200, x - 10, y + 18, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1130, 5607, 238, 200, x - 59, y + 18, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1371, 5607, 237, 196, x - 9.5, y + 22.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1371, 5607, 237, 196, x - 59, y + 22.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1611, 5607, 236, 192, x - 9, y + 25, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1611, 5607, 236, 192, x - 59, y + 25, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1850, 5607, 198, 189, x - 7, y + 27, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1850, 5607, 198, 189, x - 23, y + 27, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5872, 181, 197, x - 7, y + 19, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5872, 181, 197, x - 6, y + 19, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 182, 5872, 176, 210, x - 5, y + 7.5, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 182, 5872, 176, 210, x - 3, y + 7.5, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		return;
	}
}
/**
* função que controla frame a frame a animação Round Wave
*/
void Terry::RoundWave()//animação 53
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 343, 5607, 163, 264, x + 1, y - 48, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 343, 5607, 163, 264, x + 4.5, y - 48, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 508, 5607, 182, 251, x + 1.5, y - 34, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 508, 5607, 182, 251, x - 14, y - 34, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}

	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 691, 5607, 194, 213, x - 7.5, y + 3.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 691, 5607, 194, 213, x - 18, y + 3.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 888, 5607, 239, 207, x - 11.5, y + 10, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 888, 5607, 239, 207, x - 59, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1130, 5607, 238, 200, x - 10, y + 18, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1130, 5607, 238, 200, x - 59, y + 18, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1371, 5607, 237, 196, x - 9.5, y + 22.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1371, 5607, 237, 196, x - 59, y + 22.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1611, 5607, 236, 192, x - 9, y + 25, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1611, 5607, 236, 192, x - 59, y + 25, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1850, 5607, 198, 189, x - 7, y + 27, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1850, 5607, 198, 189, x - 23, y + 27, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5872, 181, 197, x - 7, y + 19, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5872, 181, 197, x - 6, y + 19, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 182, 5872, 176, 210, x - 5, y + 7.5, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 182, 5872, 176, 210, x - 3, y + 7.5, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		return;
	}
}
/**
* função que controla frame a frame a animação Crack Shoot
*/
void Terry::CrackShoot()//animação 54 - 56
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1000, 5846, 186, 182, x - 0.5, y + 34.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1000, 5846, 186, 182, x - 18.5, y + 34.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1188, 5846, 171, 193, x - 0.5, y + 25, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1188, 5846, 171, 193, x - 8.5, y + 25, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1361, 5846, 187, 208, x + 5, y + 6.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1361, 5846, 187, 208, x - 27, y + 6.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1550, 5846, 237, 216, x + 30, y - 5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1550, 5846, 237, 216, x - 99.5, y - 5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1789, 5846, 259, 225, x + 52, y - 13.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1789, 5846, 259, 225, x - 143, y - 13.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 6082, 214, 255, x + 44.5, y - 44, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 6082, 214, 255, x - 92.5, y - 44, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		return;
	}
}
/**
* função que controla frame a frame a animação Crack Shoot Jumping
*/
void Terry::CrackShootJumping()//animação 55 - 57
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 216, 6082, 131, 247, x + 3.5, y - 70, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 216, 6082, 131, 247, x + 39, y - 70, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF + 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 348, 6082, 178, 219, x - 1, y - 51.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 348, 6082, 178, 219, x - 8, y - 51.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF + 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 527, 6082, 234, 227, x - 8, y - 34.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 527, 6082, 234, 227, x - 46, y - 34.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF + 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 762, 6082, 223, 238, x - 8, y - 50, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 762, 6082, 223, 238, x - 44, y - 50, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF + 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 986, 6082, 151, 278, x - 2, y - 62, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 986, 6082, 151, 278, x + 15.5, y - 62, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		return;
	}
}

/**
* função que controla frame a frame a animação Power Dunk Start
*/
void Terry::PowerDunkStart()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 478, 7168, 165, 197, x + 37.5, y + 15, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 478, 7168, 165, 197, x - 34.5, y + 15, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 654, 7168, 180, 155, x + 11, y + 60, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 654, 7168, 180, 155, x - 22, y + 60, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 845, 7167, 172, 205, x + 134, y + 6.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 845, 7167, 172, 205, x - 137.5, y + 6.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		return;
	}
	return;
}
/**
* função que controla frame a frame a animação Power Dunk Jumping
*/
void Terry::PowerDunkJumping()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1018, 7167, 206, 262, x - 38.5, y - 37, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1018, 7167, 206, 262, x + 1, y - 37, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1245, 7167, 187, 240, x - 9.5, y - 5.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1245, 7167, 187, 240, x - 6, y - 5.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1466, 7167, 164, 304, x + 5.5, y - 42.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1466, 7167, 164, 304, x - 6.5, y - 42.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1683, 7167, 165, 317, x - 4.5, y - 55.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1683, 7167, 165, 317, x - 6.5, y - 55.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		return;
	}
	return;
}
/**
* função que controla frame a frame a animação Weak Power Dunk Falling
*/
void Terry::WeakPowerDunkFalling()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1860, 7167, 188, 244, x - 36.5, y - 12.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1860, 7167, 188, 244, x + 17, y, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1860, 7167, 188, 244, x - 32.5, y - 22.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 3, 7486, 181, 254, x + 17, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 185, 7486, 229, 181, x + 2.5, y, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 185, 7486, 229, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 415, 7486, 216, 181, x + 2.5, y, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 415, 7486, 216, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 632, 7486, 222, 181, x + 2.5, y, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 632, 7486, 222, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 855, 7486, 227, 181, x + 2.5, y, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 855, 7486, 227, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1083, 7486, 230, 181, x + 2.5, y, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1083, 7486, 230, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1314, 7486, 211, 181, x + 2.5, y, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1314, 7486, 211, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1543, 7486, 211, 181, x + 2.5, y, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1543, 7486, 211, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF - 45) { frame++; captureTime = clock(); }
		return;
	}
	return;
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1776, 7486, 211, 181, x + 2.5, y, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 1776, 7486, 211, 181, x - 66.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		return;
	}
	return;
}
/**
* função que controla frame a frame a animação Strong Power Dunk Falling
*/
void Terry::StrongPowerDunkFalling()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1860, 7167, 188, 244, x - 36.5, y - 12.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1860, 7167, 188, 244, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1860, 7167, 188, 244, x - 32.5, y - 22.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 3, 7486, 181, 254, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 185, 7486, 229, 181, x + 2.5, y, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 185, 7486, 229, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 415, 7486, 216, 181, x + 2.5,y, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 415, 7486, 216, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 632, 7486, 222, 181, x + 2.5, y, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 632, 7486, 222, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 855, 7486, 227, 181, x + 2.5, y, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 855, 7486, 227, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1083, 7486, 230, 181, x + 2.5, y, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1083, 7486, 230, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1314, 7486, 211, 181, x + 2.5, y, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1314, 7486, 211, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1543, 7486, 211, 181, x + 2.5, y, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1543, 7486, 211, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && clock() - captureTime > TBF - 20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1776, 7486, 211, 181, x + 2.5, y, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 1776, 7486, 211, 181, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		return;
	}
	return;
}

/**
* função que controla frame a frame a animação Weak Burnig Knuckle Start
*/
void Terry::WeakBurnigKnuckleStart()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1460, 6361, 179, 213, x-5, y+3, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1460, 6361, 179, 213, x-9, y+3, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1651, 6361, 185, 216, x, y, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1651, 6361, 185, 216, x-18.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1 
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1842, 6361, 206, 216, x-2, y, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1842, 6361, 206, 216, x-38.5, y, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 6656, 212, 209, x+90, y+3, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 6656, 212, 209, x-136.5, y+3, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		return;
	}
	return;
}

/**
* função que controla frame a frame a animação Strong Burnig Knuckle Start
*/
void Terry::StrongBurnigKnuckleStart()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 219, 6361, 170, 207, x-2, y+9, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 219, 6361, 170, 207, x-2, y+9, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 400, 6361, 169, 212, x-1.5, y+4, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 400, 6361, 169, 212, x-1.5, y+4, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 570, 6361, 229, 267, x-39, y-51, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 570, 6361, 229, 267, x-22.5, y-51, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 810, 6361, 216, 279, x-35.5, y-63, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 810, 6361, 216, 279, x-14, y-63, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1047, 6361, 198, 294, x-31, y-77.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1047, 6361, 198, 294, x-0.5, y-77.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1256, 6361, 183, 238, x-16, y-22, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1256, 6361, 183, 238, x-1, y-22, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF - 15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 6656, 212, 209, x+90, y+3, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 6656, 212, 209, x-136.5, y+3, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		return;
	}
	return;
}

/**
* função que controla frame a frame a animação Burnig Knuckle
*/
void Terry::BurnigKnuckle()
{

	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 243, 6656, 277, 232, x - 33.5, y - 23, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 243, 6656, 277, 232, x - 82.5, y - 23, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 561, 6656, 277, 214, x - 35, y-5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 561, 6656, 277, 214, x - 81, y-5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 859, 6656, 275, 232, x - 33.5, y - 23, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 859, 6656, 275, 232, x - 81.5, y-23, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1175, 6656, 275, 214, x - 35, y - 5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1175, 6656, 275, 214, x - 80.5, y-5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1471, 6656, 274, 232, x - 33.5, y - 23, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1471, 6656, 274, 232, x - 81, y-23, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1774, 6656, 274, 217, x - 35, y - 7.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1774, 6656, 274, 217, x - 80, y-7.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF-15) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 6889, 277, 232, x - 33.5, y - 23, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 6889, 277, 232, x - 83, y-23, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		return;
	}

	return;
}

/**
* função que controla frame a frame a animação Rising Tackle Start
*/
void Terry::RisingTackleStart()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 288, 6889, 153, 200, x + 66, y + 10, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 288, 6889, 153, 200, x - 52.5, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 452, 6889, 148, 171, x + 65.5, y + 40.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 452, 6889, 148, 171, x - 44, y + 40.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 611, 6889, 168, 171, x + 38.5, y + 40.5, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 611, 6889, 168, 171, x - 37.5, y + 40.5, ALLEGRO_FLIP_HORIZONTAL);//frame 2

		return;
	}

	return;
}

/**
* função que controla frame a frame a animação Rising Tackle
*/
void Terry::RisingTackle()
{

	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1026, 6889, 103, 247, x - 42, y - 29.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1026, 6889, 103, 247, x + 4.5, y - 29.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF-20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1140, 6889, 174, 273, x - 42.5, y - 97, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1140, 6889, 174, 273, x + 18, y - 97, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && clock() - captureTime > TBF-20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1256, 6361, 183, 238, x + 13.5, y - 92, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1256, 6361, 183, 238, x - 20, y - 92, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && clock() - captureTime > TBF-20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1325, 6889, 189, 273, x + 9.5, y - 96, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1325, 6889, 189, 273, x - 30.5, y - 96, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && clock() - captureTime > TBF-20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1525, 6889, 110, 270, x + 18, y - 94, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 1525, 6889, 110, 270, x + 38.5, y - 94, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && clock() - captureTime > TBF-20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1656, 6889, 178, 273, x - 25.5, y - 97, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 1656, 6889, 178, 273, x + 15, y - 97, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && clock() - captureTime > TBF-20) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1841, 6889, 207, 278, x - 45.5, y - 98, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1841, 6889, 207, 278, x + 5, y - 98, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		return;
	}

	return;
}
/**
* função que controla frame a frame a animação Rising Tackle Fall
*/
void Terry::RisingTackleFall()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 7168, 242, 103, x - 45.5, y + 25.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 7168, 242, 103, x - 43.5, y + 25.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 253, 7168, 224, 195, x - 9.5, y + 15.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 253, 7168, 224, 195, x - 51.5, y + 15.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1

		return;
	}
	return;
}

/**
* função que controla frame a frame a animação Power Geyser
*/
void Terry::PowerGeyser()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1167, 6082, 164, 226, x+4, y-9.5, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 1167, 6082, 164, 226, x+6, y-9.5, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1362, 6082, 176, 231, x-5.5, y-14.5, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 1362, 6082, 176, 231, x+4.5, y - 14.5, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1559, 6082, 181, 265, x-11, y-48, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 1559, 6082, 181, 265, x+4.5, y - 48, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1771, 6082, 195, 263, x-19.5, y-46.5, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 1771, 6082, 195, 263, x-2, y - 46.5, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 6361, 208, 242, x-48.5, y-25.5, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 6361, 208, 242, x+3.5, y - 25.5, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 691, 5607, 194, 213, x - 7.5, y + 3.5, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 691, 5607, 194, 213, x - 18, y + 3.5, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 888, 5607, 239, 207, x - 11.5, y + 10, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 888, 5607, 239, 207, x - 59, y + 10, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1130, 5607, 238, 200, x - 10, y + 18, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1130, 5607, 238, 200, x - 59, y + 18, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1371, 5607, 237, 196, x - 9.5, y + 22.5, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1371, 5607, 237, 196, x - 59, y + 22.5, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1611, 5607, 236, 192, x - 9, y + 25, 0);//frame 9
		if (!toRight) al_draw_bitmap_region(basicSprites, 1611, 5607, 236, 192, x - 59, y + 25, ALLEGRO_FLIP_HORIZONTAL);//frame 9
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1850, 5607, 198, 189, x - 7, y + 27, 0);//frame 10
		if (!toRight) al_draw_bitmap_region(basicSprites, 1850, 5607, 198, 189, x - 23, y + 27, ALLEGRO_FLIP_HORIZONTAL);//frame 10
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 5872, 181, 197, x - 7, y + 19, 0);//frame 11
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 5872, 181, 197, x - 6, y + 19, ALLEGRO_FLIP_HORIZONTAL);//frame 11
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 12)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 182, 5872, 176, 210, x - 5, y + 7.5, 0);//frame 12
		if (!toRight) al_draw_bitmap_region(basicSprites, 182, 5872, 176, 210, x - 3, y + 7.5, ALLEGRO_FLIP_HORIZONTAL);//frame 12
		return;
	}
	return;
}

/**
* função que controla frame a frame a animação Buster Wolf Start
*/
void Terry::BusterWolfStart()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 7933, 117, 224, x, y, 0);//frame 0
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 7933, 117, 224, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 0
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 138, 7933, 110, 222, x, y, 0);//frame 1
		if (!toRight) al_draw_bitmap_region(basicSprites, 138, 7933, 110, 222, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 1
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 269, 7933, 155, 243, x, y, 0);//frame 2
		if (!toRight) al_draw_bitmap_region(basicSprites, 269, 7933, 155, 243, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 2
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 435, 7933, 197, 265, x, y, 0);//frame 3
		if (!toRight) al_draw_bitmap_region(basicSprites, 435, 7933, 197, 265, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 3
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 653, 7933, 197, 267, x, y, 0);//frame 4
		if (!toRight) al_draw_bitmap_region(basicSprites, 653, 7933, 197, 267, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 4
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 871, 7933, 190, 239, x, y, 0);//frame 5
		if (!toRight) al_draw_bitmap_region(basicSprites, 871, 7933, 190, 239, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 5
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1092, 7933, 205, 242, x, y, 0);//frame 6
		if (!toRight) al_draw_bitmap_region(basicSprites, 1092, 7933, 205, 242, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 6
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1318, 7933, 210, 247, x, y, 0);//frame 7
		if (!toRight) al_draw_bitmap_region(basicSprites, 1318, 7933, 210, 247, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 7
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1549, 7933, 183, 223, x, y, 0);//frame 8
		if (!toRight) al_draw_bitmap_region(basicSprites, 1549, 7933, 183, 223, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 8
		return;
	}
}

/**
* função que controla frame a frame a animação Buster Wolf
*/
void Terry::BusterWolf()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1744, 7933, 302, 209, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1744, 7933, 302, 209, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 8201, 337, 222, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 8201, 337, 222, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 342, 8201, 329, 213, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 342, 8201, 329, 213, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 674, 8201, 338, 221, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 674, 8201, 338, 221, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1016, 8201, 343, 231, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1016, 8201, 343, 231, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1360, 8201, 343, 271, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1360, 8201, 343, 271, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1709, 8201, 339, 275, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1709, 8201, 339, 275, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 8476, 335, 226, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 8476, 335, 226, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 370, 8476, 343, 299, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 370, 8476, 343, 299, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 745, 8476, 368, 312, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 745, 8476, 368, 312, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1136, 8476, 376, 320, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1136, 8476, 376, 320, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1559, 8476, 382, 320, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1559, 8476, 382, 320, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF - 25) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 12)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 8797, 384, 320, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 8797, 384, 320, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame
		return;
	}
}

/**
* função que controla frame a frame a animação Buster Wolf End
*/
void Terry::BusterWolfEnd()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 425, 8797, 136, 285, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 425, 8797, 136, 285, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 586, 8797, 136, 289, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 586, 8797, 136, 289, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 733, 8797, 160, 273, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 733, 8797, 160, 273, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 899, 8797, 219, 245, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 899, 8797, 219, 245, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1154, 8797, 266, 235, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1154, 8797, 266, 235, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1429, 8797, 306, 235, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1429, 8797, 306, 235, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1746, 8797, 302, 236, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1746, 8797, 302, 236, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 7)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 9118, 278, 253, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 9118, 278, 253, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 8)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 284, 9118, 297, 251, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 284, 9118, 297, 251, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 9)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 588, 9118, 305, 229, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 588, 9118, 305, 229, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 10)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 896, 9118, 314, 224, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 896, 9118, 314, 224, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 11)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1216, 9118, 228, 225, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1216, 9118, 228, 225, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 12)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1511, 9118, 178, 223, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1511, 9118, 178, 223, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 13)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1699, 9118, 172, 223, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1699, 9118, 172, 223, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 14)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1878, 9118, 170, 233, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1878, 9118, 170, 233, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 15)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 9372, 170, 230, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 9372, 170, 230, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 16)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 181, 9372, 170, 226, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 181, 9372, 170, 226, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 17)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 362, 9372, 170, 218, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 362, 9372, 170, 218, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 18)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 544, 9372, 175, 217, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 544, 9372, 175, 217, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame
		return;
	}
}

/**
* função que controla frame a frame a animação Buster Wolf Fail
*/
void Terry::BusterWolfFail()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 730, 9372, 251, 206, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 730, 9372, 251, 206, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 992, 9372, 221, 195, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 992, 9372, 221, 195, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1224, 9372, 207, 182, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1224, 9372, 207, 182, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1443, 9372, 212, 180, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1443, 9372, 212, 180, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1666, 9372, 187, 193, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1666, 9372, 187, 193, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
}

/**
* função que controla frame a frame a animação Active Pow
*/
void Terry::ActivePow()
{
	return;
}

/**
* função que controla frame a frame a animação Recover
*/
void Terry::Recover()
{
	if (frame == 0)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 1870, 9372, 178, 219, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 1870, 9372, 178, 219, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 1)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 0, 9603, 172, 219, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 0, 9603, 172, 219, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 2)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 173, 9603, 170, 228, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 173, 9603, 170, 228, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 3)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 344, 9603, 170, 227, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 344, 9603, 170, 227, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 4)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 181, 9372, 170, 226, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 181, 9372, 170, 226, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 5)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 362, 9372, 170, 218, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 362, 9372, 170, 218, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		if (!*gamePause && !animPause && clock() - captureTime > TBF) { frame++; captureTime = clock(); }
		return;
	}
	if (frame == 6)
	{
		if (toRight)  al_draw_bitmap_region(basicSprites, 544, 9372, 175, 217, x, y, 0);//frame 
		if (!toRight) al_draw_bitmap_region(basicSprites, 544, 9372, 175, 217, x, y, ALLEGRO_FLIP_HORIZONTAL);//frame 
		return;
	}
}

/**
* função que controla frame a frame a animação Stuned
*/
void Terry::Stuned()
{
	return;
}

/*	//função que permite escalonar o sprite

	if (player == 1)
	{
		al_draw_tinted_scaled_rotated_bitmap_region(
			basicSprites,
			0, 0, 169, 217,
			al_map_rgb(255, 255, 255),
			0, 0, x, y - 110, 1.5, 1.5,
			0, 0);
	}
	else
	{
		al_draw_tinted_scaled_rotated_bitmap_region(
			basicSprites,
			0, 0, 169, 217,
			al_map_rgb(255, 255, 255),
			0, 0, x, y - 110, 1.5, 1.5,
			0, ALLEGRO_FLIP_HORIZONTAL);
	}
*/