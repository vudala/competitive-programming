

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define P int(1e9 + 7)
int to_i(char c) { return c - 48; }
const int S = 10;

struct trie {
    vector<int> nxt;
    int cnt;
    int leaf;
    trie() : nxt (S, -1), cnt (0), leaf (false) {}
};

vector<trie> t (1);

void ins(string ne) {
    int u = 0;
    for (char c : ne) {
        int ch = to_i(c);
        if (t[u].nxt[ch] == -1) {
            t[u].nxt[ch] = t.size();
            trie n;
            t.push_back(n);
        }
        u = t[u].nxt[ch];
        t[u].cnt++;
    }
    t[u].leaf++;
}

vector<vector<char>> letters = {
    {},                     // 0
    {},                     // 1
    {'a', 'b', 'c'},        // 2
    {'d', 'e', 'f'},        // 3
    {'g', 'h', 'i'},        // 4
    {'j', 'k', 'l'},        // 5
    {'m', 'n', 'o'},        // 6
    {'p', 'q', 'r', 's'},   // 7
    {'t', 'u', 'v'},        // 8
    {'w', 'x', 'y', 'z'},   // 9
};
map<char, char> nums;

string to_nums(string str) {
    string ret;
    for(char& c : str)
        ret.push_back(nums[c]);
    return ret;
}

vector<int> mem;
int solve(int i, string& s, int n) {
    if (i >= n) { return 1; }
    if (mem[i] != -1) return mem[i];
    ll ans = 0;
    int u = 0;
    for (int j = i; j < n; j++) {
        u = t[u].nxt[to_i(s[j])];

        if (u == -1) { break; }

        if (t[u].leaf) {
            ans += (ll(t[u].leaf) * ll(solve(j+1, s, n))) % P;
            ans %= P;
        }
    }
    return mem[i] = ans;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i = 2; i < 10; i++)
        for(char& c : letters[i])
            nums[c] = i + 48;

    int n;
    cin >> n;

    string phone;
    cin >> phone;

    mem = vector<int> (phone.size(), -1);

    int k;
    cin >> k;

    while(k--) {
        int w_size; string word;
        cin >> w_size >> word;
        ins(to_nums(word));
    }

    cout << solve(0, phone, phone.size());
}