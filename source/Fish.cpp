#include <cstdlib>
#include <GL/glut.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "headers/Fish.h"

using namespace std;

Fish::Fish() :
	pos_x(1.2f),
	pos_y(0.0f)
{
	level = rand_level_gen();
	required_to_pull = pull_value();
}

// ========== GETTERS ==========
float Fish::get_pos_x() const {
	return pos_x;
}

float Fish::get_pos_y() const {
	return pos_y;
}

int Fish::get_level() const {
    return level;
}

float Fish::get_required_to_pull() const {
    return required_to_pull;
}

void Fish::set_pos_x(float x) {
	pos_x = x;
}

// ========== Public ==========

void Fish::run_display(){
	draw_fish();
}

bool Fish::is_off_screen(){
	return pos_x < -1.2f;
}

void Fish::update_movement(){
	pos_x -= 0.025f;
}

// ========== Private ==========

void Fish::draw_fish(){
	GLfloat fish_vertex[] = {
		0.1f + pos_x, 0.1f + pos_y, 0.0f,
		0.1f + pos_x, -0.1f + pos_y, 0.0f,
		-0.1f + pos_x, -0.1f + pos_y, 0.0f,
		-0.1f + pos_x, 0.1f + pos_y, 0.0f
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, fish_vertex);
	glColor3f(0.0, 0.3, 0.5);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);	
}

void Fish::level_display(){
	stringstream ss;
	ss << level;
	string level_string = ss.str();
				
	glColor3f(0.7, 0.7, 0.7);
	glRasterPos2f(pos_x - 0.0075, pos_y + 0.115);
	
	for(int i=0; level_string[i] != '\0'; i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, level_string[i]);	
	}
	
}


int Fish::pull_value(){
	int base_value = level * 7;
	int variation = rand() % (level  + 3);
	int value = base_value + variation;
	
	return value;
}

int Fish::rand_level_gen(){
	int level = 1 + (rand() % 10 );
	return level;
}
