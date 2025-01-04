
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char *argv[]){
	initVM();
	Chunk chunk;
	initChunk(&chunk);
	writeChunk(&chunk, OP_RETURN, 123);

	disassembleChunk(&chunk, "test chunk");

	interpret(&chunk);
	// passing this chunk into the vm
	freeChunk(&chunk);
	freeVM();
	// basic use of all the functions so far
  }