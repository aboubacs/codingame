#pragma once // <ck:del>

#include <type_traits>

#include "../PlayerDecision.h"
#include "../../../../util/my_assert.h"
#include "../../../../util/Rand.h"

template<uint32_t nb_float>
class FloatPlayerDecision : public PlayerDecision {
    static_assert(
        nb_float > 0,
        "Number of float in the decision should be more than 0"
    );
public:
    FloatPlayerDecision() : PlayerDecision() {}

    void set(int i, float new_value) {
        ASSERT(new_value >= 0.f);
        ASSERT(new_value <= 1.f);
        m_data[i] = new_value;
    }

    float get(int i) const {
        ASSERT(i >= 0);
        ASSERT(i < nb_float);
        return m_data[i];
    }

    void randomize_one(int i) {
        m_data[i] = Rand::Double();
        ASSERT(m_data[i] >= 0);
        ASSERT(m_data[i] <= 1);
    }

    void randomize_all() {
        for (int i = 0; i < nb_float; i++) {
            randomize_one(i);
        }
    }

protected:
    float m_data[nb_float];

};

