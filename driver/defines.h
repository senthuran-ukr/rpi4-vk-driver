#pragma once

#define UNUSED_VARIABLE(var) (void)var

#define MEM_ALLOC(size, alignment, scope) malloc(size)
#define MEM_FREE(mem) free(mem)

#define ARRAY_SIZE(x, type) (sizeof(x) / sizeof(type))
