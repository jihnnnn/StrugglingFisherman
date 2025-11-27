#include <iostream>
#include <GL/glut.h>

#include "headers/Game.h"
#include "headers/Fish.h"


using namespace std;

void handle_display();
void handle_keyboard(unsigned char key, int posX, int posY);
void handle_mouse(int button, int state, int x, int y);
void global_game_event(int value);

Game game;

int main(int argc, char** argv){
	
	// Initialization of Window
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Struggling Fisherman | AN31");
	
	// Handles Inputs, and Window Display
	glutDisplayFunc(handle_display);
	glutKeyboardFunc(handle_keyboard);
	glutMouseFunc(handle_mouse);
	
	// For Vertex Arrays
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Prevent Holding down key
	glutIgnoreKeyRepeat(1);
	
	// Handles Global Timer from the function GlobalGameEvent
	glutTimerFunc(0, global_game_event, 0);
	
	glutMainLoop();
	
	return 0;

}

void global_game_event(int value){
	game.update();
	glutPostRedisplay();
	glutTimerFunc(16, global_game_event, 0);
}


void handle_display(){
	glClear(GL_COLOR_BUFFER_BIT);

	game.render();
	glFlush();
}

void handle_keyboard(unsigned char key, int posX, int posY){
	
	cout << "PRESSED KEY: " << (int)key << endl;
	
	switch(key){
		case 32: // Keyboard Space
			if(!game.get_is_fish_caught()){
				game.check_if_caught();
				game.reset_reels();
			}
			else {
				game.reeling();
			}
			break;
		case 27:
			cout << "TThank you for playing!" << endl;
			exit(0);
			break;
	}
}

void handle_mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(!game.get_is_fish_caught()){
			game.check_if_caught();
			game.reset_reels();
		}
		else {
			game.reeling();
		}
		
		//if
	}		
}


