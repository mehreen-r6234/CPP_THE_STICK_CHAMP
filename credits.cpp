#include "graphics.h"
int credits ()
{
	cleardevice();
	setcolor (WHITE);
	int a=150, b=200,i;
	
	settextstyle (0,0,6);
	outtextxy (100,200,"Mehreen Rahman Rebab");
	settextstyle (0,0,5);
	outtextxy (400,400,"SN - 61");
	delay(3000);

	int y=200;
	int flag=1;
	/*
	for (i=0;i<1200;i++)
	{
		if (y>=150 && flag==0)
		{
			fillellipse (i,y-150,15,15);
			
			fillellipse (i,y+430,15,15);
			y--;
			if (y==150)
				flag=1;
			delay (5);
			
		}
		if (y<=250 && flag==1)
		{
			fillellipse (i,y-150,15,15);
			fillellipse (i,y+430,15,15);
			y++;
			if (y==250)
				flag=0;
			delay (5);
		}
	}
	*/
	//readimagefile ("credit1.jpg",0,0,1200,700);
	//delay(2000);
	//readimagefile ("credit2.jpg",0,0,1200,700);
	//delay(3000);
	return 1;
	
}