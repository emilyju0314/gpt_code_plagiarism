#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int Laharl_position, Laharl_movement_range, Laharl_throwing_range;
    int Etna_position, Etna_movement_range, Etna_throwing_range;
    int Flonne_position, Flonne_movement_range, Flonne_throwing_range;

    cin >> Laharl_position >> Laharl_movement_range >> Laharl_throwing_range;
    cin >> Etna_position >> Etna_movement_range >> Etna_throwing_range;
    cin >> Flonne_position >> Flonne_movement_range >> Flonne_throwing_range;

    int max_position = max({Laharl_position, Etna_position, Flonne_position});

    for (int i = 0; i <= max_position; i++) {
        int positions[3] = {Laharl_position, Etna_position, Flonne_position};
        int movement_ranges[3] = {Laharl_movement_range, Etna_movement_range, Flonne_movement_range};
        int throwing_ranges[3] = {Laharl_throwing_range, Etna_throwing_range, Flonne_throwing_range};

        for (int j = 0; j < 3; j++) {
            if (positions[j] != i) {
                for (int k = 0; k < 3; k++) {
                    if (abs(positions[j] - positions[k]) == 1) {
                        if (positions[j] == i && movement_ranges[k] > 0) {
                            positions[k] = i;
                            movement_ranges[k]--;
                            if (positions[k] == i) {
                                movement_ranges[j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max({Laharl_position, Etna_position, Flonne_position});

    return 0;
}