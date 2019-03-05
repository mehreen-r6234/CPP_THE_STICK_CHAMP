#include "graphics.h"
#include <stdio.h>
#include<math.h>

char score[100];

void delipse(int x, int y, int a)
{
    setcolor(15);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, a, a);

}

void dpoly(int c, int p, int a[10])
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillpoly(p, a);

}

void linesinc(int x, int y)
{
            line(10+x, 500, 10+x, 500-y);
			line(11+x, 500, 11+x, 500-y);
			line(12+x, 500, 12+x, 500-y);
			line(13+x, 500, 13+x, 500-y);
			line(14+x, 500, 14+x, 500-y);
			line(15+x, 500, 15+x, 500-y);

}

void printscore(int value)
{
    setcolor(15);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    sprintf(score, "SCORE : %d", value);
    outtextxy(650, 80, score);

}

int main()
{
    int a, b, i=45, j=453, c, p1=10, p2=440, p3=15, p4=435, p5=45, p6=50, p7=495, p8=48, p9=500, p10=43, p11=490, p12=17, p13=15, p14=12;
    int q1=8, q2=442, q3=52, q4=449, q5=446, q6=4, q7=453, q8=438, q9=445, inc=0, r=5, value=0;
    int xi, yi;
    int points[50]= {p1, p2, p3, p4, p5, p4, p6, p2, p6, p7, p8, p9, p5, p9, p10, p7, p10, p11, p12, p11, p12, p7, p13, p9, p14, p9, p1, p7, p1, p2};
    int recs[20]= {q1, q2, q3, q2, q3, q4, q1, q4, q1, q5, q6, q7, q6, q8, q1, q9, q1, q2};


    initwindow(800, 600, "STICK HERO! :)");
    int pillarthick1, heromoves, x = 0;
    int stickinc=20, stepcnt;
    int pillarthick2=(rand()%40)+40;

    pillarthick1=pillarthick2;

    //int strtrec[10]={8, 600, 8+pillarthick1, 600, 8+pillarthick1, 500, 8, 500, 8, 600};

    setlinestyle(SOLID_LINE, 0, 5);

    stepcnt=(rand()%(24))+2;



    while(1)
    {
        heromoves=20;

        readimagefile("background.jpg", 0, 0, 800, 600);

        printscore(value);


        pillarthick1=pillarthick2;
        pillarthick2=(rand()%40)+40;

        dpoly(0, 15, points);

        dpoly(RED, 9, recs);

        delipse(i, j, r);

        int strtrec[10]={8, 600, 8+pillarthick1, 600, 8+pillarthick1, 500, 8, 500, 8, 600};

        dpoly(0, 5, strtrec);


        stepcnt=(rand()%(24))+2;
        while((x+(stepcnt*heromoves)-8)<=0 || (x+(stepcnt*heromoves)+pillarthick1+pillarthick2)>=588){
            stepcnt=stepcnt-1;  //(rand()%(24))+1
            }
        //x=8;

       int nxtrec[10]={8+pillarthick1+(stepcnt*heromoves), 600, (8+(stepcnt*heromoves)+pillarthick1+pillarthick2), 600, (8+(stepcnt*heromoves)+pillarthick1+pillarthick2), 500, 8+pillarthick1+(stepcnt*heromoves), 500, 8+pillarthick1+(stepcnt*heromoves), 600};
       printf("%d %d %d    %d %d %d %d\n", x, pillarthick1, stepcnt*heromoves, x, pillarthick1, stepcnt*heromoves, pillarthick2);

       dpoly(0, 5, nxtrec);

        while(1){
            c=getch();
            delay(1);
            if(c==72){
                stickinc=stickinc+20;

            }



            if(c==13)
            {
                break;

            }
            linesinc(pillarthick1, stickinc);

        }

        double angle = 3.1416/2;
        while(angle>=0){
        xi =(int)stickinc*1.0*cos(angle),
        yi =(int)stickinc*1.0*sin(angle);
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
    int fstickl=stickinc;
    int dist1=stepcnt*heromoves;
    int dist2=dist1+pillarthick2;
    int moveinc=0;

if(fstickl>=dist1 && fstickl<=dist2){
    while((moveinc*heromoves)<=fstickl){
            readimagefile("background.jpg", 0, 0, 800, 600);


            printscore(value);

                dpoly(0, 4, strtrec);

    dpoly(0, 4, nxtrec);

               a=heromoves;

                b=0;

                moveinc++;


    int cpypoints[50]= {p1+a*moveinc, p2+b, p3+a*moveinc, p4+b, p5+a*moveinc, p4+b, p6+a*moveinc, p2+b, p6+a*moveinc, p7+b, p8+a*moveinc, p9+b, p5+a*moveinc, p9+b, p10+a*moveinc, p7+b, p10+a*moveinc, p11+b, p12+a*moveinc, p11+b, p12+a*moveinc, p7+b, p13+a*moveinc, p9+b, p14+a*moveinc, p9+b, p1+a*moveinc, p7+b, p1+a*moveinc, p2+b};
    int cpyrecs[20]= {q1+a*moveinc, q2+b, q3+a*moveinc, q2+b, q3+a*moveinc, q4+b, q1+a*moveinc, q4+b, q1+a*moveinc, q5+b, q6+a*moveinc, q7+b, q6+a*moveinc, q8+b, q1+a*moveinc, q9+b, q1+a*moveinc, q2+b};
    dpoly(0, 15, cpypoints);

    dpoly(RED, 9, cpyrecs);

    delipse(i+a*moveinc, j+b, r);


    setcolor(0);
    setfillstyle(SOLID_FILL, 0);
    rectangle(8+pillarthick1, 500, 8+pillarthick1+fstickl, 502);
    floodfill(8+pillarthick1+1, 501, 0);


    delay(200);

}
value++;

    printscore(value);

}


stickinc=20;
     //
     if(c==27)
       return 0;

    }
}

