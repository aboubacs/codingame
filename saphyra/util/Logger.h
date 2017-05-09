#pragma once //<ck:del>

#include <ostream>
#include <iostream>

#include "my_assert.h"

using namespace std;

class Object;

class Logger
{
public:
    Logger(ostream& stream);
    Logger(Object* obj, ostream& stream);

    template<typename U>
    Logger& operator<< (const U& data) {
        ASSERT(m_object != nullptr);
        m_out_stream << data;
        return *this;
    }

private:
    ostream& m_out_stream;
    Object* m_object;
};


