#pragma once
#include <string>

struct Metric {
    long long timestamp_ns;
    std::string source; // perf_counter, event_log, network
    std::string name; // cpu_usage, disk_latency
    double value;
    int pid;
};

struct Event {
    long long timestamp_ns;
    std::string source;
    std::string type; // crash, warning, error
    std::string message;
    std::string process;
    int pid;
};