#pragma once //<ck:del>

#include "Object.h"

template<typename T>
class AbstractGroup : public Object {
public:
    AbstractGroup() : Object() {}
    AbstractGroup(const string& name) : Object(name) {};
    virtual void push(const T&)=0;
    virtual void clear()=0;
    virtual T& get(int i) =0;
    virtual void remove(int i)=0;
    virtual uint32_t get_size() const =0;
};


