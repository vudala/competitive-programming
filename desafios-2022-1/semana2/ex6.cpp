#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int i;
    char op;

    list<int> tape;
    list<int>::iterator head;
    int val1, val2;

    head = tape.begin();
    
    int j;
    for (i = 0; i < n; i++) {
        cin >> op;
        if (op == 'm') {
            cin >> val1;
            if (val1 < 0)
                for (j = 0; j < abs(val1); j++)
                    head--;
            else if (val1 > 0)
                for (j = 0; j < abs(val1); j++)
                    head++;
                    
        }
        else if (op == 'i') {
            cin >> val1 >> val2;
            for (j = 0; j < val1; j++)
                tape.insert(head, val2);

            for (j = 0; j < val1; j++)
                head--;

            if (tape.size() == 1)
                head = tape.begin();
        }
        else if (op == 'd') {
            head = tape.erase(head);
        }
        else {
            cout << *head << "\n";
        }
    }
}