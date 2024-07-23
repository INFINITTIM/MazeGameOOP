#include "GrPainter.h"

void GrPainter::setGr(Graphics^ _g) {
	g = _g;
}

void GrPainter::initIcons() {
	names = { "Wall12", "bitc", "dirt", "tankk", "TANK"};
	for each (string name in names) {
		String^ tmp = gcnew String((name + ".ico").c_str());
		gcroot<Icon^> newIcon = gcnew Icon(tmp);
		icons[name] = newIcon;
	}
}

void GrPainter::paintCell(string fileName, int x, int y) {
	int drawX = x * cellPixelSize;
	int drawY = y * cellPixelSize;
	rect = Drawing::Rectangle(drawX, drawY, cellPixelSize, cellPixelSize);

	g->DrawIcon(icons[fileName], rect);
}

void GrPainter::Wall(int x, int y) {
	paintCell("Wall12", x, y);
}
void GrPainter::Moneta(int x, int y) {
	paintCell("bitc", x, y);
}
void GrPainter::EmptyCell(int x, int y) {
	paintCell("dirt", x, y);
}
void GrPainter::Monster(int x, int y) {
	paintCell("tankk", x, y);
}
void GrPainter::Hero(int x, int y) {
	paintCell("TANK", x, y);
}