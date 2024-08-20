#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n-1);
        for(int i=0;i<n-1;i++)
        {
            cin >> arr[i];
        }


        vector<int> output(n);
        output[0] = arr[0]+1;
        for(int i=1;i<n;i++)
        {
            output[i] = arr[i-1] + output[i-1];
        }


        for(int i=0;i<n;i++)
        {
            cout << output[i] <<" ";
        }
        cout << endl;

    }

    return 0;
}