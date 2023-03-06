#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define PN cout << "\n"

double euc_dist(pair<int, int>& a, pair<int, int>& b) {
    double x = fabs(a.first - b.first);
    double y = fabs(a.second - b.second);
    return sqrt(x*x + y*y);
}

int N;
vector<vector<double>> g;
vector<double> d;
vector<bool> vis;
double prim(int src) {
    double sum = 0;
    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > Q;
    Q.push(make_pair(d[src] = 0, src));
    while (!Q.empty()) {
        auto [c, u] = Q.top();
        Q.pop();
        if (vis[u]) { continue; }
        vis[u] = true;
        sum += c;

        for(int i = 1; i <= N; i++)
            if (!vis[i] && g[u][i] < d[i] && u != i)
                Q.push(make_pair(d[i] = g[u][i], i));
    }
    return sum;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, c;
    cin >> n >> a >> c;
    N = n;
    d = vector<double> (n+1, INFINITY);
    vis = vector<bool> (n+1, false);
    g = vector<vector<double>> (n+1, vector<double> (n+1, INFINITY));

    vector<pair<int, int>> loc (n+1);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        loc[i+1] = {x, y};
    }

    int m;
    cin >> m;

    // prenche com o preco de criar estradas em todos
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            if (u != v) {
                double dist = c * euc_dist(loc[u], loc[v]);
                g[u][v] = dist;
                g[v][u] = dist;
            }
            else {
                g[u][v] = 0;
                g[v][u] = 0;
            }

    while(m--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (c == 't') {
            double dist = a * euc_dist(loc[u], loc[v]);
            g[u][v] = dist;
            g[v][u] = dist;
        }
        else {
            g[u][v] = 0;
            g[v][u] = 0;
        }
    }

    cout.precision(16);
    cout << prim(1) << '\n';
}