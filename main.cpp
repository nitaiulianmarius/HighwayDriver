#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<graphics.h>

#define key(x) GetAsyncKeyState(x)
using namespace std;

	int u=85,maxx=8*u,maxy=2.4*u;
	int nmasini,ncoada,banda,timestart; // numar de masini, numar de masini in linie, banda masinii, contor de update
	int prima;
	int castig=1;
	int x,y; // pt maus
	int pauza=0;
	int Cremorca,Ccabina,Cgeamuri,Croti,Cbarijos,model;


void FillCircle(int x,int y,int r,int color)
{
     setcolor(color);
     circle(x,y,r);
     for(int i=x-r;i<=x+r;i++)
             for(int j=y-r;j<=y+r;j++)
             {
                     int dx=x-i,dy=y-j;
                     if(dx*dx+dy*dy<=r*r)
                          putpixel(i,j,color);
             }
}



bool Click(int x1,int y1,int x2,int y2)
{
//	getmouseclick(WM_LBUTTONDOWN,x,y);

	if(x1<x&&x<x2&&y1<y&&y<y2)
		return true;
	return false;
}



struct Scor
{
	int nr;
	int x,y;

	Scor()
	{
		nr=0;
		x=6.8*u;
		y=2.2*u;
	}

	void draw()
	{
		char s[10];
		sprintf(s,"Scor: %d",nr);
		setcolor(WHITE);
		outtextxy(x,y,s);
	}

	void del()
	{
		setfillstyle(0,0);
		bar(x,y,x+100,y+20);
	}

	void update()
	{
		del();
		nr+=10;
		draw();
	}

}scor;



struct Player
{
	int y;
	Player();

	void draw()
	{
               switch ( model )
            {
            
            	case 1:
            	
            		Cremorca 	=LIGHTBLUE;
            		Ccabina		=RED;
            		Cgeamuri	=BLUE;
            		Croti		=DARKGRAY;
            		Cbarijos	=YELLOW;
            
            		break;
            
            	case 2:
            
            		Cremorca 	=GREEN;
            		Ccabina		=YELLOW;
            		Cgeamuri	=LIGHTBLUE;
            		Croti		=DARKGRAY;
            		Cbarijos	=YELLOW;
            
            		break;
            
            	case 3:
            
            		Cremorca 	=YELLOW;
            		Ccabina		=MAGENTA;
            		Cgeamuri	=LIGHTBLUE;
            		Croti		=RED;
            		Cbarijos	=GREEN;
            
            		break;
            
            	case 4:
            
            		Cremorca 	=YELLOW;
            		Ccabina		=RED;
            		Cgeamuri	=LIGHTBLUE;
            		Croti		=BLUE;
            		Cbarijos	=GREEN;
            
            		break;
            
            	case 5:
            
            		Cremorca 	=MAGENTA;
            		Ccabina		=RED;
            		Cgeamuri	=LIGHTBLUE;
            		Croti		=LIGHTGRAY;
            		Cbarijos	=YELLOW;
            
            		break;

				case 6:
                     
                    Cremorca	=GREEN;
					Ccabina		=RED;
					Cgeamuri	=BLUE;
					Croti		=DARKGRAY;
					Cbarijos	=LIGHTGRAY;
					
					break;
            }
		setfillstyle(1,Cremorca);
		bar(0.08*u,y*u+0.12*u,1.35*u,y*u+0.85*u);
		setfillstyle(1,Cgeamuri);
		bar(1.4*u+1,y*u+0.08*u,1.85*u,y*u+0.32*u);
		setfillstyle(1,Ccabina);
		bar(1.62*u,y*u+0.08*u,1.63*u,y*u+0.32*u);
		bar(1.4*u+1,y*u+0.32*u,1.85*u,y*u+0.85*u);
		setfillstyle(1,Cbarijos);
		bar(0.08*u,y*u+0.85*u,0.17*u,y*u+0.95*u);
		bar(1.704*u,y*u+0.85*u,1.85*u,y*u+0.95*u);
		bar(0.42*u,y*u+0.85*u,1.58*u,y*u+0.95*u);
		FillCircle(0.23*u,y*u+0.91*u,0.06*u,Croti);
		FillCircle(0.35*u,y*u+0.91*u,0.06*u,Croti);
		FillCircle(1.64*u,y*u+0.91*u,0.06*u,Croti);
	}

	void del()
	{
		setfillstyle(0,0);
		bar(0,y*u,2*u,y*u+u);
	}

	void update()
	{
		del();
		y=1-y;
		draw();
	}

}eu;


