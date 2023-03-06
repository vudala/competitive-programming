#include <bits/stdc++.h>
using namespace std;
#define PN cout << '\n'
using ll = long long;

vector<pair<int, bool>> a;

ll swaps = 0;
void merge_sort(int l, int r) {
    if (r - l == 1) { return; }
    int mi = l + (r - l) / 2;
    merge_sort(l, mi);
    merge_sort(mi, r);
    vector<pair<int, bool>> aux (r - l);
    int i = l, j = mi;
    for (int k = 0; k < r - l; k++) {
        if (i < mi && j < r) {
            if (!(a[i] < a[j]) && !a[j].second) { swaps += mi - i; }
            if (a[i] < a[j]) { aux[k] = a[i++]; }
            else { aux[k] = a[j++]; }
        } 
        else if (i < mi) { aux[k] = a[i++]; }
        else { aux[k] = a[j++]; }
    }
    for(int i = 0; i < (r-l); i++) {
        a[i + l] = aux[i];
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, h;
    cin >> n >> h;

    vector<pair<int,bool>> members (n);
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        members[i] = make_pair(x, ((h--)) > 0);
    }
    a = members;
    merge_sort(0, n);
    cout << swaps; PN;  
}