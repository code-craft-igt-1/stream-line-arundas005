
#include <gtest/gtest.h>
#include <memory>
#include "./HealthParameterStub.hpp"
#include "./Formater.hpp"

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

TEST_F(HealthParameterStubTest, TestTemperatureSensor) {
    double temperature = healthParameterStub->getTemperatureInFarenheit();
    EXPECT_TRUE(95.0 <= temperature &&  105.0 >= temperature);
}

TEST_F(HealthParameterStubTest, TestPulseRateSensor) {
    int pulseRate = healthParameterStub->getPulseRateInBPM();
    EXPECT_TRUE(60 <= pulseRate && 140 >= pulseRate);
}

TEST_F(HealthParameterStubTest, TestSPO2Sensor) {
    int spo2 = healthParameterStub->getSpo2InPercentage();
    EXPECT_TRUE(90 <= spo2 && 100 >= spo2);
}

TEST_F(HealthParameterStubTest, TestDisplayTextFormat) {
    std::string formattedOutput = formatSensorOutput(97.0, 70, 95);
    std::string expectedOutput = 
        "{\"Temperature\": {\"value\": 97.0, \"unit\": \"F\"}, "
        "\"PulseRate\": {\"value\": 70, \"unit\": \"bpm\"}, "
        "\"Spo2\": {\"value\": 95, \"unit\": \"%\"}}";
    EXPECT_TRUE(expectedOutput.compare(formattedOutput) == 0);
}
