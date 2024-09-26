#pragma once
#include "RandomNumberGenerator.hpp"
#include <memory>

class HealthParameterStub {
    public:
        HealthParameterStub(std::shared_ptr<RandomNumberGenerator>);
        double getTemperatureInFarenheit();
        int getPulseRateInBPM();
        int getSpo2InPercentage();
    private:
        std::shared_ptr<RandomNumberGenerator> m_pRandomNumberGenerator;
};