#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << '\n'

#define oo 1987654321

void floyd(int n, vector<vector<ll>>& d) {
    for (int u = 0; u < n; u++)
        d[u][u] = 0;

    for (int m = 0; m < n; m++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++) 
                d[u][v] = min(d[u][v], d[u][m] + d[m][v]);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> d (n, vector<ll>(n, oo));

    int u, v, w;
    while(m--) {
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    floyd(n, d);

    ll max = oo;
    ll el;
    for(vector<ll>& a : d) {
        el = a[0];
        for(ll& x : a)
            if (x != oo && x > el)
                el = x;

        if (el < max && el != oo)
            max = el;
    }

    cout << max; PN;
}