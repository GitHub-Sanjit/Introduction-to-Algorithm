#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
int visited[N];
int counter = 1;
void dfs(int node)
{
    visited[node] = 1;
    counter++;
    for(auto v : adj[node])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}
int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cc;
    for(int i = 1; i <= 1000; i++)
    {
        counter = 0;
        if(visited[i]) continue;
        dfs(i);
        cc.push_back(counter);
    }
    sort(cc.begin(), cc.end());
    for(auto i : cc){
        if (i == 1) // Note: There will be no component with single node.
            continue; 
        cout << i << " ";
    }
    return 0;
}
