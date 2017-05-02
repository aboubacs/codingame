#pragma once

#include "../../util/Object.h"
#include "../../util/my_assert.h"

template<typename T, int size>
class CycleArray : public Object {
public:
    CycleArray() : Object() {
        iid = 0;
    }

    const T& get(int i) const {
        ASSERT(i >= 0);
        ASSERT(i < size);
        return m_data[i];
    }

    T& get_ref(int i) {
        ASSERT(i >= 0);
        ASSERT(i < size);
        return m_data[i];
    }

    T* get_pointer(int i) const {
        ASSERT(i >= 0);
        ASSERT(i < size);
        return &(m_data[size]);
    }

    void set_and_turn(const T& t) {
        this->set(iid, t);
        ++iid;
        if (iid == size) iid = 0;
    }

    void set(int i, const T& t) {
        ASSERT(i >= 0);
        ASSERT(i < size);
        m_data[i] = t;
    }

protected:
    T m_data[size];
    int iid;
};


