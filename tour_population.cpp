//
// Created by Houman on 2019-12-01.
//

#include "tour_population.hpp"
tour_population::tour_population(vector<city *> cities) {
    for(int i = 0; i < POP_SIZE; ++i) {
        tour* tour_ptr = new tour(cities);
        population.push_back(tour_ptr);
    }
}

tour_population::~tour_population() {
    for(tour* t : population)
        delete(t);
}