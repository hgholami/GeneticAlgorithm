//
// Created by Houman on 2019-11-15.
//
#pragma once
#include <iostream>

using namespace std;
/*
 * Class representing a city
 */
class city {
    //name of city
    string name;

    //x coordinate of the city
    int x;

    //y coordinate of the city
    int y;

public:
    /*
     * Constructor
     * @param - name: name of the city to be created
     * @param - x coordinate of the city to be created
     * @param - y coordinate of the city to be created
     */
    city(string name, int x, int y) : name(name), x(x), y(y){};

    /*
     * Default destructor
     */
    ~city(){};

    /*
     * Getter method for the name of the city
     * @return - name of city
     */
    string getName() {return name;}

    /*
     * Getter method for the x coordinate of the city
     * @return - x coordinate of city
     */
    int getX() {return x;}

    /*
     * Getter method for the y coordinate of the city
     * @return - y coordinate of city
     */
    int getY() {return y;}
};
