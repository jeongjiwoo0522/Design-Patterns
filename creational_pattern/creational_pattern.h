#pragma once

using namespace std;

enum Direction { North, South, East, West };

class MapSite {
public:
	virtual void Enter() = 0;
};

class Room : public MapSite {
public:
	Room(int RoomNo);
	MapSite* GetSide(Direction, MapSite*);
	void SetSide(Direction, MapSite*);

	virtual void Enter();

private:
	MapSite* _sides[4];
	int _roomNumber;
};

class Wall : public MapSite {
public: 
	Wall();
	virtual void Enter();
};

class Door : public MapSite {
public:
	Door(Room* = 0, Room* = 0);
	virtual void Enter();
	Room* OtherSideFrom(Room*);

private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;
};

class Maze {
public:
	Maze();

	void AddRoom(Room*);
	Room* RoomNo(int) const;
};

class Spell {};
class EnchantedRoom : public Room {
public:
	EnchantedRoom(int n, Spell* spell);
};

class BombedWall : public Wall {};
class RoomWithABomb : public Room {
public:
	RoomWithABomb(int n);
};

class DoorNeedingSpell : public Door {
public:
	DoorNeedingSpell(Room*, Room*);
};