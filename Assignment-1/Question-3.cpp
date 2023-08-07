
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
    bool flag = false;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] == t)
        {
            if(v[mid-1]== t || v[mid+1] == t){
                flag = true;
                break;
            }
            if(v[mid-1] != t && v[mid+1] != t){
                flag = false;
                break;
            }
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
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}