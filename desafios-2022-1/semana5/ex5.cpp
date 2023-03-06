
#include <bits/stdc++.h>
using namespace std;
#define PN cout << '\n'
using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b, c;
    cin >> a >> b >> c;
    ll delta = b * b - 4LL * a * c;

    double root = sqrt(delta);
    if ((ll)root * (ll)root == delta) {
        cout << 'Y'; PN;
    }
    else {
        cout << 'N'; PN;
    }
}