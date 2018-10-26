int matrixMultiply(int matrixArr[], int num);

int _matrixMultiply(int matrixArr[], int **table, int i, int j)
{
    if (table[i][j] != 0 || i == j)
        return table[i][j];

    int min = __INT_MAX__;
    for (int k = i + 1; k <= j; ++k)
    {
        int cand = _matrixMultiply(matrixArr, table, i, k - 1) + _matrixMultiply(matrixArr, table, k, j) + matrixArr[i] * matrixArr[k] * matrixArr[j + 1];
        min = cand < min ? cand : min;
    }

    table[i][j] = min;
    return min;
}

int matrixMultiply(int matrixArr[], int num)
{
    int **table;
    table = new int *[num];
    for (int i = 0; i < num; ++i)
        table[i] = new int[num];

    int length = num * num;
    for (int i = 0; i < length; ++i)
        table[i / num][i % num] = 0;

    return _matrixMultiply(matrixArr, table, 0, num - 1);
}
