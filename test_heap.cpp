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
    mh.display();

    int p[] = {43, 53, 53, 123, 5, 2, 41, 5, 2, 5, 68, 9, 21, 643, 3342, 42, 444};
    mh.makeHeap(p, 17);

    mh.heapSort();
    mh.display();

    for (int i = 0; i < 20; ++i)
    {
        mh.pop();
        mh.display();
    }

    system("pause");
}