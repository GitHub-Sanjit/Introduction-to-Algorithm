#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool dp[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = false;
        }
        dp[1] = true;

        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                dp[i] = dp[i / 2];
            }
            if (i >= 3)
            {
                dp[i] = dp[i] || dp[i - 3];
            }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //    cout<<dp[i]<<" ";
        // }
        // cout << endl;

        if (dp[n])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
       
    }

    return 0;
}