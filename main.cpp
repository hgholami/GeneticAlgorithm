#include <vector>
#include <random>
#include "city.hpp"

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

    for(city* c: cities)
        cout << c->getName() << " (" << c->getX() << "," << c->getY() << ")" << endl;

    for(city* c: cities)
        delete(c);
    return 0;
}