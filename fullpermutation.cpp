#include "quicksortNonRec.cpp"
//example: test quicksort without recursive
#include <iostream>
#include <time.h>

#define len 12
//array length

void swapFp(int &x, int &y)
{
    if (&x == &y)
        return;

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

void timeRecord(double &t, int p[], int n)
{
    clock_t start, end;
    start = clock();
    quickSort(p, n);
    //call sort function here
    end = clock();
    t += (double)(end - start) / CLOCKS_PER_SEC;
}

void fullperm(int p[], int finishnum, int n, double &t)
{
    if (finishnum == n)
    {
        timeRecord(t, p, n);
        return;
    }

    for (int i = finishnum; i < n; ++i)
    {
        swapFp(p[i], p[finishnum]);
        fullperm(p, finishnum + 1, n, t);
        swapFp(p[i], p[finishnum]);
    }
}

int main()
{
    int p[len];
    for (int i = 0; i < len; ++i)
        p[i] = i;
    int n = len;
    double t = 0;

    fullperm(p, 0, n, t);

    std::cout << "Full permutation time: " << t << " s\n";
}
