#pragma once

#define loop(i, end) for (int i = 0; i < end; i++)

#include <cstring>
#define COPY_ARRAY(dst, src) memcpy(dst, src, sizeof(dst));

#define MAX(a, b) (a>b?a:b)
#define MIN(a, b) (a>b?b:a)

#define POW2(expr) ((expr)*(expr))