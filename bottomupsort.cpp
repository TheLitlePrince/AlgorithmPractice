#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int p, int q, int r)
{
    int x = p, y = q, pos = p;
    vector<int> swap = v;
    while (x < q && y < r)
    {
        if (v[x] < v[y])
            swap[pos++] = v[x++];
        else
            swap[pos++] = v[y++];
    }
    if (y == r)
        for (; x < q; ++x)
            swap[pos++] = v[x];
    v = swap;
}

void bottomupsort(vector<int> &v)
{
    int cur = 1, next = 2, sum = v.size();
    while (cur < sum)
    {
        int num = 0;
        while (num + next <= sum)
        {
            merge(v, num, num + cur, num + next);
            num += next;
        }
        if (num + cur < sum)
            merge(v, num, num + cur, sum);
        cur = next;
        next = 2 * cur;
    }
}

int main()
{
    vector<int> v = {1, 5, 2, 6, 2, 7, 8, 4, 6, 2, 23, -23, 54};
    bottomupsort(v);
    for (int x : v)
        cout << x << endl;
    system("pause");
}