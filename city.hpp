//
// Created by houma on 2019-11-15.
//
#pragma once
#include <iostream>

using namespace std;

class city {
    string name;
    int x;
    int y;

public:
    city(string name, int x, int y) : name(name), x(x), y(y){};

    string getName() {return name;}
    int getX() {return x;}
    int getY() {return y;}
};
