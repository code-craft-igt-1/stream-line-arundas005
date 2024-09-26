#include "HealthParameterStub.hpp"

HealthParameterStub::HealthParameterStub( std::shared_ptr<RandomNumberGenerator> _pRandomNumberGenerator ) :
    m_pRandomNumberGenerator(_pRandomNumberGenerator) {
}

double HealthParameterStub::getTemperatureInFarenheit() {
    return m_pRandomNumberGenerator->getRandomNumber(95.0, 106.0);
}

int HealthParameterStub::getPulseRateInBPM() {
    return m_pRandomNumberGenerator->getRandomNumber(60, 140);
}

int HealthParameterStub::getSpo2InPercentage() {
    return m_pRandomNumberGenerator->getRandomNumber(90, 100);
}