

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool is_email(string str) {
    return regex_match(str, regex ("[a-z]+[a-z0-9]*@([a-z]+\\.)?ufpr\\.br"));
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    map<string, int> counts;
    while(q--) {
        string str;
        cin >> str;

        if (is_email(str)) {
            if (counts.find(str) == counts.end())
                counts[str] = 1;
            else 
                counts[str] += 1;
            cout << counts[str] << '\n';
        }
    }
}