#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n, q;
    cin >> k >> n >> q;

    vector<pair<int, int>> engines(k);
    for (int i = 0; i < k; i++) {
        cin >> engines[i].first >> engines[i].second;
    }

    vector<pair<int, int, int>> factories(n);
    for (int i = 0; i < n; i++) {
        cin >> factories[i].first >> factories[i].second >> factories[i].third;
    }

    for (int i = 0; i < q; i++) {
        int pxi, pyi, ti;
        cin >> pxi >> pyi >> ti;

        int reachable_cars = 0;
        for (int j = 0; j < n; j++) {
            int fx = factories[j].first;
            int fy = factories[j].second;

            bool reachable = false;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    int dx = pxi - fx - a * ti * engines[0].first;
                    int dy = pyi - fy - b * ti * engines[0].second;

                    bool all_engines_valid = true;
                    for (int m = 1; m < k; m++) {
                        int engine_dx = a * ti * engines[m].first;
                        int engine_dy = b * ti * engines[m].second;

                        if (dx + engine_dx != 0 || dy + engine_dy != 0) {
                            all_engines_valid = false;
                        }
                    }

                    if (all_engines_valid) {
                        reachable = true;
                        break;
                    }
                }
                if (reachable) {
                    break;
                }
            }

            if (reachable) {
                reachable_cars += factories[j].third;
            }
        }

        cout << reachable_cars << endl;
    }

    return 0;
}