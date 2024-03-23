// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int *arr, int len, int value) {
 int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count > (0)) {
        return count;
    }
  return 0;
}

int countPairs2(int *arr, int len, int value) {
  return 0;

int countPairs2(int* arr, int len, int value) {
    int count = 0, m = 0, j = 0;
    for (int i = 0; i < (len - 1); i++) {
        if ((arr[i] + arr[i + 1]) >= value) {
            m = i;
            break;
        }
    }
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        if (m <= i) {
            j = i + 1;
        } else {
            j = m;
        }
        for (; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
            if (arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  return 0;

int countPairs3(int* arr, int len, int value) {
    int count = 0, p = 0, min = 0, max = len;
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        min = i;
        max = len - 1;
        while (min < max) {
            p = min + ((max - min) / 2);
            if (min == max) {
                break;
            }
            if ((arr[i] + arr[p]) > value) {
                for (int n = (p - 1); n >= min; n--) {
                    max = n + 1;
                    if (arr[p] != arr[n]) {
                        break;
                    }
                }
                if (max - min == 1) {
                    break;
                }
            }
            if ((arr[i] + arr[p]) < value) {
                for (int n = (p + 1); n <= max; n++) {
                    min = n - 1;
                    if (arr[p] != arr[n]) {
                        break;
                    }
                }
                if (max - min == 1) {
                    break;
                }
            }
            if ((arr[i] + arr[p]) == value) {
                int r = max;
                for (int n = (p + 1); n <= r; n++) {
                    max = n - 1;
                    if (arr[p] != arr[n]) {
                        break;
                    }
                }
                r = min;
                for (int n = (p - 1); n >= r; n--) {
                    min = n + 1;
                    if (arr[p] != arr[n]) {
                        break;
                    }
                }
                break;
            }
        }
        for (int j = min; j <= max; j++) {
            if (((arr[i] + arr[j]) == value) && (i != j)) {
                count++;
            }
        }
    }
    return count;
}

