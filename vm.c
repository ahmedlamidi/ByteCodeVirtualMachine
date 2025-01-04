

#include "common.h"
#include "vm.h"

#include <debug.h>
#include <stdio.h>

VM vm;
// we just need one global vm right now
// simplifies the code a lot

static void ResetStack()
{
	vm.stackTop = vm.stack;
}
void initVM()
{
	ResetStack();
	// we just move back to the start of the stack
	// no need to actually clear all the previous values
}

void freeVM()
{

}

InterpretResult interpret(Chunk *chunk)
{
	// essentially just putting the chunk and its code into the vm
	vm.chunk = chunk;
	vm.ip = chunk->code;
	// put the location of the start of the code into the instruction pointer
	return run();

}

static InterpretResult run()
{
#define READ_BYTE() (*vm.ip++) // this means that we return the pointer to the position of the code to be executed then increment
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()]) // we are going to find the correct value in the constants table
#define BINARY_OP(op) \
	do { \
	double b = pop(); \
	double a = pop(); \
	push(a op b); \
	} while (false)
	//  basically we just pop both of them and put the operation between them
	// using the do while loop to ensure that

	for (;;)
	{
#ifdef DEBUG_TRACE_EXECUTION
		printf("			");
		for (Value* slot = vm.stack; slot < vm.stackTop; slot++)
		{
			printf("[ ");
			printValue(*slot);
			printf("  ]");
			// every value in the stack , need to dereference
		}
		printf("\n");
		disassembleInstruction(vm.chunk, (int) (vm.ip - vm.chunk->code));
		// the dissassemble chunk takes an offset so we convert the address of the instruction pointer by subtracting the starting position
#endif

		uint8_t instruction;
		switch (instruction = READ_BYTE())
		{
			case OP_RETURN:
			// this is the end of the function being called so we can return that we Interpreted okay
			printValue(pop());
			return INTERPRET_OK;

			case OP_CONSTANT:

			Value constant = READ_CONSTANT();
			push(constant);
			printValue(constant);
			printf("\n");
			break;

			case OP_NEGATE:

				push(-pop());
				break;
				// simple as it seems we just add the negated value to the stack
				// need to add checks for when it is an empty stack
			case OP_ADD: BINARY_OP(+); break;
			case OP_SUBTRACT: BINARY_OP(-); break;
			case OP_DIVIDE: BINARY_OP(/); break;
			case OP_MULTIPLY: BINARY_OP(*); break;
		}
	}

#undef READ_BYTE // cleaning up this macro
#undef READ_CONSTANT
}

void push(Value value)
{
	*vm.stackTop = value;
	vm.stackTop++;
	// set then update
}

Value pop()
{
	vm.stackTop--; // we need to go to the actual value
	return *vm.stackTop;
	// assume it cannot be used anymore since we have moved down
}