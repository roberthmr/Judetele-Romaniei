#include <iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<graphics.h>
#include<ctype.h>
#include "judete.h"

using namespace std;

int main()
{
	int MainWindow = initwindow( 800, 500, "", 200, 50 );
	setcurrentwindow( MainWindow );
	readimagefile("bg/bg.jpg",0,0,800,500);
	settextstyle(8,0,7);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(149,149,209));
	outtextxy(getmaxx()/2,100,"JUDETELE ROMANIEI");
	settextstyle(4,0,1);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	setbkcolor(RGB(133,125,176));
	outtextxy(60,150,"DE HEVESI ROBERT");
	int i=255;
	bool dim=true;
	settextstyle(8,0,1);
	settextjustify(1,0);
	setbkcolor(RGB(44,47,56));
	while(!kbhit())
	{
		setcolor(RGB(i,i,i));
		if(dim)
			i-=10;
		else
			i+=10;
		if(i<50||i>254)
			dim = !dim;
		outtextxy(getmaxx()/2, 490," Apasa orice tasta pentru a continua... ");
		Sleep(40);
	}
	
	citire();
	motto();
	meniu();
	
    getch();
    return 0;
}

void motto()
{
	cleardevice();
	readimagefile("bg/bg2.jpg",0,0,800,500);
	settextstyle(3,0,2);
	setcolor(WHITE);
	settextjustify(1,0);
	setbkcolor(RGB(68,70,82));
	outtextxy(getmaxx()/2,95,"''Imi iubesc pamantul natal, nu pot sta nicaieri,");
	setbkcolor(RGB(72,71,85));
	outtextxy(getmaxx()/2,120,"printre straini, mai mult de doua luni,");
	setbkcolor(RGB(82,71,75));
	outtextxy(getmaxx()/2,145,"pasii mei pornesc singuri inapoi spre");
	setbkcolor(RGB(86,68,64));
	outtextxy(getmaxx()/2,170,"tara mea de care mi-e dor, mi-e dor.''");
	setbkcolor(RGB(73,61,63));
	settextstyle(8,0,1);
	outtextxy(470,195,"- George Enescu");
	int i=255;
	bool dim = true;
	settextstyle(8,0,1);
	setbkcolor(RGB(11,7,4));
	getch();/////////
	
	while (   !kbhit())
	{
		setcolor(RGB(i,i,i));
		if(dim)
			i-=10;
		else
			i+=10;
		if(i<50||i>254)
			dim = !dim;
		outtextxy(getmaxx()/2, 490, " Apasa orice tasta pentru a continua... " );
		Sleep(40);
	}
	getch();
}

char* cautare( char* sir, int& strk )
{
	sir[strk] = getch();
	strk++;
	if (sir[strk - 1] == 8 )
	{
		sir[strk - 2] = '\0';
		sir[strk - 1] = '\0';
		strk -= 2;
	}
	if ( strk < 0 ) strk = 0; 
	sir[strk] = '\0';
	return sir;
}


void encryptDecrypt(char* inpString)
{
    char xorKey = 'P';
    int len = strlen(inpString);
    for (int i = 0; i < len; i++)
    {
		if ( inpString[i] != 13 )
			inpString[i] = inpString[i] ^ xorKey;
		
    }
}

void parola()
{
	cleardevice();
	char cuvant[55];
	char parola[55];
	cuvant[0] = '\0';
	int strk=0;
	readimagefile("bg/encryption.jpg",0,0,800,500);
	readimagefile("bg/encryption_pw.jpg",270,179,530,232);
	setcolor(WHITE);
	settextstyle(8,0,5);
	setbkcolor(RGB(40,26,19));
	settextjustify(1,0);
	outtextxy(getmaxx()/2,70,"LOGARE ADMINISTRATOR");
	
	swapbuffers();	
	readimagefile("bg/encryption.jpg",0,0,800,500);
	readimagefile("bg/encryption_pw.jpg",270,179,530,232);
	setcolor(WHITE);
	settextstyle(8,0,5);
	setbkcolor(RGB(40,26,19));
	settextjustify(1,0);
	outtextxy(getmaxx()/2,70,"LOGARE ADMINISTRATOR");
	
	fstream f1("password.txt", ios::in);
	f1>>parola;
	
	int i, ok=0, ok2=1;
	char auxencrypt[55];
	do
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		readimagefile("bg/encryption_pw.jpg",270,179,530,232);
		getmouseclick( WM_LBUTTONDOWN, x, y );	
		if( kbhit() )
		{
			cautare(cuvant,strk);
		}
		if( cuvant[0] == '\0' )
		{
			readimagefile("bg/encryption_pw.jpg",270,179,530,232);
			ok=0;
		}	
		
		if( cuvant[0] != '\0')
		{
			readimagefile("bg/encryption_pw_apasat.jpg",270,179,530,232);
			setbkcolor(RGB(175,92,32));
			settextstyle(8,0,1);
			for(i=1; i<=strk; i++)
			{
				outtextxy(285+i*10,216,"*");
			}
			ok=1;
		}
		if(ok==0)
		{
			if(mx>270 && mx<530 && my>179 && my<232) 
			{
				readimagefile("bg/encryption_pw_apasat.jpg",270,179,530,232);		
			}
		}
		
		if( cuvant[strk - 1] == 13 )
		{
			cuvant[strk - 1] = '\0';
			strcpy( auxencrypt, cuvant );
			encryptDecrypt(auxencrypt);
			if( strcmp( auxencrypt, parola ) != 0 )
			{				
				tries--;
				strk = 0;
				cuvant[0] = '\0';
				ok2=0;
			}
			else
			{
				admin = true;
				admin_da();
			}
		}
		if(ok2==0)
		{
			char triesSir[5];
			itoa(tries,triesSir,10);
			settextjustify(0,1);
			settextstyle(3,0,3);
			setbkcolor(RGB(40,26,19));
			setcolor(RED);
			outtextxy(252,265,"Parola gresita. ");
			setcolor(WHITE);
			outtextxy(381,265,triesSir);
			setcolor(WHITE);
			outtextxy(394,265," incercari ramase.");
		}
		if(tries==0)
		{
			admin=false;
			admin_nu();
		}
	}
	while( tries > 0 ); 
	meniu();
	getch();
	
}

void admin_da()
{
	cleardevice();
	
	readimagefile("bg/encryption.jpg",0,0,800,500);
	setcolor(WHITE);
	settextstyle(8,0,5);
	setbkcolor(RGB(40,26,19));
	settextjustify(1,0);
	outtextxy(getmaxx()/2,70,"LOGARE ADMINISTRATOR");
	settextjustify(1,1);
	settextstyle(8,0,3);
	setcolor(GREEN);
	outtextxy(getmaxx()/2,getmaxy()/2,"Succes! Logat ca si administrator!");
	
	swapbuffers();
	
	readimagefile("bg/encryption.jpg",0,0,800,500);
	setcolor(WHITE);
	settextstyle(8,0,5);
	setbkcolor(RGB(40,26,19));
	settextjustify(1,0);
	outtextxy(getmaxx()/2,70,"LOGARE ADMINISTRATOR");
	settextjustify(1,1);
	settextstyle(8,0,3);
	setcolor(GREEN);
	outtextxy(getmaxx()/2,getmaxy()/2,"Succes! Logat ca si administrator!");
	
	int i=255;
	bool dim=true;
	
	settextstyle(8,0,1);
	settextjustify(1,0);
	setbkcolor(RGB(40,26,19));
	
	while(!kbhit())
	{
		swapbuffers();
		setcolor(RGB(i,i,i));
		if(dim)
			i-=10;
		else
			i+=10;
		if(i<50||i>254)
			dim = !dim;
		outtextxy(getmaxx()/2, 490," Apasa orice tasta pentru a continua... ");
		Sleep(40);
	}
	getch();
	meniu();
}

void admin_nu()
{
	cleardevice();
	
	readimagefile("bg/encryption.jpg",0,0,800,500);
	setcolor(WHITE);
	settextstyle(8,0,5);
	setbkcolor(RGB(40,26,19));
	settextjustify(1,0);
	outtextxy(getmaxx()/2,70,"LOGARE ADMINISTRATOR");
	settextjustify(1,1);
	settextstyle(8,0,3);
	setcolor(RED);
	outtextxy(getmaxx()/2,getmaxy()/2,"Oops! Logat ca si utilizator!");
	
	swapbuffers();
	
	readimagefile("bg/encryption.jpg",0,0,800,500);
	setcolor(WHITE);
	settextstyle(8,0,5);
	setbkcolor(RGB(40,26,19));
	settextjustify(1,0);
	outtextxy(getmaxx()/2,70,"LOGARE ADMINISTRATOR");
	settextjustify(1,1);
	settextstyle(8,0,3);
	setcolor(RED);
	outtextxy(getmaxx()/2,getmaxy()/2,"Oops! Logat ca si utilizator!");
	
	int i=255;
	bool dim=true;
	
	settextstyle(8,0,1);
	settextjustify(1,0);
	setbkcolor(RGB(40,26,19));
	
	while(!kbhit())
	{
		swapbuffers();
		setcolor(RGB(i,i,i));
		if(dim)
			i-=10;
		else
			i+=10;
		if(i<50||i>254)
			dim = !dim;
		outtextxy(getmaxx()/2, 490," Apasa orice tasta pentru a continua... ");
		Sleep(40);
	}
	getch();
	meniu();
}

