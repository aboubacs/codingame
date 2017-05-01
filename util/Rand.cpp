#include "Rand.h"

unsigned int Rand::g_seed = 42;

Rand::Rand(){}

inline int Rand::rand() {
    Rand::g_seed = (214013*Rand::g_seed+2531011);
    return (Rand::g_seed>>16)&0x7FFF;
}

inline int Rand::Int(int maxSize) {
    return Rand::rand() % maxSize;
}

inline int Rand::Int(int a, int b) {
    return(a + Rand::Int(b - a));
}

inline double Rand::Double() {
    return static_cast<double>(Rand::rand()) / 0x7FFF;
}

inline double Rand::Double(double a, double b) {
    return a + (static_cast<double>(Rand::rand()) / 0x7FFF)*(b-a);
}