#include "./Formater.hpp"
#include <sstream>
#include <iomanip>

std::string formatSensorOutput(double temperature, int pulseRate, int spo2) {
    std::ostringstream stream;
    stream << "{";
    stream << "\"Temperature\": {\"value\": " << std::fixed << std::setprecision(1) \
           << temperature << ", \"unit\": \"F\"}, ";
    stream << "\"PulseRate\": {\"value\": " << pulseRate << ", \"unit\": \"bpm\"}, ";
    stream << "\"Spo2\": {\"value\": " << spo2 << ", \"unit\": \"%\"}";
    stream << "}";
    return stream.str();
}
