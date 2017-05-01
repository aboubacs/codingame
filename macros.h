#pragma once

#define loop(i, end) for (int i = 0; i < end; i++)

#include <cstring>
#define COPY_ARRAY(dst, src) memcpy(dst, src, sizeof(dst));