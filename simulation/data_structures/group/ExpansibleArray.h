#pragma once //<ck:del>

#include <vector>

#include "CappedArray.h"

template<typename T, uint32_t S>
class ExpansibleArray : public CappedArray<T,S> {
    friend class ExpansibleArray_test;
public:
    ExpansibleArray() : CappedArray<T, S>() {}
    ExpansibleArray(const string& name) : CappedArray<T, S>(name) {}

    void push(const T& t) {
        if (is_static_full()) {
            m_dynamic_data.push_back(t);
        } else {
            this->m_data[this->m_current_size] = t;
            ++(this->m_current_size);
        }
    }

    void clear() {
        this->m_current_size = 0;
        m_dynamic_data.clear();
    }

    T& get(int i) {
        ASSERT(i >= 0);
        if (i < S) {
            ASSERT(i < this->m_current_size);
            return this->m_data[i];
        } else {
            ASSERT(i < S+m_dynamic_data.size());
            return m_dynamic_data[i-S];
        }
    }

    void remove(int i) {
        ASSERT(i >= 0);
        if (is_static_full()) {
            if (i < S) {
                memmove(
                        this->m_data + i,
                        this->m_data + i + 1,
                        sizeof(T) * (this->m_current_size - i - 1)
                );
                if (m_dynamic_data.size() > 0) {
                    this->m_data[S-1] = m_dynamic_data[0];
                    this->m_dynamic_data.erase(this->m_dynamic_data.begin());
                } else {
                    ASSERT(this->m_current_size == S);
                    this->m_current_size--;
                }
            } else {
                ASSERT(i < S+m_dynamic_data.size());
                this->m_dynamic_data.erase(this->m_dynamic_data.begin()+(i-S));
            }
        } else {
            ASSERT((this->m_current_size - i - 1) >= 0);
            memmove(
                this->m_data + i,
                this->m_data + i + 1,
                sizeof(T) * (this->m_current_size - i - 1)
            );
            this->m_current_size--;
        }
    }

    uint32_t get_size() const {
        return this->m_current_size + static_cast<uint32_t>(m_dynamic_data.size());
    }

protected:
    bool is_static_full() {
        ASSERT(this->m_current_size <= S);
        return this->m_current_size == S;
    }
    vector<T> m_dynamic_data;
};


