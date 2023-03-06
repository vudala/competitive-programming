#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int isfifo(vector<int> order, vector<int> ages) {
    queue<int> aux;
    int n = ages.size();
    int i;
    for (i = 0; i < n; i++) {
        if (!order[i])
            aux.push(ages[i]);
        else {
            if (aux.front() != ages[i])
                return 0;
            else {
                aux.pop();
            }
        }
        
    }

    return 1;
}

int isprio(vector<int> order, vector<int> ages) {
    int n = ages.size();
    set<int> great;
    int i;
    for (i = 0; i < n; i++) {
        if (!order[i]) {
            great.insert(ages[i]);
        }
        else {
            if (great.upper_bound(ages[i]) != great.end()) {
                return 0;
            }
            else {
                great.erase(ages[i]);
            }
        }
    }
        
    return 1;
}

int islifo(vector<int> order, vector<int> ages) {
    stack<int> aux;
    int n = ages.size();
    int i;
    for (i = 0; i < n; i++) {
        if (!order[i]) {
            aux.push(ages[i]);
        }
        else {
            if (ages[i] != aux.top())
                return 0;
            else
                aux.pop();
        }
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> order;
    vector<int> idades;

    int op, idade;
    int i;
    for (i = n; i; i--) {
        cin >> op >> idade;
        order.push_back(op);
        idades.push_back(idade);
    }


    int fifo = isfifo(order, idades);
    int lifo = islifo(order, idades);
    int prio = isprio(order, idades);
    
    if (fifo && lifo)
        cout << "ambiguous";
    else if (fifo && prio)
        cout << "ambiguous";
    else if (lifo && prio)
        cout << "ambiguous";
    else if (fifo && lifo && prio)
        cout << "ambiguous";
    else if (prio)
        cout << "priority";
    else if (fifo)
        cout << "fifo";
    else if (lifo)
        cout << "lifo";
    else 
        cout << "unknown";
        
}