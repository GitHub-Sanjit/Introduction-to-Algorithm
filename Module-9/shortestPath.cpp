#include<bits/stdc++.h>
using namespace std;
void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	level[s] = 0;
	parent[s] = -1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int v: adj[u])
		{
			if(visited[v] == true) continue;
			q.push(v);
			visited[v] = true;
			level[v] = level[u] + 1;
			parent[v] = u; 
		}

	}
}

int main()
{
    init_code();

    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
    	int u,v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
	int s, d;
	cin >> s >> d;

	bfs(s);
	cout <<"Distance : "<< level[d] << endl;
	// for (int i = 1; i <= n; i++){
	// 	cout << "Parent of " << i << ": " << parent[i] << endl;
	// }

	vector<int> path;
	int cur = d;

	while(cur != -1){
		path.push_back(cur);
		cur = parent[cur];
	}
	reverse(path.begin(), path.end());
	cout << "Path : ";
	for(int node : path){
		cout << node << " ";
	}
	return 0;
    
}