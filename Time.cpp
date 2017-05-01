#include "Time.h"

Time::Time() {

}
void Time::set_checkpoint() {
    m_checkpoint_time = high_resolution_clock::now();
}
bool Time::is_elapsed(double time) {
    return (
        duration_cast<duration<double>> (
            high_resolution_clock::now() - m_checkpoint_time
        ).count() >= time
    );
}