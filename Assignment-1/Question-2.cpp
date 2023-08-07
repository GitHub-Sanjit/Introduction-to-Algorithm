#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t;
    cin >> t;
    int left = 0;
    int right = v.size() - 1;
    int index = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] == t)
        {
            index = mid;
            break;
        }
        else if (v[mid] < t)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (index != -1)
    {
        cout << index;
    }
    else 
    {
        cout << "Not Found";
    }
    return 0;
}