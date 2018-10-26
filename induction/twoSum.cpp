#include "radixSort.cpp"

bool twoSum(int p[], int n, int target)
{
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = p[i];
    radixsort(arr, n);

    int i = 0, j = n - 1;
    while (i <= j)
    {
        int test = arr[i] + arr[j];
        if (test > target)
            j--;
        else if (test < target)
            i++;
        else
            break;
    }

    if (i == j)
        return false;
    else
        return true;
}
