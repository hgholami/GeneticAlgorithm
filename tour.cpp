//
// Created by Houman on 2019-12-01.
//

#include "tour.hpp"
void tour::calculate_fitness() {
    double distance_travelled = 0;
    for(auto it = cities.begin() + 1; it != cities.end(); ++it){
        auto prev = it - 1;
        distance_travelled += sqrt(pow((*it)->getX() - (*prev)->getX(), 2)
                                    + pow((*it)->getY() - (*prev)->getY(),2) * 1.0);
    }

    fitness = 1 / distance_travelled * SCALAR;
}