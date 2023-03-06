#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"


int cmp(const tuple<vector<int>,int,int>& a, const tuple<vector<int>,int,int>& b) {
    return get<2>(a) < get<2>(b);
}

// se a contem b
int M;
bool contains(vector<int>& a, vector<int>& b) {
    for(int i = 1; i <= M; i++) {
        if (b[i] != -1 && a[i] == -1)
            return 0;
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    M = m;
    vector<tuple<vector<int>,int, int>> emp (n, tuple<vector<int>,int, int> ({vector<int> (m+1, -1), -1, -1}));

    int id = 0, u, x;
    for(int i = 0; i < n; i++) {
        cin >> u;
        get<2>(emp[id]) = u;
        while(u--) {
            cin >> x;
            get<0>(emp[id])[x] = x;
        }
        get<1>(emp[id]) = id;
        id++;
    }

    stable_sort(emp.begin(), emp.end(), cmp);

    vector<bool> src (n, true);

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if (contains(get<0>(emp[j]), get<0>(emp[i])))
                src[get<1>(emp[j])] = false;

    for(int i = 0; i < n; i++)
        if (src[i])
            cout << i << '\n';
}