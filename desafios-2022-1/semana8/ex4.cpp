

#include <bits/stdc++.h>

using namespace std;

#define PN cout << '\n'

int gcd (int a, int b) {
    if (b == 0) { return a; }
    return gcd(b, a%b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, m, s;
    cin >> h >> m >> s;

    int aux = gcd(m, s);
    int div = gcd(h, aux);

    cout << div; PN;

    int i, j, k;
    for (
        i = 0, j = 0, k = 0;
        i < h && j < m && k < s;
        i += h / div, j += m / div, k += s / div
    ) {
        cout << i << ' ' << j << ' ' << k; PN;
    }
}