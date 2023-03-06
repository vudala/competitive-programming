
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 1e5+320

vector<vector<int>> dp(N, vector<int> (320+10, 0));

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  int root = sqrt(n);

  vector<int> pos(n + 320, 0);

  for(; k--;){
    int a, l, d;
    cin >> a >> l >> d;

    if(l < root){
      for(int i = 0; l--; i++){
        pos[a + d*i] += 1;
      }
    }
    else{
      dp[a][d] += 1;
      dp[a + l*d][d] -= 1;
    }
  }

  for(int d = 1; d < 320; d++){
    for(int a = d; a <= n; a++){
      dp[a][d] += dp[a-d][d];
    }
  }

  for(int a = 1; a <= n; a++){
    int ret = 0; 
    for(int d = 1; d <= 320; d++)
      ret+= dp[a][d];
    ret += pos[a];
    cout << ret << ' ';
  }
}