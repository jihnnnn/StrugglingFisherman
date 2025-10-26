#include <iostream>
#include <GL/glut.h>

#include "headers/Game.h"
#include "headers/Fish.h"


using namespace std;

void handleDisplay();
void handleKeyboard(unsigned char key, int posX, int posY);
void handleMouse(int button, int state, int x, int y);

int main(int argc, char** argv){
	
	// Initialization of Window
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Struggling Fisherman | AN31");
	
	// Handles Inputs, and Window Display
	glutDisplayFunc(handleDisplay);
	glutKeyboardFunc(handleKeyboard);
	glutMouseFunc(handleMouse);
	
	// For Vertex Arrays
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Prevent Holding down key
	glutIgnoreKeyRepeat(1);
	
	// Handles Global Timer from the function GlobalGameEvent
	// glutTimerFunc(0, GlobalGameEvent, 0);
	
	glutMainLoop();
	
	return 0;

}

void handleDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);

	// game.render();
	glFlush();
}

void handleKeyboard(unsigned char key, int posX, int posY){
	
	cout << "PRESSED KEY: " << (int)key << endl;
	
	switch(key){
		/* case 32: // Keyboard Space
			
			if(!game.isFishCaught){
				game.checkIfCaught();
				game.numberOfReels = 0;
			}
			else {
				game.reelFish();
			}
			break; */
		case 27:
			cout << "TThank you for playing!" << endl;
			exit(0);
			break;
	}
}

void handleMouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		/* if(!game.isFishCaught){
			game.checkIfCaught();
			game.numberOfReels = 0;
		}
		else {
			game.reelFish();
		} */
	}
}