Player::Player()
{	
    y=1;	

}


struct Inamic
{
	int x;
	int y;
	int model;
	short lungime;

	Inamic()
	{
		x=maxx;
	}

	void draw()
	{

    switch(model){
       case 1:

            setfillstyle(1,GREEN);
            bar(x+0.08*u,y*u+0.76*u,x+0.9*u,y*u+0.61*u);
            setfillstyle(1,YELLOW);
            bar(x+0.08*u,y*u+0.76*u,x+0.15*u,y*u+0.82*u);
            bar(x+0.235*u,y*u+0.76*u,x+0.7*u,y*u+0.82*u);
            bar(x+0.79*u,y*u+0.76*u,x+0.9*u,y*u+0.82*u);
            setfillstyle(1,BLUE);
            bar(x+0.18*u,y*u+0.61*u+1,x+0.65*u,y*u+0.4*u);
            setcolor(BLUE);
            for(int i=0.12*u;i<=0.18*u;i++)
                line(x+0.18*u,y*u+0.4*u,x+i,y*u+0.61*u);
            for(int i=0.65*u;i<=0.82*u;i++)
                line(x+0.65*u,y*u+0.4*u,x+i,y*u+0.61*u);
            FillCircle(x+0.193*u,y*u+0.8*u,0.04*u,DARKGRAY);
            FillCircle(x+0.745*u,y*u+0.8*u,0.04*u,DARKGRAY);
            lungime=1;

        break;

       case 2:

            setfillstyle(1,4);
            bar(x+0.08*u,y*u+0.69*u,x+0.9*u,y*u+0.76*u);
            bar(x+0.08*u,y*u+0.62*u,x+0.7*u,y*u+0.69*u);
            setfillstyle(1,BLACK);
            bar(x+0.24*u,y*u+0.54*u,x+0.26*u,y*u+0.62*u);
            bar(x+0.46*u,y*u+0.54*u,x+0.48*u,y*u+0.62*u);
            setfillstyle(1,11/*LIGHTGRAY*/);
            bar(x+0.08*u,y*u+0.76*u,x+0.9*u,y*u+0.82*u);
            setfillstyle(1,DARKGRAY);
            bar(x+0.23*u,y*u+0.62*u,x+0.24*u,y*u+0.76*u);
            bar(x+0.46*u,y*u+0.62*u,x+0.47*u,y*u+0.76*u);
            bar(x+0.69*u,y*u+0.62*u,x+0.7*u,y*u+0.76*u);
            bar(x+0.49*u,y*u+0.63*u,x+0.52*u,y*u+0.64*u);
            bar(x+0.26*u,y*u+0.63*u,x+0.29*u,y*u+0.64*u);
            FillCircle(x+0.193*u,y*u+0.8*u,0.04*u,DARKGRAY);
            FillCircle(x+0.75*u,y*u+0.8*u,0.04*u,DARKGRAY);
            setcolor(4);
            for(int i=0.62*u;i<=0.7*u;i++)
               line(x+0.89*u,y*u+0.69*u,x+0.7*u,y*u+i);
            setcolor(BLUE);
            for(int i=0.52*u;i<=0.62*u;i++)
               line(x+0.7*u,y*u+0.62*u,x+0.66*u,y*u+i);
            setcolor(11);
            for(int i=0.59*u;i<=0.62*u;i++)
               line(x+0.08*u,y*u+0.62*u,x+0.19*u,y*u+i);
            lungime=1;

        break;

        case 3:

            setfillstyle(1,LIGHTGREEN);
            bar(x+0.06*u,y*u+0.65*u,x+0.64*u,y*u+0.73*u);
            bar(x+0.06*u,y*u+0.65*u,x+0.09*u,y*u+0.5*u);
            bar(x+0.61*u,y*u+0.65*u,x+0.64*u,y*u+0.5*u);
            setfillstyle(1,14);
            bar(x+0.65*u+1,y*u+0.35*u,x+0.95*u,y*u+0.76*u);
            bar(x+0.06*u,y*u+0.76*u,x+0.144*u,y*u+0.82*u);
            bar(x+0.26*u,y*u+0.76*u,x+0.735*u,y*u+0.82*u);
            bar(x+0.85*u,y*u+0.76*u,x+0.95*u,y*u+0.82*u);
            bar(x+0.144*u,y*u+0.76*u,x+0.26*u,y*u+0.77*u);
            setfillstyle(1,DARKGRAY);
            bar(x+0.12*u,y*u+0.73*u,x+0.15*u,y*u+0.76*u);
            bar(x+0.5*u,y*u+0.73*u,x+0.53*u,y*u+0.76*u);
            bar(x+0.8*u,y*u+0.56*u,x+0.84*u,y*u+0.575*u);
            bar(x+0.77*u,y*u+0.5*u,x+0.78*u,y*u+0.76*u);
            setfillstyle(1,LIGHTBLUE);
            bar(x+0.65*u,y*u+0.35*u,x+0.95*u,y*u+0.5*u);
            setfillstyle(1,BLUE);
            bar(x+0.77*u,y*u+0.35*u,x+0.785*u,y*u+0.5*u);
            FillCircle(x+0.2*u,y*u+0.82*u,0.05*u,DARKGRAY);
            FillCircle(x+0.79*u,y*u+0.815*u,0.05*u,DARKGRAY);
            setcolor(GREEN);
            rectangle(x+0.77*u,y*u+0.5*u,x+0.94*u,y*u+0.755*u);
            lungime=1;

            break;

		case 4:

			setfillstyle(1,RED);
			bar(x+0.08*u,y*u+0.58*u,x+0.75*u,y*u+0.75*u);
			bar(x+0.08*u,y*u+0.4*u,x+0.43*u,y*u+0.65*u+1);
			setcolor(11);
			setfillstyle(1,11);
			bar(x+0.08*u,y*u+0.25*u,x+0.35*u,y*u+0.4*u);
			setfillstyle(1,BLUE);
			bar(x+0.26*u,y*u+0.25*u,x+0.27*u+1,y*u+0.4*u);
			setfillstyle(1,YELLOW);
			bar(x+0.65*u,y*u+0.615*u,x+0.69*u,y*u+0.645*u);
			setfillstyle(1,BROWN);
			bar(x+0.25*u,y*u+0.55*u,x+0.43*u,y*u+0.56*u);
			bar(x+0.25*u,y*u+0.4*u,x+0.26*u,y*u+0.56*u);
			bar(x+0.42*u,y*u+0.4*u,x+0.43*u,y*u+0.56*u);
			bar(x+0.25*u,y*u+0.4*u,x+0.43*u,y*u+0.41*u);
			bar(x+0.35*u,y*u+0.44*u,x+0.38*u,y*u+0.45*u);
			bar(x+0.6*u,y*u+0.5*u,x+0.65*u,y*u+0.58*u);
			bar(x+0.619*u,y*u+0.45*u,x+0.63*u+1,y*u+0.5*u);
			FillCircle(x+0.67*u,y*u+0.77*u,0.07*u,DARKGRAY);
			setfillstyle(1,DARKGRAY);
			fillellipse(x+0.2*u,y*u+0.7*u,0.14*u,0.14*u);
			FillCircle(x+0.65*u,y*u+0.63*u,0.015*u,YELLOW);
			for(int i=0.25*u;i<=0.4*u;i++)
			   line(x+0.43*u,y*u+0.4*u,x+0.35*u,y*u+i);
             lungime=1;

			break;
			
		case 5:
			
			setfillstyle(1,RED);
			bar(x+0.08*u,y*u+0.75*u,x+0.15*u,y*u+0.83*u);
			bar(x+0.35*u,y*u+0.75*u,x+1.6*u,y*u+0.83*u);
			bar(x+1.7*u,y*u+0.75*u,x+1.8*u,y*u+0.83*u);
			setfillstyle(1,YELLOW);
			bar(x+0.08*u,y*u+0.45*u,x+1.8*u,y*u+0.75*u);
			setfillstyle(1,LIGHTBLUE);
			bar(x+1.53*u,y*u+0.2*u,x+1.8*u,y*u+0.52*u);
			bar(x+0.08*u,y*u+0.2*u,x+1.53*u,y*u+0.45*u);
			setfillstyle(1,DARKGRAY);
			bar(x+1.531*u,y*u+0.2*u,x+1.54*u,y*u+0.52*u);
			bar(x+1.22*u,y*u+0.2*u,x+1.23*u,y*u+0.45*u);
			bar(x+0.91*u,y*u+0.2*u,x+0.92*u,y*u+0.45*u);
			bar(x+0.6*u,y*u+0.2*u,x+0.61*u,y*u+0.45*u);
			bar(x+0.3*u,y*u+0.2*u,x+0.31*u,y*u+0.45*u);
			setfillstyle(1,BROWN);
			bar(x+1.53*u,y*u+0.52*u+1,x+1.8*u,y*u+0.53*u);
			bar(x+1.53*u,y*u+0.52*u+1,x+1.54*u,y*u+0.75*u);
			bar(x+1.79*u,y*u+0.52*u+1,x+1.8*u,y*u+0.75*u);
			bar(x+1.53*u,y*u+0.74*u,x+1.8*u,y*u+0.75*u);
			bar(x+1.7*u,y*u+0.56*u,x+1.74*u,y*u+0.58*u);
			FillCircle(x+0.2*u,y*u+0.8*u,0.05*u,DARKGRAY);
			FillCircle(x+0.3*u,y*u+0.8*u,0.05*u,DARKGRAY);
			FillCircle(x+1.65*u,y*u+0.8*u,0.05*u,DARKGRAY);
			lungime=2;

			break;
			
            }
	}

