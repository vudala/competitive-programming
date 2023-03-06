#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << '\n'

int N;
vector<int> bit;
void add(int i, int delta) {
    for (; i <= N; i += i & (-i))
        bit[i] += delta;
}

int get(int i) {
    int ans = 0;
    for (;i > 0; i -= i & (-i))
        ans += bit[i];
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    N= n;
    bit = vector<int> (n+1, 0);
    vector<int> elements (n+1);
    int x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        elements[i] = x;
        add(i, 0);
    }
    
    int d, head = 1;
    char op;
    for(int& x : bit) cout << x << " ";PN;
    while(q--) {
        cin >> op;
        if (op == 'm') {
            cin >> d;
            head = binsearch(head + d);
        }
        else if (op == 'd') {
            add(head, 1);
            head += 1;
        }
        else {
            cout << elements[get(head)]; PN;
        }
        for(int& x : bit) cout << x << " ";PN;
        cout << head; PN;
    }
}