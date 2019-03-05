#include "graphics.h"
#include <stdio.h>

int printhowtoplay()
{
	readimagefile("howtoplay.jpg", 0, 0, 800, 600);
	char c;
	c=getch();
	delay(400);
	return 1;
	
}