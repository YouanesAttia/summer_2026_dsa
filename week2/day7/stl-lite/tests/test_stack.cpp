#include <gtest/gtest.h>
#include "stack.hpp"

TEST(StackTest, IsEmpty)
{
    Stack<int> st;
    EXPECT_TRUE(st.isEmpty());
}

TEST(StackTest, pushBackSingleElement)
{
    Stack<int> st;
    st.push(2);
    EXPECT_FALSE(st.isEmpty());
    EXPECT_EQ(st.stackTop(), 2);
}

TEST(StackTest, pushBackMultipleElements)
{
    Stack<int> st;
    st.push(2);
    st.push(3);
    st.push(6);
    EXPECT_FALSE(st.isEmpty());
    EXPECT_EQ(st.stackTop(), 6);
}

TEST(StackTest, PopElements)
{
    Stack<int> st;
    st.push(10);
    st.push(20);

    EXPECT_EQ(st.pop(), 20);
    EXPECT_EQ(st.stackTop(), 10);
    EXPECT_EQ(st.pop(), 10);
    EXPECT_TRUE(st.isEmpty());
}

TEST(StackTest, IsFull)
{
    Stack<int> st(2); // Stack of size 2
    st.push(1);
    EXPECT_FALSE(st.isFull());
    st.push(2);
    EXPECT_TRUE(st.isFull());
}

TEST(StackTest, PushOverflowThrowsException)
{
    Stack<int> st(1);
    st.push(100);
    EXPECT_THROW(st.push(200), std::out_of_range);
}

TEST(StackTest, PopUnderflowThrowsException)
{
    Stack<int> st;
    EXPECT_THROW(st.pop(), std::out_of_range);
}

TEST(StackTest, StackTopEmptyThrowsException)
{
    Stack<int> st;
    EXPECT_THROW(st.stackTop(), std::out_of_range);
}

TEST(StackTest, PeekFunctionality)
{
    Stack<int> st;
    st.push(10); // pos 3
    st.push(20); // pos 2
    st.push(30); // pos 1

    // According to your peek logic: index = top - pos + 1
    // top is 2.
    // pos 1: 2 - 1 + 1 = index 2 (Value 30)
    // pos 2: 2 - 2 + 1 = index 1 (Value 20)
    EXPECT_EQ(st.peek(1), 30);
    EXPECT_EQ(st.peek(2), 20);
    EXPECT_EQ(st.peek(3), 10);
}

TEST(StackTest, WorksWithStrings)
{
    Stack<std::string> st;
    st.push("Hello");
    st.push("World");
    EXPECT_EQ(st.pop(), "World");
    EXPECT_EQ(st.stackTop(), "Hello");
}
