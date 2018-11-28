#include "basic_mod_func.h"
#include "fermat.cpp"
#include <iostream>

#define digits 2
using namespace std;

prime_t get_randE(prime_t M)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);

    uniform_int_distribution<int> d1(2, M % 100);

    return d1(e);
}

int main()
{
    prime_t p = pri_generate(digits), q = pri_generate(digits);
    while (q == p)
        q = pri_generate(digits);

    prime_t N = p * q, M = (p - 1) * (q - 1);

    prime_t e = get_randE(M);
    while (_gcd(M, e) != 1)
        e = get_randE(M);

    prime_t d = get_inverse(M, e);

    cout << "Hello, Alice! RSA keys generation finished." << endl;
    cout << "N:\t" << N << endl;
    cout << "e:\t" << e << endl;
    cout << endl;

    while (true)
    {
        cout << "Please enter the message sending to Bob." << endl;
        cout << ">";
        unsigned msg;
        cin >> msg;

        unsigned send = exp_mod(msg, e, N);
        cout << "Ok! And we will send " << send << " to Bob." << endl;

        unsigned receive = exp_mod(send, d, N);
        cout << "Bingo! And Bob have received it and translate to " << receive << endl;
        cout << endl;
    }
}