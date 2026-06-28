#include <gtest/gtest.h>
#include "linked_list.hpp"

TEST(DoublyLinkedListTest, PushFrontSingle)
{
    DoublyLinkedList<int> list;

    list.push_front(10);

    EXPECT_EQ(list.pop_front(), 10);
}

TEST(DoublyLinkedListTest, PushFrontMultiple)
{
    DoublyLinkedList<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 1);
}

TEST(DoublyLinkedListTest, PushBackSingle)
{
    DoublyLinkedList<int> list;

    list.push_back(5);

    EXPECT_EQ(list.pop_back(), 5);
}

TEST(DoublyLinkedListTest, PushBackMultiple)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.pop_back(), 3);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.pop_back(), 1);
}

TEST(DoublyLinkedListTest, PushFrontPushBack)
{
    DoublyLinkedList<int> list;

    list.push_front(2);
    list.push_front(1);
    list.push_back(3);
    list.push_back(4);

    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_front(), 4);
}

TEST(DoublyLinkedListTest, PopBackAfterPushFront)
{
    DoublyLinkedList<int> list;

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    EXPECT_EQ(list.pop_back(), 3);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.pop_back(), 1);
}

TEST(DoublyLinkedListTest, PopFrontEmptyThrows)
{
    DoublyLinkedList<int> list;

    EXPECT_THROW(list.pop_front(), std::runtime_error);
}

TEST(DoublyLinkedListTest, PopBackEmptyThrows)
{
    DoublyLinkedList<int> list;

    EXPECT_THROW(list.pop_back(), std::runtime_error);
}

TEST(DoublyLinkedListTest, FindExisting)
{
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_NE(list.find(20), nullptr);
}

TEST(DoublyLinkedListTest, FindMissing)
{
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.find(100), nullptr);
}

TEST(DoublyLinkedListTest, InsertAtFront)
{
    DoublyLinkedList<int> list;

    list.push_back(2);
    list.push_back(3);

    list.insert_at(0, 1);

    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 3);
}

TEST(DoublyLinkedListTest, InsertAtMiddle)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(3);

    list.insert_at(1, 2);

    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 3);
}

TEST(DoublyLinkedListTest, InsertAtEnd)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);

    list.insert_at(2, 3);

    EXPECT_EQ(list.pop_back(), 3);
}

TEST(DoublyLinkedListTest, InsertInvalidIndexThrows)
{
    DoublyLinkedList<int> list;

    list.push_back(1);

    EXPECT_THROW(list.insert_at(5, 10), std::out_of_range);
}

TEST(DoublyLinkedListTest, DeleteFront)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.delete_at(0);

    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 3);
}

TEST(DoublyLinkedListTest, DeleteMiddle)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.delete_at(1);

    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.pop_front(), 3);
}

TEST(DoublyLinkedListTest, DeleteBack)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.delete_at(2);

    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.pop_back(), 1);
}

TEST(DoublyLinkedListTest, DeleteInvalidIndexThrows)
{
    DoublyLinkedList<int> list;

    list.push_back(1);

    EXPECT_THROW(list.delete_at(3), std::out_of_range);
}

TEST(DoublyLinkedListTest, DeleteEmptyThrows)
{
    DoublyLinkedList<int> list;

    EXPECT_THROW(list.delete_at(0), std::out_of_range);
}

TEST(DoublyLinkedListTest, HasNoCycle)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_FALSE(list.hasCycle());
    EXPECT_FALSE(list.hasCycle2());
}

TEST(DoublyLinkedListTest, DetectCycle)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.makeCycle();

    EXPECT_TRUE(list.hasCycle());
    EXPECT_TRUE(list.hasCycle2());
}