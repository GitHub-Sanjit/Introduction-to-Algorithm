#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
int visited[N];

void bfs(int node)
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
        }
        break;
    }
}

int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> s;
    bfs(k);
    for (int val : adj[k])
    {
        s.push_back(val);
    }
    cout << s.size();
    return 0;
}
