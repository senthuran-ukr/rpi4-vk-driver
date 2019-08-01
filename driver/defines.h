#pragma once

#define UNUSED_VARIABLE(var) (void)var

#define ALLOC(size, alignment, scope) malloc(size)


#define ARRAY_SIZE(x, type) (sizeof(x) / sizeof(type))
