//

#include <stdlib.h>
#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk) {
	chunk->count = 0; // set the count to 0
	chunk->capacity = 0;
	chunk->code = NULL;
	chunk->lines = NULL;
	chunk->line_start = 0;
	initValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
	if(chunk->capacity < chunk->count + 1) { // this is the dynamic allocation // amortized complexity of O(1)
		int oldCapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldCapacity);
  		chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
	}
	while (line - chunk -> line_start > chunk->line_capacity)
	{
		if (chunk -> line_start == 0)
		{
			chunk->line_start = line;
		}
		int oldCapacity = chunk->line_capacity;
		chunk->line_capacity = GROW_CAPACITY(oldCapacity);
		chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->line_capacity);
		for (int ind = oldCapacity; ind < chunk->line_capacity; ind++)
		{
			chunk->lines[ind] = 0;
			// initialize them all to zero
			// ensures that there is no data unclean in the array
			// should now be equal to line number
		}
		// this is to initiialize it and to make it the right size
	}
	chunk->code[chunk->count] = byte;
	chunk->lines[line - chunk->line_start] += 1;
	// compressed the line data
	// need to make sure they all start at 0
	chunk->count++;
  // count should point to the end of the chunk array
}

void freeChunk(Chunk* chunk){
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	freeValueArray(&chunk->constants);
	FREE_ARRAY(int, chunk->lines, chunk->capacity);
	initChunk(chunk);
}

int addConstant(Chunk* chunk, Value value)
{
	writeValueArray(&chunk->constants, value);
	return chunk->constants.count - 1;
	// this is the actual location of the value in the array
}
//
