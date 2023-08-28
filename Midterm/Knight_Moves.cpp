#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n, m;
vector<pi> path = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}
int main()
{
    // Write your code here
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ki, kj;
        cin >> ki >> kj;
        int Qi, Qj;
        cin >> Qi >> Qj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
                dis[i][j] = 0;
            }
        }
        bfs(ki, kj);
        if(vis[Qi][Qj]){
            cout << dis[Qi][Qj] << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}