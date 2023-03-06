#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"

vector<vector<int>> g;
vector<bool> visited;
vector<int> weight;
void explore(int u) {
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v]) {
            weight[v] += 1;
            if (weight[v] <= 2)
                explore(v);
        }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    g = vector<vector<int>> (n+1, vector<int> (0));
    weight = vector<int> (n+1, 0);
    vector<bool> src (n+1, true);
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        src[v] = false;
    }
    for(int i = 1; i <= n; i++)
        if (src[i]) {
            visited = vector<bool> (n+1, false);
            explore(i);
        }

    int count = 0;
    for(int i = 1; i <= n; i++)
        if (weight[i] > 1)
           count++;
    cout << count << '\n';
}