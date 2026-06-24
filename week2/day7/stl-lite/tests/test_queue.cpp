#include <gtest/gtest.h>
#include "queue.hpp"

TEST(QueueTest, IsEmpty)
{
    Queue<int> q(5);
    EXPECT_TRUE(q.isempty());
    EXPECT_EQ(q.getsize(), 0);
}

TEST(QueueTest, EnqueueElements)
{
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    EXPECT_FALSE(q.isempty());
    EXPECT_EQ(q.getsize(), 2);
    EXPECT_EQ(q.front(), 10);
}

TEST(QueueTest, DequeueElements)
{
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);

    EXPECT_EQ(q.dequeue(), 10);
    EXPECT_EQ(q.front(), 20);
    EXPECT_EQ(q.dequeue(), 20);
    EXPECT_TRUE(q.isempty());
}

TEST(QueueTest, IsFull)
{
    Queue<int> q(2);
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_TRUE(q.isfull());
    EXPECT_THROW(q.enqueue(3), std::runtime_error);
}

TEST(QueueTest, UnderflowThrows)
{
    Queue<int> q(5);
    EXPECT_THROW(q.dequeue(), std::runtime_error);
}

TEST(QueueTest, CircularBehavior)
{
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    q.enqueue(4);

    EXPECT_EQ(q.getsize(), 3);
    EXPECT_EQ(q.front(), 2);

    q.dequeue();
    q.dequeue();
    EXPECT_EQ(q.getsize(), 1);
    EXPECT_EQ(q.front(), 4);
}

TEST(QueueTest, WorksWithStrings)
{
    Queue<std::string> q(5);
    q.enqueue("Hello");
    q.enqueue("World");
    EXPECT_EQ(q.dequeue(), "Hello");
    EXPECT_EQ(q.front(), "World");
}