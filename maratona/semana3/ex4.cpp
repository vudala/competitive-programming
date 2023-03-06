#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    vector<bool> sieve (n+3, true);
    sieve[0] = sieve[1] = false;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++)
        if (sieve[i])
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
    for(int i = 2; i <= n; i++)
        if (sieve[i])
            primes.push_back(i);
    
    int size = primes.size();

    int c = 0;
    for(int i = 0; i < size; i++) {
        if (sieve[n - primes[i]])
            c++;
        sieve[primes[i]] = false;
            
    }
    cout << c; PN;
}