#pragma once

class Fish{
	
	public:
		Fish();
		
		float get_pos_x() const;
		float get_pos_y() const;
		int get_level() const;
		float get_required_to_pull() const;
		
		void set_pos_x(float x);
		void set_pos_y(float y);
		
		void update_movement();
		bool is_off_screen();
		void run_display();

	private:
		// Variables
		float pos_x;
		float pos_y;
		int level;
		float required_to_pull;
		
		int rand_level_gen();
		void draw_fish();
		void level_display();
		int pull_value();
};
