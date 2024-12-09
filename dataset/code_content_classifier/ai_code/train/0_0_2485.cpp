#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long k, a_start, b_start;
    cin >> k >> a_start >> b_start;

    vector<vector<int>> alice_choices(3, vector<int>(3));
    vector<vector<int>> bob_choices(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> alice_choices[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> bob_choices[i][j];
        }
    }

    int alice_points = 0, bob_points = 0;
    vector<int> game_choices = {0, a_start, b_start};

    for (long long i = 1; i <= k; i++) {
        int alice_choice = game_choices[1];
        int bob_choice = game_choices[2];

        if (alice_choice != bob_choice) {
            if (alice_choices[alice_choice - 1][bob_choice - 1] == 1) {
                alice_points++;
            } else {
                bob_points++;
            }
        }

        game_choices[1] = alice_choices[alice_choice - 1][bob_choice - 1];
        game_choices[2] = bob_choices[alice_choice - 1][bob_choice - 1];
        
        if (game_choices == vector<int> {0, a_start, b_start}) {
            long long remaining_games = k - i;
            long long cycle_length = i - 1;
            long long full_cycles = remaining_games / cycle_length;
            i += full_cycles * cycle_length;
        }
    }

    cout << alice_points << " " << bob_points << endl;

    return 0;
}