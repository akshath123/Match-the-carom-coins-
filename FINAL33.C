#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include"graphics.h"
#include"alloc.h"
#include"time.h"

instructions();
welcome();
cake();
print();

union REGS i,o ;

int a[16] ;
static f = 1 ;

int main()
{
	int gd = DETECT , gm , maxx , maxy , i ;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	welcome();

	instructions();

	closegraph();
	restorecrtmode();

	return 0 ;
}

instructions()
{
	int maxx , maxy , i , j , z , w , area ;

	int x , y , button , x1 , y1 , xdir = 1 ;

	char *buff ;   // for the smilie

	showmouseptr() ;

	cleardevice();

	if(initmouseptr() == 0)
	{
		closegraph();
		restorecrtmode();
		printf("Mouse could not be loaded.....");
		getch();
		exit(0);
	}

	maxx = getmaxx();
	maxy = getmaxy();

	/* ------------------- Rectangle part ---------------------- */

	setcolor(BLUE);
	rectangle(0,20,maxx-10,maxy-10);
	rectangle(10,30,maxx-20,maxy-20);

	setfillstyle(BKSLASH_FILL,BLUE);
	floodfill(5,25,BLUE);

	setviewport(0,20,maxx-10,maxy-10,1);

	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(20,35,"NOTE : USE THE MOUSE OR TOUCHPAD");
	setcolor(CYAN);
	outtextxy(20,50," DON'T SUPERIMPOSE THE MOUSE ON THE SMILE IT WILL CAUSE PROBLEMS SORRY.");

	/* ------------------- Instruction part --------------------- */

	setcolor(GREEN);
	settextstyle(0,0,1);
	outtextxy(250,70,"################");
	outtextxy(250,80,"# INSTRUCTIONS #");
	outtextxy(250,90,"################");

	setcolor(WHITE);
	setfillstyle(1,WHITE);
	circle(30,123,5);
	circle(30,123,2.5);
	floodfill(30,123,WHITE);
	circle(30,153,5);
	circle(30,153,2.5);
	floodfill(30,153,WHITE);
	circle(30,213,5);
	circle(30,213,2.5);
	floodfill(30,213,WHITE);
	circle(30,183,5);
	circle(30,183,2.5);
	floodfill(30,183,WHITE);
	circle(30,243,5);
	circle(30,243,2.5);
	floodfill(30,243,WHITE);

	setcolor(MAGENTA);
	outtextxy(40,120," There is a game in the next page defeat it in");
	setcolor(WHITE);
	outtextxy(410,120," 40 SECONDS.");
	setcolor(MAGENTA);
	outtextxy(40,150," Eliminate the ['THREE'] carroms of the same color by clicking on them.");
	outtextxy(40,180," Click on the inner circle.");
	outtextxy(40,210," Eliminate all the carroms within the ['TIME LIMIT'] to see what happens next.");
	outtextxy(40,240," If finished reading click on the button. ");
	setcolor(WHITE);
	outtextxy(370,240,"GO FOR IT BOY.");
	setcolor(LIGHTGRAY);



	/* ---------------------- For the Button ------------------------- */

	setfillstyle(1,LIGHTGRAY);
	bar(550,400,570,420);
	rectangle(550,400,570,420);
	setcolor(WHITE);
	rectangle(549,399,571,421);

	setcolor(RED);
	setfillstyle(2,RED);
	rectangle(556,350,563,380);
	floodfill(560,352,RED);
	line(545,380,558,380);
	line(558,380,573,380);
	line(545,380,560,390);
	line(573,380,560,390);
	floodfill(560,383,RED);

	/* ----------------------- For the smilie ----------------------- */

	setcolor(BLUE);
	circle(150,340,70);
	setfillstyle(1,YELLOW);
	floodfill(150,340,BLUE);

	setcolor(GREEN);
	line(110,320,130,320);
	arc(120,320,0,180,10);
	setfillstyle(1,GREEN);
	ellipse(120,320,0,180,10,20);
	floodfill(120,319,GREEN);

	line(170,320,190,320);
	arc(180,320,0,180,10);
	ellipse(180,320,0,180,10,20);
	floodfill(180,319,GREEN);

	setcolor(RED);
	ellipse(150,350,180,360,40,30);

      gotoxy( 65 ,23);
      printf(" Click Me ");

      /* -------------------- Animation part ---------------------- */

      area = imagesize(80,270,220,410);

      buff = malloc(area);

      if( buff == NULL )
      {
	printf("Memory not alloted ");
	getch() ;
	exit(0);
      }

      getimage(80,270,220,410,buff);

      x1 = 80 , y1 = 270 ;

      while(!kbhit())
      {
		delay(100);
		getmousepos(&button ,&x ,&y);
		if( x >= 550 && x <= 570 && y >= 420 && y <=440 )
		{
			if((button & 1) == 1)
			{
				while((button & 1) == 1)
				getmousepos(&button,&x,&y);

				if( x >= 550 && x <= 570 && y >= 400 && y <= 440 )
				{
					clearviewport();
					closegraph();
					hidemouseptr();
					fflush(stdin);
					game();
				}
			}
		}

		 putimage(x1,y1,buff,XOR_PUT);
		 x1 = x1 + ( xdir * 5 ) ;
		 putimage(x1,y1,buff,XOR_PUT);

		 if( x  >= x1-20 && x <= x1+150 && y >= y1-20 && y <= y1+150 )
		 hidemouseptr();
		 else
		 showmouseptr();

		 if( x1 >=  300 || x1 <= 80 )
		 {
		  xdir = xdir * -1 ;
		  delay(10);
		 }
	 }
 return ;
}

welcome()
{
	int gd = DETECT , gm , i , j , i1 ;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	i = 0 ;
	j = 450 ;

	for ( i1 = 0 ; i1 <= 2 ; i1 = i1 + 1 )
	{
		cleardevice();
		setcolor(i1+1);
		settextstyle(TRIPLEX_FONT,0,i*10);
		outtextxy(i,(j-(i*10)),"WELCOME");
		delay(500);
		i = i + 20 ;
	}

	setcolor(MAGENTA);
	settextstyle(3,0,5);
//	outtextxy(195,220,"");
	getch();

	return ;
}

