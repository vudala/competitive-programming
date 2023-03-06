#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"

ll inverso_multiplicativo(ll a, ll m)
{
    ll m0 = m;
    ll y = 0LL, x = 1LL;
 
    if (m == 1LL)
        return 0LL;
 
    while (a > 1) {
        ll q = a / m;
        ll t = m;
 
        m = a % m, a = t;
        t = y;
 
        y = x - q * y;
        x = t;
    }
 
    if (x < 0)
        x += m0;
 
    return x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, c;
    cin >> n >> c;
    vector<int> ranges (n);
    for (int& x : ranges) cin >> x;

    int i, j;
    vector<int> jokers (n, 0);
    for (int k = 0; k < c; k++) {
        cin >> i >> j;
        jokers[j-1] += 1;
    }

    ll P = 1000000007LL;

    int max = *max_element(ranges.begin(), ranges.end());
    vector<ll> lookup (max+1);
    lookup[0] = lookup[1] = 1;
    for(int ii = 2; ii <= max; ii++)
        lookup[ii] = (lookup[ii-1] * ii) % P;
    
    ll accu = 1LL;
    for (i = 0; i < n; i++) {
        ll num = lookup[ranges[i]];
        ll den = lookup[ranges[i] - n + jokers[i]];
        accu = accu * ((num * inverso_multiplicativo(den, P))%P) % P;
    }
    cout << accu;
    PN;
}