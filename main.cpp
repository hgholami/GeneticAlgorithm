#include "city.hpp"
#include "tour_population.hpp"
#include<string>

//max value for x and y coordinates
#define MAP_BOUNDARY 1000

//number of cities used in simulation
#define CITIES_IN_TOUR 32

/*
 * Main method driving the program
 */
int main() {
    //List of unique city names (integers from 0 to CITIES_IN_TOUR - 1)
    string cityNames[CITIES_IN_TOUR];
    for(int i = 0; i < CITIES_IN_TOUR; ++i)
        cityNames[i] = to_string(i);

    //list of city objects
    vector<city*> cities;

    //Generating random coordinates for cities
    random_device rd;
    mt19937 iGenerator(rd());
    uniform_int_distribution<> iDistribution(0, MAP_BOUNDARY);
    for(string c : cityNames){
        cities.push_back(new city{c, iDistribution(iGenerator), iDistribution(iGenerator)});
    }

    //creating a population of 5 tours
    tour_population pop = tour_population{cities};

    //Calculating the best path using the genetic algorithm
    pop.genetic_algorithm();

    //freeing memory holding the list of cities
    for(city* c: cities)
        delete(c);
    return 0;
}