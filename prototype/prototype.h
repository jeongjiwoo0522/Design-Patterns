#include "../creational_pattern/creational_pattern.h"
#include "../abstract_factory/abstract_factory.h"

class MazePrototypeFactory : public MazeFactory {
public:
	MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

	virtual Maze* MakeMaze() const;
	virtual Room* MakeRoom(int) const;
	virtual Wall* MakeWall() const;
	virtual Door* MakeDoor(Room*, Room*) const;

private:
	Maze* _prototypeMaze;
	Room* _prototypeRoom;
	Wall* _prototypeWall;
	Door* _prototypeDoor;
};

class Door : public MapSite {
public:
	Door();
	Door(const Door&);

	virtual void Initialize(Room*, Room*);
	virtual Door* Clone() const;
	virtual void Enter();
	Room* OtherSideFrom(Room*);
private:
	Room* _room1;
	Room* _room2;
};

class BombedWall : public Wall {
public:
	BombedWall();
	BombedWall(const BombedWall&);

	virtual Wall* Clone() const;
	bool HasBomb();
private:
	bool _bomb;
};