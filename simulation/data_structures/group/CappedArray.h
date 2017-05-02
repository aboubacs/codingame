#pragma once //<ck:del>

#include <iostream>
#include <cstring>

#include "AbstractGroup.h"
#include "../../../util/my_assert.h"

template<typename T, uint32_t S>
class CappedArray : public AbstractGroup<T> {
    friend class CappedArray_test;
public:
    CappedArray() : AbstractGroup<T>() {
        clear();
    }
    CappedArray(const string& name) : AbstractGroup<T>(name) {
        clear();
    }
    void push(const T& t) {
        if (m_current_size < S) {
            m_data[m_current_size] = t;
            ++m_current_size;
        }
#ifdef LOG_GROUP_ARRAY_MAX_SIZE_ERRORS
        if (m_current_size >= S) {
#ifdef OBJECT_PROPERTIES
            //this->obj_logger << "Pushing in full array (" << S << "). Abort." << endl;
#else
            cerr << "Pushing in full array (" << S << "). Abort." << endl;
#endif
        }
#endif
    }
    void clear() {
        m_current_size = 0;
    }
    T& get(int i)  {
        ASSERT(i < m_current_size);
        ASSERT(i >= 0);
        return m_data[i];
    }

    void remove(int i) {
        ASSERT(i >= 0);
        ASSERT((m_current_size - i - 1) >= 0);
        memmove(m_data+i, m_data+i+1, sizeof(T)*(m_current_size-i-1));
        m_current_size--;
    }

    uint32_t get_size() const {
        return m_current_size;
    }

protected:
    T m_data[S];
    uint32_t m_current_size;
};


