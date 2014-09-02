#include "CppUTest\TestHarness.h"

extern "C"
{
#include "AllTypeStack.h"
}

TEST_GROUP(AllTypeStack)
{
    int size;
    void setup()
    {
        size = 10;
        createStack(size);
    }
    void teardown()
    {
        destroyStack();
    }
};

TEST(AllTypeStack, pop_fail_when_empty)
{
    CHECK_EQUAL(NULL, pop());
}

TEST(AllTypeStack, char_push_and_pop)
{
    push('a');
    push('b');
    push('c');
    CHECK_EQUAL('c', pop());
    CHECK_EQUAL('b', pop());
    CHECK_EQUAL('a', pop());
}

TEST(AllTypeStack, int_push_and_pop)
{
    push(1);
    push(2);
    push(3);
    CHECK_EQUAL(3, pop());
    CHECK_EQUAL(2, pop());
    CHECK_EQUAL(1, pop());
}

IGNORE_TEST(AllTypeStack, double_push_and_pop)
{
    push(11111111111111111111.1111111111);
    push(22222222222222222222.2222222222);
    push(33333333333333333333.3333333333);
    DOUBLES_EQUAL(33333333333333333333.3333333333, pop(), 0.0000000001);
    DOUBLES_EQUAL(22222222222222222222.2222222222, pop(), 0.0000000001);
    DOUBLES_EQUAL(11111111111111111111.1111111111, pop(), 0.0000000001);
}

TEST(AllTypeStack, push_fail_when_stack_is_full)
{
    for (int i = 0; i < size; i++) {
        push(100 + i);
    }
    CHECK_EQUAL(false, push(200));
}

TEST(AllTypeStack, pop_fail_when_stack_is_empty)
{
    for (int i = 0; i < size; i++) {
        push(100 + i);
    }
    for (int j = size; j > 0; j--) {
        CHECK_EQUAL(100 + j - 1, pop());
    }
    CHECK_EQUAL(false, pop());
}

IGNORE_TEST(AllTypeStack, test)
{
    CHECK_EQUAL(4, sizeof(void*));
}