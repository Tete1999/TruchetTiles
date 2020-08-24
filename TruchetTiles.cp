
/*
Muhammad Talal Khan 
Principles of Computer Graphics 
Professor Terry Hostetler 
*/

#include <windows.h>   
#include <gl/Gl.h>
#include <gl/glu.h>
#include "glut.h"
#include <iostream>
#include <cmath>
using namespace std;

#define SQUARE 1        
#define CIRCLUANGLE 2
#define FANCY 3
#define WEAVE 4
#define COLORFUL 5




float angles [4] = {90.0, 180.0, 270.0, 360.0};
const float PI = 3.1415926535897;
int numRows = 20;
int numCols = 20;
int menuItems = 0;
int trackOption = 0;
bool animation = false;
float dist = 35;


void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 700.0, 0.0, 700.0);// to be explained
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void drawTile1(float xPos, float yPos, float length){
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
			glVertex2d(xPos + length, yPos);
			glVertex2d(xPos, yPos);
			glVertex2d(xPos , yPos + length);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
			glVertex2d(xPos + length, yPos);
			glVertex2d(xPos, yPos + length);
			glVertex2d(xPos + length , yPos + length);
	glEnd();

}

void tileRotator1(float xPos, float yPos, float length){
	glPushMatrix();
	drawTile1(xPos, yPos, length);
	glTranslatef(xPos + length/2, yPos + length/2, 0);
	glRotatef(angles[rand()%4], 0, 0, 1);
	glTranslatef(-(xPos + length/2),-(yPos + length/2), 0);
	drawTile1(xPos, yPos, length);
	glPopMatrix();
}

