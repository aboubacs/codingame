#pragma once //<ck:del>

#include <assert.h>

#include "../config/config.h"

#ifdef PERFORM_ASSERTS
#define ASSERT(expr) assert(expr)
#else
#define ASSERT(expr) ;
#endif
