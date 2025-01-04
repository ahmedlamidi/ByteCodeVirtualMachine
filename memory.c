//
// Created by ahmed-lamidi on 1/4/25.
//
#include "memory.h"

void* reallocate(void *pointer, size_t oldSize, size_t newSize){
	if(newSize == 0){
		free(pointer);
		return NULL;
	}
	void* result = realloc(pointer, newSize);
	if (result == NULL) exit(1); // incase we do not have enough memory to allocate
	return result;
}
