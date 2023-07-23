#ifndef ___CELL_H___
#define ___CELL_H___

#include "floor.h"
#include "../constants.h"
// Forward declaration
class Character;
class Floor;


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
		virtual ~Cell();

        virtual char getSymbol();
        virtual void setSymbol(char sb);
        virtual CellType getCellType();
        virtual void setCellType(CellType ct);
        int getRow();
        void setRow(int r);
        int getCol();
        bool isOccupied();
        int getChamberID();
        void setChamberID(int id);
        virtual bool isWalkable() = 0;
        virtual Character* occupiedBy();
        Character* getCharacter();
        void setCharacter(Character* a);
    private:
		int row, col, chamberID, level;
		char symbol;
        bool walkable;
        CellType cellType;
        Character* ch;
};
#endif
