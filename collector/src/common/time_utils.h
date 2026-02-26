#pragma once
#include <windows.h>

inline long long now_fs() {
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (counter.QuadPart * 1'000'000'000LL) / freq.QuadPart;
};