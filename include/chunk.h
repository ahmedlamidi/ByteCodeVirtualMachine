//
// Created by ahmed-lamidi on 1/2/25.
//

#ifndef CHUNK_H
#define CHUNK_H
#include "common.h"
#include "value.h"

typedef enum{
  OP_CONSTANT,
  OP_RETURN,
}OPCode;
// so basically we just make OPCode a type and then the variables inside are instances of that type

typedef struct{
  int count;
  int capacity;
  uint8_t* code;
  ValueArray constants;
  int* lines;
} Chunk;
// same thing here we just made Chunk a struct which contains a list of unsigned 8 bit integers
// implement it as a dynamic array



void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line); // writing a byte into a chunk
void freeChunk(Chunk *chunk);
int addConstant(Chunk* chunk, Value value);
#endif //CHUNK_H
