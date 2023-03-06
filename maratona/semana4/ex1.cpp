#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << "\n";

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    int p, h, f, d, c;
    int acc;
    for(;t--;) {
        cin >> p >> h >> f >> d >> c;
        acc = 0;
        if (d > c) {
            for(;p > 1 && h > 0;) {
                acc += d;
                p -= 2;
                h--;
            }
            for(;p > 1 && f > 0;) {
                acc += c;
                p -= 2;
                f--;
            }
        }
        else {
            for(;p > 1 && f > 0;) {
                acc += c;
                p -= 2;
                f--;
            }
            for(;p > 1 && h > 0;) {
                acc += d;
                p -= 2;
                h--;
            }
        }
        cout << acc; PN;
    }
}
