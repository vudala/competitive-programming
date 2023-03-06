#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int toint(char c) {
    return c - '0';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    string x, y;
    int i = n;
    vector<int> lookuptable = {1,0,1,0,1,0,1,0,1,0};
    for (;i;i--) {
        cin >> x >> y;
        if (lookuptable[toint(x[x.length() - 1])] == lookuptable[toint(y[y.length() - 1])])
            cout << "PARCEIROS\n";
        else 
            cout << "NAO PARCEIROS\n";
    }
}