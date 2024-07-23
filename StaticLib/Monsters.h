#include "Cell.h"
#include "Hero.h"
class Monsters : public Cell {
private:
    int healthcount = 3;
    int monsterhealth = 1;
public:
    Monsters();
    ~Monsters();
    virtual Cell* operator+(Hero& hero);
    virtual Cell* operator-(Hero& hero);
    virtual void print(ostream& out) const;
    virtual int gethealths();
    virtual Cell* copy();

    virtual int Monsterhealth() const { return monsterhealth; }
    virtual void Monsterhealthremove() { monsterhealth--; }
    virtual bool Monstershealthzerocheck() {
        if (monsterhealth == 0) return true;
        return false;
    }

    virtual void visit(painter* p, int x, int y);
    virtual string getIcon();
};