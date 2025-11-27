#include <vector>

#include "Fish.h"

using namespace std;

class Game {
	public:
		Game();
		int caught_fish_index;

		int get_number_of_reels() const;
		bool get_is_fish_caught() const;
		
		void set_number_of_reels(int i);
		void set_is_fish_caught(bool status);
		void reset_reels();
		
		void check_if_caught();
		void update();
		void render();
		void reeling();
		
		
	private:
		// Used by outside methods
		bool is_fish_caught;

		int number_of_reels;
		
		vector<Fish> fish_list;
		int spawn_timer, spawn_interval;
		int reel_value;
		int caught_timer, max_caught_timer;

		void spawn_fish();
		void despawn_fish();
		void clear_fishes();
		void reels_counter();
		void reset_values();
};
