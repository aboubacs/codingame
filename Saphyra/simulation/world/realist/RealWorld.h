#pragma once // <ck:del>

#include <iostream>

#include "../../../util/macros.h"

template<
    typename CollisionUnits,
    typename CollisionType,
    typename MovableUnits,
    typename MovableType,
    typename SavableUnits,
    typename SavableType
>
class RealWorld {
public:
    RealWorld() {};

    void save() {
        auto size = m_savable_units.get_size();
        loop(i, size) {
            m_savable_units.get(i)->save();
        }
    }
    void rollback() {
        auto size = m_savable_units.get_size();
        loop(i, size) {
            m_savable_units.get(i)->rollback();
        }
    }

    void play() {
        float t = 0.f;
        auto size_collision = m_collision_units.get_size();
        auto size_movable = m_movable_units.get_size();
        bool previous_collision = false;
        uint32_t previous_unit_a;
        uint32_t previous_unit_b;
        while (t < 1.f) {
            float current_first_collision = 2.f;
            uint32_t first_collision_unit_a;
            uint32_t first_collision_unit_b;
            loop(i, size_collision) {
                for (int j = i; j < size_collision; j++) {
                    float collision_time =
                        m_collision_units.get(i)
                        ->collision_time(
                            m_collision_units.get(j)
                        );
                    if (collision_time >= 0) {
                        if (collision_time < current_first_collision) {
                            if (!previous_collision ||
                                i != previous_unit_a ||
                                j != previous_unit_b
                            ) {
                                current_first_collision = collision_time;
                                first_collision_unit_a = i;
                                first_collision_unit_b = j;
                            }
                        }
                    }
                }
            }
            if (current_first_collision > 1.f) {
                loop(i, size_movable) {
                    m_collision_units.get(i)
                        ->move(1.0 - t);
                    t = 1.0;
                }
            } else {
                previous_collision = true;
                previous_unit_a = first_collision_unit_a;
                previous_unit_b = first_collision_unit_b;
                loop(i, size_movable) {
                    m_movable_units.get(i)
                        ->move(current_first_collision - t);
                }
                m_collision_units.get(first_collision_unit_a)
                    ->bounce(
                        m_collision_units(first_collision_unit_b)
                    );
                t += current_first_collision;
            }
        }
    }

    CollisionUnits m_collision_units;
    MovableUnits m_movable_units;
    SavableUnits m_savable_units;
};
