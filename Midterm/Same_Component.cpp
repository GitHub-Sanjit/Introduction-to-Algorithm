#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 1005;
bool vis[N][N];
char a[N][N];
int n, m;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.')
        return true;
    else
        return false;
}

void dfs(int si, int sj,int di,int dj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj,di,dj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    dfs(si, sj,di,dj);
    if(vis[di][dj]){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}