	void del()
	{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,10+y*u,x+lungime*u+10,u+y*u-10);
	}

	void update()
	{
		del();

		if(scor.nr<100)
			x-=3;
		else
			if(scor.nr<300)
				x-=6;
			else
				if(scor.nr<500)
					x-=9;
				else
					if(scor.nr<700)
						x-=12;
					else
						if(scor.nr<900)
							x-=15;
						else
							if(scor.nr<1200)
								x-=18;
							else
								if(scor.nr<1500)
									x-=21;
								else
									if(scor.nr<1800)
										x-=24;
									else
										if(scor.nr<2000)
											x-=27;
										else
											if(scor.nr<2100)
												x-=31;
											else
												x-=35;
		draw();
	}

}pc[1000];


struct Button
{
	int x1,y1,x2,y2;
	int nr;
	int itower;
	char text[30];

	void create(int Nr,int X1,int Y1,int X2,int Y2,char *Text)
	{
	    	nr=Nr;
            x1=X1;
            x2=X2;
            y1=Y1+5;
            y2=Y2+5;
            strcpy(text,Text);
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(x1,y1,x2,y2);
            setfillstyle(0,BLACK);
            bar(x1+5,y1+5,x2-5,y2-5);
            setlinestyle(SOLID_LINE,0,3);
            setcolor(LIGHTGREEN);
            rectangle(x1,y1,x2,y2);
            int color;
            for(int i=x1+5;i<=x2-5;i+=5)
                for(int j=y1+5;j<=y2-5;j+=5,color=rand()%100)
                {
                    if(color<70)
                        color=BLACK;
                    else
                        color=YELLOW;
                    putpixel(i,j,color);
                }
            outtextxy((x1+x2)/2-textwidth(text)/2,(y1+y2)/2-textheight(text)/2,text);
	}

