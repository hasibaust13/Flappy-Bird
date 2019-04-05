# include "iGraphics.h"
# include<iostream>
#include<sstream>
#include<string>

using namespace std;

string NumberToString( int number);

int flag = 0;
int pi_x, pi_y;


void count_inc();
void rotate();
void move();

void Pillar();

int k=250,a=1;
int c_x =247, dx2,d_x=0,swap;
void bounce(int x);
bool click = true, shift = false;

FILE *hs;
int highscore = 0;
char high_score[50] ="0";

int bounce_ret, count_ret, move_ret;
bool mainflag = true;
void GameOver();

double pillar_x[100];
double bird_y[100];
double pillar_y[100];

/*................Pillar Prototypes............*/
void bottom_pillar(int x);
void top_pillar(int x);
void top_pillar(int x);

/*................Bird Prototype...............*/
void bird();

/*................Selector Prototype.....................*/
void selector();

//double height[] = { 250, 200, 300,500,600 };
int pic_x,pic_y;
int score = 0;
int count = 0, dx,bird_dx;
int a_dx;
char str[100]="0";

bool timer_flag = false;
bool over_flag = false;
void destroy(int x)
{

	if(c_x<=106) {

		iPauseTimer(bounce_ret);
		iPauseTimer(count_ret);
		iPauseTimer(move_ret);

	}

	if(pillar_x[x]+40 > 67 && pillar_x[x]+40 < (67+44)){
		if(c_x <= (pillar_y[x]+215) && (c_x-33) >= (pillar_y[x]+92))
		{
			if((pillar_x[x]+40)>=70 && pillar_x[x]+40 < 77) 
			{
                score+=5;
			}

			
		}
		else {
			GameOver();			
		}


	}

}

void GameOver()
{
	iPauseTimer(bounce_ret);
	iPauseTimer(count_ret);
	iPauseTimer(move_ret);
	over_flag = true;
	
}

void bottom_pillar(int x)
{
	/*..............Bottom Pillar Floor...............*/
	iSetColor(85,23,0);
	iFilledRectangle(0,48,1400,24);
	iSetColor(95,219,12);
	iFilledRectangle(0,50,1400,20);


	/*..............Bottom Pillar Body...............*/
	iSetColor(85,23,0);
	iFilledRectangle(pillar_x[x]-10,pillar_y[x]+68,64,24);

	/*..............Bottom Pillar Shade............*/
	iSetColor(34,223,9);
	iFilledRectangle(pillar_x[x],70,45,pillar_y[x]);
	iFilledRectangle(pillar_x[x]-8,pillar_y[x]+70,60,20);
	iSetColor(114,255,82);
	iFilledRectangle(pillar_x[x],70,6,pillar_y[x]);
	iSetColor(95,219,12);
	iFilledRectangle(pillar_x[x],70,9,pillar_y[x]+20);
	iSetColor(102,255,0);
	iFilledRectangle(pillar_x[x]+10,70,24,pillar_y[x]+20);
	iSetColor(43,207,6);
	iFilledRectangle(pillar_x[x]+36,70,9,pillar_y[x]+20);
	iSetColor(85,23,0);
	iFilledRectangle(pillar_x[x],70,2,pillar_y[x]);
	iFilledRectangle(pillar_x[x]+44,70,2,pillar_y[x]);

}

void top_pillar(int x)
{
	/*.................Top Body ..............*/

	iSetColor(85,23,0);
	iFilledRectangle(pillar_x[x]-10,pillar_y[x]+120+98,64,24);

	/*.................Top Pillar Shade.........*/
	iSetColor(34,223,9);
	iFilledRectangle(pillar_x[x],pillar_y[x]+120+100,45,pillar_y[x]+120+500);
	iFilledRectangle(pillar_x[x]-8,pillar_y[x]+120+100,60,20);
	iSetColor(114,255,82);
	iFilledRectangle(pillar_x[x],pillar_y[x]+120+100,6,pillar_y[x]);
	iSetColor(95,219,12);
	iFilledRectangle(pillar_x[x],pillar_y[x]+120+100,9,pillar_y[x]+500);
	iSetColor(102,255,0);
	iFilledRectangle(pillar_x[x]+10,pillar_y[x]+120+100,24,pillar_y[x]+500);
	iSetColor(43,207,6);
	iFilledRectangle(pillar_x[x]+36,pillar_y[x]+120+100,9,pillar_y[x]+500);
	iSetColor(85,23,0);
	iFilledRectangle(pillar_x[x],pillar_y[x]+120+120,2,pillar_y[x]+500);
	iFilledRectangle(pillar_x[x]+44,pillar_y[x]+120+120,2,pillar_y[x]+500);

}

