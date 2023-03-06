#include <bits/stdc++.h>
#define PN cout << "\n"
using namespace std;

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


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    bit = vector<int> (N+1, 0);

    string tape;
    cin >> tape;
    int i = 1;
    for(char& c : tape) add(i++, (int) c - 48);
    
    int q;
    cin >> q;

    int op;
    int a1, b1, a2, b2, d;
    int v1, v2;
    while(q--) {
        cin >> op;
        if (op == 1) {
            cin >> a1 >> b1 >> a2 >> b2 >> d;
            v1 = get(b1) - get(a1-1);
            v2 = get(b2) - get(a2-1);
            if (((v1%9) + (v2%9)) % 9 == d)
                cout << "YES";
            else
                cout << "NO";
            PN;
        }
        else if (op == 2) {
            cin >> a1 >> b1 >> a2 >> b2 >> d;
            v1 = get(b1) - get(a1-1);
            v2 = get(b2) - get(a2-1);
            if (((v1%9) * (v2%9)) % 9 == d)
                cout << "YES";
            else
                cout << "NO";
            PN;
        }
        else {
            cin >> a1 >> b1;
            add(a1, b1 - (tape[a1-1]-48));
            tape[a1-1] = (char) (b1 + 48);
        }
    }
}