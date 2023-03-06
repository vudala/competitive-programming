#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int toint(char c) {
    return c - '0';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string code; 
    int hrs, mins;
    while((cin >> code)) {
        cin >> hrs;
        cin >> mins;
        if ((hrs * 60 + mins) <= 600)
            cout << "Abel deve cursar " + code + "\n";
        else
            cout << "Abel deve cancelar " + code + "\n";
    }
}