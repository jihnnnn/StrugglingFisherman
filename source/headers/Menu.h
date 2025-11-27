#include <string>
using namespace std;

class Menu {
	public:
		Menu();
		void display();
		
	private:
		string text;
		void start_game();
		void exit_game();
		void leaderboards();
		void settings();
		
		
		// void draw_rectangle();
};


