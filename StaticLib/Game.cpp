#include "Game.h"
#include "Cell.h"
#include "Hero.h"
#include "HeroCell.h"
#include <fstream>
#include "Wall.h"
#include "Moneta.h"
#include "Monsters.h"
#include "EmptyCell.h"
#include "Exceptions.h"

void Game::setHeroPose(int i, int j) {
	lab_h = labirint.getrows();
	lab_w = labirint.getcols();

	if (hero.health == 0) throw HeroHealthExceptions();
	
	Cell* newCell = *labirint[i][j] + hero; //���� � ����� ������
	Cell* oldCell = *labirint[hero.geti()][hero.getj()] - hero; //����� ����� �� ������
	if (newCell != labirint[i][j]) { //���������� ����� ������
		delete labirint[i][j];
		labirint[i][j] = newCell;
	}
	if (oldCell != labirint[hero.geti()][hero.getj()]) { //���������� ������ ������
		delete labirint[hero.geti()][hero.getj()];
		labirint[hero.geti()][hero.getj()] = oldCell;
	}
	hero.move(i, j);

	if (hero.getcoins() == coins)
	{
		evnt();
		throw HeroWin();
	}
}
void Game::TotalCoins() {
	for (int i = 0; i < labirint.getrows(); ++i) {
		for (int j = 0; j < labirint.getcols(); ++j) {
			if (dynamic_cast<Moneta*>(labirint[i][j]) != nullptr) {
				coins++;
			}
		}
	}
}

Game::Game() 
{

} 

//������������ �����
void Game::move(ACTION act)
{
	int ip = 0;
	int jp = 0;

	ip = hero.geti();
	jp = hero.getj();

	//������������ ���������
	switch (act) {
	case UP:
		ip--;
		break;
	case DOWN:
		ip++;
		break;
	case LEFT:
		jp--;
		break;
	case RIGHT:
		jp++;
		break;
	}
	//hero.addsteps();
	setHeroPose(ip, jp);
	evnt();
}

istream& operator>>(istream& in, Cell*& cell) {
	char symbol;
	in >> noskipws >> symbol; // ������ ������

	switch (symbol) {
	case '#':
		cell = new Wall();
		break;
	case 'C':
		cell = new Moneta();
		break;
	case 'M':
		cell = new Monsters();
		break;
	case 'R':
		cell = new HeroCell();
		break;
	default:
		cell = new EmptyCell();
		break;
	}
	return in;
}

//���������� ���������� �� ����� ���������
void Game::read(const string& filename) {
	ifstream file(filename);
	if (file) {
		int newrows, newcols, counthealth;
		file >> newrows >> newcols >> counthealth;
		hero.health = counthealth;
		file.ignore(); //����� �������� \n
		DynamicLab tempLab(newrows, newcols, counthealth);
		this->labirint = tempLab; //������������� � ���������� ������������
		file >> this->labirint;
		//����� ��� ������ � 0 � 0
		delete labirint[0][0];
		labirint[0][0] = new Wall();
	}
	else {
		cout << "Error with opening of file: " << filename << endl;
	}
}

void Game::displayLab() const{
	int lab_height = labirint.getrows();
	int lab_width = labirint.getcols();

	Cell* emptyCell = new Wall();
	for (int i = 0; i <= lab_height; i++) {
		for (int j = 0; j <= lab_width; j++) {
			if (i < 0 || i >= lab_height || j < 0 || j >= lab_width) {
				emptyCell->visit(p, j, i);
			}
			else {
				labirint[i][j]->visit(p, j, i);
			}
		}
		cout << endl;
	}
}