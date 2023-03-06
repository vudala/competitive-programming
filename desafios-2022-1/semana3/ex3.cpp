#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PN cout << "\n"

void findCombinations(vector<ll> const &arr, ll i, ll k,
                set<vector<ll>> &subarrays, vector<ll> &out)
{
    if (arr.size() == 0 || k > arr.size())
        return;
 
    if (k == 0) {
        subarrays.insert(out);
        return;
    }
 
    for (int j = i; j < arr.size(); j++)
    {
        out.push_back(arr[j]);
        findCombinations(arr, j + 1, k - 1, subarrays, out);
        out.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll a, b, n;
    cin >> a >> b >> n;

    vector<ll > primes (n);
    for(ll& x : primes) cin >> x;

    ll accu = 0LL;
    ll tam = b - a + 1;
    ll accumulate_sub;
    set<vector<ll>> combinations;
    set<vector<ll>>::iterator itr;
    vector<ll> aux;
    ll mult;
    ll cardi;
    for (int i = 1; i <= n; i++) {

        findCombinations(primes, 0, i, combinations, aux);

        accumulate_sub = 0LL;

        for(itr = combinations.begin(); itr != combinations.end(); itr++) {
            vector<ll> vec = *itr;
            mult = 1LL;
            for(ll& pl : vec)
                mult = mult * pl;
            cardi = (b/mult) - ((a-1) / mult);
            accumulate_sub = accumulate_sub + cardi;
        }
        combinations.clear();

        if (i % 2 != 0)
            accu = accu + accumulate_sub;
        else
            accu = accu - accumulate_sub;
    }
    cout << tam - accu;
}