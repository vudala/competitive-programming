#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << '\n'

vector<ll> buff;
void factorize (ll n) {
    for (ll i = 2; i*i <= n; i++)
        while (n % i == 0) {
            n /= i;
            buff.push_back(i);
        }
    if (n > 1) { buff.push_back(n); }
}


// ll power_(ll x, ll y) {
//     if (y == 0)
//         return 1;
//     ll p_ = power_(x, y / 2);
//     if (y % 2 == 0)
//         return p_ * p_;
//     else
//         return x * p_ * p_;
// }

ll pow_it(int p, int e) {
    ll mult = 1;
    for(int i = 0; i < e; i++)
        mult *= p;
    return mult;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;
    cin >> t;

    ll k;
    while(t--) {
        cin >> k;
        ll p, e;
        ll mult = 1;
        while(k--) {
            cin >> p >> e;
            mult *= pow_it(p, e);
        }
        factorize(mult - 1);

        reverse(buff.begin(), buff.end());

        for(ll i = 0; i < ll(buff.size()); i++) {
            ll times = 1;
            if (i != buff.size() - 1)
                while(buff[i] == buff[i + 1]) {
                    times++;
                    i++;
                    if (i == buff.size() - 1) break;
                }
            cout << buff[i] << ' ' << times << '\n';
        }

        buff.clear();
    }
}