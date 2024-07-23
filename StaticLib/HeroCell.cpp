#include "HeroCell.h"
#include "EmptyCell.h"

//�������� +
Cell* HeroCell::operator+(Hero& hero) {
    return this;
}
//�������� -
Cell* HeroCell::operator-(Hero& hero) {
    return new EmptyCell;
}
//����� ������ �� ������
void HeroCell::print(ostream& out) const {
    out << "R";
}
//����������� �������
Cell* HeroCell::copy() {
    return new HeroCell(*this);
}

void HeroCell::visit(painter* p, int x, int y)
{
    p->Hero(x, y);
}

string HeroCell::getIcon()
{
    return "Hero";
}