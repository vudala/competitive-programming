

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << '\n'
const ll oo = 1987654321987654321;

void floyd(int n, vector<vector<ll>>& d, vector<vector<int>>& next) {
    for (int u = 0; u < n; u++) {
        d[u][u] = 0;
        next[u][u] = u;
    }
    
    for (int m = 0; m < n; m++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++) 
                if (d[u][v] > d[u][m] + d[m][v]) {
                    d[u][v] = d[u][m] + d[m][v];
                    next[u][v] = next[u][m];
                }
}

vector<ll> path(ll u, ll v, vector<vector<int>>& next){
  vector<ll> ret;
  
  if(next[u][v] == 1987654321) return ret;

  while (u != v){
    u = next[u][v];
    ret.push_back(u);
  }

  return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, c, k;
    cin >> n >> m >> c >> k;
    vector<vector<ll>> d (n, vector<ll>(n, oo));
    vector<vector<int>> next(n, vector<int> (n, 1987654321));

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
        next[u][v] = v;
        next[v][u] = u;
    }

    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < c && j != i + 1)
                d[i][j] = oo;

    floyd(n, d, next);

    cout << (d[k][c-1]); PN;
}