#include "AllTypeStack.h"
#include <stdlib.h>

int** atStack = 0;
int sp = -1;
int stSize = 0;
int stLength = 0;

void createStack(int stackLength)
{
    *atStack = (int*)calloc(stackLength, sizeof(void*));
    stLength = stackLength;
}

void destroyStack()
{
    free(atStack);
    atStack = 0;
    sp = -1;
    stSize = 0;
}

int pop()
{
    int result;
    if(isEmpty())
    {
        return 0;
    }
    else 
    {
        result = atStack[sp];
        sp--;
        stSize--;
        return result;
    }
}

BOOL push(void* num)
{
    if(isFull()) {
        return FALSE;
    }
    else {
        sp++;
        stSize++;
        atStack[sp] = (void*)malloc(sizeof(num));
        atStack[sp] = *num;
        return TRUE;
    }
}

BOOL isEmpty()
{
    if(0 == stSize) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

BOOL isFull()
{
    if(stLength <= stSize) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}