#include "graphics.h"
#include <stdio.h>
#include<math.h>
#include "MyHeader.h"

char score[100];

int a, b, i=45, j=453, c, p1=10, p2=440, p3=15, p4=435, p5=45, p6=50, p7=495, p8=48, p9=500, p10=43, p11=490, p12=17, p13=15, p14=12;
int q1=8, q2=442, q3=52, q4=449, q5=446, q6=4, q7=453, q8=438, q9=445, inc=0, r=5, value=0;
int xi, yi;
int points[50]= {p1, p2, p3, p4, p5, p4, p6, p2, p6, p7, p8, p9, p5, p9, p10, p7, p10, p11, p12, p11, p12, p7, p13, p9, p14, p9, p1, p7, p1, p2};
int recs[20]= {q1, q2, q3, q2, q3, q4, q1, q4, q1, q5, q6, q7, q6, q8, q1, q9, q1, q2};


//variables and arrays declared globally for the formation of the character and to move it as well when
//required keys are pressed.


void delipse(int x, int y, int a)  //for the eye of the character
{
    setcolor(15);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, a, a);

}

void dpoly(int c, int p, int a[10]) //for the body parts of the character
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillpoly(p, a);

}

void linesinc(int x, int y) //lines increased when up key is pressed
{
    line(10+x, 500, 10+x, 500-y);
    line(11+x, 500, 11+x, 500-y);
    line(12+x, 500, 12+x, 500-y);
    line(13+x, 500, 13+x, 500-y);
    line(14+x, 500, 14+x, 500-y);
    line(15+x, 500, 15+x, 500-y);

}

void printscore(int value) //prints the score on the top of the window
{
    setcolor(15);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    sprintf(score, "SCORE : %d", value);
    outtextxy(650, 80, score);

}


