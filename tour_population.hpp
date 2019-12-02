//
// Created by Houman on 2019-12-01.
//

#pragma once
#include "tour.hpp"

//size of population in this tour
#define POP_SIZE 32

//number of elite tours
#define NUMBER_OF_ELITES 1

//number of potential parents for each crossover
#define PARENT_POOL_SIZE  5

//number of parents to be crossed
#define NUMBER_OF_PARENTS 2

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

private:
    /*
     * Helper class for genetic algorithm
     * moves the elite class to the first position of the population
     */
    void create_elite();

    /*
     * Helper class for genetic algorithm
     * @return - randomly populated parent pool
     */
    vector<tour*> populate_parent_pool();

    /*
     * Helper class for genetic algorithm
     * @param - parent_pool: a pool of potential parents
     * @return - the most fit parent from pool
     */
    tour* find_fittest_parent(vector<tour*> parent_pool);
};