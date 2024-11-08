#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int maxProductEnd = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int maxProductStart = nums[0] * nums[1] * nums[numsSize - 1];
    return (maxProductEnd > maxProductStart) ? maxProductEnd : maxProductStart;
}

/*int main() {
    int nums1[] = {1, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf(" {1, 2, 3}: %d\n", maximumProduct(nums1, size1));

    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("{1, 2, 3, 4}: %d\n", maximumProduct(nums2, size2));

    int nums3[] = {-1, -2, -3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("{-1, -2, -3}: %d\n", maximumProduct(nums3, size3));

    return 0;
}
*/