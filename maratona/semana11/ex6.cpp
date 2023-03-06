

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    const int N = 2e5+15, B = 330;
    list<int> l;
    vector<int> bsz (N/B + 1);
    vector<list<int>::iterator> bbegin (N/B + 1);

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        auto ins = l.insert(l.end(), x);
        if (i % B == 0) { bbegin[i/B] = ins; }
        bsz[i/B]++;
    }

    int head = 0;
    while(q--) {
        char op;
        cin >> op;
        if (op == 'm') {
            int d;
            cin >> d;
            head += d;
        }
        else if (op == 'i') {
            int t;
            cin >> t;

            int i = head;
            auto it = bbegin[i/B]; 
            advance(it, i%B);
            l.insert(it, t);

            if (i % B == 0) {
                bbegin[i/B]--;
            }
                
            int bi = i/B;
            while (bsz[bi+1] > 0) {
                bbegin[bi+1]--;
                bi++;
            }
            if (bsz[bi] >= B) {
                bbegin[bi+1] = next(bbegin[bi], B);
                bsz[bi+1] = 1;
            }
            else
                bsz[bi]++;
        }
        else if (op == 'd') {
            int i = head;
            auto it = bbegin[i/B];
            advance(it, i%B);
            if (i % B == 0)
                bbegin[i/B]++;
            l.erase(it);
            int bi = i/B;
            while (bsz[bi+1] > 0) {
                bbegin[bi+1]++;
                bi++;
            }
            bsz[bi]--;
        }
        else if (op == 'q') {

            int i = head;
            auto it = bbegin[i/B];
            advance(it, i%B);
            cout << *it << '\n';
        }
    }
}