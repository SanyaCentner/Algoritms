#include "gtest/gtest.h"
#include "func.h"

TEST(test, test1) {
int n = 3;
int m = 3;
int A[] = {10, 20, 30};
int B[] = {9, 15, 35};

int k_range[2];
std::string result;
for (int i = 0; i < m; ++i) {
find_k(B[i], A, n, k_range);
int search_result = binary(A, k_range[0], k_range[1], n, B[i]);
result += std::to_string(min_number(A, search_result, B[i], n)) + " ";
}
ASSERT_EQ("0 0 2 ", result);
}

TEST(test, test2) {
int n = 3;
int m = 4;
int A[] = {10, 20, 30};
int B[] = {8, 9, 10, 32};

int k_range[2];
std::string result;
for (int i = 0; i < m; ++i) {
find_k(B[i], A, n, k_range);
int search_result = binary(A, k_range[0], k_range[1], n, B[i]);
result += std::to_string(min_number(A, search_result, B[i], n)) + " ";
}
ASSERT_EQ("0 0 0 2 ", result);
}

TEST(test, test3) {
int n = 10;
int m = 1;
int A[] = {21, 30, 31, 41, 46, 56, 65, 71, 78, 87};
int B[] = {35};

int k_range[2];
std::string result;
for (int i = 0; i < m; ++i) {
find_k(B[i], A, n, k_range);
int search_result = binary(A, k_range[0], k_range[1], n, B[i]);
result += std::to_string(min_number(A, search_result, B[i], n)) + " ";
}
ASSERT_EQ("2 ", result);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

