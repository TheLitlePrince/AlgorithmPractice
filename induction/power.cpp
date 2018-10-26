unsigned long powerRec(int x, int n)
{
    if (n == 0)
        return 1;

    int result = powerRec(x, n / 2);
    result = result * result;
    if (n % 2 != 0)
        result *= x;

    return result;
}

unsigned long powerNonRec(int x, int n)
{
    int mask = INT_MIN, result = 1;
    for (int i = 0; i < 63; ++i)
    {
        result = result * result;
        if (mask & (n != 0))
            result *= x;
        n <<= 1;
    }

    return result;
}
