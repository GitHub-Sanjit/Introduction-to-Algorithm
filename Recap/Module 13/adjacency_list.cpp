#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 5;
// int adj[N][N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i <= n;i++){
        cout << "Index " << i << ": ";
        for (int j = 0; j < adj[i].size();j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}