#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define PN cout << "\n"


ld getratio(vector<ll>& elements) {
    ld rat1, rat2, rat3;
    rat1 = (ld) elements[1] / (ld) elements[0];
    rat2 = (ld) elements[2] / (ld) elements[1];
    rat3 = (ld) elements[3] / (ld) elements[2];
    if (rat1 == rat2) return rat1;
    if (rat2 == rat3) return rat3;
    return rat1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;
    vector<ll> elements (n);
    for(ll& x : elements) cin >> x;

    sort(elements.begin(), elements.end());

    // for(ll& x : elements) cout << x << " ";PN;

    bool found = false;
    ld ratio = getratio(elements);
    for(int i = 0; i < n - 1 && !found; i++) {
        if ((elements[i] * ratio) != elements[i+1]) {
            cout << (ll)(elements[i] * ratio); PN;
            found = true;
        }
    }

    if (!found) {
        if ((elements[1] != elements[2]) && (elements[0] != 1))
            if (elements[0] / ratio == (ll) (elements[0] / ratio))
                cout << (ll) (elements[0] / ratio) << "\n";
        cout << (ll) (elements[n - 1] * ratio) << "\n";
    }
}