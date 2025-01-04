
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char *argv[]){
	initVM();
	Chunk chunk;
	initChunk(&chunk);
	// writeChunk(&chunk, 100, 123);
	int constant = addConstant(&chunk, 2);
	writeChunk(&chunk, OP_CONSTANT, 123);
	writeChunk(&chunk, constant, 123);
	writeChunk(&chunk, OP_NEGATE, 123);
	writeChunk(&chunk, OP_RETURN, 123);
	// disassembleChunk(&chunk, "test chunk");
	interpret(&chunk);
	// passing this chunk into the vm
	freeChunk(&chunk);
	freeVM();
	// basic use of all the functions so far
  }