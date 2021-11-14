

#include "func.h"
#include <cmath>

void find_k(const int elem, const int *mas, int count, int k[2]) {
    if (elem < mas[0]) {
        k[0] = 0;
        k[1] = 0;
        return;
    }
    if (elem > mas[count - 1]) {
        k[0] = count - 1;
        k[1] = count - 1;
        return;
    }
    int k_range_one = 0;
    for (int i = 1; i < count; i *= 2) {
        if (elem >= mas[k_range_one]) {
            if ((i * 2 - 1) > count - 1) {
                k[0] = k_range_one;
                k[1] = count - 1;
                return;
            } else if (elem < mas[i * 2 - 1]) {
                k[0] = k_range_one;
                k[1] = i * 2 - 1;
                return;
            }
        }
        k_range_one = i;
    }
    k[0] = k_range_one;
    k[1] = count - 1;
}

int binary(const int *mas, int first, int last, int count, int elem) {
    while (first < last) {
        int mid = (first + last) / 2;
        if (elem > mas[mid]) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return first;
}

int min_number(const int *mas, int result_number, int elem, int count){
    if (result_number > 0 && elem < mas[count - 1]) {
        if (abs(elem - mas[result_number]) < abs(elem - mas[result_number - 1])) {
            return result_number;
        } else {
            return result_number - 1;
        }
    } else {
        return result_number;
    }
}
