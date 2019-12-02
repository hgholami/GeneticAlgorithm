//
// Created by Houman on 2019-12-01.
//

#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "city.hpp"

#define SCALAR 10000

/*
 * Class representing a tour of cities
 */
struct tour {
    //tour of cities
    vector<city*> cities;

    //represents the quality of the tour
    double fitness;

    /*
     * Constructor
     * Accepts a list of cities and creates a tour with a random order
     * @param - cities: cities to populate the tour
     */
    tour(vector<city*> cities) : cities(cities){
        random_shuffle(begin(this->cities), end(this->cities));
        calculate_fitness();
    };

    /*
     * Destructor
     * Frees memory used for each city
     */
    ~tour(){};

private:
    /*
     * Calculates the fitness of this tour
     */
    void calculate_fitness();
};