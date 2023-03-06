#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2 * 1e5 + 15;

vector<int> left_partion;

vector<vector<int>> g (N);
vector<int> match (N, -1);
vector<int> dist (N);
bool bfs() {
    queue<int> Q;
    for(int& u : left_partion) {
        if (match[u] == -1) {
            dist[u] = 0;
            Q.push(u);
        }
        else
            dist[u] = -1;
    }
        
    bool ans = false;
    while (!Q.empty()) {
        int l = Q.front(); Q.pop();
        for (auto r : g[l])
            if (match[r] == -1) {
                ans = true;
            }
            else if (dist[match[r]] == -1) {
                dist[match[r]] = dist[l] + 1;
                Q.push(match[r]);
            }
    }
    return ans;
}


bool dfs(int l) {
    if (l == -1) { return true; }
    for (auto r : g[l])
        if (match[r] == -1 || dist[match[r]] == dist[l] + 1)
            if (dfs(match[r])) {
                match[r] = l;
                match[l] = r;
                return true;
            }
    return false;
}

int hopcroft() {
    int ans = 0;
    while (bfs())
        for(int& u : left_partion)
            if (match[u] == -1 && dfs(u)) { ans++; }
    return ans;
}

vector<bool> visited (N, false);
void explore(int u, bool color) {
    visited[u] = true;

    if (color)
        left_partion.push_back(u);

    for (int v : g[u])
        if (!visited[v])
            explore(v, !color);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    explore(0, true);
    cout << hopcroft() << '\n';
}