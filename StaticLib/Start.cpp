#include "Header.h"
#include "Game.h"
#include <fstream>
#include "Exceptions.h"
#include "IOBserver.h"
#include "Start.h"
using namespace std;

void start_game() {
    Game g;
    string filename = "D:\\Новая папка\\VisualLabirintForm 3\\StaticLib\\labirint2.txt";
    g.read(filename);

    //все наблюдатели
    ViewHealth healthView(cout);
    ViewCoins coinsView(cout);
    ViewLabirint labirintView(g, cout);

    g.addObserver(&healthView);
    g.addObserver(&coinsView);
    g.addObserver(&labirintView);

    g.initPainter(new painter);

    Controller heroController(g);
    int val = _getch();
    while (val != 27) {
        system("cls");
        heroController.cmove(val);
        val = _getch();
    }
}
