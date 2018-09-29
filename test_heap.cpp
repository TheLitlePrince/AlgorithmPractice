#include "maxheap.h"
#include <iostream>

using namespace std;

int main()
{
    maxheap mh;
    for (int i = 0; i < 20; ++i)
    {
        mh.insert(i);
    }

    for (int i = 0; i < 20; ++i)
    {
        mh.display();
        mh.pop();
    }

    system("pause");
}