	bool click(int nr);

}buton[30];


bool Button::click(int nr)
{
	    	if(buton[nr].x1<=x&&x<=buton[nr].x2)
                if(buton[nr].y1<=y&&y<=buton[nr].y2)
                    return true;
            return false;
}

void VerifKey()
{
	if((key(VK_UP)&&eu.y==1)||(key(VK_DOWN)&&!eu.y))
		eu.update();
}



void DisplayAndInitGame()
{
	initwindow(maxx,maxy,"RaceGame",getmaxwidth()/2-maxx/2,getmaxheight()/2-maxy/2);
    srand(time(NULL));
	eu.draw();
	scor.draw();

	timestart=clock();
	do
	{
		VerifKey();
	}while(clock()-timestart<3000);

	pc[nmasini].y=rand()%2;
	pc[nmasini].draw();
	ncoada=rand()%4;
}




void UpdatePc()
{
	for(int i=prima;i<=nmasini;i++)
	{
		pc[i].update();

		if(pc[i].x<-pc[i].lungime*u)
		{
			scor.update();
			prima++;
		}
		if(pc[i].y==eu.y&&pc[i].x>=-pc[i].lungime*u&&pc[i].x<=2*u)
			castig=0;
	}

	if(pc[nmasini].x+pc[nmasini].lungime*u+15<maxx&&ncoada)
	{
		pc[++nmasini].y=pc[nmasini-1].y;
		pc[nmasini].model=rand()%5+1;
		ncoada--;
	}

	if(pc[nmasini].x+pc[nmasini].lungime*u+3*u<maxx&&!ncoada)
	{
		ncoada=rand()%3+1;
		pc[++nmasini].y=1-pc[nmasini-1].y;
		pc[nmasini].model=rand()%5+1;
	}

}



