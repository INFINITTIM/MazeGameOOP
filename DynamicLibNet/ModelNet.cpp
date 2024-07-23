#include "ModelNet.h"
#include "Exceptions.h"


void ModelNet::addObserverstoC() {
    OModel* tmp = new OModel(this);
    modelC->addObserver(tmp);
}

ModelNet::ModelNet() {
    modelC = new Game();
    modelC->read("D:\\Новая папка\\VisualLabirintForm 3\\StaticLib\\labirint2.txt");
    modelC->TotalCoins();
    observers = gcnew List<ObserverNet^>(3);
    addObserverstoC();
}

ModelNet::~ModelNet() {
    delete modelC;
    for each (ObserverNet ^ observer in observers) {
        delete observer;
    }
    delete observers;
}

void ModelNet::update() {
    for each (ObserverNet ^ observer in observers) {
        observer->evnt_net(this);
    }
}

void ModelNet::move(ACTION act) {
    try {
        modelC->move(act);
    }
    catch (HeroHealthExceptions) {
        throw gcnew HeroHPNet();
    }
    catch (WallExceptions) {
        throw gcnew WallEx();
    }
    catch (MonstersExceptions) {
        throw gcnew WallEx();
    }
    catch (HeroWin) {
        throw gcnew WinnerHero();
    }
}

void ModelNet::addObserver(ObserverNet^ observer) {
    observers->Add(observer);
    update();
}

void ModelNet::displayLab(Graphics^ panel) {
    if (painter == nullptr) 
{
        painter = new GrPainter(panel);
        modelC->initPainter(painter);
    }
    painter->setGr(panel);
    modelC->displayLab();
}

void OModel::evnt(Game& model) {
    mNET->update();
}

void ControllerNet::step(int val)
{
    switch (val)
    {
    case 40:
        (*model).move(DOWN);
        break;
    case 38:
        (*model).move(UP);
        break;
    case 39:
        (*model).move(RIGHT);
        break;
    case 37:
        (*model).move(LEFT);
        break;
    }
}