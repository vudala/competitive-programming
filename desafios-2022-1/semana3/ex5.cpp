#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    int x;
    
    queue<int> window;
    map<int, int> frequency;
    int maior = 0;
    for(int i = 0; i < k; i++) {
        cin >> x;
        window.push(x);
        if (frequency.find(x) != frequency.end())
            frequency[x] += 1;
        else
            frequency[x] = 1;
        if (frequency[x] > maior)
            maior = frequency[x];
    }

    for(int i = k; i < n; i++) {
        frequency[window.front()] -= 1;
        window.pop();
        cin >> x;
        window.push(x);
        if (frequency.find(x) != frequency.end())
            frequency[x] += 1;
        else
            frequency[x] = 1;
        if (frequency[x] > maior)
            maior = frequency[x];
    }
    cout << maior;
}