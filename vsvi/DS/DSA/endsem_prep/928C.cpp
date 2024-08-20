#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    vector <int> v (200001, 0);
    v[0] = 0;
    v[1] = 1;
    int currMaxItr = 1;
    while (t--) {
        int n;
        cin >> n;
        if (n <= currMaxItr) {
            cout << v[n] << "\n";
        }
        if (n > currMaxItr) {
            
            for (int i = currMaxItr + 1; i <= n; i++) {
                int k = 0;
                int j = i;
                while (j > 0) {
                    k += (j % 10);
                    j = j / 10;
                }
                v[i] = v[i-1] + k;
            }
            cout << v[n] << "\n";
            currMaxItr = n;
        }
    }
}