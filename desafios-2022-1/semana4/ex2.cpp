#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << '\n';

vector<int> coins = {1, 5, 10, 25, 50};
vector<vector<ll>> values (5, vector<ll> (30001, -1LL));

ll gen(int remaining, int chosen) {
    if (values[chosen][remaining] != -1LL) return values[chosen][remaining];

    if (remaining == 0 || chosen == 0)
        return values[chosen][remaining] = 1LL;

    ll acc = 0;
    if (remaining > 0)
        for(int c = 0; c < 5; c++)
            if (c <= chosen)
                acc += gen(remaining - coins[c], c);
                
    return values[chosen][remaining] = acc;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    while(cin >> n)
        cout << gen(n, 4) << "\n";
}