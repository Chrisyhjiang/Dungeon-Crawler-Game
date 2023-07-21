#ifndef ___CELL_H___
#define ___CELL_H___

// Forward declaration
class Character;
class Entity;
class Player;
class Enemy;
class Floor;
class Drow;
class Goblin;

class Cell {
	
	public:
		enum CellType {
                WALL,
                TILE,
                PASSAGE,
                DOORWAY,
                STAIR,
                UNKNOWN
        };

		Cell(int i, int j, char symbol);
		virtual ~Cell() = 0;

        virtual char getSymbol();
        virtual void setSymbol(char sb);
        virtual CellType getCellType();
        virtual void setCellType(CellType ct);
        int getRow();
        void setRow(int r);
        bool isOccupied();
        int getChamberID();
        void setChamberID(int id);
        bool isWalkable();
        // virtual occupiedBy();
    private:
		int row, col, chamberID;
		char symbol;
        bool walkable;
        CellType cellType;
        // Todo: Character* ch;
};
#endif
