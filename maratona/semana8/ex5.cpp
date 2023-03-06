#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}

int count(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
        return abs(y1 - y2) - 1 + 2;

    if (y1 == y2)
        return abs(x1 - x2) - 1 + 2;

    return gcd(abs(x1 - x2), abs(y1 - y2)) - 1 + 2;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << count(x1, y1, x2, y2) << '\n';
    }
}