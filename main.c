
#include "include/common.h"
#include "include/chunk.h"
#include "include/debug.h"

int main(int argc, char *argv[]){
	Chunk chunk;
	initChunk(&chunk);
	writeChunk(&chunk, OP_RETURN);
	freeChunk(&chunk);
	// basic use of all the functions so far
  }