game()
{
	int maxx , maxy , i ,j , count = 0 , x , y , z  ;
	int gd = DETECT , gm ;

	int flag1 = 0 , flag2 = 0 , flag3 = 0 ;

	int y1 = 0 , y2 = 0 , y3 = 0 ;
	int x1 = 0 , x2 = 0 , x3 = 0 ;

	int q1,w1,e1,r1;
	int q2,w2,e2,r2;
	int q3,w3,e3,r3;

	int count1 = 0 ;

	int count2 = 45 ;

	char *buff1 , *buff2 , *buff3 , ch ;

	int l , m , n ;

	int sec = 59, milsec = 99 ;

	int xcor , ycor , button , pix1 , pix2 , pix3 , area , z1 ,z2 ,z3 , b[48];

     // 	outtextxy(60,60,"Click on the inner circle to make a valid click ");

	for ( i = 0 ; i < 48 ; i++ )
	b[i] = 1 ;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	maxx = getmaxx();
	maxy = getmaxy();

	srand(time(NULL));

	setcolor(RED);
	rectangle(0,10,maxx,maxy);
	setfillstyle(7,RED);
	rectangle(10,20,maxx-10,maxy-10);
	floodfill(5,15,RED);

	/* ---------------------- 1st two rows -------------------- */

	setcolor(WHITE);
	j = 100 ;

	for( i = 1 ; i <= 15 ; i++ )
	{
		count++ ;
		db:
		y = rand() % 16 ;
		if( y == YELLOW )
		goto db ;
		z = hash(y);
		if(z==1)
		{
			goto db;
		}
		setfillstyle(1,y);

		if(count <= 8)
		{
			if(y == BLACK)
			{
				setcolor(WHITE);
				circle(j,125,20);
				circle(j,125,30);
				floodfill(j,125,WHITE);
				j = j + 60 ;
				x = 1 ;
			}
			else
			{
			setcolor(y);
			circle(j,125,30);
			floodfill(j,125,y);
			setcolor(BLACK);
			circle(j,125,20);
			j = j + 60 ;
			x = 1 ;
			}
		}
		else
		{
			if( x == 1)
			{
				j = 130 ;
				x = 0 ;
			}
			if(y == BLACK)
			{
				setcolor(WHITE);
				circle(j,185,20);
				circle(j,185,30);
				floodfill(j,185,WHITE);
				j = j + 60 ;
			}
			else
			{
			setcolor(y);
			circle(j,185,30);
			floodfill(j,185,y);
			setcolor(BLACK);
			circle(j,185,20);

			j = j + 60 ;
			}
		}
		delay(100);
	}
	/* ---------------------- 2nd two rows ---------------------- */

	j = 100 ;
	count = 0;
	f = 1 ;
		for( i = 1 ; i <= 15 ; i++ )
	{
		count++ ;
		db1:
		y = rand()%16;
		if( y == YELLOW )
		goto db1 ;
		z = hash(y);
		if(z == 1)
		{
			goto db1 ;
		}

		setfillstyle(1,y);

		if(count <= 8)
		{
			if( y == BLACK)
			{
				setcolor(WHITE);
				circle(j,245,20);
				circle(j,245,30);
				floodfill(j,245,WHITE);
				j = j + 60 ;
				x = 1 ;
			}
			else
			{
			setcolor(y);
			circle(j,245,30);
			floodfill(j,245,y);
			setcolor(BLACK);
			circle(j,245,20);
			j = j + 60 ;
			x = 1 ;
			}
		}
		else
		{
			if( x == 1)
			{
				j = 130 ;
				x = 0 ;
			}
			if( y == BLACK )
			{
				setcolor(WHITE);
				circle(j,305,30);
				circle(j,305,20);
				floodfill(j,305,WHITE);
				j = j + 60 ;
			}
			else
			{
			setcolor(y);
			circle(j,305,30);
			floodfill(j,305,y);
			setcolor(BLACK);
			circle(j,305,20);
			j = j + 60 ;
			}
		}
		delay(100);
	}

	/* ---------------------- 3rd two rows ---------------------- */

	j = 100 ;
	f = 1 ;
	count = 0;

		for( i = 1 ; i <= 15 ; i++ )
	{
		count++ ;
		db2:
			y = rand()%16 ;
			if( y == YELLOW )
			goto db2 ;
			z = hash(y);
			if(z==1)
			{
				goto db2;
			}

			setfillstyle(1,y);

		if(count <= 8)
		{
			if(y == BLACK)
			{
				setcolor(WHITE);
				circle(j,365,30);
				circle(j,365,20);
				floodfill(j,365,WHITE);
				j = j + 60 ;
				x = 1;
			}
			else
			{
			setcolor(y);
			circle(j,365,30);
			floodfill(j,365,y);
			setcolor(BLACK);
			circle(j,365,20);
			j = j + 60 ;
			x = 1 ;
			}
		}
		else
		{
			if( x == 1)
			{
				j = 130 ;
				x = 0 ;
			}
			if( y == BLACK )
			{
				setcolor(WHITE);
				circle(j,425,30);
				circle(j,425,20);
				floodfill(j,425,WHITE);
				j = j + 60 ;
			}
			else
			{
			setcolor(y);
			circle(j,425,30);
			floodfill(j,425,y);
			setcolor(BLACK);
			circle(j,425,20);
			j = j + 60 ;
			}
		}
		delay(100);
	}

		if(initmouseptr() ==  0)
		{
			closegraph();
			restorecrtmode();
			printf(" Mouse could not loaded........");
			getch();
			exit(0);
		}
		showmouseptr();

		gotoxy(58,3);
		printf("TIME : 00 : 40 : 00");

		while(!kbhit())
		{
			if( count2 == 0 )
			{
				cake();
				closegraph();
				restorecrtmode();
				exit(0);
			}
			delay(10);
			milsec-- ;
			if(milsec == 0 )
			{
				sec-- ;
				milsec = 99 ;
			}
			gotoxy(58,3);
			if(sec > 9 )
			printf("TIME : 00 : %d : %d" ,sec,milsec);
			else
			printf("TIME : 00 : 0%d : %d" , sec,milsec);
			showmouseptr();
			if(sec == 0 )
			{
				hidemouseptr();
	while(!kbhit())
	{
		db9:
		cleardevice();
		  y = rand()%16;
		  if(y == WHITE)
		  goto db9;
		  setcolor(y);
		  setbkcolor(BLACK);
		  settextstyle(TRIPLEX_FONT,0,5) ;
		  outtextxy((maxx/2)-100,maxy/5,"GAME OVER");
		  settextstyle(TRIPLEX_FONT,0,3);
		  outtextxy(100,300," PRESS Any key to exit ");
		  delay(100);
	}

			}

		       getmousepos(&button,&xcor,&ycor);

		       if((button & 1) == 1)
		       {

		       hidemouseptr();

		       while((button&1) == 1)
		       getmousepos(&button,&xcor,&ycor);
    /* ------------------------ 1st row --------------------------------------*/

		       if( xcor >= 80 && xcor <= 120 && ycor >= 105 && ycor <= 145 && b[0] == 1)   // --1  center = 100 , 125
		       {

					if( z1 == 0)
					{
						l = 0 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 0 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 0;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(100,125);
						l= 0 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(100,125);
						n = 0 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(100,125);
						m = 0 ;
						x3 = 1 ;
					}

				       area = imagesize(70,95,130,155);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(70,95,130,155,buff1);
					q1 = 70 ; w1 = 95 ; e1 = 130 ; r1 = 155 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(70,95,130,155,buff2);
						q2 = 70 ; w2 = 95 ; e2 = 130 ; r2 = 155 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(70,95,130,155,buff3);
						q3 = 70 ; w3 = 95 ; e3 = 130 ; r3 = 155 ;
						y3 = 1;
					}

				       count1++ ;
				       b[0] = 2 ;
		       }

		       else if( xcor >= 140 && xcor <= 180 && ycor >= 105 && ycor <= 145 && b[1] == 1) // -- 2  center = 160 , 125
		       {
						if( z1 == 0)
					{

						l = 1 ;
						z1 = 1;
					}
					 if(z2 == 0)
					{

						m = 1 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 1;
						z3 = 1;

					}
					if( x1 == 0 )
					{
						pix1 = getpixel(160,125);
						l = 1 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(160,125);
						m =  1;

						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(160,125);
						n = 1 ;
						x3 = 1;
					}
					area = imagesize(130,95,190,155);
					    if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(130,95,190,155,buff1);
					q1 = 130 ; w1 = 95 ; e1 = 190 ; r1 = 155 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(130,95,190,155,buff2);
						q2 = 130 ; w2 = 95 ; e2 = 190 ; r2 = 155 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(130,95,190,155,buff3);
						q3 = 130 ; w3 = 95 ; e3 = 190 ; r3 = 155 ;
						y3 = 1;
					}

					b[1] = 2 ;
				       count1++ ;
		       }

			 else if( xcor >= 200 && xcor <= 240 && ycor >= 105 && ycor <= 145 && b[2] == 1) // --- 3 center = 220 , 125
				 {
					if( z1 == 0)
					{
						l = 2 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 2 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 2;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(220,125);
						l = 2 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(220,125);
						m =  2;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(220,125);
						n =  2;
						x3 = 1;
					}
					area = imagesize(190,95,250,155);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(190,95,250,155,buff1);
						q1 = 190 ; w1 = 95 ; e1 = 250 ; r1 = 155 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(190,95,250,155,buff2);
						q2 = 190 ; w2 = 95 ; e2 = 250 ; r2 = 155 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(190,95,250,155,buff3);
						q3 = 190 ; w3= 95 ; e3 = 250 ; r3 = 155 ;
						y3 = 1;
					}
					count1++ ;
					b[2] = 2 ;
				 }

				 else if( xcor >= 260 && xcor <= 300 && ycor >= 105 && ycor <= 145 && b[3] == 1) // --- 4 center = 280 , 125
				 {
					if( z1 == 0)
					{
						l = 3 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 3 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 3;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(280,125);
						l =  3;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(280,125);
						m =  3;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(280,125);
						n = 3 ;
						x3 = 1;
					}
					area = imagesize(250,95,310,155);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(250,95,310,155,buff1);
						q1 = 250 ; w1 = 95 ; e1 = 310 ; r1 = 155 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(250,95,310,155,buff2);
						q2 = 250 ; w2 = 95 ; e2 = 310 ; r2 = 155 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(250,95,310,155,buff3);
						q3 = 250 ; w3 = 95 ; e3 = 310 ; r3 = 155 ;
						y3 = 1;
					}
					count1++ ;
					b[3] = 2 ;
				 }

				 else if( xcor >= 320 && xcor <= 360 && ycor >= 105 && ycor <= 145 && b[4] == 1) // --- 5 center = 400 , 125
				 {
				 if( z1 == 0)
					{
						l = 4 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 4 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 4;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(340,125);
						l =  4;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(340,125);
						 m = 4 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(340,125);
						n = 4 ;
						x3 = 1;
					}
					area = imagesize(310,95,370,155);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(310,95,370,155,buff1);
						q1 = 310 ; w1 = 95 ; e1 = 370 ; r1 = 155 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(310,95,370,155,buff2);
						q2 = 310 ; w2 = 95 ; e2 = 370 ; r2 = 155 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(310,95,370,155,buff3);
						q3 = 310 ; w3 = 95 ; e3 = 370 ; r3 = 155 ;
						y3 = 1;
					}
					count1++ ;
					b[4] = 2 ;
				 }

				 else if( xcor >= 380 && xcor <= 420 && ycor >= 105 && ycor <= 145 && b[5] == 1) // --- 6 center = 220 , 125
				 {
				 if( z1 == 0)
					{
						l = 5 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 5 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 5;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(400,125);
						l = 5 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(400,125);
						m = 5 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(400,125);
						n = 5 ;
						x3 = 1;
					}
					area = imagesize(370,95,430,155);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(370,95,430,155,buff1);
						q1 = 370 ; w1 = 95 ; e1 = 430 ; r1 = 155 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(370,95,430,155,buff2);
						q2 = 370 ; w2 = 95 ; e2 = 430 ; r2 = 155 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(370,95,430,155,buff3);
						q3 = 370 ; w3 = 95 ; e3 = 430 ; r3 = 155 ;
						y3 = 1;
					}
					count1++ ;
					b[5] = 2 ;
				 }

				 else if( xcor >= 440 && xcor <= 480 && ycor >= 105 && ycor <= 145 && b[6] == 1) // --- 7 center = 460 , 125
				 {
					if( z1 == 0)
					{
						l = 6;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 6 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 6;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(460,125);
						l = 6 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(460,125);
						m = 6 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(460,125);
						n = 6 ;
						x3 = 1;
					}
					area = imagesize(430,95,490,155);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(430,95,490,155,buff1);
						q1 = 430 ; w1 = 95 ; e1 = 490 ; r1 = 155 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(430,95,490,155,buff2);
						q2 = 430 ; w2 = 95 ; e2 = 490 ; r2 = 155 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(430,95,490,155,buff3);
						q3 = 430 ; w3 = 95 ; e3 = 490 ; r3 = 155 ;
						y3 = 1;
					}
					b[6] = 2 ;
					count1++ ;
				 }

				 else if( xcor >= 500 && xcor <= 540 && ycor >= 105 && ycor <= 145 && b[7] == 1) // --- 8 center = 520 , 125
				 {
				 if( z1 == 0)
					{
						l = 7 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 7 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 7;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(520,125);
						l = 7 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(520,125);
						m = 7 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(520,125);
						n = 7 ;
						x3 = 1;
					}
					area = imagesize(490,95,550,155);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(490,95,550,155,buff1);
						q1 = 490 ; w1 = 95 ; e1 = 550 ; r1 = 155 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(490,95,550,155,buff2);
						q2 = 490 ; w2 = 95 ; e2 = 550 ; r2 = 155 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(490,95,550,155,buff3);
						q3 = 490 ; w3 = 95 ; e3 = 550 ; r3 = 155 ;
						y3 = 1;
					}
					count1++ ;
				}
	 /* ------------------------ 2nd Row -------------------------------- */

		else if( xcor >= 110 && xcor <= 150 && ycor >= 165 && ycor <= 205 && b[8] == 1 ) // --- 9 center = 130 , 185
				 {
					if( z1 == 0)
					{
						l = 8 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 8 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 8;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(130,185);
						l = 8 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(130,185);
						m = 8 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(130,185);
						n = 8 ;
						x3 = 1;
					}
					area = imagesize(100,155,160,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(100,155,160,215,buff1);
						 q1 = 100 ; w1 = 155 ; e1 = 160 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(100,155,160,215,buff2);
						q2 = 100 ; w2 = 155 ; e2 = 160 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(100,155,160,215,buff3);
						q3 = 100 ; w3 = 155 ; e3 = 160 ; r3 = 215 ;
						y3 = 1;
					}
					count1++ ;
					b[8] = 2 ;
				 }

			     else if( xcor >= 170 && xcor <= 210 && ycor >= 165 && ycor <= 205 && b[9] == 1 ) // --- 10 center = 130 , 185
				 {
					if( z1 == 0)
					{
						l = 9 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 9 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 9;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(190,185);
						l = 9 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(190,185);
						m = 9 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(190,185);
						n = 9 ;
						x3 = 1;
					}
					area = imagesize(160,155,220,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(160,155,220,215,buff1);
						q1 = 160 ; w1 = 155 ; e1 = 220 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(160,155,220,215,buff2);
						q2 = 160 ; w2 = 155 ; e2 = 220 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(160,155,220,215,buff3);
						q3 = 160 ; w3 = 155 ; e3 = 220 ; r3 = 215 ;
						y3 = 1;
					}
					count1++ ;
					b[9] = 2 ;
				 }

				else if( xcor >= 230 && xcor <= 270 && ycor >= 165 && ycor <= 205 && b[10] == 1 ) // --- 11 center = 250 , 185
				 {
					if( z1 == 0)
					{
						l = 10 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 10 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 10;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(250,185);
						l = 10 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(250,185);
						m = 10 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(250,185);
						n = 10 ;
						x3 = 1;
					}
					area = imagesize(220,155,280,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(220,155,280,215,buff1);
						q1 = 220 ; w1 = 155 ; e1 = 280 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(220,155,280,215,buff2);
						q2 = 220 ; w2 = 155 ; e2 = 280 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(220,155,280,215,buff3);
						q3 = 220 ; w3 = 155 ; e3 = 280 ; r3 = 215 ;
						y3 = 1;
					}
					count1++ ;
					b[10] = 2 ;
				 }

			else if( xcor >= 290 && xcor <= 330 && ycor >= 165 && ycor <= 205 && b[11] == 1 ) // --- 12 center = 310 , 185
				 {
					if( z1 == 0)
					{
						l = 11 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 11 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 11;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(310,185);
						l = 11 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(310,185);
						m = 11 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(310,185);
						n = 11 ;
						x3 = 1;
					}
					area = imagesize(280,155,340,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(280,155,340,215,buff1);
						q1 = 280 ; w1 = 155 ; e1 = 340 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(280,155,340,215,buff2);
						q2 = 280 ; w2 = 155 ; e2 = 340 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(280,155,340,215,buff3);
						q3 = 280 ; w3 = 155 ; e3 = 340 ; r3 = 215 ;
						y3 = 1;
					}
					count1++ ;
					b[11] = 2 ;
				 }

				else if( xcor >= 350 && xcor <= 390 && ycor >= 165 && ycor <= 205 && b[12] == 1 ) // --- 13 center = 370 , 185
				 {
					if( z1 == 0)
					{
						l = 12 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 12;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 12;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(370,185);
						l = 12 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(370,185);
						m = 12 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(370,185);
						n = 12 ;
						x3 = 1;
					}
					area = imagesize(340,155,400,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(340,155,400,215,buff1);
						q1 = 340 ; w1 = 155 ; e1 = 400 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(340,155,400,215,buff2);
						q2 = 340 ; w2 = 155 ; e2 = 400 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(340,155,400,215,buff3);
						q3 = 340 ; w3 = 155 ; e3 = 400 ; r3 = 215 ;
						y3 = 1;
					}
					count1++ ;
					b[12] = 2 ;
				 }
		else if( xcor >= 410 && xcor <= 450 && ycor >= 165 && ycor <= 205 && b[13] == 1 ) // --- 14 center = 430 , 185
				 {
					if( z1 == 0)
					{
						l = 13 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 13;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 13;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(430,185);
						l = 13 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(430,185);
						m = 13 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(430,185);
						n = 13 ;
						x3 = 1;
					}
					area = imagesize(400,155,460,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(400,155,460,215,buff1);
						q1 = 400 ; w1 = 155 ; e1 = 460 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(400,155,460,215,buff2);
						q2 = 400 ; w2 = 155 ; e2 = 460 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(400,155,460,215,buff3);
						q3 = 400 ; w3 = 155 ; e3 = 460 ; r3 = 215 ;
						y3 = 1;
					}
					count1++ ;
					b[13] = 2 ;
				 }

				else if( xcor >= 470 && xcor <= 510 && ycor >= 165 && ycor <= 205 && b[14] == 1 ) // --- 15 center = 490 , 185
				 {
					if( z1 == 0)
					{
						l = 14 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 14;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 14;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(490,185);
						l = 14 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(490,185);
						m = 14 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(490,185);
						n = 14 ;
						x3 = 1;
					}
					area = imagesize(460,155,520,215);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(460,155,520,215,buff1);
						q1 = 460 ; w1 = 155 ; e1 = 520 ; r1 = 215 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(460,155,520,215,buff2);
						q2 = 460 ; w2 = 155 ; e2 = 520 ; r2 = 215 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(460,155,520,215,buff3);
						y3 = 1;
						q3 = 460 ; w3 = 155 ; e3= 520 ; r3 = 215 ;
					}
					count1++ ;
					b[14] = 2 ;
				 }

