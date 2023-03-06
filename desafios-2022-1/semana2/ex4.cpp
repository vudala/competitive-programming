#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;

    cin >> n >> k;

    set<string> meias;


    string buff;
    int size = 0;
    int i;
    for (i = 0; i < 2 * n; i++) {
        cin >> buff;
        if (size == 0) {
            meias.insert(buff);
            size++;
        }
        else {
            if (meias.find(buff) != meias.end()) {
                size--;
                meias.erase(buff);
            }
            else {
                size++;
                meias.insert(buff);
            }
        }

        if (size >= k) {
            cout << "7.18808";
            return 0;
        }
    }

    cout << "3.14159";
}