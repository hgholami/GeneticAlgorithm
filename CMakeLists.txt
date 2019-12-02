cmake_minimum_required(VERSION 3.15)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticAlgorithm main.cpp city.hpp tour_population.cpp tour_population.hpp tour.cpp tour.hpp)