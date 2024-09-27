#include "./HealthParameterStub.hpp"
#include "./Formater.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    auto pRandomNumberGenerator = std::make_shared<RandomNumberGenerator>();
    HealthParameterStub healthParameterStub(pRandomNumberGenerator);
    int count  = 50;
    while (0 < count--) {
        std::cout << formatSensorOutput(healthParameterStub.getTemperatureInFarenheit(),
                   healthParameterStub.getPulseRateInBPM(),
                   healthParameterStub.getSpo2InPercentage()) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    return 0;
}
