#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
#include "Monsters.h"
#include "EmptyCell.h"

// ���������� ��������� ������ ��� ������ Cell
ostream& operator<<(ostream& out, const Cell& cell) {
    cell.print(out);
    return out;
}
