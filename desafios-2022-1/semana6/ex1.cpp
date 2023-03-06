#include <bits/stdc++.h>
using namespace std;
#define PN cout << '\n'
using ll = long long;

vector<int> rep;
vector<int> rnk;
vector<int> siz;

int ds_find(int u) {
    if (rep[u] != u) { rep[u] = ds_find(rep[u]); }
    return rep[u];
}

void ds_union(int u, int v) {
    int x, y;
    x = ds_find(u); y = ds_find(v);
    if (x == y) return;
    if (rnk[x] <= rnk[y]) { swap(x, y); }
    if (rnk[x] == rnk[y]) { rnk[x]++; }
    rep[y] = x;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    rep = vector<int> (n);
    rnk = vector<int> (n, 0);
    for(int i = 0; i < n; i++)
        rep[i] = i;

    int u, v;
    while(m--) {
        cin >> u >> v;
        ds_union(u, v);
    }

    set<int> groups;
    for(int i = 0; i < n; i++)
        groups.insert(ds_find(i));
    
    cout << groups.size();PN;
}