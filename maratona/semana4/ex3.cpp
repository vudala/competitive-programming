#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long acc = 0LL;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if (x > 10)
            acc += x - 10;
    }
    cout << acc;
}
