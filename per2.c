int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void backtrack(int* nums, int numsSize, int* current, bool* used, int depth, 
               int*** result, int* resultCount, int* capacity) {
    if (depth == numsSize) {
        if (*resultCount >= *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, (*capacity) * sizeof(int*));
        }
        (*result)[*resultCount] = (int*)malloc(numsSize * sizeof(int));
        memcpy((*result)[*resultCount], current, numsSize * sizeof(int));
        (*resultCount)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        current[depth] = nums[i];
        backtrack(nums, numsSize, current, used, depth + 1, result, resultCount, capacity);
        used[i] = false;
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 10;
    int** result = (int**)malloc(capacity * sizeof(int*));
    int resultCount = 0;
    int* current = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    backtrack(nums, numsSize, current, used, 0, &result, &resultCount, &capacity);
    *returnSize = resultCount;
    *returnColumnSizes = (int*)malloc(resultCount * sizeof(int));
    for (int i = 0; i < resultCount; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    free(current);
    free(used);
    return result;
}