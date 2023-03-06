#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 5e4 + 15;

const int L = log2(N);
vector<int> depth (N, 0);
vector<vector<int>> weiop (N, vector<int>(L+1));
vector<vector<int>> up (N, vector<int>(L+1));

vector<vector<ii>> g (N);
#define NEUTRAL 0
#define OP(X, Y) (X + Y)

void bl_euler_tour(int u, int p, int w) {
    up[u][0] = p; weiop[u][0] = w; depth[u] = depth[p] + 1;
    for (auto [v, w] : g[u]) if (v != p)
    bl_euler_tour(v, u, w);
}

void bl_init(int u, int n) {
    depth[u] = 0; bl_euler_tour(u, u, 0);
    for (int l = 0; l < L; l++)
    for (int u = 0; u < n; u++) {
    int a = up[u][l];
    up[u][l+1] = up[a][l];
    weiop[u][l+1] = OP(weiop[u][l], weiop[a][l]);
    }
}

ll bl_op(int a, int b) {
    if (!(depth[a] > depth[b])) { swap(a, b); }
    ll res = NEUTRAL;
    ll diff = depth[a] - depth[b];
    for (int l = L; l >= 0; l--) if (diff & (1 << l)) {
    res = OP(res, weiop[a][l]); a = up[a][l]; }
    if (a == b) { return res; }
    for (int l = L; l >= 0; l--)
    if (up[a][l] != up[b][l]) {
    res = OP(res, OP(weiop[a][l], weiop[b][l]));
    a = up[a][l], b = up[b][l];
    }
    return OP(res, OP(weiop[a][0], weiop[b][0]));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    map<int, pair<int, int>> coord;

    vector<int> src (n+1);
    for(int i = 0; i < n; i++) {
        cin >> src[i];
        if (coord.find(src[i]) != coord.end())
            coord[src[i]] = {coord[src[i]].first, i};
        else
            coord[src[i]] = {i, -1};
    }

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back({b, 1});
        g[b].push_back({a, 1});
    }

    bl_init(0, n);

    ll sum = 0;
    for(int i = 0; i < n / 2; i++)
        sum += bl_op(coord[i+1].first, coord[i+1].second);

    cout << sum << '\n';
}