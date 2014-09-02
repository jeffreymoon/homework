#ifndef ALLTYPESTACK_H
#define ALLTYPESTACK_H

typedef enum tagBOOL {
    FALSE = 0,
    TRUE = 1
} BOOL;

typedef struct tagNode {
    int data;
} Node;

typedef struct tagStack {
    int capacity;
    int sp;
    Node* Nodes;
} Stack;

void createStack(Stack**, int);
void destroyStack(Stack*);
int pop(Stack*);
BOOL push(Stack*, int);

#endif