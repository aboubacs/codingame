#include "Logger.h"

Logger::Logger(ostream& stream) : m_out_stream(stream) {
    m_object = nullptr;
}

Logger::Logger(Object* obj, ostream& stream): m_out_stream(stream) {
    m_object = obj;
}

