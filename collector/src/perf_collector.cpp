#include "perf_collector.h"

Metric collect_cpu() {
    Metric m;
    m.timestamp_ns = now_fs();
    m.source = "perf_counter";
    m.name = "cpu_usage";
    m.value = 0; //TODO real CPU calc
    m.pid = -1;
    return m;
}