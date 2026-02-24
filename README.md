# Telemetry_Tracker

A hybrid C++/Python system telemetry platform for detecting crashes, stutters, and anomalous network behavior.

## Features
- Windows Event Log crash tracking
- Performance telemetry logging
- Process-level network monitoring
- SQLite time-series storage
- Python analysis and visualization

## Architecture
C++ collector → SQLite → Python analyzer

## Roadmap
- ETW kernel tracing
- Real-time GUI dashboard
- Remote telemetry agents
