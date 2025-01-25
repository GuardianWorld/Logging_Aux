#ifndef LOGGINGENUMS_HPP
#define LOGGINGENUMS_HPP

#include <string>

enum class ETypes {
    Normal,    // Normal operation
    Warning,   // Minor problem
    Error,     // Something went very badly, but program can recover
    Critical,   // Program will close. Failure to work
    Unknown   // Unknown type
};

// A helper function to convert ETypes to string
constexpr const char* ETypesToString(ETypes type) {
    switch (type) {
        case ETypes::Normal: return "NORMAL";
        case ETypes::Warning: return "WARNING";
        case ETypes::Error: return "ERROR";
        case ETypes::Critical: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

constexpr ETypes stringToETypes(const std::string& str) {
    if (str == "NORMAL") return ETypes::Normal;
    if (str == "WARNING") return ETypes::Warning;
    if (str == "ERROR") return ETypes::Error;
    if (str == "CRITICAL") return ETypes::Critical;
    return ETypes::Unknown; // Default
}

#endif 