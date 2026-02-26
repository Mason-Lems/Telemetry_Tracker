#include "sqlite_sink.h"
#include <iostream>

SQLiteSink::SQLiteSink(const char* path) {
    if (sqlite3_open(path, &db) != SQLITE_OK) {
        std::cerr << "Failed to open DB\n";
    }

    const char* create_sql =
        "CREATE TABLE IF NOT EXISTS metrics ("
        "timestamp INTEGER, "
        "source TEXT, "
        "name TEXT, "
        "value REAL);";
    
    sqlite3_exec(db, create_sql, nullptr, nullptr, nullptr);

    const char* insert_sql =
        "INSERT INTO metrics VALUES (?, ?, ?, ?);";

    sqlite3_prepare_v2(db, insert_sql, -1, &insert_stmt, nullptr);
}

SQLiteSink::~SQLiteSink() {
    sqlite3_finalize(insert_stmt);
    sqlite3_close(db);
}

void SQLiteSink::write_metric(const Metric& m) {
    sqlite3_bind_int64(insert_stmt, 1, m.timestamp_ns);
    sqlite3_bind_text(insert_stmt, 2, m.source.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(insert_stmt, 3, m.name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(insert_stmt, 4, m.value);

    sqlite3_step(insert_stmt);
    sqlite3_reset(insert_stmt);
}