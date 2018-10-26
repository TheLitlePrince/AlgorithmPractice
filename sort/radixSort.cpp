#define baseNum 10

#define getDigit(x, exp) ((x) / exp) % baseNum

void radixsort(int p[], int n);

void digitSort(int p[], int n, int exp)
{
    int desposit[n];
    int buckets[baseNum] = {0};

    for (int i = 0; i < n; ++i)
        ++buckets[getDigit(p[i], exp)];

    for (int i = 1; i < baseNum; ++i)
        buckets[i] += buckets[i - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        int digit = getDigit(p[i], exp);
        int pos = buckets[digit] - 1;
        desposit[pos] = p[i];
        --buckets[digit];
    }

    for (int i = 0; i < n; ++i)
        p[i] = desposit[i];
}

int getMax(int p[], int n)
{
    int i = 0;
    for (int j = 1; j < n; ++j)
        if (p[j] > p[i])
            i = j;
    return p[i];
}

void radixsort(int p[], int n)
{
    int max = getMax(p, n);
    int exp = 1;
    while (max >= exp)
    {
        digitSort(p, n, exp);
        exp *= baseNum;
    }
}