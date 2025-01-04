//
// Created by ahmed-lamidi on 1/3/25.
//

#ifndef VM_H
#define VM_H


#include "chunk.h"
#define STACK_MAX 256 // we want to keep 256 values in the stack for now

typedef struct {
	Chunk *chunk;
	uint8_t *ip; // instruction pointer
	Value stack[STACK_MAX];
	Value* stackTop; // pointer to the top of the stack // the one after the last filled part of the stack
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
static void ResetStack();
void push(Value value);
Value pop();
#endif //VM_H
