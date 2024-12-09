#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ant {
    int position;
    char direction;
    int id;
};

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<Ant> ants(n);
    for (int i = 0; i < n; i++) {
        cin >> ants[i].position >> ants[i].direction;
        ants[i].id = i;
    }

    vector<int> final_positions(n);
    for (int i = 0; i < n; i++) {
        if (ants[i].direction == 'R') {
            final_positions[i] = (ants[i].position + t) % m;
        } else {
            final_positions[i] = (ants[i].position - t + m) % m;
        }
    }

    sort(ants.begin(), ants.end(), [](Ant a, Ant b) {
        return a.position < b.position;
    });

    for (int i = 0; i < n; i++) {
        cout << final_positions[ants[i].id] + 1 << " ";
    }

    return 0;
}