#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, vagas;
    cin >> n >> vagas >> ws;

    int counter = 1;
    int i;
    for (i = 1; vagas && i < n; i+=2) {
        cout << i+1 << "\n";
        vagas--;
    }

    for (i = 0; vagas && i < n; i+=2) {
        cout << i+1 << "\n";
        vagas--;
    }
}