#include "./data_processor.h"
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <deque>
#include <limits>

using std::cout;
using std::endl;
using std::string;

double extractValue(const string& jsonString, const std::regex& pattern, const string& label) {
    std::smatch match;
    if (std::regex_search(jsonString, match, pattern) && match.size() > 1) {
        return std::stod(match.str(1));
    }
    else {
        cout << label << " not found!" << endl;
        return std::numeric_limits<double>::quiet_NaN();  // Return NaN if not found
    }
}

std::vector<double> extractSensorData(string jsonString) {
    std::vector<double> data;

    // Define patterns
    std::regex temperaturePattern(R"("Temperature":\s*\{"value":\s*([\d.]+))");
    std::regex pulseRatePattern(R"("PulseRate":\s*\{"value":\s*([\d.]+))");
    std::regex spo2Pattern(R"("Spo2":\s*\{"value":\s*([\d.]+))");

    // Extract values using the helper function
    data.push_back(extractValue(jsonString, temperaturePattern, "Temperature"));
    data.push_back(extractValue(jsonString, pulseRatePattern, "Pulse Rate"));
    data.push_back(extractValue(jsonString, spo2Pattern, "SpO2"));

    return data;
}

void printStatistics(const std::deque<double>& values, const std::string& label) {
    if (values.empty()) return;

    double maxVal = *std::max_element(values.begin(), values.end());
    double minVal = *std::min_element(values.begin(), values.end());
    double sum = 0.0;
    for (double value : values) {
        sum += value;
    }
    double movingAvg = sum / values.size();

    cout << label << " - Max: " << maxVal << ", Min: " << minVal
        << ", Moving Average (last " << values.size() << " values): "
        << movingAvg << endl;
}

void addValue(std::deque<double>& values, double value) {
    values.push_back(value);
    if (values.size() > 5) {
        values.pop_front();
    }
}

void processInputLine(const string& line,
    std::deque<double>& temperatures,
    std::deque<double>& pulseRates,
    std::deque<double>& spo2s) {
    std::vector<double> output = extractSensorData(line);
    if (output.size() >= 3) {
        addValue(temperatures, output[0]);
        addValue(pulseRates, output[1]);
        addValue(spo2s, output[2]);

        printStatistics(temperatures, "Temperature");
        printStatistics(pulseRates, "Pulse Rate");
        printStatistics(spo2s, "SpO2");
    }
    else {
        cout << "No complete values extracted." << endl;
    }
}

int main() {
    string line;
    std::deque<double> temperatures;
    std::deque<double> pulseRates;
    std::deque<double> spo2s;

    // Read input data (from pipe)
    while (std::getline(std::cin, line)) {
        processInputLine(line, temperatures, pulseRates, spo2s);
    }

    return 0;
}
