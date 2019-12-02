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
    create_elite();

    vector<tour*> parents;

    for(int i = 0; i < NUMBER_OF_PARENTS; ++i) {
        vector<tour *> parent_pool = populate_parent_pool();
        parents.push_back(find_fittest_parent(parent_pool));
    }

}

void tour_population::create_elite(){
    auto iterator = find(population.begin(), population.end(), fittest_tour);
    if(iterator != population.end())
        population.erase(iterator);
    population.insert(population.begin(), fittest_tour);
}

vector<tour*> tour_population::populate_parent_pool() {
    vector<tour*> parent_pool;
    for(int i = 0; i < PARENT_POOL_SIZE; ++i){
        std::random_device random_device;
        std::mt19937 engine{random_device()};
        std::uniform_int_distribution<int> dist(1, population.size() - 1);
        parent_pool.push_back(population[dist(engine)]);
    }
    return parent_pool;
}

tour* tour_population::find_fittest_parent(vector<tour *> parent_pool) {
    tour* fit_parent = parent_pool.at(0);

    for(tour* p : parent_pool)
        if(p->get_fitness() < fit_parent->get_fitness())
            fit_parent = p;

    return fit_parent;
}