#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write your code here
    int e;
    cin >> e;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    while(e--){
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
