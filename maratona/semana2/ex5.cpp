#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int issiga(string at1) {
    return (at1 == "idjassu" || at1 == "galhofa" || at1 == "aipenkuit");
}

int istarde(string at2) {
    int x =stoi(at2.substr(0, 2));
    return (x >= 13);
}


struct Dados {
    string lutador;
    int pos;
    int classi;
};


int cmp(Dados d1, Dados d2) {
    if (d1.lutador == d2.lutador)
        return d1.classi < d2.classi;
    return d1.lutador < d2.lutador;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, vagas;
    cin >> n >> vagas;

    string at1, at2, at3, at4;

    vector<Dados> competidores;
    
    int i;
    for (i = 0; i < n; i++) {
        cin >> at1 >> at2 >> at3 >> at4;

        Dados d;
        d.lutador = to_string(!issiga(at1)) + to_string(!istarde(at2)) + to_string(200 - stoi(at3));
        d.classi = stoi(at4);
        d.pos = i + 1;
        competidores.push_back(d);
    }

    sort(competidores.begin(), competidores.end(), cmp);

    for (i = 0; i < vagas; i++)
        cout << competidores[i].pos << "\n";
}