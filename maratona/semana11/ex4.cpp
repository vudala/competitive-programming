


#include <bits/stdc++.h>
using namespace std;

#define N 1e5+320
vector<vector<int>> dp(N, vector<int> (320+10, 0));

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> values(n + 320, 0);
    int root = sqrt(n);
    while(k--) {
        int a, l, d;
        cin >> a >> l >> d;
        a--;

        if(l < root){
            for(int i = a; i < n && l; i += d, l--)
                values[i] += 1;
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

    for(int a = 0; a < n; a++){
        int ret = 0; 
        for(int d = 1; d <= 320; d++)
            ret+= dp[a][d];
        ret += values[a];
        cout << ret << ' ';
    }
}
