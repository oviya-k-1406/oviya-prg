
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        int numElements = i + 1;
        (*returnColumnSizes)[i] = numElements;
        triangle[i] = (int*)malloc(numElements * sizeof(int));
        triangle[i][0] = 1;
        triangle[i][numElements - 1] = 1;
        for (int j = 1; j < numElements - 1; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}