#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string shapes;
    cin >> shapes;

    vector<int> wins(n, 0);
    vector<int> loses(n, 0);
    vector<int> draws(n, 0);
    vector<int> champions;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((shapes[i] == 'R' && shapes[j] == 'S') ||
                (shapes[i] == 'S' && shapes[j] == 'P') ||
                (shapes[i] == 'P' && shapes[j] == 'R')) {
                wins[i]++;
                loses[j]++;
            } else if ((shapes[i] == 'S' && shapes[j] == 'R') ||
                       (shapes[i] == 'P' && shapes[j] == 'S') ||
                       (shapes[i] == 'R' && shapes[j] == 'P')) {
                wins[j]++;
                loses[i]++;
            } else {
                draws[i]++;
                draws[j]++;
            }
        }

        if (wins[i] + draws[i] == n - 1) {
            champions.push_back(i);
        }
    }

    cout << champions.size() << endl;

    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;

        for (int i = 0; i < n; i++) {
            if (i != p) {
                if ((shapes[p] == 'R' && c == 'S') ||
                    (shapes[p] == 'S' && c == 'P') ||
                    (shapes[p] == 'P' && c == 'R')) {
                    wins[i]++;
                    loses[p]++;
                } else if ((shapes[p] == 'S' && c == 'R') ||
                           (shapes[p] == 'P' && c == 'S') ||
                           (shapes[p] == 'R' && c == 'P')) {
                    wins[p]++;
                    loses[i]++;
                } else {
                    draws[i]++;
                    draws[p]++;
                }

                if (wins[i] + draws[i] == n - 1 && find(champions.begin(), champions.end(), i) == champions.end()) {
                    champions.push_back(i);
                } else if (wins[i] + draws[i] < n - 1 && find(champions.begin(), champions.end(), i) != champions.end()) {
                    champions.erase(remove(champions.begin(), champions.end(), i), champions.end());
                }
            }
        }

        shapes[p] = c;

        cout << champions.size() << endl;
    }

    return 0;
}