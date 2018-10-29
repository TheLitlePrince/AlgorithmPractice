int matrixMultiply(int R[], int n)
{
    int C[n][n];
    for (int i = 0; i < n; ++i)
        C[i][i] = 0;

    for (int d = 1; d < n; ++d)
    {
        int i = 0, j = d;
        for (; j < n; ++i, ++j)
        {
            int min = __INT_MAX__;
            for (int k = i + 1; k <= j; ++k)
            {
                int cand = C[i][k - 1] + C[k][j] + R[i] * R[k] * R[j + 1];
                min = min < cand ? min : cand;
            }
            C[i][j] = min;
        }
    }

    return C[0][n - 1];
}
