# Shortest path algorithm in connected undirected acyclic graphs

The aim of the study was to develop an algorithm and software implementation of the methodfinding the shortest path between two given vertices in a connectedundirected acyclic graph. To achieve this goal wassystematized theoretical information of graph theory, the understanding of which requiressolution of the proposed problem of finding the optimal path on the undirectedconnected acyclic unweighted graphs and clearly demonstrated as storedundirected connected acyclic unweighted graph in the adjacency matrix.

An algorithm for calculation is proposed in the research workthe optimal path between two given vertices in an undirected connectedacyclic unweighted graph. The essence of the algorithm is to determine the levels of bothvertices. If they are different, go from the lowest to the highest level, and then performsimultaneous stepwise movement towards the root apex. In the proposedThe algorithm uses a graph traversal algorithm - a search in depth thatallows you to determine the levels of the vertices and the sequence of vertices when descending to depthcolumn. This algorithm has practical application in many search tasksthe shortest path in connected undirected acyclic unweighted graphs.The proposed algorithm works for all connected non-oriented acyclicsunweighted graphs.
A description of algorithms in C++ is presented, which contains enough details toprovide almost direct implementation in any programming language.The method of finding the optimal path on the graph G = (V, E), presented as an adjacency matrix, implemented in program code anddisassembled for the possibility of further research and improvement of the algorithm.

The practical value of the study lies in the possibility of applying the algorithmfinding the shortest distance when developing software when solvingpractical tasks of finding the shortest routes from the city on one large tributaryriver to the city on its other tributary and other similar tasks.

Keywords: connected undirected acyclic graphs, optimal path,algorithm, vertices, edges, matrix.

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
