#ifndef ALLTYPESTACK_H
#define ALLTYPESTACK_H

typedef enum BOOL_t {
    FALSE = 0,
    TRUE = 1
} BOOL;

void createStack(int);
void destroyStack();
int pop();
BOOL push(int);

#endif