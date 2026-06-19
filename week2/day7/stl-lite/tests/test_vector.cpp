#include <gtest/gtest.h>
#include "vector.hpp"

// Test 1: Check if a new vector is empty
TEST(VectorTest, IsEmptyInitially)
{
    Vector<int> vec;
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

// Test 2: Check pushing back a single element
TEST(VectorTest, PushBackSingleElement)
{
    Vector<int> vec;
    vec.push_back(10);
    EXPECT_FALSE(vec.empty());
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 10);
}

// Test 3: Check pushing back multiple elements
TEST(VectorTest, PushBackMultipleElements)
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

// Test 4: Check if capacity increases (resize logic)
TEST(VectorTest, CapacityIncreasesOnPush)
{
    Vector<int> vec;
    int initial_capacity = vec.capacity();

    // Push enough elements to force a resize
    for (int i = 0; i < initial_capacity + 5; ++i)
    {
        vec.push_back(i);
    }

    EXPECT_GT(vec.capacity(), initial_capacity); // Capacity should be Greater Than initial
}

// Test 5: Check pop_back functionality
TEST(VectorTest, PopBackReducesSize)
{
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.pop_back();

    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 5);
}

// Test 6: Check modifying existing elements
TEST(VectorTest, ModifyExistingElements)
{
    Vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);

    vec[0] = 500; // Overwrite
    EXPECT_EQ(vec[0], 500);
    EXPECT_EQ(vec[1], 200);
}

// Test 7: Check clearing the vector
TEST(VectorTest, ClearVector)
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.clear();

    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

// Test 8: Large volume stress test
TEST(VectorTest, StressTest)
{
    Vector<int> vec;
    for (int i = 0; i < 1000; ++i)
    {
        vec.push_back(i);
    }

    EXPECT_EQ(vec.size(), 1000);
    EXPECT_EQ(vec[999], 999);
}

// Test 9: Check copy constructor (if you wrote one!)
TEST(VectorTest, CopyConstructor)
{
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    Vector<int> vec2 = vec1; // Copy
    EXPECT_EQ(vec2.size(), 2);
    EXPECT_EQ(vec2[0], 1);

    // Ensure deep copy (changing vec2 doesn't affect vec1)
    vec2[0] = 99;
    EXPECT_EQ(vec1[0], 1);
    EXPECT_EQ(vec2[0], 99);
}

// Test 10: Store strings instead of ints (tests template functionality)
TEST(VectorTest, WorksWithStrings)
{
    Vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("world");

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], "hello");
    EXPECT_EQ(vec[1], "world");
}