//
// Created by Houman on 2019-12-01.
//

#pragma once
#include "tour.hpp"

//size of population in this tour
#define POP_SIZE 5

/*
 * Class representing a population of tours of cities
 */
class tour_population {
    //List of all tours
    vector<tour*> population;

    //the shortest tour
    tour* fittest_tour;

    //starting distance
    double base_distance;

public:
    /*
     * Constructor
     * Creates tours containing randomly shuffled list of cities
     * initializes the starting distance
     * @param - cities: The list of cities to be used to populate tours
     */
    tour_population(vector<city*> cities);

    /*
     * Destructor
     * Deletes memory used for each tour
     */
    ~tour_population();

    /*
     * The genetic algorithm calculating the best route
     */
    void genetic_algorithm();
};