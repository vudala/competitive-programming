#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << "\n";


#define BIGINT 1e9

int gen(vector<vector<int>>& values, vector<int>& squares, int pens, int last_pos, int len) {
    if (values[pens][last_pos] != BIGINT) return values[pens][last_pos];

    int gen1 = -BIGINT, gen2 = -BIGINT;
    
    if ((last_pos + 1) < (int) squares.size() && pens - 1 >= 0)
        gen1 = gen(values, squares, pens - 1, last_pos + len, len);
        
    if (pens * len <= ((int) squares.size() - (last_pos + 1))) {
        gen2 = squares[last_pos];
        if ((last_pos + 1) < (int) squares.size())
            gen2 += gen(values, squares, pens, last_pos + 1, len);
    }
    
    int ret = gen1 > gen2 ? gen1 : gen2;
    if (gen1 == -BIGINT && gen2 == -BIGINT) ret = 0;
    values[pens][last_pos] = ret;
    return ret;
}

vector<int> squares;
int comprimento;
int gen(int lapis, int ultima_posicao ) {
    int gen1, gen2;

    // coloca o lapis
    gen1 = gen(lapis - 1, ultima_posicao + comprimento);

    // nao coloca o lapis
    gen2 = squares[ultima_posicao];
    gen2 += gen(lapis, ultima_posicao + 1);

    return gen1 > gen2 ? gen1 : gen2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k, c;
    cin >> n >> k >> c;

    vector<int> squares (n);
    for(int& s : squares) cin >> s;

    vector<vector<int>> values (k+1, vector<int> (n+1, BIGINT));

    cout << gen(values, squares, k, 0, c) << "\n";
}
