#include "common/telemetry_types.h"
#include "perf_collector.h"
#include "sqlite_sink.h"

int main() {
    SQLiteSink sink("../data/telemetry01.db");
    while(1) {
        Metric m = collect_cpu();
        sink.write_metric(m);
        Sleep(1000);
    };
}