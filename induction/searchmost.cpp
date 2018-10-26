int searchMost(int p[], int n);

int candidate(int p[], int n, int index)
{
    int cand = p[index], count = 1, j = index + 1;
    while (count > 0)
    {
        if (j == n)
            break;

        if (p[j++] == cand)
            count++;
        else
            count--;
    }

    return count > 0 ? cand : candidate(p, n, index + 1);
}

int searchMost(int p[], int n)
{
    if (n == 0)
        return 0;

    int cand = candidate(p, n, 0), count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (p[i] == cand)
            count++;
        else
            count--;
    }

    return count > 0 ? cand : 0;
}
