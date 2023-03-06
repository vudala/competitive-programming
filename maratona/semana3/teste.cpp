#include <bits/stdc++.h>
using namespace std;
#define PN cout << "\n"

using ll = long long;
int main() {
    ll a = 1LL;
    for(int i = 0;;i++) {
        if (i % 2 == 0) {
            a = a - 1;
        }
        else {
            a = a + 1;
        }
        cout << a << " ";
    }
}