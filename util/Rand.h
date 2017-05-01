#pragma once

class Rand {
public:
    static inline int rand();
    static inline int Int(int maxSize);
    static inline int Int(int a, int b);
    static inline double Double();
    static inline double Double(double a, double b);

private:
    static unsigned int g_seed;
    Rand();
};
