#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <string>
using namespace std;

unsigned long get_randP(unsigned long n)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);

    uniform_int_distribution<int> d1(0, 1);
    string str = "";
    for (int i = 0; i < n; ++i)
        str += to_string(d1(e));

    return stoul(str, nullptr, 2);
}

unsigned long get_randA(unsigned long p)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);

    uniform_int_distribution<int> d1(1, p - 1);

    return d1(e);
}

unsigned long exp_mod(unsigned long x, unsigned long y, unsigned long N)
{
    if (y == 0)
        return 1;

    unsigned long z = exp_mod(x, y / 2, N);
    if (y % 2 == 0)
        return (z * z) % N;
    else
        return (x * z * z) % N;
}

bool test_pri(unsigned long x)
{
    if (x == 0)
        return false;

    for (int i = 0; i < 10; ++i)
        if (exp_mod(get_randA(x), x - 1, x) != 1)
            return false;
    return true;
}

unsigned long pri_generate(unsigned long n)
{
    unsigned long pri;
    while (!test_pri(pri))
        pri = get_randP(n);

    return pri;
}
