#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "abstract_factory.h"

class MazeGame {
public:
	Maze* CreateMaze(MazeFactory& factory) {
		Maze* aMaze = factory.MakeMaze();
		Room* r1 = factory.MakeRoom(1);
		Room* r2 = factory.MakeRoom(2);
		Door* aDoor = factory.MakeDoor(r1, r2);

		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		r1->SetSide(North, factory.MakeWall());
		r1->SetSide(East, aDoor);
		r1->SetSide(South, factory.MakeWall());
		r1->SetSide(West, factory.MakeWall());

		r2->SetSide(North, factory.MakeWall());
		r2->SetSide(East, factory.MakeWall());
		r2->SetSide(South, factory.MakeWall());
		r2->SetSide(West, aDoor);
	}
};

int main() {
	MazeGame game1;
	MazeGame game2;
	MazeGame game3;

	MazeFactory basicMazeFactory;
	BombedMazeFactory bombedMazeFactory;
	EnchantedMazeFactory enchantedMazeFactory;

	game1.CreateMaze(basicMazeFactory);
	game2.CreateMaze(bombedMazeFactory);
	game2.CreateMaze(enchantedMazeFactory);

	return 0;
}