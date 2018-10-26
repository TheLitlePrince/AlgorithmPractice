#include <cmath>
#include <iostream>

struct pointInfo
{
    int parent = -1;
    int rank = 1;
};

class disjointSets
{
  public:
    disjointSets(int num) : n(num)
    {
        p = new pointInfo[num];
        for (int i = 0; i < num; ++i)
            p[i].parent = i;
    };
    ~disjointSets()
    {
        delete[] p;
    }
    int Find(int x);
    void Union(int x, int y);

  private:
    pointInfo *p;
    const int n;
};

int disjointSets::Find(int x)
{
    if (x < 0 || x >= n)
        return -1;

    int par = x, maxNum = n - log(p[x].rank) / log(2), count = 0;
    int *col = new int[maxNum];

    while (par != p[par].parent)
    {
        col[count++] = par;
        par = p[par].parent;
    }

    for (int i = 0; i < count; ++i)
        p[col[i]].parent = par;
    delete[] col;

    return par;
}

void disjointSets::Union(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || x == y)
        return;

    int index_x = Find(x), index_y = Find(y);
    if (p[index_x].rank <= p[index_y].rank)
    {
        p[index_x].parent = index_y;
        if (p[index_x].rank == p[index_y].rank)
            (p[index_y].rank)++;
    }
    else
    {
        p[index_y].parent = index_x;
    }
}