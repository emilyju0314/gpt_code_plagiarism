#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000009

using namespace std;

struct Cube {
    int x, y;
};

bool compareCubes(Cube c1, Cube c2) {
    return c1.y > c2.y;
}

int main() {
    int m;
    cin >> m;

    vector<Cube> cubes(m);

    for(int i = 0; i < m; i++) {
        cin >> cubes[i].x >> cubes[i].y;
    }

    sort(cubes.begin(), cubes.end(), compareCubes);

    long long ans = 0;
    long long base = 1;

    for(int i = 0; i < m; i++) {
        ans = (ans + base * cubes[i].x) % MOD;
        base = (base * m) % MOD;
    }

    cout << ans << endl;

    return 0;
}