\
      /* -------------------------------- 3rd Row --------------------------------- */

	       if( xcor >= 80 && xcor <= 120 && ycor >= 225 && ycor <= 265 && b[16] == 1)   // --17  center = 100 , 245
		       {
					if( z1 == 0)
					{
						l = 16 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 16 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 16;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(100,245);
						l= 16;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(100,245);
						m = 16 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(100,245);
						n = 16 ;
						x3 = 1 ;
					}

				       area = imagesize(70,215,130,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(70,215,130,275,buff1);
					q1 = 70 ; w1 = 215 ; e1 = 130 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(70,215,130,275,buff2);
						q2 = 70 ; w2 = 215 ; e2 = 130 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(70,215,130,275,buff3);
						q3 = 70 ; w3 = 215 ; e3 = 130 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[16] = 2 ;
		       }

      if( xcor >= 140 && xcor <= 180 && ycor >= 225 && ycor <= 265 && b[17] == 1)   // --18  center = 160 , 245
		       {
					if( z1 == 0)
					{
						l = 17 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 17 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 17;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(160,245);
						l = 17 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(160,245);
						m = 17 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(160,245);
						n = 17 ;
						x3 = 1 ;
					}

				       area = imagesize(130,215,190,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(130,215,190,275,buff1);
					q1 = 130 ; w1 = 215 ; e1 = 190 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(130,215,190,275,buff2);
						q2 = 130 ; w2 = 215 ; e2 = 190 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(130,215,190,275,buff3);
						q3= 130 ; w3 = 215 ; e3 = 190 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[17] = 2 ;
		       }

      if( xcor >= 200 && xcor <= 240 && ycor >= 225 && ycor <= 265 && b[18] == 1)   // --19  center = 220 , 245
		       {
					if( z1 == 0)
					{
						l = 18 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 18 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 18;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(220,245);
						l = 18 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(220,245);
						m = 18 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(220,245);
						n = 18 ;
						x3 = 1 ;
					}

				       area = imagesize(190,215,250,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(190,215,250,275,buff1);
					q1 = 190 ; w1 = 215 ; e1 = 250 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(190,215,250,275,buff2);
						q2 = 190 ; w2 = 215 ; e2 = 250 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(190,215,250,275,buff3);
						q3 = 190 ; w3 = 215 ; e3 = 250 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[18] = 2 ;
		       }

      if( xcor >= 260 && xcor <= 300 && ycor >= 225 && ycor <= 265 && b[19] == 1)   // --20  center = 280 , 245
		       {
					if( z1 == 0)
					{
						l = 19 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 19 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 19;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(280,245);
						l = 19 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(280,245);
						m = 19 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(280,245);
						n = 19 ;
						x3 = 1 ;
					}

				       area = imagesize(250,215,310,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(250,215,310,275,buff1);
					q1 = 250 ; w1 = 215 ; e1 = 310 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(250,215,310,275,buff2);
						q2 = 250 ; w2 = 215 ; e2 = 310 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(250,215,310,275,buff3);
						q3 = 250 ; w3 = 215 ; e3 = 310 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[19] = 2 ;
		       }

      if( xcor >= 320 && xcor <= 360 && ycor >= 225 && ycor <= 265 && b[20] == 1)   // --21  center = 340 , 245
		       {
					if( z1 == 0)
					{
						l = 20 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 20 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 20;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(340,245);
						l = 20 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(340,245);
						m = 20 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(340,245);
						n = 20 ;
						x3 = 1 ;
					}

				       area = imagesize(310,215,370,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(310,215,370,275,buff1);
					q1 = 310 ; w1 = 215 ; e1 = 370 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(310,215,370,275,buff2);
						q2 = 310 ; w2 = 215 ; e2 = 370 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(310,215,370,275,buff3);
						q3 = 310 ; w3 = 215 ; e3 = 370 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[20] = 2 ;
		       }

		       if( xcor >= 380 && xcor <= 420 && ycor >= 225 && ycor <= 265 && b[21] == 1)   // --22  center = 400 , 245
		       {
					if( z1 == 0)
					{
						l = 21 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 21 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 21;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(400,245);
						l = 21 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(400,245);
						m = 21 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(400,245);
						n = 21 ;
						x3 = 1 ;
					}

				       area = imagesize(370,215,430,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(370,215,430,275,buff1);
					q1 = 370 ; w1 = 215 ; e1 = 430 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(370,215,430,275,buff2);
						q2 = 370 ; w2 = 215 ; e2 = 430 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(370,215,430,275,buff3);
						q3 = 370 ; w3 = 215 ; e3 = 430 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[21] = 2 ;
		       }

	   if( xcor >= 440 && xcor <= 480 && ycor >= 225 && ycor <= 265 && b[22] == 1)   // --23  center = 460 , 245
		       {
					if( z1 == 0)
					{
						l = 22 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 22 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 22;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(460,245);
						l = 22 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(460,245);
						m = 22 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(460,245);
						n = 22 ;
						x3 = 1 ;
					}

				       area = imagesize(430,215,490,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(430,215,490,275,buff1);
					q1 = 430 ; w1 = 215 ; e1 = 490 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(430,215,490,275,buff2);
						q2 = 430 ; w2 = 215 ; e2 = 490 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(430,215,490,275,buff3);
						q3 = 430 ; w3 = 215 ; e3 = 490 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[22] = 2 ;
		       }

	   if( xcor >= 500 && xcor <= 540 && ycor >= 225 && ycor <= 265 && b[23] == 1)   // --24  center = 520 , 245
		       {
					if( z1 == 0)
					{
						l = 23 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 23 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 23;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(520,245);
						l = 23 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(520,245);
						m = 23;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(520,245);
						n = 23 ;
						x3 = 1 ;
					}

				       area = imagesize(490,215,550,275);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(490,215,550,275,buff1);
					q1 = 490 ; w1 = 215 ; e1 = 550 ; r1 = 275 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(490,215,550,275,buff2);
						q2 = 490 ; w2 = 215 ; e2 = 550 ; r2 = 275 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(490,215,550,275,buff3);
						q3 = 490 ; w3 = 215 ; e3 = 550 ; r3 = 275 ;
						y3 = 1;
					}

				       count1++ ;
				       b[23] = 2 ;
		       }
   /* --------------------------- 4 th row ------------------------------------ */

	else if( xcor >= 110 && xcor <= 150 && ycor >= 285 && ycor <= 325 && b[24] == 1 ) // --- 25 center = 130 , 305
				 {
					if( z1 == 0)
					{
						l = 24 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 24;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 24;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(130,305);
						l = 24 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(130,305);
						m = 24 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(130,305);
						n = 24 ;
						x3 = 1;
					}
					area = imagesize(100,275,160,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(100,275,160,335,buff1);
						q1 = 100 ; w1 = 275 ; e1 = 160 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(100,275,160,335,buff2);
						q2 = 100 ; w2 = 275 ; e2 = 160 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(100,275,160,335,buff3);
						q3 = 100 ; w3 = 275 ; e3 = 160 ; r3 = 335 ;
						y3 = 1;
					}
					count1++ ;
					b[24] = 2 ;
				 }

	else if( xcor >= 170 && xcor <= 210 && ycor >= 285 && ycor <= 325 && b[25] == 1 ) // --- 26 center = 190 , 305
				 {
					if( z1 == 0)
					{
						l = 25 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 25;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 25;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(190,305);
						l = 25 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(190,305);
						m = 25 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(190,305);
						n = 25 ;
						x3 = 1;
					}
					area = imagesize(160,275,220,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(160,275,220,335,buff1);
						q1 = 160 ; w1 = 275 ; e1 = 220 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(160,275,220,335,buff2);
						q2 = 160 ; w2 = 275 ; e2 = 220 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(160,275,220,335,buff3);
						q3 = 160 ; w3 = 275 ; e3 = 220 ; r3 = 335 ;
						y3 = 1;
					}
					count1++ ;
					b[25] = 2 ;
				 }

	else if( xcor >= 230 && xcor <= 270 && ycor >= 285 && ycor <= 325 && b[26] == 1 ) // --- 27 center = 250 , 305
				 {
					if( z1 == 0)
					{
						l = 26 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 26;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 26;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(250,305);
						l = 26 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(250,305);
						 m = 26 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(250,305);
						n = 26 ;
						x3 = 1;
					}
					area = imagesize(220,275,280,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(220,275,280,335,buff1);
						q1 = 220 ; w1 = 275 ; e1 = 280 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(220,275,280,335,buff2);
						q2 = 220 ; w2 = 275 ; e2 = 280 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(220,275,280,335,buff3);
						q3 = 220 ; w3 = 275 ; e3 = 280 ; r3 = 335 ;
						y3 = 1;
					}
					count1++ ;
					b[26] = 2 ;
				 }

	else if( xcor >= 290 && xcor <= 330 && ycor >= 285 && ycor <= 325 && b[27] == 1 ) // --- 28 center = 310 , 305
				 {
					if( z1 == 0)
					{
						l = 27 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 27;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 27;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(310,305);
						l =  27 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(310,305);
						m = 27;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(310,305);
						n = 27 ;
						x3 = 1;
					}
					area = imagesize(280,275,340,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(280,275,340,335,buff1);
						q1 = 280 ; w1 = 275 ; e1 = 340 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(280,275,340,335,buff2);
						q2 = 280 ; w2 = 275 ; e2 = 340 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(280,275,340,335,buff3);
						q3 = 280 ; w3 = 275 ; e3 = 340 ; r3 = 335 ;
						y3 = 1;

					}
					count1++ ;
					b[27] = 2 ;
				 }

	else if( xcor >= 350 && xcor <= 390 && ycor >= 285 && ycor <= 325 && b[28] == 1 ) // --- 29 center = 370 , 305
				 {
					if( z1 == 0)
					{
						l = 28 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 28;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 28;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(370,305);
						l = 28 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(370,305);
						m = 28;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(370,305);
						n = 28 ;
						x3 = 1;
					}
					area = imagesize(340,275,400,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(340,275,400,335,buff1);
						q1 = 340 ; w1 = 275 ; e1 = 400 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(340,275,400,335,buff2);
						q2 = 340 ; w2 = 275 ; e2 = 400 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(340,275,400,335,buff3);
						q3 = 340 ; w3 = 275 ; e3 = 400 ; r3 = 335 ;
						y3 = 1;
					}
					count1++ ;
					b[28] = 2 ;
				 }

  else if( xcor >= 410 && xcor <= 450 && ycor >= 285 && ycor <= 325 && b[29] == 1 ) // --- 30 center = 430 , 305
				 {
					if( z1 == 0)
					{
						l = 29 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 29;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 29;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(430,305);
						l = 29 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(430,305);
						m = 29 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(430,305);
						n = 29;
						x3 = 1;
					}
					area = imagesize(400,275,460,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(400,275,460,335,buff1);
						q1 = 400 ; w1 = 275 ; e1 = 460 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(400,275,460,335,buff2);
						q2 = 400 ; w2 = 275 ; e2 = 460 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(400,275,460,335,buff3);
						q3 = 400 ; w3 = 275 ; e3 = 460 ; r3 = 335 ;
						y3 = 1;
					}
					count1++ ;
					b[29] = 2 ;
				 }

   else if( xcor >= 470 && xcor <= 510 && ycor >= 285 && ycor <= 325 && b[30] == 1 ) // --- 31 center = 490 , 305
				 {
					if( z1 == 0)
					{
						l = 30 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 30;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 30;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(490,305);
						l = 30 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(490,305);
						m = 30 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(490,305);
						n = 30 ;
						x3 = 1;
					}
					area = imagesize(460,275,520,335);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(460,275,520,335,buff1);
						q1 = 460 ; w1 = 275 ; e1 = 520 ; r1 = 335 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(460,275,520,335,buff2);
						q2 = 460 ; w2 = 275 ; e2 = 520 ; r2 = 335 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(460,275,520,335,buff3);
						q3 = 460 ; w3 = 275 ; e3 = 520 ; r3 = 335 ;
						y3 = 1;
					}
					count1++ ;
					b[30] = 2 ;
				 }

   /* ------------------------- 5 th row ------------------------------- */
	if( xcor >= 80 && xcor <= 120 && ycor >= 345 && ycor <= 385 && b[32] == 1)   // --33  center = 100 , 365
		       {
					if( z1 == 0)
					{
						l = 32 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 32 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 32;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(100,365);
						l = 32 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(100,365);
						m = 32 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(100,365);
						n = 32 ;
						x3 = 1 ;
					}

				       area = imagesize(70,335,130,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(70,335,130,395,buff1);
					q1 = 70 ; w1 = 335 ; e1 = 130 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(70,335,130,395,buff2);
						q2 = 70 ; w2 = 335 ; e2 = 130 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(70,335,130,395,buff3);
						q3 = 70 ; w3 = 335 ; e3 = 130 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[32] = 2 ;
		       }

	if( xcor >= 140 && xcor <= 180 && ycor >= 345 && ycor <= 385 && b[33] == 1)   // --34  center = 160 , 365
		       {
					if( z1 == 0)
					{
						l = 33 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 33 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 33;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(160,365);
						l = 33 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(160,365);
						m = 33 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(160,365);
						n = 33 ;
						x3 = 1 ;
					}

				       area = imagesize(130,335,190,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(130,335,190,395,buff1);
					q1 = 130 ; w1 = 335 ; e1 = 190 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(130,335,190,395,buff2);
						q2 = 130 ; w2 = 335 ; e2 = 190 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(130,335,190,395,buff3);
						q3 = 130 ; w3 = 335 ; e3 = 190 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[33] = 2 ;
		       }

	if( xcor >= 200 && xcor <= 240 && ycor >= 345 && ycor <= 385 && b[34] == 1)   // --35  center = 220 , 365
		       {
					if( z1 == 0)
					{
						l = 34 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 34 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 34;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(220,365);
						l = 34 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(220,365);
						m = 34 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(220,365);
						n = 34 ;
						x3 = 1 ;
					}

				       area = imagesize(190,335,250,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(190,335,250,395,buff1);
					q1 = 190 ; w1 = 335 ; e1 = 250 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(190,335,250,395,buff2);
						q2 = 190 ; w2 = 335 ; e2 = 250 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(190,335,250,395,buff3);
						q3 = 190 ; w3 = 335 ; e3 = 250 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[34] = 2 ;
		       }

   if( xcor >= 260 && xcor <= 300 && ycor >= 345 && ycor <= 385 && b[35] == 1)   // --36  center = 280 , 365
		       {
					if( z1 == 0)
					{
						l = 35 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 35 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 35;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(280,365);
						l = 35 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(280,365);
						m = 35 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(280,365);
						n = 35 ;
						x3 = 1 ;
					}

				       area = imagesize(250,335,310,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(250,335,310,395,buff1);
					q1 = 250 ; w1 = 335 ; e1 = 310 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(250,335,310,395,buff2);
						q2 = 250 ; w2 = 335 ; e2 = 310 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(250,335,310,395,buff3);
						q3 = 250 ; w3 = 335 ; e3 = 310 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[35] = 2 ;
		       }

   if( xcor >= 320 && xcor <= 360 && ycor >= 345 && ycor <= 385 && b[36] == 1)   // --37  center = 340 , 365
		       {
					if( z1 == 0)
					{
						l = 36 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 36 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 36;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(340,365);
						l = 36 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(340,365);
						m = 36 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(340,365);
						n = 36 ;
						x3 = 1 ;
					}

				       area = imagesize(310,335,370,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(310,335,370,395,buff1);
					q1 = 310 ; w1 = 335 ; e1 = 370 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(310,335,370,395,buff2);
						q2 = 310 ; w2 = 335 ; e2 = 370 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(310,335,370,395,buff3);
						q3 = 310 ; w3 = 335 ; e3 = 370 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[36] = 2 ;
		       }

   if( xcor >= 380 && xcor <= 420 && ycor >= 345 && ycor <= 385 && b[37] == 1)   // --38  center = 400 , 365
		       {
					if( z1 == 0)
					{
						l = 37 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 37 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 37;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(400,365);
						l = 37 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(400,365);
						m = 37 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(400,365);
						n = 37 ;
						x3 = 1 ;
					}

				       area = imagesize(370,335,430,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(370,335,430,395,buff1);
					q1 = 370 ; w1 = 335 ; e1 = 430 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(370,335,430,395,buff2);
						q2 = 370 ; w2 = 335 ; e2 = 430 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(370,335,430,395,buff3);
						q3 = 370 ; w3 = 335 ; e3 = 430 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[37] = 2 ;
		       }

   if( xcor >= 440 && xcor <= 480 && ycor >= 345 && ycor <= 385 && b[38] == 1)   // --39  center = 460 , 365
		       {
					if( z1 == 0)
					{
						l = 38 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 38 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 38;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(460,365);
						l = 38 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(460,365);
						m = 38 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(460,365);
						n = 38 ;
						x3 = 1 ;
					}

				       area = imagesize(430,335,490,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(430,335,490,395,buff1);
					q1 = 430 ; w1 = 335 ; e1 = 490 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(430,335,490,395,buff2);
						q2 = 430 ; w2 = 335 ; e2 = 490 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(430,335,490,395,buff3);
						q3 = 430 ; w3 = 335 ; e3 = 490 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[38] = 2 ;
		       }

   if( xcor >= 500 && xcor <= 540 && ycor >= 345 && ycor <= 385 && b[39] == 1)   // --40  center = 520 , 365
		       {
					if( z1 == 0)
					{
						l = 39 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 39 ;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 39;
						z3 = 1;
					}

					if( x1 == 0 )
					{
						pix1 = getpixel(520,365);
						l = 39 ;
						x1 = 1;
					}
					else if( x2 == 0 )
					{
						pix2 = getpixel(520,365);
						m = 39 ;
						x2 = 1;
					}
					else if( x3 == 0 )
					{
						pix3 = getpixel(520,365);
						n = 39 ;
						x3 = 1 ;
					}

				       area = imagesize(490,335,550,395);
				       if( y1 == 0)
				       {
					buff1 = malloc(area);
					getimage(490,335,550,395,buff1);
					q1 = 490 ; w1 = 335 ; e1 = 550 ; r1 = 395 ;
					y1 = 1;
					}
				       else if( y2 == 0)
					{
						buff2 = malloc(area);
						getimage(490,335,550,395,buff2);
						q2 = 490 ; w2 = 335 ; e2 = 550 ; r2 = 395 ;
						y2 = 1 ;
					}
				       else if( y3 == 0)
					{
						buff3 = malloc(area);
						getimage(490,335,550,395,buff3);
						q3 = 490 ; w3 = 335 ; e3 = 550 ; r3 = 395 ;
						y3 = 1;
					}

				       count1++ ;
				       b[39] = 2 ;
		       }
  /* --------------------------- 6 th row ----------------------------------------- */

   else if( xcor >= 110 && xcor <= 150 && ycor >= 405 && ycor <= 445 && b[40] == 1 ) // --- 41 center = 130 , 425
				 {
					if( z1 == 0)
					{
						l = 40 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 40;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 40;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(130,425);
						l = 40 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(130,425);
						m = 40 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(130,425);
						n = 40 ;
						x3 = 1;
					}
					area = imagesize(100,395,160,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(100,395,160,455,buff1);
						q1 = 100 ; w1 = 395 ; e1 = 160 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(100,395,160,455,buff2);
						q2 = 100 ; w2 = 395 ; e2 = 160 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(100,395,160,455,buff3);
						q3 = 100 ; w3 = 395 ; e3 = 160 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
					b[40] = 2 ;
				 }

     else if( xcor >= 170 && xcor <= 210 && ycor >= 405 && ycor <= 445 && b[41] == 1 ) // --- 42 center = 190 , 425
				 {
					if( z1 == 0)
					{
						l = 41 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 41;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 41;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(190,425);
						l = 41 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(190,425);
						m = 41 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(190,425);
						n = 41 ;
						x3 = 1;
					}
					area = imagesize(160,395,220,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(160,395,220,455,buff1);
						q1 = 160 ; w1 = 395 ; e1 = 220 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(160,395,220,455,buff2);
						q2 = 160 ; w2 = 395 ; e2 = 220 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(160,395,220,455,buff3);
						q3 = 160 ; w3 = 395 ; e3 = 220 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
					b[41] = 2 ;
				 }

	else if( xcor >= 230 && xcor <= 270 && ycor >= 405 && ycor <= 445 && b[42] == 1 ) // --- 43 center = 250 , 425
				 {
					if( z1 == 0)
					{
						l = 42 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 42;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 42;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(250,425);
						l = 42 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(250,425);
						m = 42 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(250,425);
						x3 = 1;
					}
					area = imagesize(220,395,280,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(220,395,280,455,buff1);
						q1 = 220 ; w1 = 395 ; e1 = 280 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(220,395,280,455,buff2);
						q2 = 220 ; w2 = 395 ; e2 = 280 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						n = 42 ;
						getimage(220,395,280,455,buff3);
						q3 = 220 ; w3 = 395 ; e3 = 280 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
					b[42] = 2 ;
				 }


	else if( xcor >= 290 && xcor <= 330 && ycor >= 405 && ycor <= 445 && b[43] == 1 ) // --- 44 center = 310 , 425
				 {
					if( z1 == 0)
					{
						l = 43 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 43;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 43;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(310,425);
						l = 43 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(310,425);
						m = 43 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(310,425);
						n = 43 ;
						x3 = 1;
					}
					area = imagesize(280,395,340,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(280,395,340,455,buff1);
						q1 = 280 ; w1 = 395 ; e1 = 340 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(280,395,340,455,buff2);
						q2 = 280 ; w2 = 395 ; e2 = 340 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(280,395,340,455,buff3);
						q3 = 280 ; w3 = 395 ; e3 = 340 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
					b[43] = 2 ;
				 }


	else if( xcor >= 350 && xcor <= 390 && ycor >= 405 && ycor <= 445 && b[44] == 1 ) // --- 45 center = 370 , 425
				 {
					if( z1 == 0)
					{
						l = 44 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 44;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 44;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(370,425);
						l = 44 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(370,425);
						m = 44 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(370,425);
						n = 44 ;
						x3 = 1;
					}
					area = imagesize(340,395,400,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(340,395,400,455,buff1);
						q1 = 340 ; w1 = 395 ; e1 = 400 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(340,395,400,455,buff2);
						q2 = 340 ; w2 = 395 ; e2 = 400 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(340,395,400,455,buff3);
						q3 = 340 ; w3 = 395 ; e3 = 400 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
					b[44] = 2 ;
				 }


	else if( xcor >= 410 && xcor <= 450 && ycor >= 405 && ycor <= 445 && b[45] == 1 ) // --- 46 center = 430 , 425
				 {
					if( z1 == 0)
					{
						l = 45 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 45;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 45;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(430,425);
						l = 45 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(430,425);
						m = 45 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(430,425);
						n = 45 ;
						x3 = 1;
					}
					area = imagesize(400,395,460,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(400,395,460,455,buff1);
						q1 = 400 ; w1 = 395 ; e1 = 460 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(400,395,460,455,buff2);
						q2 = 400 ; w2 = 395 ; e2 = 460 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(400,395,460,455,buff3);
						q3 = 400 ; w3 = 395 ; e3 = 460 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
				b[45] = 2 ;
				 }


	else if( xcor >= 470 && xcor <= 510 && ycor >= 405 && ycor <= 445 && b[46] == 1 ) // --- 47 center = 490 , 425
				 {
					if( z1 == 0)
					{
						l = 46 ;
						z1 = 1;
					}
					else if(z2 == 0)
					{
						m = 46;
						z2 = 1;
					}
					else if(z3 == 0)
					{
						n = 46;
						z3 = 1;
					}
					if( x1 == 0 )
					{
						pix1 = getpixel(490,425);
						l = 46 ;
						x1 = 1;
					}
					else if(x2 == 0)
					{
						pix2 = getpixel(490,425);
						m = 46 ;
						x2 = 1;
					}
					else if(x3 == 0)
					{
						pix3 = getpixel(490,425);
						n = 46 ;
						x3 = 1;
					}
					area = imagesize(460,395,520,455);
					if(y1 == 0)
					{
						buff1 = malloc(area);
						getimage(460,395,520,455,buff1);
						q1 = 460 ; w1 = 395 ; e1 = 520 ; r1 = 455 ;
						y1 = 1;
					}
					else if(y2 == 0)
					{
						buff2 = malloc(area);
						getimage(460,395,520,455,buff2);
						q2 = 460 ; w2 = 395 ; e2 = 520 ; r2 = 455 ;
						y2 = 1;
					}
					else if(y3 == 0)
					{
						buff3 = malloc(area);
						getimage(460,395,520,455,buff3);
						q3 = 460 ; w3 = 395 ; e3 = 520 ; r3 = 455 ;
						y3 = 1;
					}
					count1++ ;
				b[46] = 2 ;
				 }

			if( count1 == 1 && flag1 == 0 )
			{
				flag1 = 1 ;
				if( pix1 == BLUE )
				{
					setcolor(GREEN);
					circle(q1+30,w1+30,20);
					setfillstyle(5,YELLOW);
					floodfill(q1+30,w1+30,GREEN);
				}
				else
				{
				setcolor(BLUE);
			       circle(q1+30,w1+30,20);
			       setfillstyle(5,YELLOW);
				floodfill(q1+30,w1+30,BLUE) ;
				}
			}

			else if( count1 == 2  && flag2 == 0 )
			{
				flag2 = 1 ;
				if( pix1 ==  pix2)
				{
				if( pix2 == BLUE )
				{
					setcolor(GREEN);
					circle(q2+30,w2+30,20);
					setfillstyle(5,YELLOW);
					floodfill(q2+30,w2+30,GREEN);
				}
				else
				{
				setcolor(BLUE);
			       circle(q2+30,w2+30,20);
			       setfillstyle(5,YELLOW);
				floodfill(q2+30,w2+30,BLUE) ;
				}
				}
				else
				{  //     printf("what");
					sound(150);
					if( pix1 == BLACK )
					{
						setcolor(WHITE);
						circle(q1+30,w1+30,20);
						setfillstyle(1,BLACK);
						floodfill(q1+30,w1+30,WHITE);
					}
					else
					{       int b1 , b2 , b3 , b4 ;
				      //		printf("you");
						setcolor(pix1);
						setfillstyle(0,pix1);
						circle(q1+30,w1+30,30);

						floodfill(q1+30,w1+30,pix1) ;
					//	printf("go");
						setfillstyle(1,pix1);
						floodfill(q1+30,w1+30,pix1);
						setcolor(BLACK);
						circle(q1+30,w1+30,20);
					 }
						delay(10);

						flag1 = 0 ;
						flag2 = 0 ;
						b[l] = 1 ;
						b[m] = 1 ;
						count1 = 0 ;
						x1 = 0 ;
						x2 = 0 ;
						y1 = 0 ;
						y2 = 0 ;
						z1 = 0 ;
						z2 = 0 ;

						nosound();

				}
			}
				if( count1 == 3  && flag3 == 0 )
				{
				    //	printf("Just");
					flag3 = 1 ;
					if( pix2 == pix3  )
					{
						int b1 , b2 , b3 , b4 ;
						putimage(q1,w1,buff1,XOR_PUT);
						putimage(q2,w2,buff2,XOR_PUT);
						putimage(q3,w3,buff3,XOR_PUT);
						free(buff1);
						free(buff2);
						free(buff3);

						b3 = b1 = q1 + 30 ;
						b4 = b2 = w1 + 30 ;
						b1 = b1 - 20 ;
						b2 = b2 - 20 ;
						b3 = b3 + 20 ;
						b4 = b4 + 20 ;
						area = imagesize(b1,b2,b3,b4) ;
						buff1 = malloc(area);
						getimage(b1,b2,b3,b4,buff1);
						putimage(b1,b2,buff1,XOR_PUT);
						free(buff1);

						b3 = b1 = q2 + 30 ;
						b4 = b2 = w2 + 30 ;
						b1 = b1 - 20 ;
						b2 = b2 - 20 ;
						b3 = b3 + 20 ;
						b4 = b4 + 20 ;
						area = imagesize(b1,b2,b3,b4) ;
						buff2 = malloc(area);
						getimage(b1,b2,b3,b4,buff2);
						putimage(b1,b2,buff1,XOR_PUT);
						free(buff2);

						count2 -= 3 ;
						flag1 = 0 ;
						flag2 = 0 ;
						flag3 = 0 ;
						count1 = 0 ;
						x1 = 0 ;
						x2 = 0 ;
						x3 = 0 ;
						y1 = 0 ;
						y2 = 0 ;
						y3 = 0 ;
						z1 = 0 ;
						z2 = 0 ;
						z3 = 0 ;


					}
					else
					{
						sound(150);
						if( pix1 == BLACK )
						{
							setcolor(WHITE);
							circle(q1+30,w1+30,20);
							setfillstyle(1,BLACK);
							floodfill(q1+30,w1+30,WHITE);
						}
						else
						{

						   //	printf("you");
							setcolor(pix1);
							setfillstyle(0,pix1);
							circle(q1+30,w1+30,30);

							floodfill(q1+30,w1+30,pix1) ;
						     //	printf("go");
							setfillstyle(1,pix1);
							floodfill(q1+30,w1+30,pix1);
							setcolor(BLACK);
							circle(q1+30,w1+30,20);
						 }


						if( pix2 == BLACK )
						{
							setcolor(WHITE);
							circle(q2+30,w2+30,20);
							setfillstyle(1,BLACK);
							floodfill(q2+30,w2+30,WHITE);
						}
						else
						{

					       //		printf("you");
							setcolor(pix2);
							setfillstyle(0,pix2);
							circle(q2+30,w2+30,30);

							floodfill(q2+30,w2+30,pix2) ;
						 //	printf("go");
							setfillstyle(1,pix2);
							floodfill(q2+30,w2+30,pix2);
							setcolor(BLACK);
							circle(q2+30,w2+30,20);
						 }
						delay(10);

						flag1 = 0 ;
						flag2 = 0 ;
						flag3 = 0 ;
						b[l] = 1 ;
						b[m] = 1 ;
						b[n] = 1 ;
						count1 = 0 ;
						x1 = 0 ;
						x2 = 0 ;
						x3 = 0 ;
						y1 = 0 ;
						y2 = 0 ;
						y3 = 0 ;
						z1 = 0 ;
						z2 = 0 ;
						z3 = 0 ;
						nosound() ;
					}
			       }

		}

	}

	return ;
 }


int hash(int x)
{
	int i;
	       if( f == 1)
		{
			for( i = 0 ; i < 16 ; i++ )
			a[i] = 88 ;
		}

		f = 0 ;

		if(a[x] == 88)
		{
			a[x] = x ;
			return 0 ;
		}
		else
		return 1 ;

}



initmouseptr()
{
	i.x.ax = 0 ;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

showmouseptr()
{
	i.x.ax = 1 ;
	int86(0x33,&i,&o);
	return ;
}

restrictmouseptr(int x1 ,int y1 ,int x2 ,int y2)
{
	i.x.ax = 7 ;
	int86(0x33,&i,&o);
	i.x.cx = x1 ;
	i.x.dx = x2 ;

	i.x.ax = 8 ;
	int86(0x33,&i,&o);
	i.x.cx = y1 ;
	i.x.dx = y2 ;

	return ;
}

getmousepos(int *button,int *x,int *y)
{
	i.x.ax = 3 ;
	int86(0x33,&i,&o);
	*button = o.x.bx ;
	*x = o.x.cx ;
	*y = o.x.dx ;

	return ;
}

hidemouseptr()
{
	i.x.ax = 2 ;
	int86(0x33,&i,&o);
	return ;
}

print()
{
	int i ;
	for( i = 0 ; i < 16 ; i++ )
	{
		printf(" %d ",a[i]);
	}
	return ;

}

  cake()
{

	int gd = DETECT , gm , i ;
	char str[40] ;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	settextstyle(TRIPLEX_FONT,VERT_DIR,3);
    //	outtextxy(0,60,"Happy Birthday");

	setcolor(GREEN);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
     //	outtextxy(20,20," To");

	settextstyle(SCRIPT_FONT,0,4);
	setcolor(13);
    //	outtextxy(100,0,"Vishnu Priya");

	settextstyle(TRIPLEX_FONT,0,3);
	setcolor(BLUE);
     //	outtextxy(315,10,"FROM");

	settextstyle(SCRIPT_FONT,0,4);
	setcolor(WHITE);
     //	outtextxy(400,0,"Akshath Varugeese");

	settextstyle(TRIPLEX_FONT,0,6);
	setcolor(12);
    //	outtextxy(550,50,"&");

	settextstyle(SCRIPT_FONT,VERT_DIR,4);
	setcolor(15);
   //	outtextxy(580,60,"His Computer");
	/* --------------- For the candeles --------------- */

	setfillstyle(1,GREEN);
	bar(170,140,180,80);

	setfillstyle(1,MAGENTA);
	bar(260,140,270,80);

	setfillstyle(1,LIGHTCYAN);
	bar(350,140,360,80);

	setfillstyle(1,LIGHTGRAY);
	bar(440,140,450,80);

	/* ----------------- FLAME FOR THE CANDLE ;) ------------------- */

	setcolor(YELLOW);
	setfillstyle(1,YELLOW);
	arc(175,70,180,360,10);
	moveto(185,70);
	lineto(175,50);
	moveto(165,70);
	lineto(175,50);
	floodfill(175,70,YELLOW);

	arc(265,70,180,360,10);
	moveto(275,70);
	lineto(265,50);
	moveto(255,70);
	lineto(265,50);
	floodfill(265,70,YELLOW);

	arc(355,70,180,360,10);
	moveto(365,70);
	lineto(355,50);
	moveto(345,70);
	lineto(355,50);
	floodfill(355,70,YELLOW);

	arc(445,70,180,360,10);
	moveto(455,70);
	lineto(445,50);
	moveto(435,70);
	lineto(445,50);
	floodfill(445,70,YELLOW);

	/* ----------- Cherry ------------ */

	setcolor(RED);
	setfillstyle(1,RED);

	circle(115,130,10);
	floodfill(115,130,RED);

	circle(150,130,10);
	floodfill(150,130,RED);

	circle(200,130,10);
	floodfill(200,130,RED);

	circle(240,130,10);
	floodfill(240,130,RED);

	circle(290,130,10);
	floodfill(290,130,RED);

	circle(330,130,10);
	floodfill(330,130,RED);

	circle(380,130,10);
	floodfill(380,130,RED);

	circle(420,130,10);
	floodfill(420,130,RED);

	circle(470,130,10);
	floodfill(470,130,RED);

	circle(505,130,10);
	floodfill(505,130,RED);

	/* ----------------- For the Cake :D --------------- */

	setcolor(BROWN);
	setfillstyle(4,BROWN);
	bar(40,300,581,390);
	rectangle(40,300,581,390);

	setcolor(BROWN);
	setfillstyle(5,BROWN);
	bar(60,230,562,300);
	rectangle(60,230,562,300);

	setfillstyle(4,BROWN);
	bar(80,180,540,230);
	rectangle(80,180,540,230);

	setcolor(BROWN);
	setfillstyle(5,BROWN);
	bar(100,140,520,180);
	rectangle(100,140,520,180);


	/* --------------------- Cream Part ------------------------ */

		/* ------ 1ST ------- */

	setcolor(WHITE);
	setfillstyle(1,WHITE);
     /*	ellipse(120,140,180,360,20,20);
	line(100,140,140,140);
	floodfill(120,150,WHITE);*/

      //	int i ;
	for( i = 120 ; i <= 500 ; i = i + 40 )
	{
		ellipse(i,140,180,360,20,20);
		line(i-20,140,i+20,140);
		floodfill(i,150,WHITE);
	}

	arc(520,140,180,270,20);
	moveto(500,140);
	lineto(520,140);
	lineto(520,160);
	floodfill(510,145,WHITE);

		  /* ----- 4TH ----- */

	for( i = 60 ; i <= 571 ; i = i+40 )
	{
		ellipse(i,300,180,360,20,20);
		line(i-20,300,i+20,300);
		floodfill(i,310,WHITE);
	}

	arc(581,300,180,270,20);
	moveto(581,320);
	lineto(581,300);
	moveto(561,300);
	lineto(581,300);
	floodfill(576,310,WHITE);

		/* ------ 3 RD ------ */

	for ( i = 80 ; i <= 542 ; i = i + 40 )
	{
		ellipse(i,230,180,360,20,20);
		line(i-20,230,i+20,230);
		floodfill(i,240,WHITE);
	}

	arc(561,230,180,270,20);
	moveto(561,250);
	lineto(561,230);
	moveto(541,230);
	lineto(561,230);
	floodfill(552,240,WHITE);

		/* -------- 2ND --------- */

	for( i = 100 ; i <= 520 ; i = i + 40 )
	{
		ellipse(i,180,180,360,20,20);
		line(i-20,180,i+20,180);
		floodfill(i,190,WHITE);
	}

	arc(540,180,180,270,20);
	moveto(540,200);
	lineto(540,180);
	moveto(520,180);
	lineto(540,180);
	floodfill(530,190,WHITE);



	/* ---------- For the Base ----------- */

	setcolor(BLUE);
	setfillstyle(1,BLUE);
	bar(20,390,600,400);
	rectangle(20,390,600,400);

	getch();

 return ;
}



