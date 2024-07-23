#pragma once
#include <iostream>
#include "Cell.h"
using namespace std;

class DynamicLab {
private:
    Cell*** m;
    int rows, cols, healths;
public:
    //����������� ��� ������������� ������� 
    DynamicLab(int rows = 0, int cols = 0, int healths=0);
    //���������� ��� ����
    ~DynamicLab();
    //����������� �����������
    DynamicLab(const DynamicLab& second_lab);
    //���������� �������� ������������ =
    DynamicLab& operator=(const DynamicLab& second_lab);
    //���������� ��������� []
    Cell**operator[](int row) const;
    //�������� ������� ����� ����� � ��������
    int getrows() const { return rows; }
    int getcols() const { return cols; }
    int gethealth() const { return healths; }
    friend istream& operator>>(istream& in, DynamicLab& labirint);
    friend ostream& operator<<(ostream& out, DynamicLab& labirint);
};
