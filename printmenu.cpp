#include "graphics.h"

int printmenu()
{
	readimagefile ("menu.jpg",0,0,800,600);
	while (1)
	{
		clearmouseclick(WM_LBUTTONDOWN);
		int x=mousex();
		int y=mousey();
		if (x>=320 && x<=490 && y>=200 &&y<=240)
		{
			setcolor(RED);
			setfillstyle (SOLID_FILL,RED);
			fillellipse(280,230,15,15);
			
			setcolor(BLACK);
			setfillstyle (SOLID_FILL,BLUE);


			//fillellipse(280,230,15,15);
			fillellipse(280,320,15,15);
			fillellipse(280,420,15,15);
			fillellipse(280,520,15,15);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				return 1;
			}

		}
		else if (x>=300 && x<=500 && y>=300 &&y<=340)
		{
			setcolor(RED);
			setfillstyle (SOLID_FILL,RED);
			fillellipse(280,320,15,15);
			
			setcolor(BLACK);
			setfillstyle (SOLID_FILL,BLUE);


			fillellipse(280,230,15,15);
			//fillellipse(280,320,15,15);
			fillellipse(280,420,15,15);
			fillellipse(280,520,15,15);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				return 2;
			}
		}
		else if (x>=330 && x<=470 && y>=400 &&y<=440)
		{
			setcolor(RED);
			setfillstyle (SOLID_FILL,RED);
			fillellipse(280,420,15,15);
			
			setcolor(BLACK);
			setfillstyle (SOLID_FILL,BLUE);

			fillellipse(280,230,15,15);
			fillellipse(280,320,15,15);
			//fillellipse(280,420,15,15);
			fillellipse(280,520,15,15);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				return 3;
			}
		}
		else if (x>=360 && x<=440 && y>=500 &&y<=540)
		{
			setcolor(RED);
			setfillstyle (SOLID_FILL,RED);
			fillellipse(280,520,15,15);
			
			setcolor(BLACK);
			setfillstyle (SOLID_FILL,BLUE);
			
			fillellipse(280,230,15,15);
			fillellipse(280,320,15,15);
			fillellipse(280,420,15,15);


			if (ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				return 4;
			}
		}
		else if (x>=39 && x<=174 && y>=545 &&y<=662)
		{
			//setcolor(RED);
			setfillstyle (SOLID_FILL,BLUE);
			fillellipse(280,230,15,15);
			fillellipse(280,320,15,15);
			fillellipse(280,420,15,15);
			fillellipse(280,520,15,15);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				return 5;
			}


		}
		else
		{
			setcolor(RED);
			setfillstyle (SOLID_FILL,BLUE);
			fillellipse(280,230,15,15);
			fillellipse(280,320,15,15);
			fillellipse(280,420,15,15);
			fillellipse(280,520,15,15);


		}


	}

	return 0;
}