void drawTile1Pattern(int rows , int cols, float xPos, float yPos, float length){
		int i = 0;
		int cntrl = yPos;
		int temp = xPos;
		while (i != cols){
			tileRotator1(xPos, cntrl, length);
			for (int j = 0; j != rows-1; j ++ ){
				temp += length;
				tileRotator1(temp, cntrl, length);} 
			temp = xPos;
			i += 1;
			cntrl += length;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void drawTile2(float xPos, float yPos, float length){
    glColor3f(0.4,0.7,0.66);
	glBegin(GL_POLYGON);
    glVertex2f(xPos + length, yPos);
	glVertex2f(xPos, yPos);
	glVertex2f(xPos , yPos + length);
	glVertex2f(xPos + length , yPos + length);
	glEnd();
	glColor3f(0.7,1.0,0.5);
	glBegin(GL_POLYGON);
	int lineAmount = 100; 
	float halfPi = 0.5 * PI;
	glBegin(GL_POLYGON);
		for(int i = 0; i <= lineAmount;i++) { 
			glVertex2f(xPos + (length/2*cos(i*halfPi/lineAmount)), yPos + (length/2* sin(i*halfPi/lineAmount)));
		}
	glEnd();
	glColor3f(0.7,0.4,0.5);
	glBegin(GL_POLYGON);
    glVertex2f(xPos + length, yPos+2*length/5);
	glVertex2f(xPos + (length-length/2.5), yPos+length);
	glVertex2f(xPos + length, yPos+length);
	
	glEnd();
}

void tileRotator2(float xPos, float yPos, float length){
	glPushMatrix();
	drawTile2(xPos, yPos, length);
	glTranslatef(xPos + length/2, yPos + length/2, 0);
	glRotatef(angles[rand()%4], 0, 0, 1);
	glTranslatef(-(xPos + length/2),-(yPos + length/2), 0);
	drawTile2(xPos, yPos, length);
	glPopMatrix();
}

void drawTile2Pattern(int rows , int cols, float xPos, float yPos, float length){
		int i = 0;
		int cntrl = yPos;
		int temp = xPos;
		while (i != cols){
			tileRotator2(xPos, cntrl, length);
			for (int j = 0; j != rows-1; j ++ ){
				temp += length;
				tileRotator2(temp, cntrl, length);} 
			temp = xPos;
			i += 1;
			cntrl += length;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void drawTile3(float xPos, float yPos, float length){
	glColor3f(0.2, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(xPos + length, yPos);
		glVertex2f(xPos, yPos);
		glVertex2f(xPos , yPos + length);
		glVertex2f(xPos + length , yPos + length);
	glEnd();
	glColor3f(0.8,0.0,0.4);
	float halfPi = 0.5 * PI;
	glBegin(GL_LINE_STRIP);
	for (float angle = 0.0; angle < 90 * 0.01745329; angle += 0.01745329){
		glVertex2f( xPos + (length/2)*cos(angle), yPos + (length/2)*sin(angle));
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (float angle = 0.0; angle < 90 * 0.01745329; angle += 0.01745329){
		glVertex2f( xPos + length -(length/2)*cos(angle), yPos + length - (length/2)*sin(angle));
	}
	glEnd();
}

void tileRotator3(float xPos, float yPos, float length){
	glPushMatrix();
	drawTile3(xPos, yPos, length);
	glTranslatef(xPos + length/2, yPos + length/2, 0);
	glRotatef(angles[rand()%4], 0, 0, 1);
	glTranslatef(-(xPos + length/2),-(yPos + length/2), 0);
	drawTile3(xPos, yPos, length);
	glPopMatrix();
}

void drawTile3Pattern(int rows , int cols, float xPos, float yPos, float length){
		int i = 0;
		int cntrl = yPos;
		int temp = xPos;
		while (i != cols){
			tileRotator3(xPos, cntrl, length);
			for (int j = 0; j != rows-1; j ++ ){
				temp += length;
				tileRotator3(temp, cntrl, length);} 
			temp = xPos;
			i += 1;
			cntrl += length;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void drawTile4(float xPos, float yPos, float length){
	glColor3f(0.4, 0.1, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(xPos + length, yPos, 0);
		glVertex3f(xPos, yPos, 0);
		glVertex3f(xPos, yPos + length, 0);
		glVertex3f(xPos + length, yPos + length, 0);
	glEnd();
	int factor = length/5;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.8);
		glVertex3f(xPos + factor, yPos, 0);
		glVertex3f(xPos+ factor, yPos+length, 0);
		glVertex3f(xPos + 2*factor, yPos+length, 0);
		glVertex3f(xPos + 2*factor, yPos , 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.9, 1.0);
		glVertex3f(xPos, yPos + factor, 0);
		glVertex3f(xPos+ length, yPos+factor, 0);
		glVertex3f(xPos + length, yPos+2*factor, 0);
		glVertex3f(xPos, yPos + 2*factor , 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4, 1.0, 0.6);
		glVertex3f(xPos + (length - factor), yPos + length, 0);
		glVertex3f(xPos + (length - factor), yPos, 0);
		glVertex3f(xPos + (length - 2*factor), yPos, 0);
		glVertex3f(xPos + (length - 2*factor), yPos + length, 0);
	
	glEnd();

	
	

}

void tileRotator4(float xPos, float yPos, float length){
	glPushMatrix();
	drawTile4(xPos, yPos, length);
	glTranslatef(xPos + length/2, yPos + length/2, 0);
	glRotatef(angles[rand()%4], 0, 0, 1);
	glTranslatef(-(xPos + length/2),-(yPos + length/2), 0);
	drawTile4(xPos, yPos, length);
	glPopMatrix();
}

void drawTile4Pattern(int rows , int cols, float xPos, float yPos, float length){
		int i = 0;
		int cntrl = yPos;
		int temp = xPos;
		while (i != cols){
			tileRotator4(xPos, cntrl, length);
			for (int j = 0; j != rows-1; j ++ ){
				temp += length;
				tileRotator4(temp, cntrl, length);} 
			temp = xPos;
			i += 1;
			cntrl += length;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void drawTile5(float xPos, float yPos, float length){
	float num1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float num2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float num3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	glColor3f(1.0, 1.0, 0.5);
	glBegin(GL_POLYGON);
			glVertex2d(xPos + length, yPos);
			glVertex2d(xPos, yPos);
			glVertex2d(xPos , yPos + length);
			glVertex2d(xPos + length , yPos + length);
	glEnd();
	glColor3f(num1 ,num2, num3);
	glBegin(GL_LINE_STRIP);
			glVertex2d(xPos + length, yPos + length);
			glVertex2d(xPos, yPos);
	glEnd();

}

void tileRotator5(float xPos, float yPos, float length){
	glPushMatrix();
	drawTile5(xPos, yPos, length);
	glTranslatef(xPos + length/2, yPos + length/2, 0);
	glRotatef(angles[rand()%4], 0, 0, 1);
	glTranslatef(-(xPos + length/2),-(yPos + length/2), 0);
	drawTile5(xPos, yPos, length);
	glPopMatrix();
}

void drawTile5Pattern(int rows , int cols, float xPos, float yPos, float length){
		int i = 0;
		int cntrl = yPos;
		int temp = xPos;
		while (i != cols){
			tileRotator5(xPos, cntrl, length);
			for (int j = 0; j != rows-1; j ++ ){
				temp += length;
				tileRotator5(temp, cntrl, length);} 
			temp = xPos;
			i += 1;
			cntrl += length;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void processRightMenuEvents(int option) {
	switch (option) {
		case SQUARE : glClear(GL_COLOR_BUFFER_BIT);
			trackOption = SQUARE;
			drawTile1Pattern(numRows, numCols, 0.0, 0.0, dist);
			glFlush();
			glutChangeToMenuEntry(1, "Square *", SQUARE);
			glutChangeToMenuEntry(2, "Circluangle", CIRCLUANGLE); 
			glutChangeToMenuEntry(3, "Fancy", FANCY); 
			glutChangeToMenuEntry(4, "Weave", WEAVE);
			glutChangeToMenuEntry(5, "Colorful", COLORFUL); break;

		case CIRCLUANGLE: 
			trackOption = CIRCLUANGLE;
			glClear(GL_COLOR_BUFFER_BIT); 
			drawTile2Pattern(numRows, numCols, 0.0, 0.0, dist);
			glFlush();
			glutChangeToMenuEntry(2, "Circluangle *", CIRCLUANGLE);  
			glutChangeToMenuEntry(1, "Square", SQUARE); 
			glutChangeToMenuEntry(3, "Fancy", FANCY); 
			glutChangeToMenuEntry(4, "Weave", WEAVE); 
			glutChangeToMenuEntry(5, "Colorful", COLORFUL); break;
	

		case FANCY:
			trackOption = FANCY;
			glClear(GL_COLOR_BUFFER_BIT); 
			drawTile3Pattern(numRows, numCols, 0.0, 0.0, dist);
			glFlush();
			glutChangeToMenuEntry(2, "Circluangle", CIRCLUANGLE); 
			glutChangeToMenuEntry(1, "Square", SQUARE); 
			glutChangeToMenuEntry(3, "Fancy *", FANCY); 
			glutChangeToMenuEntry(4, "Weave", WEAVE); 
			glutChangeToMenuEntry(5, "Colorful", COLORFUL); break;

		case WEAVE:
			trackOption = WEAVE;
			glClear(GL_COLOR_BUFFER_BIT); 
			drawTile4Pattern(numRows, numCols, 0.0, 0.0, dist);
			glFlush();
			glutChangeToMenuEntry(2, "Circluangle", CIRCLUANGLE); 
			glutChangeToMenuEntry(1, "Square", SQUARE); 
			glutChangeToMenuEntry(3, "Fancy", FANCY); 
			glutChangeToMenuEntry(4, "Weave *", WEAVE);
			glutChangeToMenuEntry(5, "Colorful", COLORFUL); break;
	
		case COLORFUL:
			trackOption = COLORFUL;
			glClear(GL_COLOR_BUFFER_BIT); 
			drawTile5Pattern(numRows, numCols, 0.0, 0.0, dist);
			glFlush();
			glutChangeToMenuEntry(2, "Circluangle", CIRCLUANGLE); 
			glutChangeToMenuEntry(1, "Square", SQUARE); 
			glutChangeToMenuEntry(3, "Fancy", FANCY); 
			glutChangeToMenuEntry(4, "Weave", WEAVE); 
			glutChangeToMenuEntry(5, "Colorful *", COLORFUL); break;
	}
}
	

void ProcessKeyboardEvents(unsigned char key, int x, int y) { 
	switch(key){
	case '=': numRows *= 2; numCols *= 2; if (numRows >= 40){numRows = numCols = 40; }  break;
	case '-': if (numRows <= 2){numRows = numCols = 2;} 
			  else if(numRows >= 20){numRows = numCols = 16; }
			  else {numRows /= 2; numCols /= 2; }
			  break;
	}
	if (trackOption == 0){glutPostRedisplay();}  // Initial Display need to change 
	else { processRightMenuEvents(trackOption);}
}

	
void OnMouseClick(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { animation = !animation;}
}

void idle()
{
	if(animation == true){
	Sleep(1500);
	glutPostRedisplay();}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);  
	if(trackOption == 0){drawTile1Pattern(numRows, numCols, 0.0, 0.0, dist);}
	else{processRightMenuEvents(trackOption);}
	glFlush();		
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);; // set the display mode
	glutInitWindowSize(700,700);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("Truchet Tiles"); // open the screen window(with its exciting title)
	myInit();  
	int PatternSubmenu = glutCreateMenu(processRightMenuEvents);
	
	PatternSubmenu = glutCreateMenu(processRightMenuEvents);

	glutAddMenuEntry("Square *",SQUARE);
	menuItems += 1;

	glutAddMenuEntry("Circluangle",CIRCLUANGLE);
	menuItems += 1;

	glutAddMenuEntry("Fancy",FANCY);
	menuItems += 1;

	glutAddMenuEntry("Weave", WEAVE);
	menuItems += 1;

	glutAddMenuEntry("Colorful", COLORFUL);
	menuItems += 1;


	glutCreateMenu(processRightMenuEvents);
	glutAddSubMenu("Patterns",PatternSubmenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(myDisplay);     // register the redraw function     
	glutKeyboardUpFunc(ProcessKeyboardEvents);
	glutMouseFunc(OnMouseClick);
	glutIdleFunc(idle);

	glutMainLoop(); 		     // go into a perpetual loop



}
