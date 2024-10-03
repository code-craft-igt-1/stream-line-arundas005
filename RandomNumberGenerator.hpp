#pragma once
#include <random>

class RandomNumberGenerator {
 public:
    RandomNumberGenerator();
    int getRandomNumber(int min, int max);
    double getRandomNumber(double min, double max);
 private:
    std::default_random_engine m_generator;
};
