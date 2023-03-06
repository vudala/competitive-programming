#include <bits/stdc++.h>
#define PN cout << "\n"
using namespace std;
#define OP(X, Y) (X*Y)
int N;
vector<int> seg_tree;

void build(vector<int>& a, int v=1, int tl=1, int tr=N) {
    if (tl == tr) {
        seg_tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        seg_tree[v] = OP(seg_tree[v*2], seg_tree[v*2+1]);
    }
}

int op_inclusive(int l, int r, int v=1, int tl=1, int tr=N) {
    if (l > r) 
        return 1;

    if (l == tl && r == tr)
        return seg_tree[v];

    int tm = (tl + tr) / 2;
    int b1 = op_inclusive(l, min(r, tm), v*2, tl, tm);
    int b2 = op_inclusive(max(l, tm+1), r, v*2+1, tm+1, tr);
    return  OP(b1, b2);
}


void update(int pos, int new_val, int v=1, int tl=1, int tr=N) {
    if (tl == tr) {
        seg_tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, new_val, v*2, tl, tm);
        else
            update(pos, new_val, v*2+1, tm+1, tr);
        seg_tree[v] = OP(seg_tree[v*2], seg_tree[v*2+1]);
    }
}

int tosign(int x) {
    if (x > 0) return 1;
    if (x == 0) return 0;
    return (-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k;
    cin >> N >> k;

    int x;
    vector<int> elements (N+1);
    for(int i = 1; i <= N; i++) {
        cin >> x;
        elements[i] = tosign(x);
    }
    vector<int> t(4 * N, 1);
    seg_tree = t;

    build(elements);

    char tag;
    int i, j, res;
    for(;k--;) {
        cin >> tag >> i >> j;
        if (tag == 'A') {
            update(i, tosign(j));
        }
        else {
            res = op_inclusive(i, j);
            if (res > 0)
                cout << '+';
            else if (res == 0)
                cout << '0';
            else
                cout << '-';
        }
    }
    PN;
}