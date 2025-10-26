#pragma once

class Fish{
	
	public:
		Fish();
		
		int level;
		float posX;
		float posY;
		
		float requiredToPull;
		
		bool getIsHooked();
		
		void runDisplay();
	
	private:
		void drawFish();
		void levelDisplay();
		void pullValueDebug();
		void updateMovement();
		
		
		bool isOffScreen();
		int randLevelGen();
		
};
