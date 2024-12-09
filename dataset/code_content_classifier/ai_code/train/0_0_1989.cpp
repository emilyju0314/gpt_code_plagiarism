#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Dice {
    int x, y;
    int l, r, f, b, d, u;
    string rot;
};

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        vector<Dice> dice(N);
        for (int i = 0; i < N; ++i) {
            cin >> dice[i].x >> dice[i].y;
            cin >> dice[i].l >> dice[i].r >> dice[i].f >> dice[i].b >> dice[i].d >> dice[i].u;
            cin >> dice[i].rot;
        }

        // To be completed - Calculate the highest score for each dataset

        cout << "To be completed" << endl;
    }

    return 0;
}