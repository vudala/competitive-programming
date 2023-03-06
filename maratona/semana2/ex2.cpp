#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int i;
    int h;
    char dir;
    stack<int> torres;
    for (i = 0; i < n; i++) {
        cin >> h >> dir;

        if (torres.size() == 0) {
            if (dir == 'O') {
                cout << "N\n"; 
                return 0;
            }
            torres.push(h);
        }
        else {
            if (dir == 'L') {
                if (h < torres.top())
                    torres.push(h);
                else {
                    cout << "N\n"; 
                    return 0;
                }
            }
            else {
                if (torres.top() == h) {
                    torres.pop();
                }
                else {
                    cout << "N\n"; 
                    return 0;
                }
            }
        }
    }

    if (torres.size() == 0)
        cout << "S";
    else
        cout << "N";
}