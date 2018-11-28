#ifndef BMF
#define BMF

#include <queue>
using namespace std;

unsigned mod(int x, unsigned N)
{
    while (x < 0)
        x += N;

    return x % N;
}

unsigned exp_mod(unsigned x, unsigned y, unsigned N)
{
    unsigned res = 1;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= N;
        }
        x *= x;
        x %= N;
        y >>= 1;
    }

    return res;
}

unsigned _gcd(unsigned x, unsigned y)
{
    if (y == 0)
        return x;

    return _gcd(y, x % y);
}

void _gcd_extra(unsigned x, unsigned y, int &num, queue<int> &q)
{
    if (y == 1)
        return;

    num++;
    q.push(x / y);
    _gcd_extra(y, x % y, num, q);
}

int get_inverse(unsigned M, unsigned e)
{
    queue<int> q;
    int num = 0;

    _gcd_extra(M, e, num, q);

    int p[num][2];
    for (int i = 0; i < num; ++i)
    {
        p[i][0] = 1;
        p[i][1] = -q.front();
        q.pop();
    }

    for (int i = num - 2; i >= 0; --i)
    {
        p[i][0] *= p[i + 1][1];
        p[i][1] = p[i][1] * p[i + 1][1] + p[i + 1][0];
    }

    return mod(p[0][1], M);
}

#endif
