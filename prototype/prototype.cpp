#include "prototype.h"

MazePrototypeFactory::MazePrototypeFactory(
	Maze* m, Wall* w, Room* r, Door* d
) {
	_prototypeMaze = m;
	_prototypeWall = w;
	_prototypeRoom = r;
	_prototypeDoor = d;
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

}