void dashboard(int x)
{

	/*....................Dashboard...............*/

	iSetColor(22,133,4);
	for(int a=0; a<2000-a_dx;a=a+12){
		double X165_x[4] = {a+a_dx-50,(a+8)+a_dx-50,(a+12)+a_dx-50, (a+4)+a_dx-50};
		double Y165_y[4] = {100-50, 120-50, 120-50, 100-50};
		iFilledPolygon(X165_x, Y165_y, 4);
	}
}

void Pillar(int x)

{
	bottom_pillar(x);
	top_pillar(x);
	dashboard(x);
}

void bird()
{

	{
		//BORDER
	iSetColor(0,0,0);
	iFilledRectangle(37,c_x,18,3);
	iFilledRectangle(31,c_x-3,6,3);
	iFilledRectangle(28,c_x-6,3,3);
	iFilledRectangle(22,c_x-9,12,3);
	iFilledRectangle(19,c_x-18,3,9);
	iFilledRectangle(22,c_x-21,3,3);
	iFilledRectangle(25,c_x-27,3,6);
	iFilledRectangle(28,c_x-24,6,3);
	iFilledRectangle(34,c_x-21,3,3);
	iFilledRectangle(37,c_x-18,3,6);
	iFilledRectangle(34,c_x-12,3,3);
	iFilledRectangle(28,c_x-30,6,3);
	iFilledRectangle(34,c_x-33,15,3);
	iFilledRectangle(49,c_x-30,15,3);
	iFilledRectangle(46,c_x-27,3,3);
	iFilledRectangle(43,c_x-24,3,3);
	iFilledRectangle(49,c_x-24,18,3);
	iFilledRectangle(64,c_x-27,3,3);
	iFilledRectangle(67,c_x-21,3,3);
	iFilledRectangle(46,c_x-21,3,3);
	iFilledRectangle(49,c_x-18,18,3);
	iFilledRectangle(46,c_x-15,3,3);
	iFilledRectangle(43,c_x-12,3,9);
	iFilledRectangle(46,c_x-3,3,3);
	iFilledRectangle(55,c_x-3,3,3);
	iFilledRectangle(58,c_x-6,3,3);
	iFilledRectangle(55,c_x-12,3,6);
	iFilledRectangle(61,c_x-15,3,9);
	}

	{

		//INNERCOLOR
		iSetColor(255,243,0);
		iFilledRectangle(40,c_x-21,3,18);
		iFilledRectangle(40,c_x-18,9,3);
		iFilledRectangle(43,c_x-21,3,9);
		iFilledRectangle(37,c_x-12,3,9);
		iFilledRectangle(34,c_x-9,3,3);
		iFilledRectangle(25,c_x-21,9,3);
		iFilledRectangle(22,c_x-18,3,3);
		iFilledRectangle(34,c_x-18,3,3);

		iSetColor(255,141,1);
		iFilledRectangle(28,c_x-27,18,3);
		iFilledRectangle(34,c_x-30,15,3);
		iFilledRectangle(34,c_x-24,9,3);
		iFilledRectangle(37,c_x-21,3,3);

		iSetColor(255,0,0);
		iFilledRectangle(49,c_x-21,18,3);
		iFilledRectangle(49,c_x-27,15,3);
		iFilledRectangle(46,c_x-24,3,3);

		iSetColor(232,232,230);
		iFilledRectangle(46,c_x-12,3,6);
		iFilledRectangle(49,c_x-15,3,3);

		iSetColor(255,255,255);
		iFilledRectangle(37,c_x-3,9,3);
		iFilledRectangle(31,c_x-6,6,3);
		iFilledRectangle(22,c_x-15,12,6);
		iFilledRectangle(34,c_x-15,3,3);
		iFilledRectangle(25,c_x-18,9,3);
		iFilledRectangle(49,c_x-12,6,12);
		iFilledRectangle(52,c_x-15,9,3);
		iFilledRectangle(58,c_x-15,3,9);
		iFilledRectangle(46,c_x-6,12,3);

	}
}
          /*..........HighScore......................*/

void high_Score()
{
   
   
    hs = fopen("hs.txt","r");

	fscanf(hs,"%d",&highscore);
	strcpy(high_score,NumberToString(highscore).c_str());
	if(score>highscore)
	{
		
		fclose(hs);
		fopen("hs.txt","w");
		fprintf(hs,"%d",score);
	}
	fclose(hs);

   
}




