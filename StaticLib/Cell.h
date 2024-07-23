#include <iostream>
#include "Hero.h"
#include "painter.h"

using namespace std;

#pragma once
class Cell {
protected:
	Hero* hero; //���� �� ������, �� ������������ �����, ���� ������, �� ������ ������ ������������
public:
	//�������� +
	virtual Cell* operator+(Hero& hero) = 0;
	//�������� -
	virtual Cell* operator-(Hero& hero) = 0;

	//����� ������� ������
	virtual void print(ostream& out) const = 0;
	//���������� ��� ������
	virtual ~Cell() {}

	//���������� ������ ����� � ������ ��� ������
	friend istream& operator>>(istream& in, Cell*& cell);
	friend ostream& operator<<(ostream& out, const Cell& cell);

	//����������� �������
	virtual Cell* copy() = 0;

	virtual void visit(painter* p, int x, int y) = 0;
	virtual string getIcon() = 0;
};