#include "modifications.hpp"
#include <algorithm>
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
    vector<int> v1 = v;
    
    fill_seq(v.begin(), v.end(), 0);
    fill(v1.begin(), v1.end(), 0);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, generate_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {2, 7, 16, 14, 6, 15, 0, 4, 10, 13};

    mt19937 rng(42);

    // Fill the vector with random numbers between 0 and 99
    generate_seq(v.begin(), v.end(), [&rng]() {return rng() % 20;});
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, iter_swap_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = v;

    iter_swap_seq(v.begin(), v.end() - 1);
    iter_swap(v1.begin(), v1.end() - 1);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, partition_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = v;

    partition_seq(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    partition(v1.begin(), v1.end(), [](int i){ return i % 2 == 0; });
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, shuffle_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    mt19937 rng(42);
    shuffle_seq(v.begin(), v.end(), rng);
    shuffle_seq(v1.begin(), v1.end(), rng);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, remove_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = v;

    v.erase(remove_seq(v.begin(), v.end(), 5), v.end());
    v.erase(remove(v1.begin(), v1.end(), 5), v1.end());
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, replace_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1 = v;
    replace_seq(v.begin(), v.end(), 8, 11);
    replace(v1.begin(), v1.end(), 8, 11);
    ASSERT_EQ(v, v1);
}

TEST(TestUtils, unique_seq)
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    vector<int> v1 = v;
    v.erase(unique_seq(v.begin(), v.end()), v.end());
    v.erase(unique(v1.begin(), v1.end()), v1.end());
    ASSERT_EQ(v, v1);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}