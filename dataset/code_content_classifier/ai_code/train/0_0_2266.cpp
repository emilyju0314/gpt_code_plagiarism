#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;

    vector<int> r(h);
    for(int i = 0; i < h; i++) {
        cin >> r[i];
    }

    vector<int> c(w);
    for(int i = 0; i < w; i++) {
        cin >> c[i];
    }

    int total_cells = h * w;
    int filled_cells = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < r[i]; j++) {
            if(c[j] <= i) {
                cout << 0 << endl;
                return 0;
            }
            filled_cells++;
        }
    }
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < c[i]; j++) {
            if(r[j] <= i) {
                cout << 0 << endl;
                return 0;
            }
            filled_cells++;
        }
    }

    int ways = 1;
    for(int i = 0; i < total_cells - filled_cells; i++) {
        ways = (ways * 2) % MOD;
    }

    cout << ways << endl;

    return 0;
}