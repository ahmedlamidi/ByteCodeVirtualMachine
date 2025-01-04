//
// Created by ahmed-lamidi on 1/3/25.
//

#ifndef VM_H
#define VM_H


#include "chunk.h"

typedef struct {
	Chunk *chunk;
	uint8_t *ip; // instruction pointer
	// points to the instruction that is to be done // or the code that is to be executed
} VM; // The VM just contains the struct that it is responsible for running


typedef enum
{
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk *chunk);
static InterpretResult run();

#endif //VM_H
