#include "Cell.h"
#include "Hero.h"
class Moneta : public Cell {
private:
    int coinscount = 0;
    int totalcoints = 0;
public:
    Moneta();
    ~Moneta();
    virtual Cell* operator+(Hero& hero);
    virtual Cell* operator-(Hero& hero);
    virtual void print(ostream& out) const;
    virtual int getcoinscount();
   virtual Cell* copy();

   virtual void visit(painter* p, int x, int y);
   virtual string getIcon();
};