#include "Wall.h"
#include "EmptyCell.h"
#include "HeroCell.h"
#include "Exceptions.h"

//�������� +
Cell* Wall::operator+(Hero& hero) {
    hero.removehealth();
    //if (hero.health == 0) throw HeroHealthExceptions();
    throw WallExceptions();
}
//�������� -
Cell* Wall::operator-(Hero& hero) {
    return this;
}
//����� ������ �� ������
void Wall::print(ostream& out) const {
    out << "#";
}
//����������� �������
Cell* Wall::copy() {
    return new Wall(*this);
}

void Wall::visit(painter* p, int x, int y)
{
    p->Wall(x, y);
}

string Wall::getIcon()
{
    return "wall";
}