#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int dis[N];
bool vis[N];
vector<int> adj[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for (int i = 0; i < adj[parent].size();i++){
            int child = adj[parent][i];
            if(vis[child]==false){
                q.push(child);
                dis[child] = dis[parent] + 1;
                vis[child] = true;
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for (int i = 0; i <= n;i++){
        cout << "Node " << i << ": " << dis[i] << endl;
    }
        return 0;
}