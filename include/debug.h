//
// Created by ahmed-lamidi on 1/2/25.
//

#ifndef DEBUG_H
#define DEBUG_H
#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif //DEBUG_H
