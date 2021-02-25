#include "singleton.h"
#include <iostream>
#include <cstdlib>

MazeFactory* MazeFactory::_instance = 0;

MazeFactory* MazeFactory::Instance() {
	if (_instance == 0) {
		const char* mazeStyle = getenv("MAZESTYLE");
		
		if (strcmp(mazeStyle, "bombed") == 0) {
			_instance = new BombedMazeFactory;
		}
		else if (strcmp(mazeStyle, "enchanted") == 0) {
			_instance = new EnchantedMazeFactory;
		}
		// ... 
		else {
			_instance = new MazeFactory;
		}
	}
	return _instance;
}