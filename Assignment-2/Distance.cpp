#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

void bfs(int node, int visited[], int level[])
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto v : adj[cur])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = 1;
            level[v] = level[cur] + 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int visited[N] = {0};
        int level[N] = {0};
        int s, d;
        cin >> s >> d;
        bfs(s, visited, level);

        if (visited[d])
        {
            cout << level[d] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

