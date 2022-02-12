
#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void GameDisplay(){


	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	
	
	/* Drawing opponent car
	float x = 100; 
	float y = 100; 
	float width = 20; 
	float height = 15;
	float* color = colors[WHITE]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
	*/


	// Drawing Arena
	//bottom left
	DrawRectangle(0, 0, 400, 400, colors[RED]);
	DrawRoundRect(100,100,200,200,colors[WHITE],50); 
	//top left
	DrawRectangle(0, 650, 400, 400, colors[BLUE_VIOLET]);
	DrawRoundRect(100,750,200,200,colors[WHITE],50);
	//bottom right
	DrawRectangle(650, 0, 400, 400, colors[BLUE]);
	DrawRoundRect(750,100,200,200,colors[WHITE],50);
	//top right
	DrawRectangle(650, 650, 400, 400, colors[DARK_OLIVE_GREEN]);
	DrawRoundRect(750,750,200,200,colors[WHITE],50); 
	//centre box
	DrawRectangle(400, 400, 250, 250, colors[DARK_GRAY]);
	DrawString( 490, 510,"HOME", colors[BLACK]);
	//RIGHT BOXES
	DrawRectangle(0, 400, 80, 80, colors[WHITE]);
	vector<unsigned char> buf;
	//ReadImage("wallpaprer.jpg",buf);


int imagefunc(int argc, char** argv)
{
 // Read the image file
 Mat image = imread("/home/talha/Desktop/project/Dodge_em");

 // Check for failure
 if (image.empty()) 
 {
  cout << "Could not open or find the image" << endl;
  cin.get(); //wait for any key press
  return -1;
 }

 String windowName = "The Guitar"; //Name of the window

 namedWindow(windowName); // Create a window

 imshow(windowName, image); // Show our image inside the created window.

 waitKey(0); // Wait for any keystroke in the window

 destroyWindow(windowName); //destroy the created window
}
	glutSwapBuffers();
}
}
void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT) {
	} else if (key
			== GLUT_KEY_RIGHT) {

	} else if (key
			== GLUT_KEY_UP) {

	}

	else if (key
			== GLUT_KEY_DOWN) {

	}

	glutPostRedisplay();

}

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(1);
	}

	if (key == 'b' || key == 'B')
			{
	
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

void Timer(int m) {

	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON)
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON)
			{

	}
	glutPostRedisplay();
}
int main(int argc, char*argv[]) {

	int width = 1400, height =1000;
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(300, 30);
	glutInitWindowSize(width, height); 
	glutCreateWindow("LUDO");
	SetCanvasSize(width, height);

	glutDisplayFunc(GameDisplay);
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);
	glutMotionFunc(MousePressedAndMoved);
	glutMainLoop();
	return 1;
}
#endif