#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int toint(char c) {
    return c - '0';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tam;
    int sum;
    int x;
    int i;
    vector<int> v;
    while ((cin >> tam)) {
        sum = 0;
        for (i = tam; i; i--) {
            cin >> x;
            v.push_back(x);
        }
        for (i = 0; i < (tam / 2); i++) {
            cin >> x;
            sum = sum + abs((x - (v[i] + v[tam - i - 1])));
        }
        cout << sum;
        cout << '\n';

        v.clear();
    }
}