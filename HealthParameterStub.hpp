#pragma once
#include <memory>
#include "./RandomNumberGenerator.hpp"

class HealthParameterStub {
    public:
        explicit HealthParameterStub(std::shared_ptr<RandomNumberGenerator>);
        double getTemperatureInFarenheit();
        int getPulseRateInBPM();
        int getSpo2InPercentage();
    private:
        std::shared_ptr<RandomNumberGenerator> m_pRandomNumberGenerator;
};
