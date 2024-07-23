#include "Moneta.h"
#include "EmptyCell.h"
#include "HeroCell.h"

Moneta::Moneta() {}

Moneta::~Moneta() {}

//�������� +
Cell* Moneta::operator+(Hero& hero) {
    hero.addcoins(); 
    cout << "Total Coins: " << hero.getcoins() << endl;
    return new HeroCell;
}
//�������� -
Cell* Moneta::operator-(Hero& hero) {
    return new EmptyCell;
}
//����� ������ �� ������
 int Moneta::getcoinscount() { 
    cout << "Total Coins: " << coinscount << endl;
    return coinscount; 
 }

 //����� ������ �� ������
 void Moneta::print(ostream& out) const {
     out << "$";
 }

 //����������� �������
Cell* Moneta::copy() {
     return new Moneta(*this);
 }

void Moneta::visit(painter* p, int x, int y)
{
    p->Moneta(x, y);
}

string Moneta::getIcon()
{
    return "Moneta";
}