#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int toint(char c) {
    return c - '0';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int size;
    string dna; 
    cin >> size;
    cin >> dna;
    int count = 0;
    int start =-1, end=-1;
    int i;
    for (i = 0; i < size; i++) {
        if (dna[i] == 'A') {
            count += 1;
            if (count >= 7){
                if (start == -1)
                    start = i - 6;
                else
                    end = i+1;
            }
                
        }
        else {
            count = 0;
        }
            
    }

    if (end == -1)
        end = start + 7;
    if (start == -1)
        cout << "0\n";
    else {
        cout << end - start;
        cout << "\n";
    }
}