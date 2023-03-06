

#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string ne) {
int n = ne.size();
vector<int> pi (n, 0);
for (int i = 1, j = 0; i < n; i++) {
while (j > 0 && ne[i] != ne[j]) { j = pi[j-1]; }
if (ne[i] == ne[j]) { j++; }
pi[i] = j;
}
return pi;
}

vector<int> search(string hay, string ne) {
    vector<int> pos;
    vector<int> pi = pre(ne); int c = 0;
    for (int i = 0, j = 0; i < hay.size(); i++) {
        while (j > 0 && hay[i] != ne[j]) { j = pi[j-1]; }
        if (hay[i] == ne[j]) { j++; }
        if (j == ne.size()) { c++;
            pos.push_back(i-j+1);
            j = pi[j-1]; 
        }
    }
    return pos;
}

bool neigh(int i, int j, vector<vector<bool>> & eleg) {
    return (eleg[i-1][j-1] || eleg[i-1][j] || eleg[i-1][j+1] ||
            eleg[i][j-1] || eleg[i][j+1] ||
            eleg[i+1][j-1] || eleg[i+1][j] || eleg[i+1][j+1]);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> words (k);

    int t;
    string str;
    for(int i = 0; i < k; i++) {
        cin >> t;
        cin >> str;
        words[i] = str;
        t--;
        while(t--) {
            cin >> str;
            words[i].append(" " + str);
        }
    }

    vector<vector<bool>> eleg (102, vector<bool> (402, false));
    vector<string> els (102);
    for(int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        els[i] = x;
        for(int j = 1; j < m; j++) {
            cin >> x;
            els[i].append(" " + x);
        }
    }

    for(string& w : words)
        for(int i = 1; i <= n; i++) {
            vector<int> ret = search(els[i], w);
            for(int& r : ret)
                for(int j = 0; j < w.size(); j++)
                    eleg[i][r + j + 1] = true;
        }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < els[i].size(); j++) {
            if (els[i][j] == ' ') cout << ' ';
            else if (eleg[i][j+1]) cout << els[i][j];
            else if (neigh(i, j+1, eleg)) cout << '0';
            else cout << els[i][j];
        }
        cout << '\n';
    }
}