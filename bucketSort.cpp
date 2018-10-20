void bucketsort(int p[], int n);

#define base 10

struct Point
{
    int value;
    int next;
};

int getMaxDigit(Point p[], int n)
{
    int max = 0;
    for (int i = 1; i < n; ++i)
    {
        if (p[i].value > max)
            max = p[i].value;
    }

    int digits = 1;
    while ((max = max / base) != 0)
        digits++;

    return digits;
}

int getKey(int x, int mul)
{
    return x / mul - x / (10 * mul) * 10;
}

void radixsort(Point p[], int n)
{
    int digits = getMaxDigit(p, n), mul = 1;

    for (int j = 1; j <= digits; ++j)
    {
        int bottomBucket[base] = {0}, upBucket[base] = {0};
        int index = p[0].next;

        for (int i = 1; i < n; ++i)
        {
            int key = getKey(p[index].value, mul);

            if (upBucket[key] == 0)
                bottomBucket[key] = index;
            else
                p[upBucket[key]].next = index;

            upBucket[key] = index;
            index = p[index].next;
        }

        int next;
        index = 0;
        for (int i = 0; i < base; ++i)
        {
            while ((next = bottomBucket[i]) != 0)
            {
                p[index].next = next;
                index = next;

                if (index == upBucket[i])
                    bottomBucket[i] = 0;
                else
                    bottomBucket[i] = p[next].next;
            }

            p[index].next = 0;
        }

        mul *= base;
    }
}

void bucketsort(int p[], int n)
{
    Point arr[n + 1];
    arr[0] = {0, 1};
    for (int i = 0; i < n; ++i)
        arr[i + 1] = {p[i], i + 2};
    arr[n].next = 0;

    radixsort(arr, n + 1);

    int i = 0, j = 0;
    while (arr[i].next != 0)
    {
        i = arr[i].next;
        p[j++] = arr[i].value;
    }
}
