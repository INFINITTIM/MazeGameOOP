#pragma once
#include "DynamicLab.h"
#include <iostream>
#include "IOBserver.h"
#include <vector>
using namespace std;

class Game;

class painter;

enum ACTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Game {
	DynamicLab labirint; //�������� ������������� ������� ��� ���������
	Hero hero; //�������� ���������

	painter* p;

	vector<IOBserver*> allObservers; //������ ������������
	int lab_w, lab_h; //������� ���������
	int lab_health; //�������� �����
	int coins;
public:
	Game(); //����������� �� ��������� ��� �������� ����

	//������� painter
	painter& getPainter() { return *p; }

	void initPainter(painter* _p) {
		if (p != nullptr) delete p;
		p = _p;
	}
	//void readfromfile(const string& filename); //���������� ���� �� �����
	void addObserver(IOBserver* o) {
		allObservers.push_back(o);
	}
	void evnt() {
		for (IOBserver* o : allObservers)
		{
			o->evnt(*this);
		}
	}
	void read(const string& filename);
	void move(ACTION act); //������ ������������ ���������
	void setHeroPose(int i, int j); //������������ ������� ���������

	friend ostream& operator<<(ostream& out, const Game& g); //������ ���� � �������
	friend istream& operator>>(istream& in, Cell*& cell);

	Game(const Hero& hero) : hero(hero) {} // ����������� � �������������� �����
	const Hero& getHero() const { return hero; } //���������� ����� �����
	
	void TotalCoins();
	void displayLab() const;
};