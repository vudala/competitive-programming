#include <bits/stdc++.h>
using namespace std;
#define PN cout << '\n'
using ll = long long;
#define oo 1987654321

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

vector<int> path(int u, int v, vector<vector<int>>& next){
  vector<int> ret;
  
  if(next[u][v] == 1987654321) return ret;
  ret.push_back(u);

  while (u != v){
    u = next[u][v];
    ret.push_back(u);
  }

  return ret;
}

map<string, int> values;
map<int, string> keys;


int cmp(vector<int>& a, vector<int>& b) {
    if (a.size() == b.size()) {
        if (keys[a[0]] == keys[b[0]])
            return keys[a[a.size() - 1]] < keys[b[b.size() - 1]];
        else
            return keys[a[0]] < keys[b[0]];
    }
    else
        return a.size() < b.size();
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> d (n, vector<ll>(n, oo));
    vector<vector<int>> next(n, vector<int> (n, oo));

    string x1, x2;
    int i = 0;

    while(m--) {
        cin >> x1 >> x2;
        if (values.find(x1) == values.end()) {
            keys[i] = x1;
            values[x1] = i;
            i++;
        }
        if (values.find(x2) == values.end()) {
            keys[i] = x2;
            values[x2] = i;
            i++;
        }
        d[values[x1]][values[x2]] = 1;
        next[values[x1]][values[x2]] = values[x2];
    }
    floyd(n, d, next);


    vector<vector<int>> paths;
    vector<int> p;
    ll degree = 0;
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            p = path(i, j, next);
            if (p.size() > 1) {
                paths.push_back(p);
                degree += p.size() - 1;
            }
        }

    sort(paths.begin(), paths.end(), cmp);
    
    cout << (degree / (float) paths.size()); PN;

    for (int& x : paths[1 + ((paths.size() - 1) / 2) - 1]) {
        cout << keys[x] << ' ';
    }
    PN;
}