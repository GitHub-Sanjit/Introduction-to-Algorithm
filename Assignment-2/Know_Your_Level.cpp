#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
int visited[N];
int level[N];

void bfs(int node)
{
    queue<int> q;

    q.push(node);
    visited[node] = 1;
    level[node] = 0;

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
    // Take input the  Graph
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l;
    cin >> l;
    if(l == 0){
        cout << 0;
        return 0;
    }
    bfs(0);
    int topL = 0;
    for (int i = 0; i < N; i++){
        topL = max(topL, level[i]);
    }
    if(l > topL){
        cout << -1;
        return 0;
    }
    vector<int> s;
    for (int i = 0; i < N; i++)
    {
        if (level[i] == l)
        {
            s.push_back(i);
        }
    }

    unique(s.begin(), s.end());
    sort(s.begin(), s.end());
    for(auto i : s){
        cout << i << " ";
    }

    return 0;
}