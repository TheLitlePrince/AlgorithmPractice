#define STAR '*'
#define BLANK '-'

struct Point
{
    int x;
    int y;
};

void _fillSquare(char **p, Point start, Point flag, int k);

void fillSquare(char **p, int k)
{
    Point start = {0, 0}, flag;
    int x = 1 << k;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < x; ++j)
            if (p[i][j] == STAR)
                flag = {i, j};

    _fillSquare(p, start, flag, k);

    p[flag.x][flag.y] = STAR;
}

void getStart(char **p, Point start, int k, Point arrStart[])
{
    arrStart[0] = start;
    arrStart[1] = {start.x + (1 << (k - 1)), start.y};
    arrStart[2] = {start.x, start.y + (1 << (k - 1))};
    arrStart[3] = {start.x + (1 << (k - 1)), start.y + (1 << (k - 1))};
}

Point locateFlag(Point start, Point flag, int k, int &pos)
{
    int fx = flag.x, fy = flag.y;
    if (fx >= start.x + (1 << (k - 1)))
    {
        fx++;
        pos = 1;
    }

    if (fy >= start.y + (1 << (k - 1)))
    {
        fy++;
        pos += 2;
    }

    return {fx, fy};
}

void fillFlag(char **p, Point start, Point flag, int k, Point arrFlag[])
{
    int pos = 0;
    Point del = locateFlag(start, flag, k, pos);
    int cx = start.x + (1 << (k - 1)) - 1, cy = start.y + (1 << (k - 1)) - 1;

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            p[cx + i][cy + j] = STAR;

    arrFlag[0] = {cx, cy};
    arrFlag[1] = {cx + 1, cy};
    arrFlag[2] = {cx, cy + 1};
    arrFlag[3] = {cx + 1, cy + 1};

    arrFlag[pos] = del;
    p[cx + pos % 2][cy + pos / 2] = BLANK;
}

void _fillSquare(char **p, Point start, Point flag, int k)
{
    if (k == 1)
        return;

    Point arrStart[4], arrFlag[4];
    getStart(p, start, k, arrStart);
    fillFlag(p, start, flag, k, arrFlag);

    for (int i = 0; i < 4; ++i)
        _fillSquare(p, arrStart[i], arrFlag[i], k - 1);
}