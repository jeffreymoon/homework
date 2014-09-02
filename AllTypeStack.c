#include "AllTypeStack.h"
#include <stdlib.h>


void createStack(Stack** stack, int capacity)
{
    (*stack) = (Stack*)malloc(sizeof(Stack));
    (*stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity);
    (*stack)->capacity = capacity;
    (*stack)->sp = 0;
}

void destroyStack(Stack* stack)
{
    free(stack->Nodes);
    free(stack);
}

int pop(Stack* stack)
{
    int result;
    if(isEmpty(stack))
    {
        return 0;
    }
    else 
    {
        (stack->sp)--;
        result = (stack->Nodes)[stack->sp].data;
        return result;
    }
}

BOOL push(Stack* stack, int num)
{
    if(isFull(stack)) {
        return FALSE;
    }
    else {
        (stack->Nodes)[stack->sp].data = num;
        (stack->sp)++;
        return TRUE;
    }
}

BOOL isEmpty(Stack* stack)
{
    if(0 == stack->sp) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

BOOL isFull(Stack* stack)
{
    if(stack->capacity <= stack->sp) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}