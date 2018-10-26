void bottomupsort(int arr[], int n);

void merge(int arr[], int p, int q, int r)
{
    int x = p, y = q;
    int *deposit = new int[r - p];

    int i = 0;
    while (x < q && y < r)
    {
        if (arr[x] < arr[y])
            deposit[i++] = arr[x++];
        else
            deposit[i++] = arr[y++];
    }
    if (x == p)
    {
        for (; y < r;)
            deposit[i++] = arr[y++];
    }
    else
    {
        for (; x < q;)
            deposit[i++] = arr[x++];
    }

    i = 0;
    for (; i < r - p;)
        arr[p++] = deposit[i++];
}

void bottomupsort(int arr[], int n)
{
    int cur = 1, next = 2;
    while (cur < n)
    {
        int num = 0;
        while (num + next <= n)
        {
            merge(arr, num, num + cur, num + next);
            num += next;
        }
        if (num + cur < n)
            merge(arr, num, num + cur, n);
        cur = next;
        next = 2 * cur;
    }
}
