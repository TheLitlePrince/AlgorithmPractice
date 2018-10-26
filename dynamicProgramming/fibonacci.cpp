int fib(int n);

int _fib(int p[], int index)
{
    if (p[index] == 0)
        p[index] = _fib(p, index - 1) + _fib(p, index - 2);

    return p[index];
}

int fib(int n)
{
    int *p = new int[n];
    for (int i = 0; i < n; ++i)
        p[i] = 0;

    p[0] = p[1] = 1;
    return _fib(p, n - 1);
}
