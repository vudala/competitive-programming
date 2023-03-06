#include <bits/stdc++.h>
using namespace std;


int allowed(vector<int>& books, vector<pair<int, int>>& restr, int i) {
    for(pair<int, int> re : restr)
        if (find(books.begin(), books.begin()+i, re.first) > find(books.begin(), books.begin()+i, re.second))
            return 0;
    return 1;
}

void gen(int k, int n, vector<int>& books, vector<pair<int, int>>& restr, vector<int>& chosen) {
    if (!allowed(books, restr, k))
        return;

    if (k == n) {
        for (int i = 0; i < n; i++) { cout << books[i] << " "; }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!chosen[i]) {
            chosen[i] = 1;
            books[k] = i;
            gen(k+1, n, books, restr, chosen);
            chosen[i] = 0;
        }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, r;
    cin >> n >> r;

    vector<int> books (n);
    vector<int> chosen (n+1);

    int a, b;
    vector<pair<int, int>> restr (r);
    for(int i = 0; i < r; i++) {
        cin >> a >> b;
        restr[i] = make_pair(a, b);
    }
        
    gen(0, n, books, restr, chosen);
}