#include <vector>
#include <random>
#include "city.hpp"

int main() {
    string cityNames[] = {"Vancouver", "Victoria", "Toronto", "Ottawa", "New York", "Los Angeles", "Seattle", "Austin", "Boston", "Paris", "London", "Barcelona", "Tehran", "Cape Town"};
    vector<city> cities;

    random_device rd;
    mt19937 iGenerator(rd());
    uniform_int_distribution<> iDistribution(0, 1000);
    for(string c : cityNames){
        cities.push_back(city{c, iDistribution(iGenerator), iDistribution(iGenerator)});
    }

    for(city c: cities)
        cout << c.getName() << " (" << c.getX() << "," << c.getY() << ")" << endl;

    
    return 0;
}