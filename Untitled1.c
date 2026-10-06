/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        if (result[left] % 2 != 0 && result[right] % 2 == 0) {
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        } else {
            if (result[left] % 2 == 0) {
                left++;
            }
            if (result[right] % 2 != 0) {
                right--;
            }
        }
    }
    return result;
}