#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main () {
    cout << "Hi lol" << endl;
    return 0;

    vector<int> v(5,0);
    vector<int> v2 = {1,2,3,4,5};

    v.push_back(6);
    v.pop_back();

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}