#include "prototype.h"

class MazeGame {
public:
	Maze* CreateMaze(MazeFactory* factory) {
		Maze* aMaze = factory->MakeMaze();
		Room* room = factory->MakeRoom();
		// ...
	}
};

int main() {
	MazeGame game1;
	MazePrototypeFactory simpleMazeFactory(new Maze, new Wall, new Room, new Door);
	Maze* maze = game1.CreateMaze(simpleMazeFactory);

	MazeGame game2;
	MazePrototypeFactory bombedMazeFactory(new Maze, new BombedWall, new RoomWithABomb, new Door);
	game2.CreateMaze(bombedMazeFactory);
}