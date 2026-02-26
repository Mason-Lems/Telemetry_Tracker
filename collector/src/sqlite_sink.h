#pragma once
#include "common/telemetry_types.h"
#include <sqlite3.h>

class SQLiteSink {
public:
    SQLiteSink(const char* path);
    ~SQLiteSink();

    void write_metric(const Metric& m);

private:
    sqlite3* db;
    sqlite3_stmt* insert_stmt;
};