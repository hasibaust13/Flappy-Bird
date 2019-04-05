/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

void iDraw()
{
	
	iClear();

	iSetColor(19,33,231);
	iFilledRectangle(0,0,800,600);
	

	{
		//BORDER
	iSetColor(0,0,0);
	iFilledRectangle(370,470,180,30);
	iFilledRectangle(310,440,60,30);
	iFilledRectangle(280,410,30,30);
	iFilledRectangle(220,380,120,30);
	iFilledRectangle(190,290,30,90);
	iFilledRectangle(220,260,30,30);
	iFilledRectangle(250,200,30,60);
	iFilledRectangle(280,230,60,30);
	iFilledRectangle(340,260,30,30);
	iFilledRectangle(370,290,30,60);
	iFilledRectangle(340,350,30,30);
	iFilledRectangle(280,170,60,30);
	iFilledRectangle(340,140,150,30);
	iFilledRectangle(490,170,150,30);
	iFilledRectangle(460,200,30,30);
	iFilledRectangle(430,230,30,30);
	iFilledRectangle(490,230,180,30);
	iFilledRectangle(640,200,30,30);
	iFilledRectangle(670,260,30,30);
	iFilledRectangle(460,260,30,30);
	iFilledRectangle(490,290,180,30);
	iFilledRectangle(460,320,30,30);
	iFilledRectangle(430,350,30,90);
	iFilledRectangle(460,440,30,30);
	iFilledRectangle(550,440,30,30);
	iFilledRectangle(580,410,30,30);
	iFilledRectangle(550,350,30,60);
	iFilledRectangle(610,320,30,90);
	}

	{
	
		//INNERCOLOR
		iSetColor(255,243,0);
		iFilledRectangle(400,260,30,180);
		iFilledRectangle(400,290,90,30);
		iFilledRectangle(430,260,30,90);
		iFilledRectangle(370,350,30,90);
		iFilledRectangle(340,380,30,30);
		iFilledRectangle(250,260,90,30);
		iFilledRectangle(220,290,30,30);
		iFilledRectangle(340,290,30,30);

		iSetColor(255,141,1);
		iFilledRectangle(280,200,180,30);
		iFilledRectangle(340,170,150,30);
		iFilledRectangle(340,230,90,30);
		iFilledRectangle(370,260,30,30);
		
		iSetColor(255,0,0);
		iFilledRectangle(490,260,180,30);
		iFilledRectangle(490,200,150,30);
		iFilledRectangle(460,230,30,30);

		iSetColor(232,232,230);
		iFilledRectangle(460,350,30,60);
		iFilledRectangle(490,320,30,30);

		iSetColor(255,255,255);
		iFilledRectangle(370,440,90,30);
		iFilledRectangle(310,410,60,30);
		iFilledRectangle(220,320,120,60);
		iFilledRectangle(340,320,30,30);
		iFilledRectangle(250,290,90,30);
		iFilledRectangle(490,350,60,120);
		iFilledRectangle(520,320,90,30);
		iFilledRectangle(580,320,30,90);
		iFilledRectangle(460,410,120,30);


	}


}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
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
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 
	iInitialize(1200, 600, "demooo");
	return 0;
}	