#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c1, c2;
    cin >> n >> c1 >> c2;

    int** dist = new int*[n];
    int* res = new int[n];

    for(int i=0; i < n; i++)
        dist[i] = new int[n];

    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            dist[i][j] = INF;

    for(int i=0; i < n-2; i++)
        res[i] = 0;

    for (int i = 0; i < n-1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a-1][b-1] = w;
        dist[b-1][a-1] = w;
        dist[i][i] = 0;
    }
    
    for(int k=0; k < n; k++)
        for(int i=0; i < n; i++)
            for(int j=0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    dist[c1-1][c1-1] = dist[c1-1][c2-1] = INF;
    dist[c2-1][c2-1] = dist[c2-1][c1-1] = INF;

    for (int i = 0; i < n-2; i++)
    {
        int tmp, idx;
        tmp = INF;
        idx = -1;
        for (int j = 0; j < n; j++)
        {
            if(tmp > min(dist[c1-1][j], dist[c2-1][j]))
            {
                tmp = min(dist[c1-1][j], dist[c2-1][j]);
                idx = j;
            }
        }
        res[i] = idx+1;
        dist[c1-1][idx] = INF;
        dist[c2-1][idx] = INF;
    }

    for(int i = 0; i < n-2; i++) cout << res[i] << endl;
    return 0;
}