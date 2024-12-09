#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, t, p;

    while (cin >> n >> m >> t >> p && n != 0) {
        vector<int> folds(t);
        vector<pair<int, int>> punch(p);

        for (int i = 0; i < t; i++) {
            int di, ci;
            cin >> di >> ci;
            folds[i] = ci;
        }

        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            punch[i] = make_pair(x, y);
        }

        int holes = 1;
        int width = n, height = m;

        for (int i = 0; i < t; i++) {
            if (folds[i] < width) {
                width = width - folds[i];
            } else {
                height = height - folds[i];
            }
        }

        for (int i = 0; i < p; i++) {
            int x = punch[i].first;
            int y = punch[i].second;

            for (int j = 0; j < t; j++) {
                if (folds[j] < x) {
                    x = 2 * folds[j] - x;
                }
                if (folds[j] < y) {
                    y = 2 * folds[j] - y;
                }
            }

            holes += (width - x) * (height - y);
        }

        cout << holes << endl;
    }

    return 0;
}