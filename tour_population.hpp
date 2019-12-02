//
// Created by Houman on 2019-12-01.
//

#pragma once
#include "tour.hpp"

#define POP_SIZE 5

/*
 * Class representing a population of tours of cities
 */
struct tour_population {
    //List of all tours
    vector<tour*> population;

    /*
     * Constructor
     * Creates tours containing randomly shuffled list of cities
     * @param - cities: The list of cities to be used to populate tours
     */
    tour_population(vector<city*> cities);

    /*
     * Destructor
     * Deletes memory used for each tour
     */
    ~tour_population();
};