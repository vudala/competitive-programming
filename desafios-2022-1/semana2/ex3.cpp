#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> mins;

    int i;
    int min;
    for (i = 0; i < n; i++) {
        cin >> min;
        mins.push_back(min);
    }

    sort(mins.begin(), mins.end());

    cout << n / 2 << " " << mins[n/2] - mins[n/2 - 1];
}