int game()
{



    int pillarthick1, heromoves, x = 0;  //pillarthick1 defines the width of the previous pillar

    int stickinc=20, stepcnt;
    //stickinc defines how much the stick will increase and it is fixed to increase from the length 20units

    int pillarthick2=(rand()%40)+40;

    //pillarthick2 defines the width of the next pillar. rand is used here to make sure that the next pillar is
    //of a random width

    pillarthick1=pillarthick2;

     //this is required as randomly generated pillarthick2 swaps and becomes pillarthick1

    setlinestyle(SOLID_LINE, 0, 5);  //to ensure the thickness of the stick

    stepcnt=(rand()%(24))+2;

    //stepcnt is randomized so that the distance between the two pillars (which is later initialed as dist1)
    //is randomized as well

    while(1)
    {
        heromoves=20;

        //how many steps the character going to take after the stick's been replaced between the two pillars

        readimagefile("background.jpg", 0, 0, 800, 600);

        printscore(value);

        pillarthick1=pillarthick2;
        pillarthick2=(rand()%40)+40;

        dpoly(0, 15, points); //draws the black part of the body

        dpoly(RED, 9, recs);  //draws the red part of the body

        delipse(i, j, r);  //draws the eyes

        int strtrec[10]= {8, 600, 8+pillarthick1, 600, 8+pillarthick1, 500, 8, 500, 8, 600};
        //the array for the previous pillar

        dpoly(0, 5, strtrec); //draws the previous pillar

        stepcnt=(rand()%(24))+2;
        while((x+(stepcnt*heromoves)-8)<=0 || (x+(stepcnt*heromoves)+pillarthick1+pillarthick2)>=588)
        {
            stepcnt=stepcnt-1;

            //if the distance between the starting point of the previous pillar and the ending point of the next pillar
            //goes out of the window, then stepcnt is decreased so that the total distance mentioned remains inside
            //the window
        }
        //x=8;

        int nxtrec[10]= {8+pillarthick1+(stepcnt*heromoves), 600, (8+(stepcnt*heromoves)+pillarthick1+pillarthick2), 600, (8+(stepcnt*heromoves)+pillarthick1+pillarthick2), 500, 8+pillarthick1+(stepcnt*heromoves), 500, 8+pillarthick1+(stepcnt*heromoves), 600};

        //the array for the next pillar

        dpoly(0, 5, nxtrec); //draws the next pillar



        while(1)
        {
            c=getch();
            delay(1);
            if(c==72 && stickinc<=499)  //72= up key
            {
                stickinc=stickinc+20;

                //stick will increase when the up key's going to be pressed and cannot go out of the window screen for which
                //the above condition's been fixed
            }



            if(c==13)  //13= enter
            {
                break;

                //after the stick has been lengthened, it will break the loop and conduct the next loop which makes
                //fall down to the ground with a angular motion

            }
            linesinc(pillarthick1, stickinc); //lines increased using the pre-defined function

        }

        double angle = 3.1416/2;
        while(angle>=0)
        {
            xi =(int)stickinc*1.0*cos(angle),
            yi =(int)stickinc*1.0*sin(angle);

            //changes the x and y co-ordinates according to the changing angle

            readimagefile("background.jpg", 0, 0, 800, 600);

            printscore(value);

            setcolor(0);
            line(10+pillarthick1, 500, 10+pillarthick1+xi, 500-yi);

            dpoly(0, 5, strtrec);

            dpoly(0, 5, nxtrec);

            dpoly(0, 15, points);

            dpoly(RED, 9, recs);

            delipse(i, j, r);

            angle -= 0.05;



        }

        int fstickl=stickinc; //defines the final stick length

        int dist1=stepcnt*heromoves; //the distance in between the two pillars

        int dist2=dist1+pillarthick2;



        //previous distance including the next pillars width

        int moveinc=0;  //how many moves the character can make according to the final stick length


            while((moveinc*heromoves)<=fstickl)
            {

                readimagefile("background.jpg", 0, 0, 800, 600);


                printscore(value);

                dpoly(0, 4, strtrec);

                dpoly(0, 4, nxtrec);

                a=heromoves; //the amount of change of the x coordinate of the character

                b=0;

                moveinc++;


                int cpypoints[50]= {p1+a*moveinc, p2+b, p3+a*moveinc, p4+b, p5+a*moveinc, p4+b, p6+a*moveinc, p2+b, p6+a*moveinc, p7+b, p8+a*moveinc, p9+b, p5+a*moveinc, p9+b, p10+a*moveinc, p7+b, p10+a*moveinc, p11+b, p12+a*moveinc, p11+b, p12+a*moveinc, p7+b, p13+a*moveinc, p9+b, p14+a*moveinc, p9+b, p1+a*moveinc, p7+b, p1+a*moveinc, p2+b};
                int cpyrecs[20]= {q1+a*moveinc, q2+b, q3+a*moveinc, q2+b, q3+a*moveinc, q4+b, q1+a*moveinc, q4+b, q1+a*moveinc, q5+b, q6+a*moveinc, q7+b, q6+a*moveinc, q8+b, q1+a*moveinc, q9+b, q1+a*moveinc, q2+b};

                //cpypoints and cpyrecs are the changed arrays which will make the character movement possible

                dpoly(0, 15, cpypoints);

                dpoly(RED, 9, cpyrecs);

                delipse(i+a*moveinc, j+b, r);



                //the character's been drawn after the movement

                setcolor(0);
                setfillstyle(SOLID_FILL, 0);
                rectangle(8+pillarthick1, 500, 8+pillarthick1+fstickl, 502);
                floodfill(8+pillarthick1+1, 501, 0);

                //the final stick, which is drawn using a rectangle, leveled between the two pillars according
                //to their increased length


                delay(200); //to make the movement of the character visible

            }




        if(fstickl>=dist1 && fstickl<=dist2) //required condition, to point a score
        {
            value++;

            printscore(value);

             if(fstickl>=(dist1+20) && fstickl<=(dist2-20)) //
        {
            char bonus[10];
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
            sprintf(bonus, "+1!!");
            outtextxy(380, 150, bonus);


            value++;
			delay(500);
	   }

            printscore(value);




        }


stickinc=20;

        //this makes the stick length back to it's starting self and thus repeats the process for the next pillars to appear


        /*if(c==27)  //27= escape

            return 0;  //game can be exited using the escape key
			*/
    }
}

int active=1;

int main( )
{
    initwindow(800, 600, "STICK HERO! :)");

	//gameload();

	//game();

	while (active==1)
	{
		cleardevice();
		int x= printmenu();
		if (x==3)
		{
			active=credits();
			cleardevice();
		}
		else if (x==2)
		{
			active=printhowtoplay();
			cleardevice();
		}
		else if (x==1)
		{
			active=game();
			cleardevice();

		}
		else if (x==4)
		{
			exit(0);
		}
		else if (x==5)
		{

			//active= leaders();

		}

	}
	//cleardevice();




} // int main() ends


