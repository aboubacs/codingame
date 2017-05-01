#include "Time.h"

Time::Time() {

}
void Time::set_checkpoint() {
    m_checkpoint_time = high_resolution_clock::now();
}

bool Time::is_elapsed(double time) {
    return get_time_left(time) <= 0;
}

double Time::get_time_left(double time) const {
    return (
        time - duration_cast<duration<double>> (
            NOW - m_checkpoint_time
        ).count()
    );
}