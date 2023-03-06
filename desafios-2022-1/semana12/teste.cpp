#include <bits/stdc++.h>
using namespace std;

const int S = 10;

int to_i(char c) { return c - 48; }

struct trie {
    vector<int> nxt; int cnt; bool leaf;
    trie() : nxt (S, -1), cnt (0), leaf (false) {}
};

vector<trie> t (1);

void ins(string ne) {
    int u = 0;
    for (char c : ne) {
        int ch = to_i(c);
        if (t[u].nxt[ch] == -1) {
            t[u].nxt[ch] = t.size();
            trie n; t.push_back(n);
        }
        u = t[u].nxt[ch];
        t[u].cnt++;
    }
    t[u].leaf = true;
}

int main() {
    int n, q; cin >> n >> q;
    while (n--) { string s; cin >> s; ins(s); }
    while (q--) {
        string s; cin >> s;
        int cur = 0;
            for (char c : s) {
            cur = t[cur].nxt[to_i(c)];
            if (cur == -1) { cout << 0 << "\n"; break; }
        }
        if (cur != -1) { cout << t[cur].cnt << "\n"; }
    }
}