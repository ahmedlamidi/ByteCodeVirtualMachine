

#include "common.h"
#include "vm.h"

#include <debug.h>
#include <stdio.h>

VM vm;
// we just need one global vm right now
// simplifies the code a lot

void initVM()
{

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

	for (;;)
	{
#ifdef DEBUG_TRACE_EXECUTION
		disassembleInstruction(vm.chunk, (int) (vm.ip - vm.chunk->code));
		// the dissassemble chunk takes an offset so we convert the addrees of the instruction pointer by subtracting the starting position
#endif

		uint8_t instruction;
		switch (instruction = READ_BYTE())
		{
		case OP_RETURN:
		{
			// this is the end of the function being called so we can return that we Interpreted okay
			return INTERPRET_OK;
		}
		case OP_CONSTANT:{
			Value constant = READ_CONSTANT();
			printValue(constant);
			printf("\n");
			break;
		}
		}
	}

#undef READ_BYTE // cleaning up this macro
#undef READ_CONSTANT
}