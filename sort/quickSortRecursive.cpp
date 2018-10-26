void quickSort(int p[], int n);

void swap(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int split(int p[], int low, int high)
{
    int i = low;
    int x = p[low];
    for (int j = low + 1; j < high; ++j)
    {
        if (p[j] <= x)
        {
            ++i;
            if (i != j)
                swap(p[i], p[j]);
        }
    }
    if (low != i)
        swap(p[low], p[i]);
    return i;
}

void quickSort(int p[], int low, int high)
{
    if (low >= high)
        return;
    int w = split(p, low, high);
    quickSort(p, low, w);
    quickSort(p, w + 1, high);
}

void quickSort(int p[], int n)
{
    quickSort(p, 0, n);
}
