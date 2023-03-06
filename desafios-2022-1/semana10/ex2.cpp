#include <bits/stdc++.h>
using namespace std;
#define oo 987654321
#define N 515
struct edge { int u, v, cap;};
vector<edge> edges;
vector<vector<int>> res (N);

vector<int> queu (N), ix (N), dist (N), par (N);
bool minimum_path(int s, int t) {
    fill(dist.begin(), dist.end(), oo); dist[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) { break; }
        for (int i : res[u]) {
            edge e = edges[i]; int v = e.v;
            if (e.cap && dist[v] == oo) {
                dist[v] = dist[u] + 1;
                par[v] = u; ix[v] = i;
                q.push(v);
            }
        }
    }
    return dist[t] < oo;
}

pair<int, int> ffek(int s, int t) {
    int min_cost = 0, max_flow = 0;
    while (minimum_path(s, t)) {
        int flow = oo;
        for (int u = t; u != s; u = par[u]) {
            flow = min(flow, edges[ix[u]].cap);
        }
        for (int u = t; u != s; u = par[u]) {
            edges[ix[u] ].cap -= flow;
            edges[ix[u]^1].cap += flow;
        }
        min_cost += flow * dist[t];
        max_flow += flow;
    }
    return { min_cost, max_flow };
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        res[u].push_back(edges.size());
        edges.push_back({ u, v, 1});
        res[v].push_back(edges.size());
        edges.push_back({ v, u, 1});
    }

    auto [cost, flow ] = ffek(0, n-1);
    cout << flow << '\n';
}
