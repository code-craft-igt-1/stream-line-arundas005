#include <gtest/gtest.h>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include "./data_processor.h" 

TEST(ExtractSensorDataTest, ValidInput) {
    std::string jsonString = R"({"Temperature": {"value": 104.9, "unit": "F"}, "PulseRate": {"value": 108, "unit": "bpm"}, "Spo2": {"value": 97, "unit": "%"}})";
    auto result = extractSensorData(jsonString);

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], 104.9);
    EXPECT_DOUBLE_EQ(result[1], 108);
    EXPECT_DOUBLE_EQ(result[2], 97);
}

TEST(ExtractSensorDataTest, MissingTemperature) {
    std::string jsonString = R"({"PulseRate": {"value": 108, "unit": "bpm"}, "Spo2": {"value": 97, "unit": "%"}})";
    auto result = extractSensorData(jsonString);

    ASSERT_EQ(result.size(), 2);
    EXPECT_DOUBLE_EQ(result[0], 108);
    EXPECT_DOUBLE_EQ(result[1], 97);
}

// Helper function to validate sensor data extraction
void validateSensorDataExtraction(const std::string& jsonString, const std::vector<double>& expectedValues) {
    auto result = extractSensorData(jsonString);
    ASSERT_EQ(result.size(), expectedValues.size());
    for (size_t i = 0; i < expectedValues.size(); ++i) {
        EXPECT_DOUBLE_EQ(result[i], expectedValues[i]);
    }
}

TEST(ExtractSensorDataTest, MissingPulseRate) {
    std::string jsonString = R"({"Temperature": {"value": 104.9, "unit": "F"}, "Spo2": {"value": 97, "unit": "%"}})";
    validateSensorDataExtraction(jsonString, { 104.9, 97 });
}

TEST(ExtractSensorDataTest, MissingSpo2) {
    std::string jsonString = R"({"Temperature": {"value": 104.9, "unit": "F"}, "PulseRate": {"value": 108, "unit": "bpm"}})";
    validateSensorDataExtraction(jsonString, { 104.9, 108 });
}

// main function for running tests is provided by Google Test
