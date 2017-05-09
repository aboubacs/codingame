#include "Rand.h"

namespace Rand {

    unsigned int g_seed = 42;

    int rand() {
        Rand::g_seed = (214013 * Rand::g_seed + 2531011);
        return (Rand::g_seed >> 16) & 0x7FFF;
    }

    int Int(int maxSize) {
        return Rand::rand() % maxSize;
    }

    int Int(int a, int b) {
        return (a + Rand::Int(b - a));
    }

    double Double() {
        return static_cast<double>(Rand::rand()) / 0x7FFF;
    }

    double Double(double a, double b) {
        return a + (static_cast<double>(Rand::rand()) / 0x7FFF) * (b - a);
    }

    float Float() {
        return (Rand::rand()) / 0x7FFF;
    }

    float Float(float a, float b) {
        return a + (Rand::rand() / 0x7FFF) * (b - a);
    }

}