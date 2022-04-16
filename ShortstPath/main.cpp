#include <iostream>
#define MAX 1000

using namespace std;
int g[MAX][MAX], used[MAX], dist[MAX], up[MAX];
int n, a, b, i, ja, jb, l, j = 0;

void dfs(int v, int len = 0)
{
    used[v] = 1; dist[v] = len;
    up[j] = v;

    if (v == a) ja = j;
    if (v == b) jb = j;

    j++;
    for (int i = 0; i < n; i++)
        if ((g[v][i] == 1) && (used[i] == 0)) dfs(i, len + 1);
}

void uplevel (int a, int b, int ja, int jb)
{
    int i = ja, j = jb;

    while (a != b)
    {
        if (dist[a] > dist[up[i - 1]])
        {
            a = up[i - 1];
            ja = i - 1;
            i--;
            l++;
        }
        else
            i--;
        while (dist[a] != dist[b])
        {
                if (dist[b] > dist[up[j - 1]])
                {
                    b = up[j - 1];
                    jb = j - 1;
                    j--;
                    l++;
                }
                else
                    j--;
        }
    }
}

void tolevel (int a, int b, int ja, int jb)
{
    int i = ja, j = jb;
    while (dist[a] != dist[b])
    {
        if (dist[a] < dist[b])
            if (dist[b] > dist[up[j - 1]])
            {
                b = up[j - 1];
                jb = j - 1;
                j--;
                l++;
            }
            else
                j--;
        else
            if (dist[a] > dist[up[i - 1]])
            {
                a = up[i - 1];
                ja = i - 1;
                i--;
                l++;
            }
            else
                i--;
    }
    uplevel(a, b, ja, jb);
}

int main()
{
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    cin >> a >> b;
    dfs(0);
    tolevel(a, b, ja, jb);
    cout << l;
    return 0;
}
