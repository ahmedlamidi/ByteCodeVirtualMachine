//
// Created by ahmed-lamidi on 1/2/25.
//

#ifndef MEMORY_H
#define MEMORY_H
#include <stdlib.h>
#include "common.h"

#define GROW_CAPACITY(capacity) \
        ((capacity) < 8 ? 8 : (capacity *2))

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
        (type*)reallocate(pointer, sizeof(type) * oldCount, sizeof(type) * newCount)

#define FREE_ARRAY(type, pointer, oldCount) \
		reallocate(pointer, sizeof(type) * (oldCount), 0)


void* reallocate(void *pointer, size_t oldSize, size_t newSize){
    if(newSize == 0){
        free(pointer);
        return NULL;
    }
    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1); // incase we do not have enough memory to allocate
    return result;
}

// need to get many pointer types so we use void*

#endif //MEMORY_H
