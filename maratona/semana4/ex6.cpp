#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PN cout << '\n';
#define RESET   "\033[0m"

#define BIGINT 1987654321

int DURATION, MAX_AGE, PRICE;

vector<int> REPAIRS (3000, 0);
vector<int> SELLING (3000, 0);
vector<vector<bool>> path (3000, vector<bool>(3000, false));

vector<vector<int>> values (3000, vector<int> (3000, BIGINT));
int gen(int year, int age) {
    if (values[year][age] != BIGINT) return values[year][age];

    if (year == DURATION)
        return 0;

    int trocar, reparar; trocar = reparar = BIGINT;

    if (age > 0)
        trocar = gen(year + 1, 1) + PRICE + REPAIRS[0] - SELLING[age];

    reparar = gen(year + 1, age + 1) + REPAIRS[age];

    if (trocar <= reparar || age == MAX_AGE) {
        path[year][age] = true;
        return values[year][age] = trocar;
    }
    return values[year][age] = reparar;
}


void gen_path(int year, int age, bool& done) {
    if (year == DURATION)
        return;

    if (path[year][age]) {
        cout << year+1 << " ";
        gen_path(year + 1, 1, done);
        done = true;
    }
    else
        gen_path(year + 1, age + 1, done);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int age;
    cin >> DURATION >> age >> MAX_AGE >> PRICE;

    int x;
    for(int i = 0; i < MAX_AGE; i++) {
        cin >> x;
        REPAIRS[i] = x;
    }

    for(int i = 0; i < MAX_AGE; i++) {
        cin >> x;
        SELLING[i+1] = x;
    }

    cout << gen(0, age); PN;
    bool done = false;
    gen_path(0, age, done);
    if (!done)
        cout << 0;
}