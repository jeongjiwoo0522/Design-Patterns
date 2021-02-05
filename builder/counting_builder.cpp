#include "builder.h"

CountingMazeBuilder::CountingMazeBuilder() {
	_rooms = _doors = 0;
}

void CountingMazeBuilder::BuildRoom(int) {
	_rooms++;
}

void CountingMazeBuilder::BuildDoor(int, int) {
	_doors++;
}

void CountingMazeBuilder::GetCounts(int& rooms, int& doors) const {
	rooms = _rooms;
	doors = _doors;
}