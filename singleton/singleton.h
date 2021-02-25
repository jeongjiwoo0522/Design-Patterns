#pragma once

class MazeFactory {
public:
	static MazeFactory* Instance();
protected:
	MazeFactory();
private:
	static MazeFactory* _instance;
};

class BombedMazeFactory : public MazeFactory {
};

class EnchantedMazeFactory : public MazeFactory {
};