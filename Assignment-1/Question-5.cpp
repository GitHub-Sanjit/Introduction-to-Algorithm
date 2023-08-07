#include <bits/stdc++.h>
using namespace std;

vector<int> merge(const vector<int> &v1, const vector<int> &v2)
{
    vector<int> mergedV;
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] >= v2[j])
        {
            mergedV.push_back(v1[i]);
            i++;
        }
        else
        {
            mergedV.push_back(v2[j]);
            j++;
        }
    }   
    while (i < v1.size())
    {
        mergedV.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        mergedV.push_back(v2[j]);
        j++;
    }
    return mergedV;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    int m;
    cin >> m;
    vector<int> v2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    vector<int> mergedV = merge(v1, v2);
    for (int num : mergedV)
    {
        cout << num << " ";
    }
    return 0;
}