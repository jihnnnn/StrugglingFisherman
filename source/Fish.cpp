#include "headers/Fish.h"
#include <GL/glut.h>

Fish::Fish(){
	posX = 1.2f;
	posY = 0.0f;
	level = randLevelGen();
	requiredToPull = pullValue();
}

bool Fish::getIsHooked(){
	return isHooked;
}

void Fish::runDisplay(){
	testDraw();
}

void testDraw(){
	GLfloat fishVertex[] = {
		0.1f + posX, 0.1f + posY, 0.0f,
		0.1f + posX, -0.1f + posY, 0.0f,
		-0.1f + posX, -0.1f + posY, 0.0f,
		-0.1f + posX, 0.1f + posY, 0.0f
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, fishVertex);
	glColor3f(0.0, 0.3, 0.5);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);	
}

void pullValue(){
	int baseValue = level * 7;
	int variation = rand() % (level + 3);
	int value = baseValue + variation;
	
	return value;
}
