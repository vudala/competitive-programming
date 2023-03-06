
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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    vector<int> pref = pre(s);

    vector<int> v;
    int size = pref[pref.size() - 1];
    while(size > 0) {
        v.push_back(size);
        size = pref[size-1];
    }
    sort(v.begin(), v.end());
    for(int& x : v) cout << x << ' ';
    cout << '\n';
}