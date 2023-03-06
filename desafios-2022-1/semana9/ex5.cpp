#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"

int N = 10;
using ii = pair<int, int>;
int tk;
vector<int> tin;
vector<int> low;
vector<ii> brid;
set<int> arti;
vector<vector<int>> g;
void dfs(int u, int p) {
    tin[u] = low[u] = tk++;
    int ch = 0;
    for (auto v : g[u]) {
        if (v == p) continue;
        else if (tin[v] == -1) {
            dfs(v, u); ch++;
            if ((low[v] >= tin[u] && p != u) || (ch >= 2 && p == u))
                arti.insert(u);
            if (low[v] > tin[u])
            brid.push_back(ii(u, v));
            low[u] = min(low[u], low[v]);
        }
        else { low[u] = min(low[u], tin[v]); }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        g = vector<vector<int>> (n+1, vector<int> (0));
        while(m--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        tk = 0;
        low = vector<int> (n+1);
        tin = vector<int> (n+1, -1);
        brid.clear();
        arti.clear();
        for (int u = 0; u < n; u++) { dfs(u, u); }
        cout << arti.size() << '\n';
    }
}