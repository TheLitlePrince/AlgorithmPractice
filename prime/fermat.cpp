#include "basic_mod_func.h"
#include <chrono>
#include <iomanip>
#include <random>
#include <string>

#define NUM 100
#define BASE 10
typedef unsigned prime_t;
using namespace std;

prime_t get_randP(unsigned n)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);

    uniform_int_distribution<int> d1(0, BASE - 1);
    string str = "";
    for (int i = 0; i < n; ++i)
        str += to_string(d1(e));

    if (str[0] == '0')
        return get_randP(n);

    return stoul(str, nullptr, BASE);
}

prime_t get_randA(prime_t p)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);

    uniform_int_distribution<int> d1(1, p - 1);

    return d1(e);
}

bool test_pri(prime_t x)
{
    if (x == 0)
        return false;

    for (int i = 0; i < NUM; ++i)
        if (exp_mod(get_randA(x), x - 1, x) != 1)
            return false;
    return true;
}

prime_t pri_generate(unsigned n)
{
    prime_t pri = 0;
    while (!test_pri(pri))
        pri = get_randP(n);

    return pri;
}