void meniu()
{
	readimagefile("bg/bg3.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"JUDETELE ROMANIEI");
	setbkcolor(RGB(55,36,40));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,141,"INTRODUCERE");
	outtextxy(getmaxx()/2,193,"BAZA DE DATE");
	outtextxy(getmaxx()/2,245,"APLICATII");
	outtextxy(getmaxx()/2,297,"QUIZ");
	outtextxy(getmaxx()/2,349,"STRUCTURA LUCRARII");
	outtextxy(getmaxx()/2,401,"BIBLIOGRAFIE");
	outtextxy(getmaxx()/2,453,"DATE DESPRE AUTOR");
	setbkcolor(RGB(61,42,46));
	outtextxy(690,463,"LOGARE ADMIN");
	
	swapbuffers();

	readimagefile("bg/bg3.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"JUDETELE ROMANIEI");
	setbkcolor(RGB(55,36,40));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,141,"INTRODUCERE");
	outtextxy(getmaxx()/2,193,"BAZA DE DATE");
	outtextxy(getmaxx()/2,245,"APLICATII");
	outtextxy(getmaxx()/2,297,"QUIZ");
	outtextxy(getmaxx()/2,349,"STRUCTURA LUCRARII");
	outtextxy(getmaxx()/2,401,"BIBLIOGRAFIE");
	outtextxy(getmaxx()/2,453,"DATE DESPRE AUTOR");
	setbkcolor(RGB(61,42,46));
	outtextxy(690,463,"LOGARE ADMIN");
	
	while( getmouseclick )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/bg3.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			setcolor(WHITE);
			settextstyle(8,0,6);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setbkcolor(RGB(129,130,195));
			outtextxy(getmaxx()/2,70,"JUDETELE ROMANIEI");
			setbkcolor(RGB(55,36,40));
			settextstyle(8,0,2);
			outtextxy(getmaxx()/2,141,"INTRODUCERE");
			outtextxy(getmaxx()/2,193,"BAZA DE DATE");
			outtextxy(getmaxx()/2,245,"APLICATII");
			outtextxy(getmaxx()/2,297,"QUIZ");
			outtextxy(getmaxx()/2,349,"STRUCTURA LUCRARII");
			outtextxy(getmaxx()/2,401,"BIBLIOGRAFIE");
			outtextxy(getmaxx()/2,453,"DATE DESPRE AUTOR");
			setbkcolor(RGB(61,42,46));
			outtextxy(690,463,"LOGARE ADMIN");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>767 && mx<800 && my>0 && my<23) //X
			{
				
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			
			else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
				
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						main();
					}
			}
			
			else if(mx>284 && mx<517 && my>118 && my<154) //PRIMUL BUTON
			{
				
					
					readimagefile("bg/bg3_1.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,141,"INTRODUCERE");
					if(x>284 && x<517 && y>118 && y<154)
					{
						introducere();
					}
			}
			
			else if(mx>284 && mx<517 && my>170 && my<206) //AL DOILEA BUTON
			{
				
					
					readimagefile("bg/bg3_2.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,193,"BAZA DE DATE");
					if(x>284 && x<517 && y>170 && y<206)
					{
						bazadedate();
					}
			}
			
			else if(mx>284 && mx<517 && my>222 && my<258) //AL TREILEA BUTON
			{
				
					
					readimagefile("bg/bg3_3.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,245,"APLICATII");
					if(x>284 && x<517 && y>222 && y<258)
					{
						aplicatii();
					}
			}	
			
			else if(mx>284 && mx<517 && my>274 && my<310) //AL PATRULEA BUTON
			{
				
					
					readimagefile("bg/bg3_4.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,297,"QUIZ");
					if(x>284 && x<517 && y>274 && y<310)
					{
						quiz();
					}
			}
			
			else if(mx>284 && mx<517 && my>326 && my<362) //AL CINCILEA BUTON
			{
					
					
					readimagefile("bg/bg3_5.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,349,"STRUCTURA LUCRARII");
					if(x>284 && x<517 && y>326 && y<362)
					{
						structura();
					}
			}
			
			else if(mx>284 && mx<517 && my>378 && my<414) //AL SASELEA BUTON
			{
					
					
					readimagefile("bg/bg3_6.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,401,"BIBLIOGRAFIE");
					if(x>284 && x<517 && y>378 && y<414)
					{
						bibliografie();
					}
			}
			
			else if(mx>284 && mx<517 && my>430 && my<466) //AL SAPTELEA BUTON
			{
					
					
					readimagefile("bg/bg3_7.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,453,"DATE DESPRE AUTOR");
					if(x>284 && x<517 && y>430 && y<466)
					{
						autor();
					}
			}
			
			else if(mx>595 && mx<786 && my>322 && my<479) //ADMIN
			{
					
					
					readimagefile("bg/bg3_admin.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(690,463,"LOGARE ADMIN");
					if(x>595 && x<786 && y>322 && y<479)
					{
						parola();
					}
			}
	
	}
	getch();
	cleardevice();
}

void introducere()
{
	readimagefile("bg/bg8.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"INTRODUCERE");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,146,"GENERALITATI");
	outtextxy(getmaxx()/2,206,"EVOLUTIA JUDETELOR");
	
	swapbuffers();

	readimagefile("bg/bg8.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"INTRODUCERE");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,146,"GENERALITATI");
	outtextxy(getmaxx()/2,206,"EVOLUTIA JUDETELOR");
	
	while( getmouseclick )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/bg8.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			setcolor(WHITE);
			settextstyle(8,0,6);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setbkcolor(RGB(129,130,195));
			outtextxy(getmaxx()/2,70,"INTRODUCERE");
			setbkcolor(RGB(61,42,46));
			settextstyle(8,0,2);
			outtextxy(getmaxx()/2,146,"GENERALITATI");
			outtextxy(getmaxx()/2,206,"EVOLUTIA JUDETELOR");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>767 && mx<800 && my>0 && my<23) //X
			{
				
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			
			else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
				
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>284 && mx<517 && my>119 && my<164) //PRIMUL BUTON
			{
				
					
					readimagefile("bg/bg8_1.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,146,"GENERALITATI");
					if(x>284 && x<517 && y>119 && y<164)
					{
						generalitati1();
					}
			}
			
			else if(mx>284 && mx<517 && my>179 && my<224) //AL DOILEA BUTON
			{
				
					
					readimagefile("bg/bg8_2.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,206,"EVOLUTIA JUDETELOR");
					if(x>284 && x<517 && y>179 && y<224)
					{
						evolutie();
					}
			}
	}
	getch();
	cleardevice();
}

void generalitati1()
{
	char cuv[600][50];
	int latime=55, kk=0, i, inaltime=114, ok;
	readimagefile("bg/bg9.jpg",0,0,800,500);
	readimagefile("bg/rectangle4.jpg",49,97,750,445);
	readimagefile("media/organizare.jpg",565,105,745,437);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"GENERALITATI");
	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);

	fstream f1("text/generalitati1.txt", ios::in);
	
	do{
		kk++;
		f1>>cuv[kk];
	}while(!f1.eof());
	
	f1.close();
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	settextjustify(0,1);
	
	for(i=1; i<=kk; i++)
	{
		ok=0;
		if(latime+textwidth(cuv[i])<560)
		{
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
			ok=1;
		}
		
		if(latime+ textwidth( cuv[i] ) >=560 && ok==0)
		{
			latime=55;
			inaltime=inaltime+23;
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
		}
	}
	
	swapbuffers();	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	readimagefile("bg/bg9.jpg",0,0,800,500);
	readimagefile("bg/rectangle4.jpg",49,97,750,445);
	readimagefile("media/organizare.jpg",565,105,745,437);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"GENERALITATI");
	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	inaltime=114;
	latime=55;
	settextjustify(0,1);
	
	for(i=1; i<=kk; i++)
	{
		ok=0;
		if(latime+textwidth(cuv[i])<560)
		{
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
			ok=1;
		}
		
		if(latime+ textwidth( cuv[i] ) >=560 && ok==0)
		{
			latime=55;
			inaltime=inaltime+23;
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
		}
	}
	
	while( getmouseclick )
	{	
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			getmouseclick( WM_LBUTTONDOWN, x, y );
			
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						introducere();
					}
			}
	}
	getch();
}

void evolutie()
{
	int pag=1, i;
	START1://///////////////////////////////////////////////
	char pagpoza[20], pagtext1[20], pagtext2[30], pagsir[10], cuv[250][60], an[50][25];
	int inaltime=430, latime=55, kk1=0, kk2=0, latime2=0, ok;
	itoa(pag,pagsir,10);
	
	strcpy(pagpoza,"media/evolutie/");
	strcpy(pagtext1,"media/evolutie/");
	strcpy(pagtext2,"media/evolutie/");
	strcat(pagpoza,pagsir);
	strcat(pagtext1,pagsir);
	strcat(pagtext2,pagsir);
	strcat(pagtext2,"a");
	strcat(pagpoza,".jpg");
	strcat(pagtext1,".txt");
	strcat(pagtext2,".txt");
	
	readimagefile("bg/bg9.jpg",0,0,800,500);
	readimagefile("bg/rectangle10.gif",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	if(pag<9)readimagefile("bg/sageata_next.jpg",764,234,788,268);
	if(pag>1)readimagefile("bg/sageata_back.jpg",12,234,36,268);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"EVOLUTIE");
	readimagefile(pagpoza,188,104,613,412);
	
	fstream f1(pagtext1, ios::in);
	fstream f2(pagtext2, ios::in);
	
	do{
		kk1++;
		f1>>cuv[kk1];
	}while(!f1.eof());
	
	do{
		kk2++;
		f2>>an[kk2];
	}while(!f2.eof());
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	settextjustify(0,1);
	
	for(i=1; i<=kk1; i++)
	{
		ok=0;
		if(latime+textwidth(cuv[i])<745)
		{
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
			ok=1;
		}
		
		if(latime+ textwidth( cuv[i] ) >=745 && ok==0)
		{
			latime=55;
			inaltime=inaltime+23;
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
		}
	}
	
	latime=0;
	latime2=0;
	settextjustify(0,1);
	settextstyle(3,0,3);
	if(pag==9)settextstyle(3,0,1);
	
	for(i=1; i<=kk2; i++)
	{
		latime=latime+textwidth(an[i])+4;
	}
	latime=latime-4;
	
	for(i=1; i<=kk2; i++)
	{
		outtextxy(getmaxx()/2-latime/2+latime2,97,an[i]);
		latime2=latime2+textwidth(an[i])+4;
	}
	
	swapbuffers(); /////////////////////////////////////////////////
	
	readimagefile("bg/bg9.jpg",0,0,800,500);
	readimagefile("bg/rectangle10.gif",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	if(pag<9)readimagefile("bg/sageata_next.jpg",764,234,788,268);
	if(pag>1)readimagefile("bg/sageata_back.jpg",12,234,36,268);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"EVOLUTIE");
	readimagefile(pagpoza,188,104,613,412);
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	settextjustify(0,1);
	
	inaltime=430;
	latime=55;
	
	for(i=1; i<=kk1; i++)
	{
		ok=0;
		if(latime+textwidth(cuv[i])<745)
		{
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
			ok=1;
		}
		
		if(latime+ textwidth( cuv[i] ) >=745 && ok==0)
		{
			latime=55;
			inaltime=inaltime+23;
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
		}
	}
	
	latime=0;
	latime2=0;
	settextjustify(0,1);
	settextstyle(3,0,3);
	if(pag==9)settextstyle(3,0,1);
	
	for(i=1; i<=kk2; i++)
	{
		latime=latime+textwidth(an[i])+4;
	}
	latime=latime-4;
	
	for(i=1; i<=kk2; i++)
	{
		outtextxy(getmaxx()/2-latime/2+latime2,97,an[i]);
		latime2=latime2+textwidth(an[i])+4;
	}
	
	/////////////////////////////////////////////////
	
	while( getmouseclick )
	{	
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		if(pag<9)readimagefile("bg/sageata_next.jpg",764,234,788,268);
		if(pag>1)readimagefile("bg/sageata_back.jpg",12,234,36,268);
		getmouseclick( WM_LBUTTONDOWN, x, y );
		
		if(mx>767 && mx<800 && my>0 && my<23) 
		{
				//
				readimagefile("bg/x_apasat.gif",767,0,800,23);
				if(x>767 && x<800 && y>0 && y<23)
				{
					exit(0);
				}
		}
		else if(mx>0 && mx<33 && my>0 && my<23) 
		{
				
				readimagefile("bg/back_apasat.gif",0,0,33,23);
				if(x>0 && x<33 && y>0 && y<23)
				{
					introducere();
				}
		}
		
		else if(mx>764 && mx<788 && my>234 && my<268 && pag<9)//SAGEATA next
		{
			
			readimagefile("bg/sageata_next_apasat.jpg",764,234,788,268);
			if(x>764 && x<788 && y>234 && y<268)
			{
				pag++;
				goto START1;
			}	
		}
		
		else if(mx>12 && mx<36 && my>234 && my<268 && pag>1)//SAGEATA back
		{
			
			readimagefile("bg/sageata_back_apasat.jpg",12,234,36,268);
			if(x>12 && x<36 && y>234 && y<268)
			{
				pag--;
				goto START1;
			}	
		}
	}
	
	getch();
	cleardevice();
}

void bazadedate()
{
	readimagefile("bg/bg8.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"BAZA DE DATE");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,146,"GENERALITATI");
	outtextxy(getmaxx()/2,206,"AFISARE");
	
	swapbuffers();

	readimagefile("bg/bg8.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"BAZA DE DATE");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,146,"GENERALITATI");
	outtextxy(getmaxx()/2,206,"AFISARE");
	
	while( getmouseclick )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/bg8.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			setcolor(WHITE);
			settextstyle(8,0,6);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setbkcolor(RGB(129,130,195));
			outtextxy(getmaxx()/2,70,"BAZA DE DATE");
			setbkcolor(RGB(61,42,46));
			settextstyle(8,0,2);
			outtextxy(getmaxx()/2,146,"GENERALITATI");
			outtextxy(getmaxx()/2,206,"AFISARE");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>767 && mx<800 && my>0 && my<23) //X
			{
				
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			
			else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
				
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>284 && mx<517 && my>119 && my<164) //PRIMUL BUTON
			{
				
					
					readimagefile("bg/bg8_1.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,146,"GENERALITATI");
					if(x>284 && x<517 && y>119 && y<164)
					{
						generalitati2();
					}
			}
			
			else if(mx>284 && mx<517 && my>179 && my<224) //AL DOILEA BUTON
			{
				
					
					readimagefile("bg/bg8_2.gif",0,0,800,500);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,206,"AFISARE");
					if(x>284 && x<517 && y>179 && y<224)
					{
						tabel1();
					}
			}
	}
	getch();
	cleardevice();
}

void generalitati2()
{
	readimagefile("bg/bg9.jpg",0,0,800,500);
	readimagefile("bg/rectangle4.jpg",49,97,750,305);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"GENERALITATI");
	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);

	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	settextjustify(0,1);
	
	outtextxy(55,114,"       In afisarea bazei de date vom gasi date despre toate judetele Romaniei.");
	outtextxy(55,149,"       Programul permite sortarea fiecarei coloane de date alfabetic sau invers alfabetic, respectiv");
	outtextxy(55,174,"crescator sau descrescator.");
	outtextxy(55,209,"       Pintre functiile afisarii se numara si cautarea, care se va face in toate campurile existente in");
	outtextxy(55,234,"tabel, afisandu-se orice inregistrare a carei celule indeplineste criteriile introduse.");
	outtextxy(55,269,"       O alta caracteristica este posibilitatea unui administrator de a modifica unele campuri");
	outtextxy(55,294,"existente in tabel, sau chiar de a le sterge definitiv din memorie!");
	
	swapbuffers();	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	readimagefile("bg/bg9.jpg",0,0,800,500);
	readimagefile("bg/rectangle4.jpg",49,97,750,305);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"GENERALITATI");
	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);

	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	settextjustify(0,1);
	
	outtextxy(55,114,"       In afisarea bazei de date vom gasi date despre toate judetele Romaniei.");
	outtextxy(55,149,"       Programul permite sortarea fiecarei coloane de date alfabetic sau invers alfabetic, respectiv");
	outtextxy(55,174,"crescator sau descrescator.");
	outtextxy(55,209,"       Pintre functiile afisarii se numara si cautarea, care se va face in toate campurile existente in");
	outtextxy(55,234,"tabel, afisandu-se orice inregistrare a carei celule indeplineste criteriile introduse.");
	outtextxy(55,269,"       O alta caracteristica este posibilitatea unui administrator de a modifica unele campuri");
	outtextxy(55,294,"existente in tabel, sau chiar de a le sterge definitiv din memorie!");
	
	while( getmouseclick )
	{	
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			getmouseclick( WM_LBUTTONDOWN, x, y );
			
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					//
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						bazadedate();
					}
			}
	}
	getch();
}

