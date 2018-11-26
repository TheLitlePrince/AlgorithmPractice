int _LCS_spaceReduce(char str1[], int len1, char str2[], int len2)
{
    int L[2][len2 + 1];

    for (int i = 0; i < len2 + 1; ++i)
        L[0][i] = 0;
    L[1][0] = 0;

    int filled = 0, cand = 1;
    for (int d = 1; d < len1 + 1; ++d)
    {
        int j = 1;
        for (; j < len2 + 1; ++j)
        {
            if (str1[d - 1] == str2[j - 1])
                L[cand][j] = L[filled][j - 1] + 1;
            else
                L[cand][j] = L[cand][j - 1] > L[filled][j] ? L[cand][j - 1] : L[filled][j];
        }

        int c = filled;
        filled = cand;
        cand = c;
    }

    return L[filled][len2];
}
