//
// Created by Houman on 2019-12-01.
//

#include "tour_population.hpp"
tour_population::tour_population(vector<city *> cities) {
    for(int i = 0; i < POP_SIZE; ++i) {
        tour* tour_ptr = new tour(cities);
        population.push_back(tour_ptr);
    }

    fittest_tour = population.at(0);
    for(int i = 0; i < POP_SIZE; ++i)
        if(population.at(i)->get_fitness() < fittest_tour->get_fitness())
            fittest_tour = population.at(i);

    base_distance = fittest_tour->get_fitness();
}

tour_population::~tour_population() {
    for(tour* t : population)
        delete(t);
}

void tour_population::genetic_algorithm() {
    
}