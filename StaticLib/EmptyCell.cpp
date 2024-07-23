#include "EmptyCell.h"
#include "HeroCell.h"

Cell* EmptyCell::operator+(Hero& hero) {
    return new HeroCell;
}
Cell* EmptyCell::operator-(Hero& hero) {
    return this;
}
void EmptyCell::print(ostream& out) const {
    out << " ";
}
Cell* EmptyCell::copy() {
    return new EmptyCell(*this);
}
void EmptyCell::visit(painter* p, int x, int y)
{
    p->EmptyCell(x, y);
}
string EmptyCell::getIcon()
{
    return "EmptyCell";
}