void PlayTheGame()
{
     
		initwindow(660,290,"Highway Driver - Masina ta",getmaxwidth()/2-300,getmaxheight()/2-200);
		
        
        eu.y=0;
		u+=25;
		
        setviewport(0,20,1000,1000,1);
        model=1;
		eu.draw();
		
		setviewport(2*u,20,1000,1000,1);
		model=2;
		eu.draw();
		
		setviewport(4*u,20,1000,1000,1);
		model=3;
		eu.draw();
		
		setviewport(0,u+40,1000,1000,1);
		model=4;
		eu.draw();
		
		setviewport(2*u,u+40,1000,1000,1);
		model=5;
		eu.draw();
		
		setviewport(4*u,u+40,1000,1000,1);
		model=6;
		eu.draw();
		
		
		setviewport(0,0,1000,1000,1);
		
		
		do
		{
         getmouseclick(WM_LBUTTONDOWN,x,y);
		
		// #1 0,20
		if(0<x&&x<2*u && 20<y&&y<20+u)
			model=1;
		
		// #2 2*u,20
		else if(2*u<x&&x<4*u && 20<y&&y<20+u)
			model=2;
		
		// #3 4*u,20
		else if(4*u<x&&x<6*u && 20<y&&y<20+u)
			model=3;
		
		// #4 0,u+40
		else if(0<x&&x<2*u && u+40<y&&y<2*u+40)
			model=4;
		
		// #5 2*u,u+40
		else if(2*u<x&&x<4*u && u+40<y&&y<2*u+40)
			model=5;
		
		// #6 4*u,u+40
		else if(4*u<x&&x<6*u && u+40<y&&y<2*u+40)
			model=6;
		
		else
		  x=-1;
		
        }
        while(x==-1);
        u-=25;
		closegraph();

	DisplayAndInitGame();

	while(castig)
	{
	
    	if(!pauza)
    	{
    		VerifKey();
    		int time=clock();
    		if(time-timestart>10)
        	{
        	   UpdatePc();
        	   timestart=time;
            }
    
            if(key(VK_LEFT))
               delay(50);
    
            if(!key(VK_RIGHT))
               delay(30);
    	}
     
     for(int i=0;i<1000;i++)
            if(kbhit())
            {
    			char ch;
    			ch=getch();
    			if(ch=='p')
    			{
    				pauza=1-pauza;
    				if(pauza)
    				{
    					setcolor(RED);
    					outtextxy(6.45*u,2.2*u,"P");
    				}
    				else
    				{
    					setfillstyle(1,BLACK);
    					bar(6.3*u,2.1*u,6.3*u+30,2.2*u+30);
    				}
                }
    					
    				
            }
	}
	closegraph();
	initwindow(280,80,"Ai pierdut",getmaxwidth()/2-140,getmaxheight()/2-40);
	char score[4]; sprintf(score,"Scor: %d",scor.nr);
	outtextxy(100,30,score);
	Sleep(5000);
    closegraph();
}


void Instructiuni()
{
initwindow(700,560,"Highway Driver - Instructiuni",getmaxwidth()/2-350,getmaxheight()/2-280);


settextstyle(1,HORIZ_DIR,3);
outtextxy(350-textwidth("Highway Driver")/2,40,"Highway Driver"); 

settextstyle(1,HORIZ_DIR,1);
outtextxy(400,500,"Joc creat de:");
outtextxy(320,515,"Nita Iulian & Stefan Vlad");

outtextxy(60,120,"INSTRUCTIUNI :");
outtextxy(60,170,"Acceleratie -> sageata dreapta");
outtextxy(60,200,"Frana -> sageata stanga");
outtextxy(60,230,"Deplasare jos -> sageata jos");
outtextxy(60,260,"Deplasare sus -> sageata sus");
outtextxy(60,290,"Pauza -> P");


buton[4].create(4,60,450,180,515,"Start");

clearmouseclick(WM_LBUTTONDOWN);
do
{
 getmouseclick(WM_LBUTTONDOWN,x,y);
}while(!buton[4].click(4));

closegraph();
PlayTheGame();
//    setfillstyle(1,WHITE);
 //   bar(60,450,180,515);
}


int main()
{

    initwindow(280,180,"Highway Driver - Main menu",getmaxwidth()/2-140,getmaxheight()/2-90);
    buton[0].create(0,10,10,270,50,"Incepe jocul");
	buton[1].create(1,10,60,270,100,"Instructiuni");
	buton[2].create(2,10,110,270,160,"Inchide jocul");


	do
	{
		getmouseclick(WM_LBUTTONDOWN,x,y);
	}while(x==-1);

	closegraph();

    if(buton[0].click(0))
    {

		PlayTheGame();
		return 0;
    }

if(buton[1].click(1))
 Instructiuni();

}
