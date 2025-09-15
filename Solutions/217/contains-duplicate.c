#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp_ints(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    qsort(nums, numsSize, sizeof(int), cmp_ints);

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
}
