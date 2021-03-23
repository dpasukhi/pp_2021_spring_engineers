// Copyright 2021 Solomakhin Sergey
#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "./hoar_sort_simple_merge.h"

TEST(randomgen, run) {
    ASSERT_NO_THROW(random_gen(100));
}

TEST(randomgen, wrongsize) {
    ASSERT_ANY_THROW(random_gen(-100));
}

TEST(hoarsort, runwithoutexceptionswithsize10) {
    auto vect = random_gen(10);
    ASSERT_NO_THROW(hoar_sort(vect, 0, 9));
}

TEST(hoarsort, runwithoutexceptionswithsize_100) {
    auto vect = random_gen(100);
    ASSERT_NO_THROW(hoar_sort(vect, 0, 99));
}

TEST(hoarsort, run_withoutexceptionswithsize1000) {
    auto vect = random_gen(1000);
    ASSERT_NO_THROW(hoar_sort(vect, 0, 999));
}

TEST(hoarsort, runwithsize10) {
    auto vect = random_gen(10);
    auto sorted = hoar_sort(vect, 0, 9);
    std::sort(vect.begin(), vect.end());
    ASSERT_EQ(vect, sorted);
}

TEST(hoarsort, runwithsize100) {
    auto vect = random_gen(100);
    auto sorted = hoar_sort(vect, 0, 99);
    std::sort(vect.begin(), vect.end());
    ASSERT_EQ(vect, sorted);
}

TEST(hoarsort, runrandomsize1000) {
    auto vect = random_gen(1000);
    auto sorted = hoar_sort(vect, 0, 999);
    std::sort(vect.begin(), vect.end());
    ASSERT_EQ(vect, sorted);
}

TEST(merging, runwithsize10tosize20) {
    auto vect_a = random_gen(10);
    auto vect_b = random_gen(10);
    vect_a = hoar_sort(vect_a, 0, 9);
    vect_b = hoar_sort(vect_b, 0, 9);
    auto merged = merge(vect_a, vect_b);
    for (int i = 0; i < static_cast<int>(vect_a.size()) - 1; ++i) {
        ASSERT_TRUE(merged[i] <= merged[i + 1]);
    }
}

TEST(merging, runwithsize100tosize200) {
    auto vect_a = random_gen(100);
    auto vect_b = random_gen(100);
    vect_a = hoar_sort(vect_a, 0, 99);
    vect_b = hoar_sort(vect_b, 0, 99);
    auto merged = merge(vect_a, vect_b);
    for (int i = 0; i < static_cast<int>(vect_a.size()) - 1; ++i) {
        ASSERT_TRUE(merged[i] <= merged[i + 1]);
    }
}

TEST(merging, runwithsize1000tosize2000) {
    auto vect_a = random_gen(1000);
    auto vect_b = random_gen(1000);
    vect_a = hoar_sort(vect_a, 0, 999);
    vect_b = hoar_sort(vect_b, 0, 999);
    auto merged = merge(vect_a, vect_b);
    for (int i = 0; i < static_cast<int>(vect_a.size()) - 1; ++i) {
        ASSERT_TRUE(merged[i] <= merged[i + 1]);
    }
}



int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
