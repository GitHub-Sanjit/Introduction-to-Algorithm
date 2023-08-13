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
    }
    int k;
    cin >> k;
    bfs(k);
    int count = -1;
    for (int i = 0; i < n;i++){
        if(visited[i])
            count++;
    }
    cout << count << endl;
    return 0;
}
