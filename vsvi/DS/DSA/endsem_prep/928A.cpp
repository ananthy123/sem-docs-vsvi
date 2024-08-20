#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int a = 0;
        int b = 0;
        for (int i = 0; i < 5; i++) {
            if (x[i] == 'A') a++;
            else b++;
        }
        if (a>b) cout << "A" << "\n";
        else cout << "B" << "\n";
    }
}