void harta()
{
	int kx;
	readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");

	swapbuffers(); /////////////////
	
	readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>293 && mx<347 && my>243 && my<284) //1-AB
			{
					
					readimagefile("bg/harta/bg_ab.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>293 && x<347 && y>243 && y<293)
					{
						kx=1;
						judet1(kx);
					}
			}
			
			else if(mx>178 && mx<252 && my>231 && my<274) //2-AR
			{
					
					readimagefile("bg/harta/bg_ar.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>178 && x<252 && y>231 && y<274)
					{
						kx=2;
						judet1(kx);
					}
			}
			
			else if(mx>372 && mx<411 && my>318 && my<413) //3-AG
			{
					
					readimagefile("bg/harta/bg_ag.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>372 && x<411 && y>243 && y<413)
					{
						kx=3;
						judet1(kx);
					}
			}
			
			if(mx>463 && mx<538 && my>221 && my<271) //4-BC
			{
					
					readimagefile("bg/harta/bg_bc.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>463 && x<538 && y>221 && y<271)
					{
						kx=4;
						judet1(kx);
					}
			}
			
			else if(mx>200 && mx<269 && my>160 && my<227) //5-BH
			{
					
					readimagefile("bg/harta/bg_bh.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>200 && x<269 && y>160 && y<227)
					{
						kx=5;
						judet1(kx);
					}
			}
			
			else if(mx>343 && mx<402 && my>150 && my<200) //6-BN
			{
					
					readimagefile("bg/harta/bg_bn.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>343 && x<402 && y>150 && y<200)
					{
						kx=6;
						judet1(kx);
					}
			}
			
			else if(mx>479 && mx<521 && my>96 && my<150) //7-BT
			{
					
					readimagefile("bg/harta/bg_bt.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>479 && x<521 && y>96 && y<150)
					{
						kx=7;
						judet1(kx);
					}
			}
			
			else if(mx>385 && mx<444 && my>275 && my<317) //8-BV
			{
					
					readimagefile("bg/harta/bg_bv.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>385 && x<444 && y>275 && y<317)
					{
						kx=8;
						judet1(kx);
					}
			}
			
			else if(mx>537 && mx<585 && my>331 && my<378) //9-BR
			{
					
					readimagefile("bg/harta/bg_br.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>537 && x<585 && y>331 && y<378)
					{
						kx=9;
						judet1(kx);
					}
			}
			
			else if(mx>485 && mx<531 && my>326 && my<375) //10-BZ
			{
					
					readimagefile("bg/harta/bg_bz.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>485 && x<531 && y>326 && y<375)//////////
					{
						kx=10;
						judet1(kx);
					}
			}
			
			else if(mx>194 && mx<258 && my>317 && my<378) //11-CS
			{
					
					readimagefile("bg/harta/bg_cs.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>194 && x<258 && y>317 && y<378)//////////
					{
						kx=11;
						judet1(kx);
					}
			}
			
			else if(mx>485 && mx<570 && my>412 && my<435) //12-CL
			{
					
					readimagefile("bg/harta/bg_cl.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>485 && x<570 && y>412 && y<435)//////////
					{
						kx=12;
						judet1(kx);
					}
			}
			
			else if(mx>275 && mx<345 && my>195 && my<237) //13-CJ
			{
					
					readimagefile("bg/harta/bg_cj.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>275 && x<345 && y>195 && y<237)//////////
					{
						kx=13;
						judet1(kx);
					}
			}
			
			else if(mx>582 && mx<623 && my>389 && my<465) //14-CT
			{
					
					readimagefile("bg/harta/bg_ct.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>582 && x<623 && y>321 && y<465)//////////
					{
						kx=14;
						judet1(kx);
					}
			}
			
			else if(mx>435 && mx<481 && my>269 && my<306) //15-CV
			{
					
					readimagefile("bg/harta/bg_cv.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>435 && x<481 && y>269 && y<306)//////////
					{
						kx=15;
						judet1(kx);
					}
			}
			
			else if(mx>413 && mx<450 && my>355 && my<404) //16-DB
			{
					
					readimagefile("bg/harta/bg_db.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>413 && x<450 && y>355 && y<404)//////////
					{
						kx=16;
						judet1(kx);
					}
			}
			
			else if(mx>300 && mx<346 && my>405 && my<466) //17-DJ
			{
					//
					readimagefile("bg/harta/bg_dj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>300 && x<346 && y>405 && y<466)//////////
					{
						kx=17;
						judet1(kx);
					}
			}
			
			else if(mx>545 && mx<582 && my>271 && my<327) //18-GL
			{
					
					readimagefile("bg/harta/bg_gl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>545 && x<582 && y>271 && y<327)//////////
					{
						kx=18;
						judet1(kx);
					}
			}
			
			else if(mx>440 && mx<484 && my>427 && my<465) //19-GR
			{
					
					readimagefile("bg/harta/bg_gr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>440 && x<484 && y>427 && y<465)//////////
					{
						kx=19;
						judet1(kx);
					}
			}
			
			else if(mx>282 && mx<327 && my>342 && my<383) //20-GJ
			{
					
					readimagefile("bg/harta/bg_gj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>282 && x<327 && y>342 && y<383)//////////
					{
						kx=20;
						judet1(kx);
					}
			}
			
			else if(mx>413 && mx<450 && my>193 && my<266) //21-HR
			{
					
					readimagefile("bg/harta/bg_hr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>413 && x<450 && y>193 && y<266)//////////
					{
						kx=21;
						judet1(kx);
					}
			}
			
			else if(mx>257 && mx<302 && my>260 && my<337) //22-HD
			{
					
					readimagefile("bg/harta/bg_hd.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>257 && x<302 && y>260 && y<337)//////////
					{
						kx=22;
						judet1(kx);
					}
			}
			
			else if(mx>484 && mx<583 && my>384 && my<410) //23-IL
			{
					
					readimagefile("bg/harta/bg_il.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>484 && x<583 && y>384 && y<410)//////////
					{
						kx=23;
						judet1(kx);
					}
			}
			
			else if(mx>502 && mx<576 && my>154 && my<203) //24-IS
			{
					
					readimagefile("bg/harta/bg_is.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>502 && x<576 && y>154 && y<375)//////////
					{
						kx=24;
						judet1(kx);
					}
			}
		
			else if(mx>456 && mx<482 && my>386 && my<422) //25-IF/ILFOV
			{
					
					readimagefile("bg/harta/bg_if.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>456 && x<482 && y>386 && y<422)//////////
					{
						kx=25;
						judet1(kx);
					}
			}
			
			else if(mx>308 && mx<400 && my>117 && my<149) //26-MM
			{
					
					readimagefile("bg/harta/bg_mm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>308 && x<400 && y>117 && y<149)//////////
					{
						kx=26;
						judet1(kx);
					}
			}
			
			else if(mx>249 && mx<283 && my>385 && my<441) //27-MH
			{
					
					readimagefile("bg/harta/bg_mh.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>249 && x<283 && y>385 && y<441)//////////
					{
						kx=27;
						judet1(kx);
					}
			}
			
			else if(mx>348 && mx<407 && my>207 && my<257) //28-MS
			{
					
					readimagefile("bg/harta/bg_ms.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>348 && x<407 && y>207 && y<257)//////////
					{
						kx=28;
						judet1(kx);
					}
			}
			
			else if(mx>447 && mx<511 && my>182 && my<218) //29-NT
			{
					
					readimagefile("bg/harta/bg_nt.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>447 && x<511 && y>182 && y<218)//////////
					{
						kx=29;
						judet1(kx);
					}
			}
			
			else if(mx>350 && mx<385 && my>392 && my<471) //30-OT
			{
					
					readimagefile("bg/harta/bg_ot.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>350 && x<385 && y>392 && y<471)//////////
					{
						kx=30;
						judet1(kx);
					}
			}
			
			else if(mx>449 && mx<484 && my>337 && my<382) //31-PH
			{
					
					readimagefile("bg/harta/bg_ph.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>449 && x<484 && y>337 && y<382)//////////
					{
						kx=31;
						judet1(kx);
					}
			}
			
			else if(mx>239 && mx<306 && my>116 && my<154) //32-SM
			{
					
					readimagefile("bg/harta/bg_sm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>239 && x<306 && y>116 && y<154)//////////
					{
						kx=32;
						judet1(kx);
					}
			}
			else if(mx>270 && mx<318 && my>165 && my<197) //33-SJ
			{
					
					readimagefile("bg/harta/bg_sj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>270 && x<318 && y>165 && y<197)//////////
					{
						kx=33;
						judet1(kx);
					}
			}
			
			else if(mx>333 && mx<381 && my>271 && my<315) //34-SB
			{
					
					readimagefile("bg/harta/bg_sb.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>333 && x<381 && y>271 && y<315)//////////
					{
						kx=34;
						judet1(kx);
					}
			}
			
			else if(mx>406 && mx<472 && my>115 && my<172) //35-SV
			{
					
					readimagefile("bg/harta/bg_sv.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>406 && x<472 && y>115 && y<172)//////////
					{
						kx=35;
						judet1(kx);
					}
			}
			
			else if(mx>388 && mx<437 && my>421 && my<471) //36-TR
			{
					
					readimagefile("bg/harta/bg_tr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>388 && x<437 && y>421 && y<471)//////////
					{
						kx=36;
						judet1(kx);
					}
			}
			
			else if(mx>150 && mx<240 && my>278 && my<316) //37-TM
			{
					
					readimagefile("bg/harta/bg_tm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>150 && x<240 && y>278 && y<316)//////////
					{
						kx=37;
						judet1(kx);
					}
			}
			
			else if(mx>590 && mx<680 && my>331 && my<384) //38-TL
			{
					
					readimagefile("bg/harta/bg_tl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>590 && x<680 && y>331 && y<384)//////////
					{
						kx=38;
						judet1(kx);
					}
			}
			
			else if(mx>542 && mx<586 && my>205 && my<265) //39-VS
			{
					
					readimagefile("bg/harta/bg_vs.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>542 && x<586 && y>205 && y<265)//////////
					{
						kx=39;
						judet1(kx);
					}
			}
			
			else if(mx>329 && mx<367 && my>321 && my<381) //40-VL
			{
					
					readimagefile("bg/harta/bg_vl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>329 && x<367 && y>321 && y<381)//////////
					{
						kx=40;
						judet1(kx);
					}
			}
			
			else if(mx>485 && mx<535 && my>274 && my<320) //41-VN
			{
					
					readimagefile("bg/harta/bg_vn.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					outtextxy(getmaxx()/2,55,"HARTA INTERACTIVA");
					if(x>485 && x<535 && y>274 && y<320)//////////
					{
						kx=41;
						judet1(kx);
					}
			}
			
			else if(mx>767 && mx<800 && my>0 && my<23) 
			{
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						aplicatii();
					}
			}
	}
	getch();
	cleardevice();
}

void judet1(int kx)
{
	int latime;
	//int kx;
	char locuitorisir[15], suprafatasir[15], densitatesir[5];
	char municipiisir[5], orasesir[5], comunesir[5];
	itoa(j[kx].locuitori,locuitorisir,10);
	itoa(j[kx].suprafata,suprafatasir,10);
	itoa(j[kx].densitate,densitatesir,10);
	itoa(j[kx].municipii,municipiisir,10);
	itoa(j[kx].orase,orasesir,10);
	itoa(j[kx].comune,comunesir,10);
	
	readimagefile("bg/bg5.jpg",0,0,800,500);
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(LEFT_TEXT,0);
	setbkcolor(RGB(111,108,163));
	outtextxy(50,50,"Judetul ");
	outtextxy(50+textwidth("Judetul "),50,j[kx].judet);
	line(50,55,750,55);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	//readimagefile("bg/buton_back.jpg",12,234,36,268);
	readimagefile("bg/sageata_next.jpg",764,234,788,268);
	
	readimagefile("bg/rectangle.jpg",480,73,750,486);
	readimagefile("bg/rectangle2.jpg",50,73,471,293);
	readimagefile("bg/rectangle3.jpg",50,300,471,486);
	readimagefile(j[kx].pozajudet,490,80,740,264);
	settextjustify(1,0);
	settextstyle(3,0,1);
	setbkcolor(RGB(81,68,78));
	readimagefile(j[kx].harta,490,285,740,464);
	outtextxy(615,485,"Pozitia geografica");
	
	settextjustify(0,0);
	char vedere[25]="Vedere din judetul ";
	latime=textwidth(vedere)+textwidth(j[kx].judet);
	outtextxy((270-latime)/2+480,284,vedere);
	outtextxy((270-latime)/2+480+textwidth(vedere),284,j[kx].judet);
	
	settextjustify(0,2);
	settextstyle(3,0,1);
	outtextxy(55,78,"Judetul ");
	outtextxy(55+textwidth("Judetul "),78,j[kx].judet);
	latime=textwidth("Judetul" )+58+textwidth(j[kx].judet);
	outtextxy(latime,78,", situat in zona de ");
	latime=latime+textwidth(", situat in zona de ");
	outtextxy(latime,78,j[kx].pctcardinal);
	latime=latime+textwidth(j[kx].pctcardinal);
	outtextxy(latime,78," a Romaniei,");
	outtextxy(55,105,"are un numar de ");
	latime=55+textwidth("are un numar de ");
	outtextxy(latime,105,locuitorisir);
	latime=latime+textwidth(locuitorisir);
	outtextxy(latime,105," locuitori");
	outtextxy(55,132,"intinsi pe o suprafata de ");
	latime=55+textwidth("intinsi pe o suprafata de ");
	outtextxy(latime,132,suprafatasir);
	latime=latime+textwidth(suprafatasir);
	outtextxy(latime,132," km patrati,");
	outtextxy(55,159,"avand deci o densitate de ");
	latime=textwidth("avand deci o densitate de ")+55;
	outtextxy(latime,159,densitatesir);
	latime=latime+textwidth(densitatesir);
	outtextxy(latime,159," locuitori pe km patrati.");
	outtextxy(55,200,j[kx].municipiu);	
	latime=55+textwidth(j[kx].municipiu);	
	outtextxy(latime,200,", municipiul de resedinta a judetului ");
	latime=latime+textwidth(", municipiul de resedinta a judetului ");
	outtextxy(latime,200,j[kx].judet);
	latime=latime+textwidth(j[kx].judet);
	outtextxy(latime,200,",");
	outtextxy(55,227,"il are ca primar pe ");
	latime=55+textwidth("il are ca primar pe ");;
	outtextxy(latime,227,j[kx].primar);
	latime=latime+textwidth(j[kx].primar);
	outtextxy(latime,227,".");
	outtextxy(55,268,"Judetul are un numar de ");
	latime=55+textwidth("Judetul are un numar de ");
	outtextxy(latime,268,municipiisir);
	latime=latime+textwidth(municipiisir);
	outtextxy(latime,268," municipii, ");
	latime=latime+textwidth(" municipii, ");
	outtextxy(latime,268,orasesir);
	latime=latime+textwidth(orasesir);
	outtextxy(latime,268," orase si ");
	latime=latime+textwidth(" orase si ");
	outtextxy(latime,268,comunesir);
	latime=latime+textwidth(comunesir);
	outtextxy(latime,268," comune.");
	
	readimagefile(j[kx].stema,335,305,465,463);
	settextjustify(1,0);
	outtextxy(400,485,"Stema judetului");
	
	readimagefile(j[kx].pozaobiectiv,67,305,323,463);
	settextjustify(0,0);
	char obiectivsir[25]="Obiectiv turistic: ";
	latime=textwidth(obiectivsir)+textwidth(j[kx].obiectiv);
	outtextxy((256-latime)/2+67,485,obiectivsir);
	outtextxy((256-latime)/2+67+textwidth(obiectivsir),485,j[kx].obiectiv);
	
	swapbuffers();	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	readimagefile("bg/bg5.jpg",0,0,800,500);
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(LEFT_TEXT,0);
	setbkcolor(RGB(111,108,163));
	outtextxy(50,50,"Judetul ");
	outtextxy(50+textwidth("Judetul "),50,j[kx].judet);
	line(50,55,750,55);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	readimagefile("bg/sageata_next.jpg",764,234,788,268);
	
	readimagefile("bg/rectangle.jpg",480,73,750,486);
	readimagefile("bg/rectangle2.jpg",50,73,471,293);
	readimagefile("bg/rectangle3.jpg",50,300,471,486);
	readimagefile(j[kx].pozajudet,490,80,740,264);
	settextjustify(1,0);
	settextstyle(3,0,1);
	setbkcolor(RGB(81,68,78));
	readimagefile(j[kx].harta,490,285,740,464);
	outtextxy(615,485,"Pozitia geografica");
	
	settextjustify(0,0);
	latime=textwidth(vedere)+textwidth(j[kx].judet);
	outtextxy((270-latime)/2+480,284,vedere);
	outtextxy((270-latime)/2+480+textwidth(vedere),284,j[kx].judet);
	
	settextjustify(0,2);
	settextstyle(3,0,1);
	outtextxy(55,78,"Judetul ");
	outtextxy(55+textwidth("Judetul "),78,j[kx].judet);
	latime=textwidth("Judetul" )+58+textwidth(j[kx].judet);
	outtextxy(latime,78,", situat in zona de ");
	latime=latime+textwidth(", situat in zona de ");
	outtextxy(latime,78,j[kx].pctcardinal);
	latime=latime+textwidth(j[kx].pctcardinal);
	outtextxy(latime,78," a Romaniei,");
	outtextxy(55,105,"are un numar de ");
	latime=55+textwidth("are un numar de ");
	outtextxy(latime,105,locuitorisir);
	latime=latime+textwidth(locuitorisir);
	outtextxy(latime,105," locuitori");
	outtextxy(55,132,"intinsi pe o suprafata de ");
	latime=55+textwidth("intinsi pe o suprafata de ");
	outtextxy(latime,132,suprafatasir);
	latime=latime+textwidth(suprafatasir);
	outtextxy(latime,132," km patrati,");
	outtextxy(55,159,"avand deci o densitate de ");
	latime=textwidth("avand deci o densitate de ")+55;
	outtextxy(latime,159,densitatesir);
	latime=latime+textwidth(densitatesir);
	outtextxy(latime,159," locuitori pe km patrati.");
	outtextxy(55,200,j[kx].municipiu);	
	latime=55+textwidth(j[kx].municipiu);	
	outtextxy(latime,200,", municipiul de resedinta a judetului ");
	latime=latime+textwidth(", municipiul de resedinta a judetului ");
	outtextxy(latime,200,j[kx].judet);
	latime=latime+textwidth(j[kx].judet);
	outtextxy(latime,200,",");
	outtextxy(55,227,"il are ca primar pe ");
	latime=55+textwidth("il are ca primar pe ");;
	outtextxy(latime,227,j[kx].primar);
	latime=latime+textwidth(j[kx].primar);
	outtextxy(latime,227,".");
	outtextxy(55,268,"Judetul are un numar de ");
	latime=55+textwidth("Judetul are un numar de ");
	outtextxy(latime,268,municipiisir);
	latime=latime+textwidth(municipiisir);
	outtextxy(latime,268," municipii, ");
	latime=latime+textwidth(" municipii, ");
	outtextxy(latime,268,orasesir);
	latime=latime+textwidth(orasesir);
	outtextxy(latime,268," orase si ");
	latime=latime+textwidth(" orase si ");
	outtextxy(latime,268,comunesir);
	latime=latime+textwidth(comunesir);
	outtextxy(latime,268," comune.");
	
	readimagefile(j[kx].stema,335,305,465,463);
	settextjustify(1,0);
	outtextxy(400,485,"Stema judetului");
	
	readimagefile(j[kx].pozaobiectiv,67,305,323,463);
	settextjustify(0,0);
	//char obiectiv[25]="Obiectiv turistic: ";
	latime=textwidth(obiectivsir)+textwidth(j[kx].obiectiv);
	outtextxy((256-latime)/2+67,485,obiectivsir);
	outtextxy((256-latime)/2+67+textwidth(obiectivsir),485,j[kx].obiectiv);
	
	while( getmouseclick )
	{	
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			readimagefile("bg/sageata_next.jpg",764,234,788,268);
			getmouseclick( WM_LBUTTONDOWN, x, y );
			
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					//
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						harta();
					}
			}
			else if(mx>764 && mx<788 && my>234 && my<268)
			{
				
				readimagefile("bg/sageata_next_apasat.jpg",764,234,788,268);
				if(x>764 && x<788 && y>234 && y<268)
				{
					judet2(kx);
				}	
			}
	}
	getch();
}

void judet2(int kx)
{
	char numetext[35], text[300][35], kxsir[5], string[3]="-";
	int i, latime=555, inaltime=440, latime2=55, inaltime2=134, ktext=0;
	
	strcpy(numetext,"personalitati/");
	itoa(kx,kxsir,10);
	strcat(numetext,kxsir);
	strcat(numetext,".txt");
	
	fstream f1(numetext,ios::in);
	do{
		ktext++;
		f1>>text[ktext];
	}while(!f1.eof());
	
	readimagefile("bg/bg5.jpg",0,0,800,500);
	readimagefile("bg/personalitate.jpg",443,116,751,485);
	readimagefile("bg/personalitate_text.jpg",50,116,435,485);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	readimagefile("bg/sageata_back.jpg",12,234,36,268);
	readimagefile("bg/sageata_next.jpg",764,234,788,268);
	readimagefile(d[kx].numepoza,548,155,658,304);
	
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(LEFT_TEXT,0);
	setbkcolor(RGB(111,108,163));
	outtextxy(50,50,"Judetul ");
	
	outtextxy(50+textwidth("Judetul "),50,j[kx].judet);
	line(50,55,750,55);
	outtextxy(50,105,"Personalitate");
	
	settextstyle(10,0,3);
	settextjustify(1,0);
	setbkcolor(RGB(49,39,47));
	outtextxy(603,147,d[kx].nume);
	
	settextstyle(3,0,1);
	settextjustify(0,0);
	setbkcolor(RGB(81,68,78));
	setcolor(RGB(151,151,151));	
	
	outtextxy(460,340,"Nascut");
	outtextxy(460,360,"Decedat");
	outtextxy(460,380,"Varsta");
	outtextxy(460,400,"Casatorit cu");
	outtextxy(460,420,"Cetatenie");
	outtextxy(460,440,"Ocupatii");

	setcolor(WHITE);
	outtextxy(555,340,d[kx].nascut);
	outtextxy(555,360,d[kx].decedat);
	outtextxy(555,380,d[kx].varsta);
	outtextxy(555,400,d[kx].casatorit);
	outtextxy(555,420,d[kx].cetatenie);

	int ok=0;
	for(i=1; i<=8; i++)
	{
		ok=0;
		if( (latime+textwidth(d[kx].ocupatie[i]))<745)
		{
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,"-");
			latime=latime+textwidth("-");
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,d[kx].ocupatie[i]);
			ok=1;
			latime=latime+textwidth(d[kx].ocupatie[i])+4;
		}
		if(latime+textwidth(d[kx].ocupatie[i])>=745 && ok==0)
		{
			latime=555;
			inaltime=inaltime+20;
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,"-");
			latime=latime+textwidth("-");
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,d[kx].ocupatie[i]);
			latime=latime+textwidth(d[kx].ocupatie[i])+4;
			
		}
	}
	settextjustify(0,1);
	for(i=1; i<=ktext; i++)
	{
		ok=0;
		if(latime2+textwidth(text[i])<425)
		{
			outtextxy(latime2,inaltime2,text[i]);
			latime2=latime2+textwidth(text[i])+4;
			ok=1;
		}
		
		if(latime2+ textwidth( text[i] ) >=425 && ok==0)
		{
			latime2=55;
			inaltime2=inaltime2+23;
			outtextxy(latime2,inaltime2,text[i]);
			latime2=latime2+textwidth(text[i])+4;
		}
	}
	
	swapbuffers();	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	latime=555;
	inaltime=440;
	
	readimagefile("bg/bg5.jpg",0,0,800,500);
	readimagefile("bg/personalitate.jpg",443,116,751,485);
	readimagefile("bg/personalitate_text.jpg",50,116,435,485);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	readimagefile("bg/sageata_back.jpg",12,234,36,268);
	readimagefile("bg/sageata_next.jpg",764,234,788,268);
	readimagefile(d[kx].numepoza,548,155,658,304);
	
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(LEFT_TEXT,0);
	setbkcolor(RGB(111,108,163));
	outtextxy(50,50,"Judetul ");
	outtextxy(50+textwidth("Judetul "),50,j[kx].judet);
	line(50,55,750,55);
	outtextxy(50,105,"Personalitate");
	
	settextstyle(10,0,3);
	settextjustify(1,0);
	setbkcolor(RGB(49,39,47));
	outtextxy(603,147,d[kx].nume);
	
	settextstyle(3,0,1);
	settextjustify(0,0);
	setbkcolor(RGB(81,68,78));
	setcolor(RGB(151,151,151));	
	
	outtextxy(460,340,"Nascut");
	outtextxy(460,360,"Decedat");
	outtextxy(460,380,"Varsta");
	outtextxy(460,400,"Casatorit cu");
	outtextxy(460,420,"Cetatenie");
	outtextxy(460,440,"Ocupatii");

	setcolor(WHITE);
	outtextxy(555,340,d[kx].nascut);
	outtextxy(555,360,d[kx].decedat);
	outtextxy(555,380,d[kx].varsta);
	outtextxy(555,400,d[kx].casatorit);
	outtextxy(555,420,d[kx].cetatenie);

	for(i=1; i<=8; i++)
	{
		ok=0;
		if( (latime+textwidth(d[kx].ocupatie[i]))<745)
		{
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,"-");
			latime=latime+textwidth("-");
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,d[kx].ocupatie[i]);
			ok=1;
			latime=latime+textwidth(d[kx].ocupatie[i])+4;
		}
		if(latime+textwidth(d[kx].ocupatie[i])>=745 && ok==0)
		{
			latime=555;
			inaltime=inaltime+20;
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,"-");
			latime=latime+textwidth("-");
			if(strcmp(d[kx].ocupatie[i],string)!=0)outtextxy(latime,inaltime,d[kx].ocupatie[i]);
			latime=latime+textwidth(d[kx].ocupatie[i])+4;
			
		}
	}

	inaltime2=134;
	latime2=55;
	settextjustify(0,1);
	
	for(i=1; i<=ktext; i++)
	{
		ok=0;
		if(latime2+textwidth(text[i])<425)
		{
			outtextxy(latime2,inaltime2,text[i]);
			latime2=latime2+textwidth(text[i])+4;
			ok=1;
		}
		
		if(latime2+ textwidth( text[i] ) >=425 && ok==0)
		{
			latime2=55;
			inaltime2=inaltime2+23;
			outtextxy(latime2,inaltime2,text[i]);
			latime2=latime2+textwidth(text[i])+4;
		}
	}
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	
	while( getmouseclick )
	{	
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			readimagefile("bg/sageata_back.jpg",12,234,36,268);
			readimagefile("bg/sageata_next.jpg",764,234,788,268);
			getmouseclick( WM_LBUTTONDOWN, x, y );
			
			if(mx>767 && mx<800 && my>0 && my<23) //X
			{
					//
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			
			else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						harta();
					}
			}
			
			else if(mx>12 && mx<36 && my>234 && my<268)//SAGEATA BACK
			{
				
				readimagefile("bg/sageata_back_apasat.jpg",12,234,36,268);
				if(x>12 && x<36 && y>234 && y<268)
				{
					judet1(kx);
				}
			}
			
			else if(mx>764 && mx<788 && my>234 && my<268)//SAGEATA next
			{
				
				readimagefile("bg/sageata_next_apasat.jpg",764,234,788,268);
				if(x>764 && x<788 && y>234 && y<268)
				{
					judet3(kx);
				}	
			}
	}
	getch();
}

void judet3(int kx)
{
	int latime=55, kk=0, i, inaltime=140, ok;
	char locuitorisir[15], suprafatasir[15], densitatesir[5];
	char municipiisir[5], orasesir[5], comunesir[5];
	itoa(j[kx].locuitori,locuitorisir,10);
	itoa(j[kx].suprafata,suprafatasir,10);
	itoa(j[kx].densitate,densitatesir,10);
	itoa(j[kx].municipii,municipiisir,10);
	itoa(j[kx].orase,orasesir,10);
	itoa(j[kx].comune,comunesir,10);
	
	readimagefile("bg/bg5.jpg",0,0,800,500);
	readimagefile("bg/rectangle4.jpg",49,117,750,395);
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(LEFT_TEXT,0);
	setbkcolor(RGB(111,108,163));
	outtextxy(50,50,"Judetul ");
	outtextxy(50+textwidth("Judetul "),50,j[kx].judet);
	line(50,55,750,55);
	setbkcolor(RGB(161,152,205));
	outtextxy(50,105,"Scurt istoric al judetului");
	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	readimagefile("bg/sageata_back.jpg",12,234,36,268);
	
	char numef[25], cuv[300][35];
	strcpy(numef,"text/");
	char auxjudet[25];
	strcpy(auxjudet,j[kx].judet);
	strcat(numef,strlwr(auxjudet));
	strcat(numef,".txt");
	fstream f1(numef, ios::in);
	
	do{
		kk++;
		f1>>cuv[kk];
	}while(!f1.eof());
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	
	inaltime=140;
	latime=55;
	
	for(i=1; i<=kk; i++)
	{
		ok=0;
		if(latime+textwidth(cuv[i])<745)
		{
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
			ok=1;
		}
		
		if(latime+ textwidth( cuv[i] ) >=745 && ok==0)
		{
			latime=55;
			inaltime=inaltime+23;
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
		}
	}
	
	swapbuffers();	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	readimagefile("bg/bg5.jpg",0,0,800,500);
	readimagefile("bg/rectangle4.jpg",49,117,750,395);
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(LEFT_TEXT,0);
	setbkcolor(RGB(111,108,163));
	outtextxy(50,50,"Judetul ");
	outtextxy(50+textwidth("Judetul "),50,j[kx].judet);
	line(50,55,750,55);
	setbkcolor(RGB(161,152,205));
	outtextxy(50,105,"Scurt istoric al judetului");
	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	readimagefile("bg/sageata_back.jpg",12,234,36,268);
	
	setbkcolor(RGB(81,68,78));
	settextstyle(3,0,1);
	//settextjustify(0,1);
	
	inaltime=140;
	latime=55;
	
	for(i=1; i<=kk; i++)
	{
		ok=0;
		if(latime+textwidth(cuv[i])<745)
		{
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
			ok=1;
		}
		
		if(latime+ textwidth( cuv[i] ) >=745 && ok==0)
		{
			latime=55;
			inaltime=inaltime+23;
			outtextxy(latime,inaltime,cuv[i]);
			latime=latime+textwidth(cuv[i])+4;
		}
	}
	
	while( getmouseclick )
	{	
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			readimagefile("bg/sageata_back.jpg",12,234,36,268);
			getmouseclick( WM_LBUTTONDOWN, x, y );
			
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					//
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						harta();
					}
			}
			else if(mx>12 && mx<36 && my>234 && my<268)
			{
				
				readimagefile("bg/sageata_back_apasat.jpg",12,234,36,268);
				if(x>12 && x<36 && y>234 && y<268)
				{
					judet2(kx);
				}
				
			}
	}
	getch();
}

void sortmun( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				if( strcmp( j[i].municipiu, j[ii].municipiu ) > 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( strcmp( j[i].municipiu, j[ii].municipiu ) < 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
}

void sortjud( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				if( strcmp( j[i].judet, j[ii].judet ) > 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( strcmp( j[i].judet, j[ii].judet ) < 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
}

void sortind( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				if( strcmp( j[i].indicatorauto, j[ii].indicatorauto ) > 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( strcmp( j[i].judet, j[ii].judet ) < 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
	
	
}
void sortprimar( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				if( strcmp( j[i].primar, j[ii].primar ) > 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( strcmp( j[i].primar, j[ii].primar ) < 0 )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
}

void sortloc( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				if( j[i].locuitori > j[ii].locuitori )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( j[i].locuitori < j[ii].locuitori )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
}

void sortsupraf( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				if( j[i].suprafata > j[ii].suprafata )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( j[i].suprafata < j[ii].suprafata )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
}
void sortcod( bool asc )
{
	for( int i = 1; i < k; i++ )
	{
		for( int ii = 1; ii < k; ii++ )
		{
			if( asc )
			{
				
				if( j[i].cod > j[ii].cod )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
			else
			{
				if( j[i].cod < j[ii].cod )
				{
					judete aux;
					aux = j[i];
					j[i] = j[ii];
					j[ii] = aux;
				}
			}
		}
	}
	
	
}

int edit( int index, char modific[], int& strk, bool cif )
{
	if( kbhit() )
	{
		modific[strk] = getch();
		strk++;		
		if ( modific[strk-1] == 13 )
		{
			modific[strk-1] = '\0';
			strk = 0;
			return 1;
		}
		else if (modific[strk - 1] == 8 )
		{
			modific[strk - 2] = '\0';
			modific[strk - 1] = '\0';
			strk -= 2;
		}
		else if( modific[strk-1] == 27 )
		{
			strk = 0;
			modific[strk] = '\0';
			return 0;
		}
		if ( strk < 0 ) 
		{
			strk = 0; 
			modific[strk] = '\0';
		}
		modific[strk]='\0';
	}
	return -1;
}

int selectindex(int x, int y )
{
	int index = -1;
	
	//while( !kbhit() && index == -1 )
	{
		//getmouseclick( WM_LBUTTONDOWN, x, y );
		if( y > 128 && y < 150 && x > 48 && x < 855 )
			index = 1;
		else if( y > 152 && y < 176 && x > 48 && x < 750 )
			index = 2;
		else if( y > 178 && y < 201 && x > 48 && x < 750 )
			index = 3;
		else if( y > 203 && y < 225 && x > 48 && x < 750 )
			index = 4;
		else if( y > 227 && y < 251 && x > 48 && x < 750 )
			index = 5;
		else if( y > 253 && y < 276 && x > 48 && x < 750 )
			index = 6;
		else if( y > 278 && y < 300 && x > 48 && x < 750 )
			index = 7;
		else if( y > 302 && y < 326 && x > 48 && x < 750 )
			index = 8;
		else if( y > 328 && y < 351 && x > 48 && x < 750 )
			index = 9;
		else if( y > 353 && y < 375 && x > 48 && x < 750 )
			index = 10;
		else if( y > 377 && y < 400 && x > 48 && x < 750 )
			index = 11;
		
		else if(mousex()>767 && mousex()<800 && mousey()>0 && mousey()<23) //X
		{
			
			readimagefile("bg/x_apasat.gif",767,0,800,23);
			if(x>767 && x<800 && y>0 && y<23)
			{
				exit(0);
			}
		}
		
		else if(mousex()>0 && mousex()<33 && mousey()>0 && mousey()<23) //BACK
			{
				
				readimagefile("bg/back_apasat.gif",0,0,33,23);
				if(x>0 && x<33 && y>0 && y<23)
				{
					harta();
				}
			}
	}
	if( kbhit() )
		getch();
	return index;
}

void tabel1()
{
	int i;
	bool ascmun = true, ascjud=true, ascind=true, ascprimar=true, ascloc=true, ascsupraf=true, asccod=true;
	char locuitorisir[15];
	char suprafatasir[10];
	char codsir[10];
	char cotare[50], aux[50];
	cotare[0]='\0';
	bool quit = false;
	int strk = 0, strkk = 0, occurs = 0, pag = 1;
	int click=0;
	bool rclick = false;
	int rectx, recty;
	int index = -1;
	char primaredit[50] = {'\0'}, locedit[50]= {'\0'};
	bool modific = 0;
	while( !quit )
	{
		swapbuffers();
		readimagefile("bg/bg5.jpg",0,0,800,500);
		{
		setcolor(WHITE);
		settextstyle(8,0,5);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		setbkcolor(RGB(117,121,185));
		outtextxy(getmaxx()/2,55,"AFISARE");		
		settextstyle(3,0,1);
		settextjustify(0,1);
		setbkcolor(RGB(81,68,78));	
		readimagefile("bg/tabel.jpg",46,101,752,402);
		readimagefile("bg/sageata_next.jpg",764,234,788,268);
		readimagefile("bg/sageata_back.jpg",12,234,36,268);
		readimagefile("bg/tabel_1.jpg",48,103,163125);
		readimagefile("bg/tabel_2.jpg",166,103,299,125);
		readimagefile("bg/tabel_3.jpg",302,103,371,125);
		readimagefile("bg/tabel_4.jpg",374,103,548,125);
		readimagefile("bg/tabel_5.jpg",551,103,607,125);
		readimagefile("bg/tabel_6.jpg",610,103,675,125);
		readimagefile("bg/tabel_7.jpg",678,103,749,125);
		}
		if( cotare[0] == '\0' )
		{
			readimagefile("bg/searchbar.jpg",46,70,752,95);
			click=0;
			for(i=pag * 11 - 10; i<=pag * 11; i++)
			{
				if( i < k )
				{
					outtextxy(50,145+((i-1)%11)*25,j[i].judet);
					outtextxy(169,145+((i-1)%11)*25,j[i].municipiu);
					outtextxy(324,145+((i-1)%11)*25,j[i].indicatorauto);
					if( index == i && modific == 0 )
					{
						int ok = edit( (pag - 1) * 11 + index, primaredit, strkk, 0 );
						outtextxy(377,145+((i-1)%11)*25, primaredit);
						if ( ok == 1 )
						{
							strcpy( j[i].primar, primaredit );
							index = -1;
						}
						if( ok == 0 )
						{
							index = -1;
						}
					}
					else
						outtextxy(377,145+((i-1)%11)*25,j[i].primar);
					itoa(j[i].locuitori,locuitorisir,10);
					
					if( index == i && modific == 1 )
					{
						int ok = edit( (pag - 1) * 11 + index, locedit, strkk, 1 );
						outtextxy(552,145+((i-1)%11)*25, locedit);
						if( ok == 1)
						{
							j[i].locuitori = atoi( locedit );
							index = -1;
						}
						if( ok == 0 )
						{
							index = -1;
						}
						
					}
					else	
						outtextxy(552,145+((i-1)%11)*25,locuitorisir);
					
					itoa(j[i].suprafata,suprafatasir,10);
					outtextxy(625,145+((i-1)%11)*25,suprafatasir);
					itoa(j[i].cod,codsir,10);
					outtextxy(687,145+((i-1)%11)*25,codsir);
				}
			}
		}	
		if( cotare[0] != '\0')
		{
			readimagefile("bg/searchbar_apasat.jpg",46,70,752,95);
			occurs = 0;
			char auxjud[25];
			char auxmun[25];
			char auxind[25];
			char auxprimar[25];
			char auxloc[8];
			char auxsupr[8];
			char auxcod[8];
			for(i=1; i<=k; i++)
			{
				strcpy(auxjud,j[i].judet);
				strcpy(auxmun,j[i].municipiu);
				strcpy(auxind,j[i].indicatorauto);
				strcpy(auxprimar,j[i].primar);
				itoa(j[i].locuitori,auxloc,10);
				itoa(j[i].suprafata,auxsupr,10);
				itoa(j[i].cod,auxcod,10);
				if( strstr( strupr(auxjud), strupr(cotare) ) != NULL || 
					strstr( strupr(auxmun), strupr(cotare) ) != NULL ||
					strstr( strupr(auxind), strupr(cotare) ) != NULL ||				
					strstr( strupr(auxprimar), strupr(cotare) ) != NULL ||
					strstr( strupr(auxloc), strupr(cotare) ) != NULL ||
					strstr( strupr(auxsupr), strupr(cotare) ) != NULL ||
					strstr( strupr(auxcod), strupr(cotare) ) != NULL)
				{
					if( pag == occurs / 11 + 1)  
					{	
						outtextxy(50,145+(occurs)%11*25,j[i].judet);
						outtextxy(169,145+(occurs)%11*25,j[i].municipiu);
						outtextxy(324,145+(occurs)%11*25,j[i].indicatorauto);
						outtextxy(377,145+(occurs)%11*25,j[i].primar);
						itoa(j[i].locuitori,locuitorisir,10);
						outtextxy(552,145+(occurs)%11*25,locuitorisir);
						itoa(j[i].suprafata,suprafatasir,10);
						outtextxy(625,145+(occurs)%11*25,suprafatasir);
						itoa(j[i].cod,codsir,10);
						outtextxy(687,145+(occurs)%11*25,codsir);
					}
					occurs++;
				}
			}
		}
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		
		int mx=mousex();
		int my=mousey();
		int x,y;
		int x2,y2;
		getmouseclick( WM_LBUTTONDOWN, x, y );
		getmouseclick( WM_RBUTTONDOWN, x2, y2);
		
		if(admin)
		{
			if( x2 != -1 )
			{
				rectx = x2;
				recty = y2;
				rclick = true;			
			}
			if( rclick )
			{
				readimagefile("bg/clickdreapta.jpg",rectx,recty,rectx+80,recty+60);
				setbkcolor(RGB(57,44,54));
				outtextxy( rectx + 7, recty + 22, "EDIT" );
				outtextxy( rectx + 7, recty + 47, "DELETE" );
				
				
				if ( x != -1 )
				{
					if( x < rectx || x > rectx + 200 || y < recty || y > recty + 300 )
					{
						rclick = false;
					}
					else if( y > recty && y < recty + 50 )
					{
						index = selectindex( rectx, recty );
						index = (pag - 1) * 11 + index;
						if( y > recty + 25 )
						{	
							for( int i = index; i <= k; i++ )
							{
								j[i] = j[i+1];
							}
							k--;
							
							index = -1;
						}
						else if( y < recty + 25 )
						{
							if ( index != -1 )
							{
								strcpy( primaredit, j[index].primar );
								itoa(j[index].locuitori,locuitorisir,10);
								strcpy( locedit, locuitorisir );
							}
							if( rectx > 375 and rectx < 550 ) //377,145
							{
								modific = 0; //0 = primar
								strkk = strlen( primaredit );
							}
							if( rectx > 553 and rectx < 608 )
							{
								modific = 1; //1 = locuitori
								strkk = strlen( locedit );
							}
						}
						rclick = false;
					}
				}
			}
		}
		
		
		if(mx>46 && mx<752 && my>70 && my<95)
		{
			readimagefile("bg/searchbar_apasat.jpg",46,70,752,95);
			if(x>46 && x<752 && y>70 && y<95)
			{
				click=1;
			}
		}
		if(x<46 || x>752 || y<70 || y>95)
			click=0;
		if(click==1)readimagefile("bg/searchbar_apasat.jpg",46,70,752,95);
		setbkcolor(RGB(57,43,54));
		if( kbhit() and index == -1 )
			strcpy( cotare, cautare( cotare, strk ));
		outtextxy( 53, 88, cotare);
			
		
		
		if(mx>767 && mx<800 && my>0 && my<23) //X
		{
			
			readimagefile("bg/x_apasat.gif",767,0,800,23);
			if(x>767 && x<800 && y>0 && y<23)
			{
				exit(0);
			}
		}
		
		if(mx>45 && mx<164 && my>100 && my<130) //JudSort
		{
			
			readimagefile("bg/tabel_1_apasat.jpg",48,103,163,125);
			if(x>45 && x<164 && y>100 && y<130)
			{
				sortjud( ascjud );
				ascjud = !ascjud;
			}
		}

		else if(mx>165 && mx<300 && my>100 && my<130) //MunicipiuSort
		{
			
			readimagefile("bg/tabel_2_apasat.jpg",166,103,299,125);
			if(x>165 && x<300 && y>100 && y<130)
			{
				sortmun( ascmun );
				ascmun = !ascmun;
			}
		}
		
		else if(mx>300 && mx<373 && my>100 && my<130) //IndSort
		{
			
			readimagefile("bg/tabel_3_apasat.jpg",302,103,371,125);
			if(x>300 && x<373 && y>100 && y<130)
			{
				sortind( ascind );
				ascind = !ascind;
			}
		}
		
		else if(mx>374 && mx<549 && my>100 && my<130) //PrimarSort
		{
			
			readimagefile("bg/tabel_4_apasat.jpg",374,103,548,125);
			if(x>374 && x<549 && y>100 && y<130)
			{
				sortprimar( ascprimar );
				ascprimar = !ascprimar;
			}
		}
		
		else if(mx>550 && mx<607 && my>100 && my<130) //LocSort
		{
			
			readimagefile("bg/tabel_5_apasat.jpg",551,103,607,125);
			if(x>550 && x<607 && y>100 && y<130)
			{
				sortloc( ascloc );
				ascloc = !ascloc;
			}
		}
		
		else if(mx>610 && mx<677 && my>100 && my<130) //SuprafSort
		{
			
			readimagefile("bg/tabel_6_apasat.jpg",610,103,675,125);
			if(x>610 && x<677 && y>100 && y<130)
			{
				sortsupraf( ascsupraf );
				ascsupraf = !ascsupraf;
			}
		}
		
		else if(mx>678 && mx<750 && my>100 && my<130) //CodSort
		{
			
			readimagefile("bg/tabel_7_apasat.jpg",678,103,749,125);
			if(x>678 && x<750 && y>100 && y<130)
			{
				sortcod( asccod );
				asccod = !asccod;
			}
		}
		
		else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
				
				readimagefile("bg/back_apasat.gif",0,0,33,23);
				if(x>0 && x<33 && y>0 && y<23)
				{
					quit = true;
				}
			}
		else if(mx>764 && mx<788 && my>234 && my<268) //SAGEATA_NEXT
			{
				
				readimagefile("bg/sageata_next_apasat.jpg",764,234,788,268);
				if(x>764 && x<788 && y>234 && y<268)
				{
					pag++;
					if ( pag * 11 > k + k % 11 + 7 )
						pag--;
				}
				
			}
		else if(mx>12 && mx<36 && my>234 && my<268) //SAGEATA_BACK
			{
				
				readimagefile("bg/sageata_back_apasat.jpg",12,234,36,268);
				if(x>12 && x<36 && y>234 && y<268)
				{
					pag--;
					if ( pag < 1 )
						pag++;
				}
				
			}
		if ( cotare[0] != '\0' && pag > occurs / 11 ) pag = occurs / 11+1;
		
	}
	bazadedate();
	//getch();
	cleardevice();
}


void aplicatii()
{
	readimagefile("bg/bg6.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"APLICATII");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,156,"HARTA INTERACTIVA");
	outtextxy(getmaxx()/2,222,"CREARE PAGINA WEB");
	outtextxy(getmaxx()/2,246,"DUPA UN ANUMIT JUDET");
	outtextxy(getmaxx()/2,300,"JUDETELE DINTR-O");
	outtextxy(getmaxx()/2,324,"ANUMITA REGIUNE");
	outtextxy(getmaxx()/2,378,"JUDETELE VECINE ALE");
	outtextxy(getmaxx()/2,402,"UNUI ANUMIT JUDET");

	swapbuffers();

	readimagefile("bg/bg6.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"APLICATII");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	outtextxy(getmaxx()/2,156,"HARTA INTERACTIVA");
	outtextxy(getmaxx()/2,222,"CREARE PAGINA WEB");
	outtextxy(getmaxx()/2,246,"DUPA UN ANUMIT JUDET");
	outtextxy(getmaxx()/2,300,"JUDETELE DINTR-O");
	outtextxy(getmaxx()/2,324,"ANUMITA REGIUNE");
	outtextxy(getmaxx()/2,378,"JUDETELE VECINE ALE");
	outtextxy(getmaxx()/2,402,"UNUI ANUMIT JUDET");
	
	while( getmouseclick )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/bg6.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			setcolor(WHITE);
			settextstyle(8,0,6);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setbkcolor(RGB(129,130,195));
			outtextxy(getmaxx()/2,70,"APLICATII");
			setbkcolor(RGB(61,42,46));
			settextstyle(8,0,2);
			outtextxy(getmaxx()/2,156,"HARTA INTERACTIVA");
			outtextxy(getmaxx()/2,222,"CREARE PAGINA WEB");
			outtextxy(getmaxx()/2,246,"DUPA UN ANUMIT JUDET");
			outtextxy(getmaxx()/2,300,"JUDETELE DINTR-O");
			outtextxy(getmaxx()/2,324,"ANUMITA REGIUNE");
			outtextxy(getmaxx()/2,378,"JUDETELE VECINE ALE");
			outtextxy(getmaxx()/2,402,"UNUI ANUMIT JUDET");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>767 && mx<800 && my>0 && my<23) //X
			{
				
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			
			else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
				
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>240 && mx<559 && my>121 && my<180) //PRIMUL BUTON
			{
				
					
					readimagefile("bg/rectangle5.jpg",240,121,559,180);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,156,"HARTA INTERACTIVA");
					if(x>240 && x<559 && y>121 && y<180)
					{
						harta();
					}
			}
			
			else if(mx>250 && mx<559 && my>199 && my<258) //AL DOILEA BUTON
			{
				
					
					readimagefile("bg/rectangle5.jpg",240,199,559,258);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,222,"CREARE PAGINA WEB");
					outtextxy(getmaxx()/2,246,"DUPA UN ANUMIT JUDET");
					if(x>250 && x<559 && y>199 && y<258)
					{
						pagina_web();
					}
			}
			
			else if(mx>250 && mx<551 && my>277 && my<336) //AL TREILEA BUTON
			{
				
					
					readimagefile("bg/rectangle5.jpg",240,277,559,336);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,300,"JUDETELE DINTR-O");
					outtextxy(getmaxx()/2,324,"ANUMITA REGIUNE");
					if(x>240 && x<560 && y>277 && y<336)
					{
						aplicatie1();
					}
			}
			
			else if(mx>250 && mx<511 && my>355 && my<414) //AL PATRULEA BUTON
			{
				
					
					readimagefile("bg/rectangle5.jpg",240,355,559,414);
					setbkcolor(RGB(35,15,19));
					settextstyle(8,0,2);
					outtextxy(getmaxx()/2,378,"JUDETELE VECINE ALE");
					outtextxy(getmaxx()/2,402,"UNUI ANUMIT JUDET");
					if(x>250 && x<511 && y>355 && y<414)
					{
						aplicatie2();
					}
			}
	}
	getch();
	cleardevice();
}


void pagina_web()
{
	int kx;
	readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
	
	swapbuffers();
	
	readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
	
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
			readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			settextstyle(8,0,3);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setbkcolor(RGB(146,145,205));
			outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>293 && mx<347 && my>243 && my<284) //1-AB
			{
					
					readimagefile("bg/harta/bg_ab.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					setbkcolor(RGB(146,145,205));
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>293 && x<347 && y>243 && y<293)
					{
						kx = 1;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>178 && mx<252 && my>231 && my<274) //2-AR
			{
					
					readimagefile("bg/harta/bg_ar.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>178 && x<252 && y>231 && y<274)
					{
						kx=2;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>372 && mx<411 && my>318 && my<413) //3-AG
			{
					
					readimagefile("bg/harta/bg_ag.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>372 && x<411 && y>243 && y<413)
					{
						kx=3;
						pagina_web_2(kx);
					}
			}
			
			if(mx>463 && mx<538 && my>221 && my<271) //4-BC
			{
					
					readimagefile("bg/harta/bg_bc.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>463 && x<538 && y>221 && y<271)
					{
						kx=4;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>200 && mx<269 && my>160 && my<227) //5-BH
			{
					
					readimagefile("bg/harta/bg_bh.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>200 && x<269 && y>160 && y<227)
					{
						kx=5;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>343 && mx<402 && my>150 && my<200) //6-BN
			{
					
					readimagefile("bg/harta/bg_bn.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>343 && x<402 && y>150 && y<200)
					{
						kx=6;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>479 && mx<521 && my>96 && my<150) //7-BT
			{
					
					readimagefile("bg/harta/bg_bt.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>479 && x<521 && y>96 && y<150)
					{
						kx=7;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>385 && mx<444 && my>275 && my<317) //8-BV
			{
					
					readimagefile("bg/harta/bg_bv.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>385 && x<444 && y>275 && y<317)
					{
						kx=8;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>537 && mx<585 && my>331 && my<378) //9-BR
			{
					
					readimagefile("bg/harta/bg_br.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>537 && x<585 && y>331 && y<378)
					{
						kx=9;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>485 && mx<531 && my>326 && my<375) //10-BZ
			{
					
					readimagefile("bg/harta/bg_bz.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>485 && x<531 && y>326 && y<375)//////////
					{
						kx=10;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>194 && mx<258 && my>317 && my<378) //11-CS
			{
					
					readimagefile("bg/harta/bg_cs.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>194 && x<258 && y>317 && y<378)//////////
					{
						kx=11;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>485 && mx<570 && my>412 && my<435) //12-CL
			{
					
					readimagefile("bg/harta/bg_cl.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>485 && x<570 && y>412 && y<435)//////////
					{
						kx=12;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>275 && mx<345 && my>195 && my<237) //13-CJ
			{
					
					readimagefile("bg/harta/bg_cj.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>275 && x<345 && y>195 && y<237)//////////
					{
						kx=13;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>582 && mx<623 && my>389 && my<465) //14-CT
			{
					
					readimagefile("bg/harta/bg_ct.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>582 && x<623 && y>321 && y<465)//////////
					{
						kx=14;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>435 && mx<481 && my>269 && my<306) //15-CV
			{
					
					readimagefile("bg/harta/bg_cv.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>435 && x<481 && y>269 && y<306)//////////
					{
						kx=15;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>413 && mx<450 && my>355 && my<404) //16-DB
			{
					
					readimagefile("bg/harta/bg_db.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>413 && x<450 && y>355 && y<404)//////////
					{
						kx=16;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>300 && mx<346 && my>405 && my<466) //17-DJ
			{
					
					readimagefile("bg/harta/bg_dj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>300 && x<346 && y>405 && y<466)//////////
					{
						kx=17;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>545 && mx<582 && my>271 && my<327) //18-GL
			{
					
					readimagefile("bg/harta/bg_gl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>545 && x<582 && y>271 && y<327)//////////
					{
						kx=18;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>440 && mx<484 && my>427 && my<465) //19-GR
			{
					
					readimagefile("bg/harta/bg_gr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>440 && x<484 && y>427 && y<465)//////////
					{
						kx=19;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>282 && mx<327 && my>342 && my<383) //20-GJ
			{
					
					readimagefile("bg/harta/bg_gj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>282 && x<327 && y>342 && y<383)//////////
					{
						kx=20;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>413 && mx<450 && my>193 && my<266) //21-HR
			{
					
					readimagefile("bg/harta/bg_hr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>413 && x<450 && y>193 && y<266)//////////
					{
						kx=21;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>257 && mx<302 && my>260 && my<337) //22-HD
			{
					
					readimagefile("bg/harta/bg_hd.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>257 && x<302 && y>260 && y<337)//////////
					{
						kx=22;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>484 && mx<583 && my>384 && my<410) //23-IL
			{
					
					readimagefile("bg/harta/bg_il.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>484 && x<583 && y>384 && y<410)//////////
					{
						kx=23;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>502 && mx<576 && my>154 && my<203) //24-IS
			{
					
					readimagefile("bg/harta/bg_is.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>502 && x<576 && y>154 && y<375)//////////
					{
						kx=24;
						pagina_web_2(kx);
					}
			}
		
			else if(mx>456 && mx<482 && my>386 && my<422) //25-IF/ILFOV
			{
					
					readimagefile("bg/harta/bg_if.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>456 && x<482 && y>386 && y<422)//////////
					{
						kx=25;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>308 && mx<400 && my>117 && my<149) //26-MM
			{
					
					readimagefile("bg/harta/bg_mm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>308 && x<400 && y>117 && y<149)//////////
					{
						kx=26;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>249 && mx<283 && my>385 && my<441) //27-MH
			{
					
					readimagefile("bg/harta/bg_mh.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>249 && x<283 && y>385 && y<441)//////////
					{
						kx=27;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>348 && mx<407 && my>207 && my<257) //28-MS
			{
					
					readimagefile("bg/harta/bg_ms.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>348 && x<407 && y>207 && y<257)//////////
					{
						kx=28;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>447 && mx<511 && my>182 && my<218) //29-NT
			{
					
					readimagefile("bg/harta/bg_nt.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>447 && x<511 && y>182 && y<218)//////////
					{
						kx=29;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>350 && mx<385 && my>392 && my<471) //30-OT
			{
					
					readimagefile("bg/harta/bg_ot.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>350 && x<385 && y>392 && y<471)//////////
					{
						kx=30;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>449 && mx<484 && my>337 && my<382) //31-PH
			{
					
					readimagefile("bg/harta/bg_ph.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>449 && x<484 && y>337 && y<382)//////////
					{
						kx=31;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>239 && mx<306 && my>116 && my<154) //32-SM
			{
					
					readimagefile("bg/harta/bg_sm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>239 && x<306 && y>116 && y<154)//////////
					{
						kx=32;
						pagina_web_2(kx);
					}
			}
			else if(mx>270 && mx<318 && my>165 && my<197) //33-SJ
			{
					
					readimagefile("bg/harta/bg_sj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>270 && x<318 && y>165 && y<197)//////////
					{
						kx=33;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>333 && mx<381 && my>271 && my<315) //34-SB
			{
					
					readimagefile("bg/harta/bg_sb.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>333 && x<381 && y>271 && y<315)//////////
					{
						kx=34;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>406 && mx<472 && my>115 && my<172) //35-SV
			{
					
					readimagefile("bg/harta/bg_sv.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>406 && x<472 && y>115 && y<172)//////////
					{
						kx=35;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>388 && mx<437 && my>421 && my<471) //36-TR
			{
					
					readimagefile("bg/harta/bg_tr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>388 && x<437 && y>421 && y<471)//////////
					{
						kx=36;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>150 && mx<240 && my>278 && my<316) //37-TM
			{
					
					readimagefile("bg/harta/bg_tm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>150 && x<240 && y>278 && y<316)//////////
					{
						kx=37;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>590 && mx<680 && my>331 && my<384) //38-TL
			{
					
					readimagefile("bg/harta/bg_tl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>590 && x<680 && y>331 && y<384)//////////
					{
						kx=38;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>542 && mx<586 && my>205 && my<265) //39-VS
			{
					
					readimagefile("bg/harta/bg_vs.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>542 && x<586 && y>205 && y<265)//////////
					{
						kx=39;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>329 && mx<367 && my>321 && my<381) //40-VL
			{
					
					readimagefile("bg/harta/bg_vl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>329 && x<367 && y>321 && y<381)//////////
					{
						kx=40;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>485 && mx<535 && my>274 && my<320) //41-VN
			{
					
					readimagefile("bg/harta/bg_vn.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,3);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
					if(x>485 && x<535 && y>274 && y<320)//////////
					{
						kx=41;
						pagina_web_2(kx);
					}
			}
			
			else if(mx>767 && mx<800 && my>0 && my<23) 
			{
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						aplicatii();
					}
			}
	}
	getch();
	cleardevice();
}

void pagina_web_2(int kx)
{
	char tralala[100];
	
	strcpy(tralala,"bg/harta/bg_");
	strcat(tralala,j[kx].indicatorauto);
	strcat(tralala,".jpg");
	
	
	char numejud[10];
	//strcpy(numejud,"x");
	strcpy(numejud,j[kx].indicatorauto);
	strcat(numejud,".html");
	
	
	readimagefile(tralala,0,0,800,500);	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	settextstyle(8,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
	readimagefile("bg/personalitate_text.jpg",610,170,770,270);
	
	settextstyle(3,0,1);
	settextjustify(0,1);
	setbkcolor(RGB(81,68,78));
	outtextxy(618,192,"Pagina web despre");
	outtextxy(618,215,"judetul selectat a");
	outtextxy(618,238,"fost salvata in fisierul");
	outtextxy(618,261,numejud);
	outtextxy(618+textwidth(numejud),261,"!");
	
	
	swapbuffers(); ////////////////////
	
	readimagefile(tralala,0,0,800,500);	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	settextstyle(8,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
	readimagefile("bg/personalitate_text.jpg",610,170,770,270);
	
	settextstyle(3,0,1);
	settextjustify(0,1);
	setbkcolor(RGB(81,68,78));
	outtextxy(618,192,"Pagina web despre");
	outtextxy(618,215,"judetul selectat a");
	outtextxy(618,238,"fost salvata in fisierul");
	outtextxy(618,261,numejud);
		outtextxy(618+textwidth(numejud),261,"!");
	
	
	fstream html(numejud, ios::out);
	int i=0, ok, i2;
	
	char cuv[2000][250];
	int kcuv1=0;
	
	fstream matrita("text/matrita.txt", ios::in);
	do{
		kcuv1++;
		matrita>>cuv[kcuv1];
	}while(!matrita.eof());
	matrita.close();
	
	for(i=1; i<=kcuv1; i++)
	{
		ok=0;
		if(  strstr(cuv[i],"inlocuire1") != NULL  )
		{
			html<<j[kx].judet<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuire2")!= NULL    )
		{
			html<<j[kx].judet<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuire3") != NULL   )
		{
			html<<j[kx].pctcardinal<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirea") != NULL   )
		{
			html<<j[kx].locuitori<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuireb") != NULL   )
		{
			html<<j[kx].suprafata<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirec")  != NULL  )
		{
			html<<j[kx].densitate<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuired") != NULL   )
		{
			html<<j[kx].municipiu<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuiree")  != NULL  )
		{
			html<<j[kx].judet;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuiref") != NULL   )
		{
			html<<j[kx].primar;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuireg")!= NULL    )
		{
			html<<j[kx].municipii<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuireh") != NULL   )
		{
			html<<j[kx].orase<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirei") != NULL   )
		{
			html<<j[kx].comune<<" ";
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirej") != NULL   )
		{
			html<<j[kx].judet;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirek")!= NULL    )
		{
			html<<j[kx].obiectiv;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirem") != NULL   )
		{
			html<<d[kx].nume;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuireo") != NULL   )
		{
			html<<d[kx].nume;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirep") != NULL   )
		{
			html<<d[kx].nascut;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuireq")!= NULL    )
		{
			html<<d[kx].decedat;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirer") != NULL   )
		{
			html<<d[kx].varsta;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuires") != NULL   )
		{
			html<<d[kx].casatorit;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuiret")!= NULL    )
		{
			html<<d[kx].cetatenie;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirev")!= NULL    )
		{
			html<<j[kx].pozajudet;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirew")!= NULL    )
		{
			html<<j[kx].harta;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirex") != NULL   )
		{
			html<<j[kx].stema;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirey") != NULL   )
		{
			html<<j[kx].pozaobiectiv;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirez") != NULL   )
		{
			html<<d[kx].numepoza;
			ok=1;
		}
		
		if(  strstr(cuv[i],"inlocuirel") != NULL   )
		{
			ok=1;
			int kk=0;
			char numef[25], cuv[300][35];
			strcpy(numef,"text/");
			char auxjudet[25];
			strcpy(auxjudet,j[kx].judet);
			strcat(numef,strlwr(auxjudet));
			strcat(numef,".txt");
			fstream f1(numef, ios::in);
			
			do{
				kk++;
				f1>>cuv[kk];
				html<<cuv[kk]<<" ";
			}while(!f1.eof());
		}
		
		if(  strstr(cuv[i],"inlocuireu") != NULL   )
		{
			ok=1;
			char string[3]="-";
			for(i2=1; i2<=8; i2++)
			{
				if(strcmp (d[kx].ocupatie[i2] , string) != 0 )
					html<<" - "<<d[kx].ocupatie[i2];
			}	
		}
		
		if(  strstr(cuv[i],"inlocuiren")!= NULL    )
		{
			ok=1;
			char numetext[35], text[300][35], kxsir[5];
			
			int ktext=0;
			strcpy(numetext,"personalitati/");
			itoa(kx,kxsir,10);
			strcat(numetext,kxsir);
			strcat(numetext,".txt");
			
			fstream f2(numetext,ios::in);
			do{
				ktext++;
				f2>>text[ktext];
				html<<text[ktext]<<" ";
			}while(!f2.eof());
		}
		
		if(ok==0)
			html<<cuv[i]<<" ";
		ok=0;
	}
	
	html.close();
	ShellExecute(NULL,"open",numejud,NULL,NULL,SW_SHOWNORMAL);
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx2=mousex();
		int my2=mousey();
		int x2,y2;
		readimagefile(tralala,0,0,800,500);	
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		settextstyle(8,0,3);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		setbkcolor(RGB(146,145,205));
		outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
		readimagefile("bg/personalitate_text.jpg",610,170,770,270);
		
		settextstyle(3,0,1);
		
		settextjustify(0,1);
		setbkcolor(RGB(81,68,78));
		outtextxy(618,192,"Pagina web despre");
		outtextxy(618,215,"judetul selectat a");
		outtextxy(618,238,"fost salvata in fisierul");
		outtextxy(618,261,numejud);
		outtextxy(618+textwidth(numejud),261,"!");
	
		getmouseclick( WM_LBUTTONDOWN, x2, y2 );	
			
		if(mx2>767 && mx2<800 && my2>0 && my2<23) 
		{
				
				readimagefile("bg/x_apasat.gif",767,0,800,23);
				if(x2>767 && x2<800 && y2>0 && y2<23)
				{
					exit(0);
				}
		}
		else if(mx2>0 && mx2<33 && my2>0 && my2<23) 
		{
				
				readimagefile("bg/back_apasat.gif",0,0,33,23);
				if(x2>0 && x2<33 && y2>0 && y2<23)
				{
					aplicatii();
				}
		}
	}
	
	
	
	//getch();
	cleardevice();
	
}


void pagina_web_3(int kx)
{
	char tralala[100];
	
	strcpy(tralala,"bg/harta/bg_");
	strcat(tralala,j[kx].indicatorauto);
	strcat(tralala,".jpg");
	
	readimagefile(tralala,0,0,800,500);	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	settextstyle(8,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
	readimagefile("bg/personalitate_text.jpg",610,170,770,270);
	
	swapbuffers();
	
	readimagefile(tralala,0,0,800,500);	
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	settextstyle(8,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
	readimagefile("bg/personalitate_text.jpg",610,170,770,270);
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx2=mousex();
		int my2=mousey();
		int x2,y2;
		readimagefile(tralala,0,0,800,500);	
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		settextstyle(8,0,3);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		setbkcolor(RGB(146,145,205));
		outtextxy(getmaxx()/2,55,"CREARE PAGINA WEB DESPRE UN ANUMIT JUDET");
		readimagefile("bg/personalitate_text.jpg",610,170,770,270);
		
		settextstyle(3,0,1);
		
		settextjustify(0,1);
		setbkcolor(RGB(81,68,78));
		outtextxy(618,192,"Pagina web despre");
		outtextxy(618,215,"judetul selectat a");
		outtextxy(618,238,"fost salvata in fisierul");
		outtextxy(618,261,"judet.html.");
	
		getmouseclick( WM_LBUTTONDOWN, x2, y2 );	
			
		if(mx2>767 && mx2<800 && my2>0 && my2<23) 
		{
				
				readimagefile("bg/x_apasat.gif",767,0,800,23);
				if(x2>767 && x2<800 && y2>0 && y2<23)
				{
					exit(0);
				}
		}
		else if(mx2>0 && mx2<33 && my2>0 && my2<23) 
		{
				
				readimagefile("bg/back_apasat.gif",0,0,33,23);
				if(x2>0 && x2<33 && y2>0 && y2<23)
				{
					aplicatii();
				}
		}
	}
}

void aplicatie1()
{
	int kx;
	readimagefile("bg/bgaplicatie1.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"JUDETELE DINTR-O ANUMITA REGIUNE");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	settextjustify(0,1);
	outtextxy(113+((221-textwidth("BANAT"))/2),139,"BANAT");
	outtextxy(113+((221-textwidth("BUCOVINA"))/2),178,"BUCOVINA");
	outtextxy(113+((221-textwidth("CRISANA"))/2),217,"CRISANA");
	outtextxy(113+((221-textwidth("DOBROGEA"))/2),256,"DOBROGEA");
	outtextxy(113+((221-textwidth("MARAMURES"))/2),295,"MARAMURES");
	outtextxy(113+((221-textwidth("MODOLVA"))/2),334,"MOLDOVA");
	outtextxy(113+((221-textwidth("MUNTENIA"))/2),373,"MUNTENIA");
	outtextxy(113+((221-textwidth("OLTENIA"))/2),412,"OLTENIA");
	outtextxy(113+((221-textwidth("TRANSILVANIA"))/2),451,"TRANSILVANIA");

	swapbuffers();
	
	readimagefile("bg/bgaplicatie1.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(129,130,195));
	outtextxy(getmaxx()/2,70,"JUDETELE DINTR-O ANUMITA REGIUNE");
	setbkcolor(RGB(61,42,46));
	settextstyle(8,0,2);
	settextjustify(0,1);
	outtextxy(113+((221-textwidth("BANAT"))/2),139,"BANAT");
	outtextxy(113+((221-textwidth("BUCOVINA"))/2),178,"BUCOVINA");
	outtextxy(113+((221-textwidth("CRISANA"))/2),217,"CRISANA");
	outtextxy(113+((221-textwidth("DOBROGEA"))/2),256,"DOBROGEA");
	outtextxy(113+((221-textwidth("MARAMURES"))/2),295,"MARAMURES");
	outtextxy(113+((221-textwidth("MODOLVA"))/2),334,"MOLDOVA");
	outtextxy(113+((221-textwidth("MUNTENIA"))/2),373,"MUNTENIA");
	outtextxy(113+((221-textwidth("OLTENIA"))/2),412,"OLTENIA");
	outtextxy(113+((221-textwidth("TRANSILVANIA"))/2),451,"TRANSILVANIA");
	
	while( getmouseclick )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
			readimagefile("bg/bgaplicatie1.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			setcolor(WHITE);
			settextstyle(8,0,4);
			setbkcolor(RGB(129,130,195));
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(getmaxx()/2,70,"JUDETELE DINTR-O ANUMITA REGIUNE");
			setbkcolor(RGB(61,42,46));
			settextstyle(8,0,2);
			settextjustify(0,1);
			outtextxy(113+((221-textwidth("BANAT"))/2),139,"BANAT");
			outtextxy(113+((221-textwidth("BUCOVINA"))/2),178,"BUCOVINA");
			outtextxy(113+((221-textwidth("CRISANA"))/2),217,"CRISANA");
			outtextxy(113+((221-textwidth("DOBROGEA"))/2),256,"DOBROGEA");
			outtextxy(113+((221-textwidth("MARAMURES"))/2),295,"MARAMURES");
			outtextxy(113+((221-textwidth("MODOLVA"))/2),334,"MOLDOVA");
			outtextxy(113+((221-textwidth("MUNTENIA"))/2),373,"MUNTENIA");
			outtextxy(113+((221-textwidth("OLTENIA"))/2),412,"OLTENIA");
			outtextxy(113+((221-textwidth("TRANSILVANIA"))/2),451,"TRANSILVANIA");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>767 && mx<800 && my>0 && my<23) //X
			{
				
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			
			else if(mx>0 && mx<33 && my>0 && my<23) //BACK
			{
				
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						aplicatii();
					}
			}
			
			else if(mx>113 && mx<334 && my>119 &&my<148 ) //1-banat
			{
				readimagefile("bg/rectangle5.jpg",113,119,334,148);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("BANAT"))/2),139,"BANAT");
				if(x>113 && x<334 && y>119 && y<148)
				{	
					kx=1;
				}
			}
			
			else if(mx>113 && mx<334 && my>158 &&my<187 ) //2 BUCOVINA
			{
				readimagefile("bg/rectangle5.jpg",113,158,334,187);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("BUCOVINA"))/2),178,"BUCOVINA");
				if(x>113 && x<334 && y>158 && y<187)
				{				
					kx=2;
				}
			}
			
			else if(mx>113 && mx<334 && my>197 &&my<226 ) //3- crisana
			{
				readimagefile("bg/rectangle5.jpg",113,197,334,226);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("CRISANA"))/2),217,"CRISANA");
				if(x>113 && x<334 && y>197 && y<226)
				{				
					kx=3;
				}
			}
			
			else if(mx>113 && mx<334 && my>236 &&my<265) //4- dobrogea
			{
				readimagefile("bg/rectangle5.jpg",113,236,334,265);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("DOBROGEA"))/2),256,"DOBROGEA");
				if(x>113 && x<334 && y>236 && y<265)
				{		
					kx=4;			
				}
			}
			
			else if(mx>113 && mx<334 && my>275 &&my<304 ) //5-maramures
			{
				readimagefile("bg/rectangle5.jpg",113,275,334,304);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("MARAMURES"))/2),295,"MARAMURES");
				if(x>113 && x<334 && y>275 && y<304)
				{		
					kx=5;				
				}
			}
			
			else if(mx>113 && mx<334 && my>314 &&my<343 ) //6-moldova
			{
				readimagefile("bg/rectangle5.jpg",113,314,334,343);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("MODOLVA"))/2),334,"MOLDOVA");
				if(x>113 && x<334 && y>314 && y<343)
				{		
					kx=6;			
				}
			}
			
			else if(mx>113 && mx<334 && my>353 &&my<382 ) //7-muntenia
			{
				readimagefile("bg/rectangle5.jpg",113,353,334,382);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("MUNTENIA"))/2),373,"MUNTENIA");
				if(x>113 && x<334 && y>353 && y<382)
				{		
					kx=7;				
				}
			}
			
			else if(mx>113 && mx<334 && my>392 &&my<421 ) //8-oltenia
			{
				readimagefile("bg/rectangle5.jpg",113,392,334,421);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("OLTENIA"))/2),412,"OLTENIA");
				if(x>113 && x<334 && y>392 && y<421)
				{		
					kx=8;		
				}
			}
			
			else if(mx>113 && mx<334 && my>431 &&my<460 ) //9-transilvania
			{
				readimagefile("bg/rectangle5.jpg",113,431,334,460);
				setbkcolor(RGB(35,14,19));
				outtextxy(113+((221-textwidth("TRANSILVANIA"))/2),451,"TRANSILVANIA");
				if(x>113 && x<334 && y>431 && y<460)
				{		
					kx=9;			
				}
			}
			
			switch( kx )
			{
				case 1:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Banat";
						readimagefile("bg/sageata1.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				case 2:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Bucovina";
						readimagefile("bg/sageata2.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				case 3:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Crisana";
						readimagefile("bg/sageata3.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}
				case 4:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Dobrogea";
						readimagefile("bg/sageata4.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				case 5:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Maramures";
						readimagefile("bg/sageata5.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				case 6:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Moldova";
						readimagefile("bg/sageata6.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				case 7:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Muntenia";
						readimagefile("bg/sageata7.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}		
				case 8:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Oltenia";
						readimagefile("bg/sageata8.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				case 9:
					{
						setbkcolor(RGB(108,63,70));
						settextstyle(3,0,1);
						char sir[25]="Transilvania";
						readimagefile("bg/sageata9.gif",0,0,800,500);
						
						int ok, i, latime=455, inaltime=271;
						
						for(i=1; i<=k; i++)
						{
							ok=0;
							if(strcmp(sir,j[i].regiune)==0)
							{
								if(latime+textwidth(j[i].judet)<700)
								{
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
									ok=1;
								}
								
								if(latime+ textwidth( j[i].judet ) >=700 && ok==0)
								{
									latime=455;
									inaltime=inaltime+23;
									outtextxy(latime,inaltime,j[i].judet);
									latime=latime+textwidth(j[i].judet)+1;
									outtextxy(latime,inaltime,", ");
									latime=latime+8;
								}
							}
						}
						break;
					}	
				default:
					break;
			}
	}
	getch();
	cleardevice();
}

void aplicatie2()
{
	int kx;
	readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");

	swapbuffers(); /////////////////
	
	readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
			readimagefile("bg/harta/bg_harta.jpg",0,0,800,500);
			readimagefile("bg/x.gif",767,0,800,23);
			readimagefile("bg/back.gif",0,0,33,23);
			settextstyle(8,0,4);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setbkcolor(RGB(146,145,205));
			outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
			getmouseclick( WM_LBUTTONDOWN, x, y );	
			
			if(mx>293 && mx<347 && my>243 && my<284) //1-AB
			{
					
					readimagefile("bg/harta/bg_ab.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					setbkcolor(RGB(146,145,205));
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>293 && x<347 && y>243 && y<293)
					{
						kx = 1;
						aplicatie2_2(kx);
					}
			}
			
			
			
			else if(mx>178 && mx<252 && my>231 && my<274) //2-AR
			{
					
					readimagefile("bg/harta/bg_ar.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>178 && x<252 && y>231 && y<274)
					{
						kx=2;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>372 && mx<411 && my>318 && my<413) //3-AG
			{
					
					readimagefile("bg/harta/bg_ag.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>372 && x<411 && y>243 && y<413)
					{
						kx=3;
						aplicatie2_2(kx);
					}
			}
			
			if(mx>463 && mx<538 && my>221 && my<271) //4-BC
			{
					
					readimagefile("bg/harta/bg_bc.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>463 && x<538 && y>221 && y<271)
					{
						kx=4;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>200 && mx<269 && my>160 && my<227) //5-BH
			{
					
					readimagefile("bg/harta/bg_bh.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>200 && x<269 && y>160 && y<227)
					{
						kx=5;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>343 && mx<402 && my>150 && my<200) //6-BN
			{
					
					readimagefile("bg/harta/bg_bn.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>343 && x<402 && y>150 && y<200)
					{
						kx=6;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>479 && mx<521 && my>96 && my<150) //7-BT
			{
					
					readimagefile("bg/harta/bg_bt.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>479 && x<521 && y>96 && y<150)
					{
						kx=7;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>385 && mx<444 && my>275 && my<317) //8-BV
			{
					
					readimagefile("bg/harta/bg_bv.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>385 && x<444 && y>275 && y<317)
					{
						kx=8;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>537 && mx<585 && my>331 && my<378) //9-BR
			{
					
					readimagefile("bg/harta/bg_br.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>537 && x<585 && y>331 && y<378)
					{
						kx=9;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>485 && mx<531 && my>326 && my<375) //10-BZ
			{
					
					readimagefile("bg/harta/bg_bz.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>485 && x<531 && y>326 && y<375)//////////
					{
						kx=10;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>194 && mx<258 && my>317 && my<378) //11-CS
			{
					
					readimagefile("bg/harta/bg_cs.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>194 && x<258 && y>317 && y<378)//////////
					{
						kx=11;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>485 && mx<570 && my>412 && my<435) //12-CL
			{
					
					readimagefile("bg/harta/bg_cl.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>485 && x<570 && y>412 && y<435)//////////
					{
						kx=12;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>275 && mx<345 && my>195 && my<237) //13-CJ
			{
					
					readimagefile("bg/harta/bg_cj.jpg",0,0,800,500);
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);/////
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>275 && x<345 && y>195 && y<237)//////////
					{
						kx=13;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>582 && mx<623 && my>389 && my<465) //14-CT
			{
					
					readimagefile("bg/harta/bg_ct.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>582 && x<623 && y>321 && y<465)//////////
					{
						kx=14;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>435 && mx<481 && my>269 && my<306) //15-CV
			{
					
					readimagefile("bg/harta/bg_cv.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>435 && x<481 && y>269 && y<306)//////////
					{
						kx=15;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>413 && mx<450 && my>355 && my<404) //16-DB
			{
					
					readimagefile("bg/harta/bg_db.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>413 && x<450 && y>355 && y<404)//////////
					{
						kx=16;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>300 && mx<346 && my>405 && my<466) //17-DJ
			{
					
					readimagefile("bg/harta/bg_dj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>300 && x<346 && y>405 && y<466)//////////
					{
						kx=17;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>545 && mx<582 && my>271 && my<327) //18-GL
			{
					
					readimagefile("bg/harta/bg_gl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>545 && x<582 && y>271 && y<327)//////////
					{
						kx=18;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>440 && mx<484 && my>427 && my<465) //19-GR
			{
					
					readimagefile("bg/harta/bg_gr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>440 && x<484 && y>427 && y<465)//////////
					{
						kx=19;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>282 && mx<327 && my>342 && my<383) //20-GJ
			{
					
					readimagefile("bg/harta/bg_gj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>282 && x<327 && y>342 && y<383)//////////
					{
						kx=20;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>413 && mx<450 && my>193 && my<266) //21-HR
			{
					
					readimagefile("bg/harta/bg_hr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>413 && x<450 && y>193 && y<266)//////////
					{
						kx=21;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>257 && mx<302 && my>260 && my<337) //22-HD
			{
					
					readimagefile("bg/harta/bg_hd.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>257 && x<302 && y>260 && y<337)//////////
					{
						kx=22;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>484 && mx<583 && my>384 && my<410) //23-IL
			{
					
					readimagefile("bg/harta/bg_il.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>484 && x<583 && y>384 && y<410)//////////
					{
						kx=23;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>502 && mx<576 && my>154 && my<203) //24-IS
			{
					
					readimagefile("bg/harta/bg_is.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>502 && x<576 && y>154 && y<375)//////////
					{
						kx=24;
						aplicatie2_2(kx);
					}
			}
		
			else if(mx>456 && mx<482 && my>386 && my<422) //25-IF/ILFOV
			{
					
					readimagefile("bg/harta/bg_if.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>456 && x<482 && y>386 && y<422)//////////
					{
						kx=25;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>308 && mx<400 && my>117 && my<149) //26-MM
			{
					
					readimagefile("bg/harta/bg_mm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>308 && x<400 && y>117 && y<149)//////////
					{
						kx=26;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>249 && mx<283 && my>385 && my<441) //27-MH
			{
					
					readimagefile("bg/harta/bg_mh.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>249 && x<283 && y>385 && y<441)//////////
					{
						kx=27;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>348 && mx<407 && my>207 && my<257) //28-MS
			{
					
					readimagefile("bg/harta/bg_ms.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>348 && x<407 && y>207 && y<257)//////////
					{
						kx=28;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>447 && mx<511 && my>182 && my<218) //29-NT
			{
					
					readimagefile("bg/harta/bg_nt.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>447 && x<511 && y>182 && y<218)//////////
					{
						kx=29;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>350 && mx<385 && my>392 && my<471) //30-OT
			{
					
					readimagefile("bg/harta/bg_ot.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>350 && x<385 && y>392 && y<471)//////////
					{
						kx=30;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>449 && mx<484 && my>337 && my<382) //31-PH
			{
					
					readimagefile("bg/harta/bg_ph.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>449 && x<484 && y>337 && y<382)//////////
					{
						kx=31;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>239 && mx<306 && my>116 && my<154) //32-SM
			{
					
					readimagefile("bg/harta/bg_sm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>239 && x<306 && y>116 && y<154)//////////
					{
						kx=32;
						aplicatie2_2(kx);
					}
			}
			else if(mx>270 && mx<318 && my>165 && my<197) //33-SJ
			{
					
					readimagefile("bg/harta/bg_sj.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>270 && x<318 && y>165 && y<197)//////////
					{
						kx=33;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>333 && mx<381 && my>271 && my<315) //34-SB
			{
					
					readimagefile("bg/harta/bg_sb.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>333 && x<381 && y>271 && y<315)//////////
					{
						kx=34;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>406 && mx<472 && my>115 && my<172) //35-SV
			{
					
					readimagefile("bg/harta/bg_sv.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>406 && x<472 && y>115 && y<172)//////////
					{
						kx=35;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>388 && mx<437 && my>421 && my<471) //36-TR
			{
					
					readimagefile("bg/harta/bg_tr.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>388 && x<437 && y>421 && y<471)//////////
					{
						kx=36;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>150 && mx<240 && my>278 && my<316) //37-TM
			{
					
					readimagefile("bg/harta/bg_tm.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>150 && x<240 && y>278 && y<316)//////////
					{
						kx=37;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>590 && mx<680 && my>331 && my<384) //38-TL
			{
					
					readimagefile("bg/harta/bg_tl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>590 && x<680 && y>331 && y<384)//////////
					{
						kx=38;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>542 && mx<586 && my>205 && my<265) //39-VS
			{
					
					readimagefile("bg/harta/bg_vs.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>542 && x<586 && y>205 && y<265)//////////
					{
						kx=39;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>329 && mx<367 && my>321 && my<381) //40-VL
			{
					
					readimagefile("bg/harta/bg_vl.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>329 && x<367 && y>321 && y<381)//////////
					{
						kx=40;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>485 && mx<535 && my>274 && my<320) //41-VN
			{
					
					readimagefile("bg/harta/bg_vn.jpg",0,0,800,500);/////
					readimagefile("bg/x.gif",767,0,800,23);
					readimagefile("bg/back.gif",0,0,33,23);
					setbkcolor(RGB(146,145,205));
					settextstyle(8,0,4);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
					if(x>485 && x<535 && y>274 && y<320)//////////
					{
						kx=41;
						aplicatie2_2(kx);
					}
			}
			
			else if(mx>767 && mx<800 && my>0 && my<23) 
			{
					
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						aplicatii();
					}
			}
	}
	getch();
	cleardevice();
}

void aplicatie2_2(int kx)
{
	fstream f5("vecini.txt", ios::out);
	char string[3]="-";
	int latime=614;
	int inaltime=200;
	int ok=1;
	char numepoza[30];
	char numepozaaux[30]="bg/harta/bg_";
	strcpy(numepoza,numepozaaux);
	strcat(numepoza,strlwr(j[kx].indicatorauto));
	strcat(numepoza,".jpg");
	f5<<"Vecinii judetului "<<j[kx].judet<<" sunt: "<<endl;
	int u;
	for(u=1; u<=7; u++)
	{
		if(strcmp(j[kx].vecin[u],string)>0)
			f5<<"- "<<j[kx].vecin[u]<<endl;
	}
	
	readimagefile(numepoza,0,0,800,500);/////
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
	
	readimagefile("bg/vecini.jpg",600,169,787,305);
	setbkcolor(RGB(108,62,72));
	settextjustify(0,1);
	settextstyle(3,0,1);
	outtextxy(614,200,"Vecinii judetului ");
	latime=latime+textwidth("Vecinii judetului ")+textwidth(j[kx].judet);
	if(latime>777)
	{
		latime=614;
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,j[kx].judet);
		latime=latime+textwidth(j[kx].judet);
		outtextxy(latime,inaltime," au fost");
		latime=614;
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,"salvati in fisierul");
		latime=614;
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,"''vecini.txt''.");
		ok=0;
	}
	if(ok==1)
	{
		outtextxy(latime-textwidth(j[kx].judet),inaltime,j[kx].judet);
		inaltime=inaltime+25;
		latime=614;
		outtextxy(latime,inaltime,"au fost salvati in fisierul");
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,"''vecini.txt''");
	}
	
	swapbuffers();////////////
	
	latime=614;
	inaltime=200;
	readimagefile(numepoza,0,0,800,500);/////
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);
	setcolor(WHITE);
	settextstyle(8,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(146,145,205));
	outtextxy(getmaxx()/2,55,"VECINII UNUI ANUMIT JUDET");
	
	readimagefile("bg/vecini.jpg",600,169,787,305);
	setbkcolor(RGB(108,62,72));
	settextjustify(0,1);
	settextstyle(3,0,1);
	outtextxy(614,200,"Vecinii judetului ");
	latime=latime+textwidth("Vecinii judetului ")+textwidth(j[kx].judet);
	if(latime>777)
	{
		latime=614;
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,j[kx].judet);
		latime=latime+textwidth(j[kx].judet);
		outtextxy(latime,inaltime," au fost");
		latime=614;
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,"salvati in fisierul");
		latime=614;
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,"''vecini.txt''.");
		ok=0;
	}
	if(ok==1)
	{
		outtextxy(latime-textwidth(j[kx].judet),inaltime,j[kx].judet);
		inaltime=inaltime+25;
		latime=614;
		outtextxy(latime,inaltime,"au fost salvati in fisierul");
		inaltime=inaltime+25;
		outtextxy(latime,inaltime,"''vecini.txt''");
	}
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						aplicatii();
					}
			}
	}
	
	getche();
	cleardevice();
}


void quiz()
{
	int punctaj=0;
	time_t timer=clock(); 
	bool clicked = false; 
	bool corect = false;
	
	while ( clock() - timer < 3000 )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
		readimagefile("bg/quiz.jpg",0,0,800,500);
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		readimagefile("bg/quiz_q.jpg",80,75,721,146);
		readimagefile("bg/rectangle10.jpg",410,181,721,408);
		readimagefile("bg/quiz_i1.jpg",489,195,642,395);
		settextstyle(8,0,2);
		setbkcolor(RGB(35,15,19));
		outtextxy(getmaxx()/2,115,"In ce judet s-a nascut poetul Mihai Eminescu?");
		
		settextstyle(8,0,2);
		setbkcolor(RGB(61,39,43));
		readimagefile("bg/quiz_a.jpg",80,181,390,222);
		outtextxy(235,205,"Arges");
		readimagefile("bg/quiz_a.jpg",80,243,390,284);
		outtextxy(235,267,"Botosani");
		readimagefile("bg/quiz_a.jpg",80,305,390,346);
		outtextxy(235,329,"Covasna");
		readimagefile("bg/quiz_a.jpg",80,367,390,408);
		outtextxy(235,391,"Prahova");
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>80 && mx<353 && my>181 && my<222)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,181,390,222);
				outtextxy(235,205,"Arges");
				if(x>80 && x<353 && y>181 && y<222)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>243 && my<284)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,243,390,284);
				outtextxy(235,267,"Botosani");
				if(x>80 && x<353 && y>243 && y<284)
				{
					corect = true;
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>305 && my<346)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,305,390,346);
				outtextxy(235,329,"Covasna");
				if(x>80 && x<353 && y>305 && y<346)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>367 && my<408)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,367,390,408);
				outtextxy(235,391,"Prahova");
				if(x>80 && x<353 && y>367 && y<408)
				{
					clicked = true; 
				}
			}
			if( !clicked )
				timer = clock();
			if ( clicked )
			{
				if ( corect )
				{
					readimagefile("bg/quiz_check.gif",250,100,550,400);
				}
				else 
				{
					readimagefile("bg/quiz_x.gif",250,100,550,400);
					
				}
			}
	}
	if(corect)punctaj++;
	
	////////////////////////////////////2
	
	timer=clock(); 
	clicked = false; /////////////////////////
	corect = false; 
	while ( clock() - timer < 3000 )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
		readimagefile("bg/quiz.jpg",0,0,800,500);
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		readimagefile("bg/quiz_q.jpg",80,75,721,146);
		readimagefile("bg/rectangle10.jpg",410,181,721,408);
		readimagefile("bg/quiz_i2.jpg",489,195,642,395);
		settextstyle(8,0,2);
		setbkcolor(RGB(35,15,19));
		outtextxy(getmaxx()/2,115,"Cum o chema pe sotia lui Lucian Blaga?");
		
		settextstyle(8,0,2);
		setbkcolor(RGB(61,39,43));
		readimagefile("bg/quiz_a.jpg",80,181,390,222);
		outtextxy(235,205,"Cornelia Brediceanu");
		readimagefile("bg/quiz_a.jpg",80,243,390,284);
		outtextxy(235,267,"Elena Goldis");
		readimagefile("bg/quiz_a.jpg",80,305,390,346);
		outtextxy(235,329,"Gerda Barbu");
		readimagefile("bg/quiz_a.jpg",80,367,390,408);
		outtextxy(235,391,"Clara Klemnitz");
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>80 && mx<353 && my>181 && my<222)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,181,390,222);
				outtextxy(235,205,"Cornelia Brediceanu");
				if(x>80 && x<353 && y>181 && y<222)
				{
					corect = true;
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>243 && my<284)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,243,390,284);
				outtextxy(235,267,"Elena Goldis");
				if(x>80 && x<353 && y>243 && y<284)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>305 && my<346)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,305,390,346);
				outtextxy(235,329,"Gerda Barbu");
				if(x>80 && x<353 && y>305 && y<346)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>367 && my<408)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,367,390,408);
				outtextxy(235,391,"Clara Klemnitz");
				if(x>80 && x<353 && y>367 && y<408)
				{
					clicked = true; 
				}
			}
			if( !clicked )
				timer = clock();
			if ( clicked )
			{
				if ( corect )
				{
					readimagefile("bg/quiz_check.gif",250,100,550,400);
				}
				else 
				{
					readimagefile("bg/quiz_x.gif",250,100,550,400);
					
				}
			}
	}
	if(corect)punctaj++;
	
	timer=clock(); 
	clicked = false; /////////////////////////
	corect = false; 
	while ( clock() - timer < 3000 )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
		readimagefile("bg/quiz.jpg",0,0,800,500);
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		readimagefile("bg/quiz_q.jpg",80,75,721,146);
		readimagefile("bg/rectangle10.jpg",410,181,721,408);
		readimagefile("bg/quiz_i3.jpg",429,195,701,395);
		settextstyle(8,0,2);
		setbkcolor(RGB(35,15,19));
		outtextxy(getmaxx()/2,115,"Din ce regiune a Romaniei face parte judetul Alba?");
		
		settextstyle(8,0,2);
		setbkcolor(RGB(61,39,43));
		readimagefile("bg/quiz_a.jpg",80,181,390,222);
		outtextxy(235,205,"Crisana");
		readimagefile("bg/quiz_a.jpg",80,243,390,284);
		outtextxy(235,267,"Banat");
		readimagefile("bg/quiz_a.jpg",80,305,390,346);
		outtextxy(235,329,"Moldova");
		readimagefile("bg/quiz_a.jpg",80,367,390,408);
		outtextxy(235,391,"Transilvania");
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>80 && mx<353 && my>181 && my<222)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,181,390,222);
				outtextxy(235,205,"Crisana");
				if(x>80 && x<353 && y>181 && y<222)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>243 && my<284)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,243,390,284);
				outtextxy(235,267,"Banat");
				if(x>80 && x<353 && y>243 && y<284)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>305 && my<346)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,305,390,346);
				outtextxy(235,329,"Moldova");
				if(x>80 && x<353 && y>305 && y<346)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>367 && my<408)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,367,390,408);
				outtextxy(235,391,"Transilvania");
				if(x>80 && x<353 && y>367 && y<408)
				{
					corect = true;
					clicked = true; 
				}
			}
			if( !clicked )
				timer = clock();
			if ( clicked )
			{
				if ( corect )
				{
					readimagefile("bg/quiz_check.gif",250,100,550,400);
				}
				else 
				{
					readimagefile("bg/quiz_x.gif",250,100,550,400);
					
				}
			}
	}
	if(corect)punctaj++;
	
	timer=clock(); 
	clicked = false; /////////////////////////
	corect = false; 
	while ( clock() - timer < 3000 )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
		readimagefile("bg/quiz.jpg",0,0,800,500);
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		readimagefile("bg/quiz_q.jpg",80,75,721,146);
		readimagefile("bg/rectangle10.jpg",410,181,721,408);
		readimagefile("bg/quiz_i4.jpg",429,195,701,395);
		settextstyle(8,0,2);
		setbkcolor(RGB(35,15,19));
		outtextxy(getmaxx()/2,115,"Ce obiectiv turistic se afla in judetul Arad?");
		
		settextstyle(8,0,2);
		setbkcolor(RGB(61,39,43));
		readimagefile("bg/quiz_a.jpg",80,181,390,222);
		outtextxy(235,205,"Castelul Rosu");
		readimagefile("bg/quiz_a.jpg",80,243,390,284);
		outtextxy(235,267,"Cetatea Poenari");
		readimagefile("bg/quiz_a.jpg",80,305,390,346);
		outtextxy(235,329,"Cetatea Soimos");
		readimagefile("bg/quiz_a.jpg",80,367,390,408);
		outtextxy(235,391,"Castelul Corvinilor");
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>80 && mx<353 && my>181 && my<222)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,181,390,222);
				outtextxy(235,205,"Castelul Rosu");
				if(x>80 && x<353 && y>181 && y<222)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>243 && my<284)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,243,390,284);
				outtextxy(235,267,"Cetatea Poenari");
				if(x>80 && x<353 && y>243 && y<284)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>305 && my<346)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,305,390,346);
				outtextxy(235,329,"Cetatea Soimos");
				if(x>80 && x<353 && y>305 && y<346)
				{
					corect = true;
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>367 && my<408)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,367,390,408);
				outtextxy(235,391,"Castelul Corvinilor");
				if(x>80 && x<353 && y>367 && y<408)
				{
					clicked = true; 
				}
			}
			if( !clicked )
				timer = clock();
			if ( clicked )
			{
				if ( corect )
				{
					readimagefile("bg/quiz_check.gif",250,100,550,400);
				}
				else 
				{
					readimagefile("bg/quiz_x.gif",250,100,550,400);
				}
			}
	}
	if(corect)punctaj++;
	
	timer=clock(); 
	clicked = false; /////////////////////////
	corect = false; 
	while ( clock() - timer < 3000 )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
		readimagefile("bg/quiz.jpg",0,0,800,500);
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		readimagefile("bg/quiz_q.jpg",80,75,721,146);
		readimagefile("bg/rectangle10.jpg",410,181,721,408);
		readimagefile("bg/quiz_i5.jpg",429,195,701,395);
		settextstyle(8,0,2);
		setbkcolor(RGB(35,15,19));
		outtextxy(getmaxx()/2,115,"Ce populatie are judetul Ilfov?");
		
		settextstyle(8,0,2);
		setbkcolor(RGB(61,39,43));
		readimagefile("bg/quiz_a.jpg",80,181,390,222);
		outtextxy(235,205,"69390");
		readimagefile("bg/quiz_a.jpg",80,243,390,284);
		outtextxy(235,267,"52677");
		readimagefile("bg/quiz_a.jpg",80,305,390,346);
		outtextxy(235,329,"295458");
		readimagefile("bg/quiz_a.jpg",80,367,390,408);
		outtextxy(235,391,"364241");
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
			
			else if(mx>80 && mx<353 && my>181 && my<222)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,181,390,222);
				outtextxy(235,205,"69390");
				if(x>80 && x<353 && y>181 && y<222)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>243 && my<284)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,243,390,284);
				outtextxy(235,267,"52677");
				if(x>80 && x<353 && y>243 && y<284)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>305 && my<346)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,305,390,346);
				outtextxy(235,329,"295458");
				if(x>80 && x<353 && y>305 && y<346)
				{
					clicked = true; 
				}
			}
			
			else if(mx>80 && mx<353 && my>367 && my<408)
			{
				settextstyle(8,0,2);
				setbkcolor(RGB(35,15,19));
				readimagefile("bg/quiz_a_apasat.jpg",80,367,390,408);
				outtextxy(235,391,"364241");
				if(x>80 && x<353 && y>367 && y<408)
				{
					corect = true;
					clicked = true; 
				}
			}
			if( !clicked )
				timer = clock();
			if ( clicked )
			{
				if ( corect )
				{
					readimagefile("bg/quiz_check.gif",250,100,550,400);
				}
				else 
				{
					readimagefile("bg/quiz_x.gif",250,100,550,400);
				}
			}
	}
	if(corect)punctaj++;
	
	while ( getmouseclick )
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		
		readimagefile("bg/quiz.jpg",0,0,800,500);
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		readimagefile("bg/rectangle10.jpg",190,200,610,262);
		settextstyle(8,0,2);
		setbkcolor(RGB(61,39,43));
		outtextxy(getmaxx()/2,223,"Rezultatele quiz-ului au fost");
		outtextxy(getmaxx()/2,248,"salvate in fisierul rezultate.txt!");
		
		fstream f1("rezultate.txt",ios::out);
		f1<<"Ati obtinut un punctaj de "<<punctaj<<" din totalul de 5 posibile. Felicitari!";
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
	}
	
	cleardevice();
}

void structura()
{
	readimagefile("bg/structura.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(119,131,194));
	outtextxy(getmaxx()/2,70,"STRUCTURA LUCRARII");	
	
	swapbuffers();
	
	readimagefile("bg/structura.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(119,131,194));
	outtextxy(getmaxx()/2,70,"STRUCTURA LUCRARII");
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
	}
	getch();
	cleardevice();
}

void bibliografie()
{
	readimagefile("bg/bibliografie.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(78,75,108));
	outtextxy(getmaxx()/2,70,"BIBLIOGRAFIE");	
	
	swapbuffers();
	
	readimagefile("bg/bibliografie.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(78,75,108));
	outtextxy(getmaxx()/2,70,"BIBLIOGRAFIE");
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
	}
	getch();
	cleardevice();
}

void autor()
{
	readimagefile("bg/autor.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(141,141,201));
	outtextxy(getmaxx()/2,70,"DATE DESPRE AUTOR");
	
	swapbuffers();
	
	readimagefile("bg/autor.jpg",0,0,800,500);
	readimagefile("bg/x.gif",767,0,800,23);
	readimagefile("bg/back.gif",0,0,33,23);setcolor(WHITE);
	settextstyle(8,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setbkcolor(RGB(141,141,201));
	outtextxy(getmaxx()/2,70,"DATE DESPRE AUTOR");
	
	while(getmouseclick)
	{
		swapbuffers();
		int mx=mousex();
		int my=mousey();
		int x,y;
		readimagefile("bg/x.gif",767,0,800,23);
		readimagefile("bg/back.gif",0,0,33,23);
		
		
		getmouseclick( WM_LBUTTONDOWN, x, y );	
			if(mx>767 && mx<800 && my>0 && my<23) 
			{
					readimagefile("bg/x_apasat.gif",767,0,800,23);
					if(x>767 && x<800 && y>0 && y<23)
					{
						exit(0);
					}
			}
			else if(mx>0 && mx<33 && my>0 && my<23) 
			{
					readimagefile("bg/back_apasat.gif",0,0,33,23);
					if(x>0 && x<33 && y>0 && y<23)
					{
						meniu();
					}
			}
	}
	getch();
	cleardevice();
}

void citire()
{
	fstream f1("date.txt", ios::in);
	int chars;
	int i;
	char aux[50];
	do{
        k++;
        f1>>j[k].judet;
		
		chars = strcspn( j[k].judet, "_" );
		
		while( chars < strlen( j[k].judet ) )
		{
			strcpy( aux, j[k].judet + chars + 1 );
			strcpy( j[k].judet + chars, " " );
			strcat( j[k].judet, aux );
			chars = strcspn( j[k].judet, "_" );
		}
		
        f1>>j[k].municipiu;
		chars = strcspn( j[k].municipiu, "_" );
		
		while( chars < strlen( j[k].municipiu ) )
		{
			strcpy( aux, j[k].municipiu + chars + 1 );
			strcpy( j[k].municipiu + chars, " " );
			strcat( j[k].municipiu, aux );
			chars = strcspn( j[k].municipiu, "_" );
		}
        f1>>j[k].indicatorauto;
        f1>>j[k].primar;
		chars = strcspn( j[k].primar, "_" );
		
		while( chars < strlen( j[k].primar ) )
		{
			strcpy( aux, j[k].primar + chars + 1 );
			strcpy( j[k].primar + chars, " " );
			strcat( j[k].primar, aux );
			chars = strcspn( j[k].primar, "_" );
		}
        f1>>j[k].regiune;
        f1>>j[k].locuitori;
        f1>>j[k].prefix;
        f1>>j[k].cod;
        f1>>j[k].suprafata;
        f1>>j[k].densitate;
        f1>>j[k].pctcardinal;
        f1>>j[k].municipii;
        f1>>j[k].orase;
        f1>>j[k].comune;
        f1>>j[k].obiectiv;
		chars = strcspn( j[k].obiectiv, "_" );
		
		while( chars < strlen( j[k].obiectiv ) )
		{
			strcpy( aux, j[k].obiectiv + chars + 1 );
			strcpy( j[k].obiectiv + chars, " " );
			strcat( j[k].obiectiv, aux );
			chars = strcspn( j[k].obiectiv, "_" );
		}
        f1>>j[k].pozaobiectiv;
        f1>>j[k].pozajudet;
        f1>>j[k].harta;
        f1>>j[k].stema;
		
		for(i=1;i<=7;i++)
			f1>>j[k].vecin[i];
		
	}while(!f1.eof());
	
	////////////////////////
	
	fstream f2("date2.txt", ios::in);

	do{
        d_k++;
		
        f2>>d[d_k].nume;
		chars = strcspn( d[d_k].nume, "_" );
		while( chars < strlen( d[d_k].nume ) )
		{
			strcpy( aux, d[d_k].nume + chars + 1 );
			strcpy( d[d_k].nume + chars, " " );
			strcat( d[d_k].nume, aux );
			chars = strcspn( d[d_k].nume, "_" );
		}
		
		f2>>d[d_k].nascut;
		chars = strcspn( d[d_k].nascut, "_" );
		while( chars < strlen( d[d_k].nascut ) )
		{
			strcpy( aux, d[d_k].nascut + chars + 1 );
			strcpy( d[d_k].nascut + chars, " " );
			strcat( d[d_k].nascut, aux );
			chars = strcspn( d[d_k].nascut, "_" );
		}
		
		f2>>d[d_k].decedat;
		chars = strcspn( d[d_k].decedat, "_" );
		while( chars < strlen( d[d_k].decedat ) )
		{
			strcpy( aux, d[d_k].decedat + chars + 1 );
			strcpy( d[d_k].decedat + chars, " " );
			strcat( d[d_k].decedat, aux );
			chars = strcspn( d[d_k].decedat, "_" );
		}
		
		f2>>d[d_k].varsta;
		chars = strcspn( d[d_k].varsta, "_" );
		while( chars < strlen( d[d_k].varsta ) )
		{
			strcpy( aux, d[d_k].varsta + chars + 1 );
			strcpy( d[d_k].varsta + chars, " " );
			strcat( d[d_k].varsta, aux );
			chars = strcspn( d[d_k].varsta, "_" );
		}
		
		f2>>d[d_k].casatorit;
		chars = strcspn( d[d_k].casatorit, "_" );
		while( chars < strlen( d[d_k].casatorit ) )
		{
			strcpy( aux, d[d_k].casatorit + chars + 1 );
			strcpy( d[d_k].casatorit + chars, " " );
			strcat( d[d_k].casatorit, aux );
			chars = strcspn( d[d_k].casatorit, "_" );
		}
		
		f2>>d[d_k].cetatenie;
		
		for(i=1;i<=8;i++)
		{
			f2>>d[d_k].ocupatie[i];
			chars = strcspn( d[d_k].ocupatie[i], "_" );
			while( chars < strlen( d[d_k].ocupatie[i] ) )
			{
				strcpy( aux, d[d_k].ocupatie[i] + chars + 1 );
				strcpy( d[d_k].ocupatie[i] + chars, " " );
				strcat( d[d_k].ocupatie[i], aux );
				chars = strcspn( d[d_k].ocupatie[i], "_" );
			}
		}
		
		f2>>d[d_k].numepoza;
		
	}while(!f2.eof());
	
	f2.close();	

}