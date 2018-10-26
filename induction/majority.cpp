int majority(int p[], int n)
{
    int cand = p[0], count = 1, index = 1;
    while (true)
    {
        while (index < n && count > 0)
        {
            int test = p[index++];
            if (test == cand)
                count++;
            else
                count--;
        }

        if (index == n)
            break;
        cand = p[index++];
        count = 1;
    }

    count = 0;
    for (int i = 0; i < n; ++i)
        if (p[i] == cand)
            count++;

    return count > n / 2 ? cand : 0;
}
