int fib(int n)
{
    int p[n + 1];
    p[1] = p[2] = 1;

    for (int i = 3; i < n + 1; ++i)
        p[i] = p[i - 1] + p[i - 2];

    return p[n];
}