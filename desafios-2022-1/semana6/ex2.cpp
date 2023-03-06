#include <bits/stdc++.h>
using namespace std;
#define PN cout << '\n'
using ll = long long;

#define oo 1987654321

struct edge { int u, v, w; };
vector<edge> edges;
vector<int> d;
int bellman_ford(int src, int dest, int n) {
    d[src] = 0;
    for (int i = 1; i <= n - 1; i++)
        for (auto e : edges)
            if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
                d[e.v] = d[e.u] + e.w;
    // Verificação de ciclos negativos
    for (auto e : edges)
        if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
            return -oo;
    return d[dest];
}

void printedger(int x) {
    if (x < 3 || x == oo)
        cout << "Não, Edsger...";
    else
        cout << x;
    PN;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    d = vector<int> (n+1, oo);

    vector<int> lotacoes (n+1);
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        lotacoes[i] = x;
    }

    int m, u, v;
    cin >> m;
    while(m--) {
        cin >> u >> v;
        edges.push_back({u, v, lotacoes[v] - lotacoes[u]});
    }

    int q;
    cin >> q;
    q--;
    cin >> x;
    printedger(bellman_ford(1, x, n));
    while(q--) {
        cin >> x;
        printedger(d[x]);
    }
}