#include <stdio.h>
#ifndef BITWISE_DATABASE_METHODS_H
#define BITWISE_DATABASE_METHODS_H

void writeFixedLength(struct Person person, FILE* fp);
struct Person readFixedLegnth(FILE *fp);
void writeVariableLength(struct Person person, FILE* fp);
struct Person readVariableLegnth(FILE *fp);
void printPerson(struct Person person);

#endif //BITWISE_DATABASE_METHODS_H
