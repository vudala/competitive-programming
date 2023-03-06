#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+15;
const int L = log2(1e9);
vector<vector<int>> up (N, vector<int>(L+2));

void bl_init(int n) {
  for (int l = 0; l < L; l++)
  for (int u = 0; u < n; u++) {
    int a = up[u][l];
    up[u][l+1] = up[a][l];
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);   

  int n, q;
  cin >> n >> q;
  int v;
  for(int u = 0; u < n; u++) {
    cin >> v;
    v--;
    up[u][0] = v;
  }
  bl_init(n);

  while(q--) {
    int node, k; 
    cin>>node>>k;
    node--;
    for(int i=L+1; i>=0; i--) {
      if( k & (1<<i) ) node = up[node][i];  
    }  
    cout<<node + 1<<endl;
  }
}
