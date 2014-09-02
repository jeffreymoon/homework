#include "CppUTest\TestHarness.h"

extern "C"
{
#include "AllTypeStack.h"
}

TEST_GROUP(AllTypeStack)
{
    int size;
    Stack* atStack;
    void setup()
    {
        size = 10;
        createStack(&atStack, size);
    }
    void teardown()
    {
        destroyStack(atStack);
    }
};

TEST(AllTypeStack, pop_fail_when_empty)
{
    CHECK_EQUAL(NULL, pop(atStack));
}

TEST(AllTypeStack, char_push_and_pop)
{
    push(atStack, 'a');
    push(atStack, 'b');
    push(atStack, 'c');
    CHECK_EQUAL('c', pop(atStack));
    CHECK_EQUAL('b', pop(atStack));
    CHECK_EQUAL('a', pop(atStack));
}

TEST(AllTypeStack, int_push_and_pop)
{
    push(atStack, 1);
    push(atStack, 2);
    push(atStack, 3);
    CHECK_EQUAL(3, pop(atStack));
    CHECK_EQUAL(2, pop(atStack));
    CHECK_EQUAL(1, pop(atStack));
}

IGNORE_TEST(AllTypeStack, double_push_and_pop)
{
    push(atStack, 11111111111111111111.1111111111);
    push(atStack, 22222222222222222222.2222222222);
    push(atStack, 33333333333333333333.3333333333);
    DOUBLES_EQUAL(33333333333333333333.3333333333, pop(atStack), 0.0000000001);
    DOUBLES_EQUAL(22222222222222222222.2222222222, pop(atStack), 0.0000000001);
    DOUBLES_EQUAL(11111111111111111111.1111111111, pop(atStack), 0.0000000001);
}

TEST(AllTypeStack, push_fail_when_stack_is_full)
{
    for (int i = 0; i < size; i++) {
        push(atStack, 100 + i);
    }
    CHECK_EQUAL(false, push(atStack, 200));
}

TEST(AllTypeStack, pop_fail_when_stack_is_empty)
{
    for (int i = 0; i < size; i++) {
        push(atStack, 100 + i);
    }
    for (int j = size; j > 0; j--) {
        CHECK_EQUAL(100 + j - 1, pop(atStack));
    }
    CHECK_EQUAL(false, pop(atStack));
}

IGNORE_TEST(AllTypeStack, test)
{
    CHECK_EQUAL(4, sizeof(void*));
}