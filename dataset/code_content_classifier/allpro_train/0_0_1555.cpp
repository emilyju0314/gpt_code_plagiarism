#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getCombatPower(int grid[5][5]) {
    int combatPower = 0;

    for (int i = 0; i < 5; i++) {
        int countTypes[4] = {0};

        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 0) continue;
            countTypes[grid[i][j] - 1]++;
        }

        for (int j = 0; j < 4; j++) {
            if (countTypes[j] == 4) {
                combatPower += (j + 1) * 80;
            } else if (countTypes[j] == 3) {
                combatPower += (j + 1) * 70;
                combatPower += 10; // Add bonus points for the missing subject
            } else if (countTypes[j] == 2) {
                combatPower += (j + 1) * 60;
            }
        }
    }

    return combatPower;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int grid[5][5];

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> grid[j][k];
            }
        }

        int combatPower = getCombatPower(grid);
        cout << combatPower << endl;
    }

    return 0;
}