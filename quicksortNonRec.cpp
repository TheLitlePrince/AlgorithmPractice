#include <queue>

struct arrayPair
{
    int low;
    int high;
};

void quickSort(int p[], int n);

void swap(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int split(int p[], int low, int high)
{
    if (low == high)
        return low;

    int desposit, blank;
    int w = low;
    int standard = p[low++];
    while (true)
    {
        // if (low > high)
        // {
        //     return low - 1;
        // }
        if (p[high] > standard)
        {
            --high;
        }
        else
        {
            desposit = p[high];
            blank = high;
            break;
        }
    }

    while (true)
    {
        if (blank == high)
        {
            while (low != high && p[low] <= standard)
                ++low;
            if (low == high)
                break;
            p[blank] = p[low];
            blank = low;
        }
        else
        {
            while (low != high && p[high] >= standard)
                --high;
            if (low == high)
                break;
            p[blank] = p[high];
            blank = high;
        }
    }

    p[blank] = standard;
    p[w] = desposit;
    return blank;
}

void quickSort(int p[], int n)
{
    std::queue<arrayPair> q;
    arrayPair ap = {0, n - 1};
    q.push(ap);

    while (!q.empty())
    {
        arrayPair ap = q.front();
        q.pop();
        int low = ap.low, high = ap.high;

        if (low == high)
            continue;

        int w = split(p, low, high);
        if (w != low)
        {
            arrayPair ap1 = {low, w - 1};
            q.push(ap1);
        }
        if (w != high)
        {
            arrayPair ap2 = {w + 1, high};
            q.push(ap2);
        }
    }
}