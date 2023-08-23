#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
bool vis[N];
int par[N];
vector<int> v[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    par[s] = -1;
    dis[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size();i++){
            int child = v[parent][i];
            if(!vis[child]){
                q.push(child);
                par[child] = parent;
                dis[child] = dis[parent] + 1;
                vis[child] = true;
            }
        }
    }
}

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": " << par[i] << endl;
    // }
    int d;
    cin >> d;
    if(vis[d]){
        vector<int> p;
        int x = d;
        while(x!=-1){
            p.push_back(x);
            x = par[x];
        }
        reverse(p.begin(), p.end());
        for(int val:p){
            cout << val << " ";
        }
    }
    return 0;
}