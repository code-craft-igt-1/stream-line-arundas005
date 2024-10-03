#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <vector>
#include <regex>
#include <string>
#include <deque>

double extractValue(const std::string& jsonString, const std::regex& pattern, const std::string& label);

std::vector<double> extractSensorData(std::string jsonString);

void printStatistics(const std::deque<double>& values, const std::string& label);

void addValue(std::deque<double>& values, double value);

void processInputLine(const std::string& line,
    std::deque<double>& temperatures,
    std::deque<double>& pulseRates,
    std::deque<double>& spo2s);

#endif // DATA_PROCESSOR_H
