#include "city.hpp"
#include "tour_population.hpp"

/*
 * Main method driving the program
 */
int main() {
    //List of unique city names
    string cityNames[] = {"Vancouver", "Victoria", "Toronto", "Ottawa", "New York", "Los Angeles", "Seattle", "Austin", "Boston", "Paris", "London", "Barcelona", "Tehran", "Cape Town"};

    //list of city objects
    vector<city*> cities;

    //Generating random coordinates for cities
    random_device rd;
    mt19937 iGenerator(rd());
    uniform_int_distribution<> iDistribution(0, 1000);
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