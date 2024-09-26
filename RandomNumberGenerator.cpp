#include "RandomNumberGenerator.hpp"

RandomNumberGenerator::RandomNumberGenerator() {
    std::random_device rd;
    m_generator = std::default_random_engine(rd());
}

int RandomNumberGenerator::getRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(m_generator);
}

double RandomNumberGenerator::getRandomNumber(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(m_generator);
}