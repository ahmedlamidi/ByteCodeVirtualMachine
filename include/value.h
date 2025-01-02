//
// Created by ahmed-lamidi on 1/2/25.
//

#ifndef VALUE_H
#define VALUE_H

typedef double Value;

typedef struct {
	int capacity;
	int count;
	Value* values;
}ValueArray; // dynamic array of values

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
voud printValue(Value value);

#endif //VALUE_H
