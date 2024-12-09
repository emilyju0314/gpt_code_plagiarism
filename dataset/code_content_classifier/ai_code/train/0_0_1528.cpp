#include <iostream>
#include <vector>

using namespace std;

struct Sofa {
    int x1, y1, x2, y2;
    int cntl, cntr, cntt, cntb;
};

bool checkConditions(Sofa s, int cntl, int cntr, int cntt, int cntb) {
    return s.cntl == cntl && s.cntr == cntr && s.cntt == cntt && s.cntb == cntb;
}

int main() {
    int d, n, m;
    cin >> d >> n >> m;

    vector<Sofa> sofas(d);
    for(int i = 0; i < d; i++) {
        cin >> sofas[i].x1 >> sofas[i].y1 >> sofas[i].x2 >> sofas[i].y2;
    }

    int cntl, cntr, cntt, cntb;
    cin >> cntl >> cntr >> cntt >> cntb;

    for(int i = 0; i < d; i++) {
        if(checkConditions(sofas[i], cntl, cntr, cntt, cntb)) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}