void selector()
{
	if(flag == 0) {
		iShowBMP(pi_x, pi_y, "mainmenu.bmp");
	}
	else if(flag == 1) {
		iShowBMP(0,0, "credit.bmp");
	}

	if(flag == 0) {
		iShowBMP(pi_x, pi_y, "mainmenu.bmp");
	}
	else if(flag == 2) {
		iShowBMP(0,0, "help.bmp");
	}
	if(flag == 0){
		iShowBMP(pi_x, pi_y, "mainmenu.bmp");
	}
	

}


void iDraw()
{

	iClear();
	iShowBMP(pic_x, pic_y+50, "Night.bmp");
	

	iSetColor(255, 255, 255);
	iText( 650, 320, "SCORE: ", GLUT_BITMAP_HELVETICA_18);
	strcpy(str,NumberToString(score).c_str());
	iText( 650, 290, str, GLUT_BITMAP_TIMES_ROMAN_24 );


	iSetColor(199,188,114);

	iFilledRectangle(0,0,800,50);

	bird();

	for(int i=0; i<count; i++)
		Pillar(i);

	selector();

	if(over_flag) 
	{
		iShowBMP(0, 0, "gameover.bmp");
		high_Score();
		iSetColor(0,0,0);
        iText( 350, 291, "HIGH SCORE: ", GLUT_BITMAP_HELVETICA_18);
	    iText(490,291, high_score, GLUT_BITMAP_TIMES_ROMAN_24);


	}
	/*iSetColor(0,201,87);
	iRectangle(50,30,80,40);//play
	iRectangle(150,30,170,40);//highscore
	iRectangle(330,30,100,40);//credit
	iRectangle(450,30,80,40);//help
	iRectangle(570,30,80,40);//exit*/
	//iSetColor(255,255,255);
	//iRectangle(615,355,80,40);

	if(flag!=3){
		iPauseTimer(bounce_ret);
		iPauseTimer(count_ret);
		iPauseTimer(move_ret);
	}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(!mainflag){
			shift = true;
			click = true;
		}
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		/*
		 * 0-> mainmenu + back
		 * 1-> credits
		 * 2-> help
		 * 3-> play
		 * 4->highscore
		 */

		if(mainflag){

			if((mx>720 && mx <800) && (my >450 && my <530)) {
				flag = 0;
			}
			if((mx>380 && mx <480) && (my >40 && my <140)) {
				flag = 1;
			}
			if((mx>510 && mx <580) && (my >40 && my <120)) {
				flag = 2;
			}
			if((mx>60 && mx <150) && (my >40 && my <130)){
				flag = 3;
				iResumeTimer(bounce_ret);
				iResumeTimer(count_ret);
				iResumeTimer(move_ret);
				mainflag = false;
			}
			if((mx>510 && mx<580) && (my >40 && my <130)){
				flag = 4;
			}

		if((mx>510 && mx <650) && (my >30 && my <110))	exit(0);
		}
	}

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(bounce_ret);
		iPauseTimer(count_ret);
		iPauseTimer(move_ret );
	}

	if(key == 'r')
	{
		iResumeTimer(bounce_ret);
		iResumeTimer(count_ret);
		iResumeTimer(move_ret);
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
}

//------------------------------------------------TIMERS--------------------------------------||

/*....This function initializes the game...*/

void count_inc()
{
	pillar_x[count] = 1400;
	//bird_y[count] = 300;
	pillar_y[count] = rand()%100+ 100;
	count++;
}

/*....This function makes the bird bounce....*/

void bounce()
{
	if(shift){
		dx2 = 6;
		if(click){
			c_x +=dx2;
			if(c_x >= d_x+60) {
				click = false;
				c_x-=dx2;
			}
		}
		else {
			c_x -=dx2;
			d_x=c_x;
		}
	}
}

/*.....This function moves the pillar.....*/
void move()
{

	for(int i=0; i<count; i++){
		pillar_x[i] -= dx;
		bird_y[i] -= bird_dx;
		destroy(i);

	}
	if(a_dx >700) a_dx = 0;
	a_dx-=7;
}


int main()
{
	dx = 7;

	bounce_ret = iSetTimer(30, bounce);
	count_ret = iSetTimer(2250, count_inc);
	move_ret = iSetTimer(20, move);

	iInitialize(800, 500, "Flappy Bird");
	return 0;
}


string NumberToString(int number)
{
	stringstream ss;
	ss<<number;
	return ss.str();
}