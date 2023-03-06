


#include <bits/stdc++.h>
using namespace std;
#define PN cout << "\n"

int binsearch (int x, int n, vector<int>& v) { 
   int inicio = -1, fim = n;
   while (inicio < fim-1) {  
      int m = (inicio + fim)/2;
      if (v[m] < x) inicio = m;
      else fim = m; 
   }
   return fim;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> pilhas (n);
    for(int& p : pilhas) cin >> p;

    vector<int> psum(n+1);
    psum[0] = 0;
    for(int i = 1; i <= n; i++) {
        psum[i] = pilhas[i-1] + psum[i-1];
    }

    int m, x;
    cin >> m;
    while(m--) {
        cin >> x;        
        cout << binsearch(x, n+1, psum) << '\n';
    }
}