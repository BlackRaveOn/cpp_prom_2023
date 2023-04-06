#include "modifications.hpp"
#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class TestFoo : public ::testing::Test
{
protected:
    void SetUp() {}
    void TearDown() {}
};

TEST(TestUtils, fill_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    fill_seq(v.begin(), v.end(), 0);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, generate_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {42, 67, 76, 14, 26, 35, 20, 24, 50, 13};

    mt19937 rng(42);

    // Fill the vector with random numbers between 0 and 99
    generate_seq(v.begin(), v.end(), [&rng]() { return rng() % 100; });
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, iter_swap_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {10, 2 , 3, 4, 5, 6, 7, 8, 9, 1};

    iter_swap_seq(v.begin(), v.end() - 1);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, partition_seq)
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {10, 2, 8, 4, 6, 5, 7, 3, 9, 1};

    partition_seq(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, shuffle_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {9, 8, 7, 10, 2, 6, 3, 1, 4, 5};
    
    mt19937 rng(42);
    shuffle_seq(v.begin(), v.end(), rng);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, remove_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {1, 2, 3, 4, 6, 7, 8, 9, 10};

    v.erase(remove_seq(v.begin(), v.end(), 5), v.end());
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, replace_seq)
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 11, 9, 10};
    replace_seq(v.begin(), v.end(), 8, 11);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, unique_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    v.erase(unique_seq(v.begin(), v.end()), v.end());
    ASSERT_EQ(v, v1);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}