#include "prototype.h"

MazePrototypeFactory::MazePrototypeFactory(
	Maze* m, Wall* w, Room* r, Door* d
) {
	_prototypeMaze = m;
	_prototypeWall = w;
	_prototypeRoom = r;
	_prototypeDoor = d;
}

Wall* MazePrototypeFactory::MakeWall() const {
	return _prototypeWall->Clone();
}

Door* MazePrototypeFactory::MakeDoor(Room* r1, Room* r2) const {
	Door* door = _prototypeDoor->Clone();
	door->Initialize(r1, r2);
	return door;
}

Wall* Wall::Clone() const {
	return new Wall(*this);
}

Door::Door(const Door& other) {
	_room1 = other._room1;
	_room1 = other._room2;
}

void Door::Initialize(Room* r1, Room* r2) {
	_room1 = r1;
	_room2 = r2;
}

Door* Door::Clone() const {
	return new Door(*this);
}

BombedWall::BombedWall(const BombedWall& other) : Wall(other) {
	_bomb = other._bomb;
}

Wall* BombedWall::Clone() const {
	return new BombedWall();
}