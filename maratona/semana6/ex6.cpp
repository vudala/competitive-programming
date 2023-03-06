#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define PN cout << '\n'

vector<vector<int>> g;
vector<bool> visited;

int explore(int u, int range) {
    int c = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int level_size = q.size();
        if (c <= range) {
            c++;
            for (int& v : g[u])
                if (!visited[v]) {
                    visited[v] = true;
                    cout << v << ' ';
                    q.push(v);
                }
        }
        else
            c--;
    }
    return c;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<pair<int, int>>> field (n, vector<pair<int, int>> (m));

    int x;
    int counter = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> x;
            field[i][j] = make_pair(x, counter);
            counter++;
        }

    g = vector<vector<int>> (n * m, vector<int> (0));
    visited = vector<bool> (n * m);

    counter = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if (j > 0)
                g[counter].push_back(field[i][j-1].second);

            if (j < m - 1)
                g[counter].push_back(field[i][j+1].second);
            if (i > 0) {
                if (j > 0)
                    g[counter].push_back(field[i-1][j-1].second);
                if (j < m - 1)
                    g[counter].push_back(field[i-1][j+1].second);
                g[counter].push_back(field[i-1][j].second);
            }
            if (i < n - 1) {
                if (j > 0)
                    g[counter].push_back(field[i+1][j-1].second);
                if (j < m - 1)
                    g[counter].push_back(field[i+1][j+1].second);

                g[counter].push_back(field[i+1][j].second);
            }
            counter++;
        }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << field[i][j].second << ' ';
        PN;
    }
        
    explore(18, 2);
    PN;
}