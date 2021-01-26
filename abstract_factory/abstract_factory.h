#pragma once

#include "../creational_pattern/creational_pattern.h"

class MazeFactory {
public:
	virtual Maze* MakeMaze() const {
		return new Maze;
	}
	virtual Wall* MakeWall() const {
		return new Wall;
	}
	virtual Room* MakeRoom(int n) const {
		return new Room(n);
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const {
		return new Door(r1, r2);
	}
};

class Spell {};
class EnchantedRoom : public Room { 
public: 
	EnchantedRoom(int n, Spell* spell); 
};
class DoorNeedingSpell : public Door {
public:
	DoorNeedingSpell(Room*, Room*);
};
class EnchantedMazeFactory : public MazeFactory {
public:
	EnchantedMazeFactory();
	virtual Room* MakeRoom(int n) const {
		return new EnchantedRoom(n, CastSpell());
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const {
		return new DoorNeedingSpell(r1, r2);
	}
protected:
	Spell* CastSpell() const;
};

class BombedWall : public Wall {};
class RoomWithABomb : public Room {
public:
	RoomWithABomb(int n);
};
class BombedMazeFactory : public MazeFactory {
public:
	Wall* MakeWall() const {
		return new BombedWall();
	}
	Room* MakeRoom(int n) const {
		return new RoomWithABomb(n);
	}
};