#ifndef maxheap_h
#define maxheap_h

#include <iostream>

class maxheap
{
  public:
    maxheap()
    {
        p = new int[8];
        size = 0;
        space = 4;
    }
    ~maxheap()
    {
        delete[] p;
    }
    void makeHeap(int arr[], int n);
    void heapSort();
    void insert(int x);
    void erase(int x);
    int pop();
    void display();

  private:
    void siftUp(int i);
    void siftDown(int i);
    void swap(int &x, int &y);
    int search(int x);
    void reserve();
    int *p;
    int size;
    int space;
};

#endif

void maxheap::display()
{
    for (int i = 0; i < size; ++i)
        std::cout << p[i] << '\t';
    std::cout << '\n';
}

void maxheap::heapSort()
{
    int sz = size;
    for (int j = sz - 1; j >= 1; --j)
    {
        swap(p[0], p[j]);
        --size;
        siftDown(0);
    }
    size = sz;
}

void maxheap::makeHeap(int arr[], int n)
{
    int *np = new int[2 * n];
    for (int i = 0; i < n; ++i)
        np[i] = arr[i];
    delete[] p;
    p = np;
    size = n;
    space = 2 * n;

    for (int j = size / 2; j >= 0; --j)
        siftDown(j);
}

int maxheap::pop()
{
    if (size == 0)
        return 0;
    int x = p[0];
    p[0] = p[--size];
    siftDown(0);
    return x;
}

void maxheap::erase(int x)
{
    int i = search(x);
    if (x == size)
        return;
    p[i] = p[--size];
    if (p[i] > x)
        siftUp(i);
    else
        siftDown(i);
}

void maxheap::insert(int x)
{
    if (size == space)
        reserve();
    p[size++] = x;
    siftUp(size - 1);
}

void maxheap::siftDown(int i)
{
    bool done = false;
    while (2 * i < size && !done)
    {
        i *= 2;
        if (i + 1 < size && p[i + 1] > p[i])
            i++;
        if (p[i] > p[i / 2])
            swap(p[i], p[i / 2]);
        else
            done = true;
    }
}

void maxheap::siftUp(int i)
{
    bool done = false;
    while (i != 0 && !done)
    {
        if (p[i] > p[i / 2])
            swap(p[i], p[i / 2]);
        else
            done = true;
        i /= 2;
    }
}

int maxheap::search(int x)
{
    for (int i = 0; i < size; ++i)
    {
        if (p[i] == x)
            return i;
    }
    return size;
}

void maxheap::reserve()
{
    int *np = new int[2 * space];
    for (int i = 0; i < size; ++i)
        np[i] = p[i];
    space *= 2;
    delete[] p;
    p = np;
}

void maxheap::swap(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}