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

void createStandardMaze() {
	Maze* maze;
	MazeGame game;
	StandardMazeBuilder builder;

	game.CreateMaze(builder);
	maze = builder.GetMaze();
}

void createCountingMaze() {
	int rooms, doors;
	MazeGame game;
	CountingMazeBuilder builder;

	game.CreateMaze(builder);
	builder.GetCounts(rooms, doors);

	cout << "the Maze has " << rooms << " rooms and" << doors << " doors" << endl;
}