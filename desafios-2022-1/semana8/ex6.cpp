#include <bits/stdc++.h>
using namespace std;
#define PN cout << '\n'


vector<int> buff;
int gcd_ (int a, int b) {
    if (b == 0)
        return a;
    buff.push_back(int(a/b));
    return gcd_(b, a%b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n, d;
    cin >> t;
    while(t--) {
        cin >> n >> d;
        gcd_(n, d);
        if (buff.size() == 1) {
            cout << '[' << buff[0] << ']';
        }
        else
        for(int i = 0; i < buff.size(); i++) {
            if (i == 0)
                cout << '[' << buff[i] << ';';
            else if (i == buff.size() - 1)
                cout << buff[i] << ']';
            else
                cout << buff[i] << ',';
        }
        PN;
        buff.clear();
    }
}