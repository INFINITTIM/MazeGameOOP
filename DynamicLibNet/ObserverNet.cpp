#include "ObserverNet.h"

void MonetaNet::evnt_net(ModelNet^ g)
{
    moneta->Text = "Coins: " + g->getCoins().ToString();
}

void HPNet::evnt_net(ModelNet^ g)
{
    hp->Text = "HP: " + g->getHeroHP().ToString();
}

void LabirintAroundNet::evnt_net(ModelNet^ g)
{
    g->displayLab(panel_labirint->CreateGraphics());
}

