#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vint = vector<int>;

ll extgcd (ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = extgcd(b, a%b, x, y);
    tie(x, y) = make_tuple(y, x - (a/b)*y);
    return g;
}

ll norm(ll a, ll b) { a %= b; return (a < 0) ? a + b : a; }
pair<ll, ll> crt_single(ll a, ll n, ll b, ll m) {
    ll x, y; ll g = extgcd(n, m, x, y);
    if ((a - b) % g) { return {-1, -1}; }
    ll lcm = (m/g) * n;
    return {
        norm(a + n*(x*(b-a)/g % (m/g)), lcm),
        lcm
    };
}
ll crt (vint& a, vint& m, int t) {
    ll ans = a[0], lcm = m[0];
    for (int i = 1; i < t; ++i) {
        tie(ans, lcm) = crt_single(ans, lcm, a[i], m[i]);
        if (ans == -1) { return -1; }
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vint m = vint(n);
    vint a = vint(n);
    for(int i = 0; i < n; i++) {
        int f, d;
        cin >> f >> d;
        m[i] = f;
        a[i] = d;
    }

    cout << crt(a, m, n) << "\n";
}