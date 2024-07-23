#include "Game.h"
#include "IOBserver.h"

void ViewHealth::evnt(Game& g) {
		out << "Health: " << g.getHero().gethealth() << " hp" << endl;
}

void ViewCoins::evnt(Game& g) {
		out << "Coins: " << g.getHero().getcoins() << endl;
}

void ViewLabirint::evnt(Game& g) {
	g.displayLab();
}

//контроллер передвижения героя
void Controller::cmove(int val) {
    int ip = g.getHero().geti();
    int jp = g.getHero().getj();
    switch (val) {
    case 80: // down
        g.setHeroPose(ip + 1, jp);
        break;
    case 72: //up
        g.setHeroPose(ip - 1, jp);
        break;
    case 75: //left
        g.setHeroPose(ip, jp - 1);
        break;
    case 77: //right
        g.setHeroPose(ip, jp + 1);
        break;
    }
}
