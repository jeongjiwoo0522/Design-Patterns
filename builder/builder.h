#pragma once

#include "../creational_pattern/creational_pattern.h"

class MazeBuilder {
public:
	virtual void BuildMaze() {}
	virtual void BuildRoom(int room) {} 
	virtual void BuildDoor(int roomFrom, int roomTo) {}

	virtual Maze* GetMaze() { return 0; }

protected:
	MazeBuilder();
};

class StandardMazeBuilder : public MazeBuilder {
public:
	StandardMazeBuilder();

	virtual void BuildMaze();
	virtual void BuildRoom(int);
	virtual void BuildDoor(int, int);

	virtual Maze* GetMaze();

protected:
	Direction CommonWall(Room*, Room*);
	Maze* _currentMaze;
};

class CountingMazeBuilder : public MazeBuilder {
public:
	CountingMazeBuilder();

	virtual void BuildMaze();
	virtual void BuildRoom(int);
	virtual void BuildDoor(int, int);

	void GetCounts(int&, int&) const;

private:
	int _doors;
	int _rooms;
};