#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << "\n";

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    string s;
    int count;
    for (int i = 0; i < t; i++) {
        cin >> s;
        count = 0;
        for(int j = 0; j < (int) s.size();) {
            if (s[j] == '_') {
                s[j] = s[j+1] = s[j+2] = '#';
                count += 1;
                j+=3;
            }
            else
                j++;
        }

        cout << "Caso " << i+1 << ": " << count; PN; 
    } 
}
