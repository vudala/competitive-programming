
#include <bits/stdc++.h>
using namespace std;

bool friends(string a, string b) {
    int diff = a.size() - b.size();
    if (diff == 0) {
        bool trigg = false;
        for(int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (trigg) return false;
                trigg = true;
            }
        }
        return true;
    }
    else if (diff == -1) {
        bool trigg = false;
        int i, j;
        for(int i = 0, j = 0; i < max(a.size(), b.size()) && j < max(a.size(), b.size());) {
            if (a[i] != b[j]) {
                if(trigg) return false;
                trigg = true;
                if (a[i] == b[j+1]) j++;
                else if (a[i+1] == b[j+1]) i++;
                else return false;
            }
            i++; j++;
        }
        return true;
    }
    else
        return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> names (n);
    for(int i = 0; i < n; i++) cin >> names[i];

    sort(names.begin(), names.end());
    for(int i = 0; i < names.size(); i++) {
        cout << names[i] << ":";
        bool trigg = false;
        for(int j = 0; j < names.size(); j++) {
            if (i != j)
                if (friends(names[i], names[j])) {
                    trigg = true;
                    cout << " " << names[j];
                }
        }
        if (!trigg)
            cout << " nenhum melhor amigo";
        cout << '\n';
    }
}