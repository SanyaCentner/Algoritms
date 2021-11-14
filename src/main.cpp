//2_4. Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. Для каждого элемента
// массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
//Требования: Время работы поиска для каждого элемента B[i]: O(log(k)). Внимание! В этой задаче для каждого B[i]
//сначала нужно определить диапазон для бинарного поиска размером порядка k, а потом уже в нем делать бинарный поиск.

#include <iostream>
#include "func.h"

int main() {
//    int n = 0;
//    std::cin >> n;
//    int *A = new int[n];
//    for (int i = 0; i < n; ++i) {
//        std::cin >> A[i];
//    }
//    int m = 0;
//    std::cin >> m;
//    int *B = new int[m];
//    for (int i = 0; i < m; ++i) {
//        std::cin >> B[i];
//    }
    int n = 10;
    int m = 1;
    int A[] = {21, 30, 31, 41, 46, 56, 65, 71, 78, 87};
    int B[] = {35};
    for (int i = 0; i < m; ++i) {
        int k[2] = {};
        find_k(B[i], A, n, k);
        int search_result = binary(A, k[0], k[1], n, B[i]);
        std::cout << min_number(A, search_result, B[i], n) << " ";
    }
//    delete[] A;
//    delete[] B;
    return 0;
}