#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l, t;
    cin >> n >> l >> t;

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    int collisions = 0;
    for (int i = 0; i < n; i++) {
        int clockwise_collisions = 0;
        int counter_clockwise_collisions = 0;

        for (int j = 0; j < n; j++) {
            if (positions[j] < positions[i]) {
                clockwise_collisions++;
            } else {
                counter_clockwise_collisions++;
            }
        }

        int distance_moved = t % l;
        int total_collisions = (n * clockwise_collisions + n * counter_clockwise_collisions) * (distance_moved / l);

        for (int j = 0; j < n; j++) {
            if ((positions[j] + distance_moved) % l == positions[i]) {
                total_collisions++;
            }
        }

        collisions += total_collisions;
    }

    double expectation = (double)collisions / (n * n);
    cout << expectation << endl;

    return 0;
}