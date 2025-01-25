#ifndef LOGGINGRESULT_HPP
#define LOGGINGRESULT_HPP

#include "LoggingEnums.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "SDK/nlohmann/json.hpp"  // Include the nlohmann JSON library

using json = nlohmann::json;

class LogObject {
private:
    json j;

public:
    // Constructor to initialize all members
    LogObject(int server_id, std::string server_name, std::string timestamp, long long unix_time,
                  std::string message, ETypes type, std::string post_status){
        j["server_id"] = server_id;
        j["server_name"] = server_name;
        j["timestamp"] = timestamp;
        j["unix_time"] = unix_time;
        j["message"] = message;
        j["warning_level"] = ETypesToString(type);
        j["post_status"] = post_status;
    }

    // Getters
    int get_server_id() const { return j["server_id"]; }
    const std::string& get_server_name() const { return j["server_name"]; }
    const std::string& get_timestamp() const { return j["timestamp"]; }
    long long get_unix_time() const { return j["unix_time"]; }
    const std::string& get_message() const { return j["message"]; }
    ETypes get_type() const { return stringToETypes(j["warning_level"].get<std::string>()); }
    const std::string& get_post_status() const { return j["post_status"]; }

    const json& get_json() const { return j; }
};

#endif