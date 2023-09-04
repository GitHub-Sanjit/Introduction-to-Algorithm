#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 5;

class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    ll dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int s;
    cin >> s;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            ll a = ed.u;
            ll b = ed.v;
            ll w = ed.w;
            if (dis[a] != INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    bool cycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        ll a = ed.u;
        ll b = ed.v;
        ll w = ed.w;
        if (dis[a] != INF && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (dis[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }
    return 0;
}
