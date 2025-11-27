#include "headers/Menu.h"

using namespace std;
Menu::Menu()
{
}
/*void Menu::draw_rectangle(float pos_x, float pos_y){
	GLfloat rectangle_vertex[] = {
		0.25f + pos_x, 0.1f + pos_y, 0.0f,
		0.25f + pos_x, -0.1f + pos_y, 0.0f,
		-0.25f + pos_x, -0.1f + pos_y, 0.0f,
		-0.25f + pos_x, 0.1f + pos_y, 0.0f
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, rectangle_vertex);
	glColor3f(0.0, 0.3, 0.5);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}*/

// Private 

void Menu::start_game(){
	// draw_rectangle(0.0f,0.3f);
}

// Public
void Menu::display(){
	start_game();
}
