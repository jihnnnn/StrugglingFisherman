#include <vector>
#include <iostream>
#include <cstdlib>

#include "headers/Fish.h"
#include "headers/Game.h"
#include "headers/Menu.h"

using namespace std;

Game::Game() :
	spawn_timer(0),
	spawn_interval(30),
	number_of_reels(0),
	
	caught_timer(0),
	max_caught_timer(300),
	caught_fish_index(-1),
	is_fish_caught(false),
	reel_value(0)
	
{
}

// SETTERS AND GETTERS
bool Game::get_is_fish_caught() const {
	return is_fish_caught;
}


void Game::set_number_of_reels(int i){
	number_of_reels += i;
}

void Game::reset_reels(){
	number_of_reels = 0;
}

void Game::set_is_fish_caught(bool status){
	is_fish_caught = status;
}


// ========== Public ==========

void Game::render(){

	// menu.display();
	for(int i = 0; i < fish_list.size(); i++){
		fish_list[i].run_display();
	}
}

void Game::update(){
	
	spawn_timer++;
	
	if(spawn_timer >= spawn_interval){
		spawn_timer = 0;
		spawn_fish();
	}
	
	if(!is_fish_caught){
		for(int i = 0; i < fish_list.size(); i++){
			fish_list[i].update_movement();
		}
	}
	else {
		if(caught_timer <= 0){
			cout << "Fish Escaped!" << endl;
			reset_values();

			return;
		}
		caught_timer--;
	}
}

void Game::check_if_caught(){
	for(int i = fish_list.size() - 1; i>= 0; i--){
		if(fish_list[i].get_pos_x() >= -0.12 && fish_list[i].get_pos_x() <= 0.12){
			
			caught_fish_index = i;
			cout << "Caught Fish!" << endl;
			
			clear_fishes();
			fish_list[0].set_pos_x(0.0f);
			set_is_fish_caught(true);
			caught_timer = max_caught_timer;
			break;
		}
	}
}


// ========== Private ==========

void Game::spawn_fish(){
	Fish new_fish;
	
	if(is_fish_caught){
		return;
	}
	
	fish_list.push_back(new_fish);
	cout << "New fish spawned!" << endl;
	
}

void Game::despawn_fish(){
	
	for(int i = fish_list.size() - 1; i>= 0; i--){
		if(fish_list[i].is_off_screen()){
			fish_list.erase(fish_list.begin() + i);
		}
	}
}

void Game::clear_fishes(){
	Fish caught_fish = fish_list[caught_fish_index];
	fish_list.clear();
	fish_list.push_back(caught_fish);
	caught_fish_index = 0;
}
void Game::reset_values(){
	fish_list.clear();
	is_fish_caught = false;
	reel_value = 0;
	caught_fish_index = -1;
	number_of_reels = 0;
}

void Game::reeling(){
	reel_value += (1 + rand() % 3);
	set_number_of_reels(number_of_reels += 1);
	
	if(reel_value >= fish_list[caught_fish_index].get_required_to_pull()){
		cout << "YOU CAUGHT THE FISH!!!";
		
		reset_values();
		// Add Points To Player Function
	}
}
