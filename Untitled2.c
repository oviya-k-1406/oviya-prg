/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bool lookup[1001] = {false};
    for (int i = 0; i < nums1Size; i++) {
        lookup[nums1[i]] = true;
    }
    int maxPossibleSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxPossibleSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < nums2Size; i++) {
        int currentVal = nums2[i];
        if (lookup[currentVal]) {
            result[count++] = currentVal;
            lookup[currentVal] = false; 
        }
    }
    *returnSize = count;
    result = (int*)realloc(result, count * sizeof(int));
    return result;
}