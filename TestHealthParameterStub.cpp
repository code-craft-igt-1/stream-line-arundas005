
#include <gtest/gtest.h>
#include <memory>
#include "HealthParameterStub.hpp"

class HealthParameterStubTest : public ::testing::Test {
protected:
    std::unique_ptr<HealthParameterStub> healthParameterStub;
    void SetUp() override {
        auto pRandomNumberGenerator = std::make_shared<RandomNumberGenerator>();
        healthParameterStub = std::make_unique<HealthParameterStub>(pRandomNumberGenerator);
    }

    void TearDown() override {
        // Clean up any necessary data here
    }
};

TEST_F(HealthParameterStubTest, TestVitalsSimulator) {
    // Assuming HealthParameterStub has some default values to check
    double temperature = healthParameterStub->getTemperatureInFarenheit();
    int pulseRate = healthParameterStub->getPulseRateInBPM();
    int spo2 = healthParameterStub->getSpo2InPercentage();
    EXPECT_TRUE(95.0 <= temperature &&  105.0 >= temperature);
    EXPECT_TRUE(60 <= pulseRate && 140 >= pulseRate);
    EXPECT_TRUE(90 <= spo2 && 100 >= spo2);
}
