int knapsack(int maxW, int value[], int weight[], int n)
{
    int V[n + 1][maxW + 1];
    for (int i = 0; i < n + 1; ++i)
        V[i][0] = 0;
    for (int j = 0; j < maxW + 1; ++j)
        V[0][j] = 0;

    for (int h = 1; h < n + 1; ++h)
    {
        int i = h, j = 1;
        for (; j < maxW + 1; ++j)
        {
            int max = V[i - 1][j], cand = 0;
            if (weight[i] < j)
                cand = V[i - 1][j - weight[i]] + value[i];
            V[i][j] = max > cand ? max : cand;
        }
    }

    return V[n][maxW];
}
