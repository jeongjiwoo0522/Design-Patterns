#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "builder.h"

using namespace std;

class MazeGame {
public:
	Maze* CreateMaze(MazeBuilder& builder) {
		builder.BuildMaze();

		builder.BuildRoom(1);
		builder.BuildRoom(2);
		builder.BuildDoor(1, 2);

		return builder.GetMaze();
	}
};

int main() {
	Maze* maze;
	MazeGame game;
	StandardMazeBuilder builder;

	game.CreateMaze(builder);
	maze = builder.GetMaze();

	return 0;
}