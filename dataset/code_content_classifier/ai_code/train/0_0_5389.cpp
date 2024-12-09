#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool is_infected(int x, int y, set<pair<int, int>>& infected_cells) {
    return infected_cells.find({x, y}) != infected_cells.end();
}

bool is_valid(int x, int y) {
    return x >= 0 && y >= 0 && (x % 2 == 0 || y % 2 == 1);
}

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> infected_cells;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        infected_cells.insert({x, y});
    }

    bool recovered = false;
    int k = 0;

    while (!recovered) {
        recovered = true;
        vector<pair<int, int>> newly_infected;

        for (int x = 0; x < 500; x++) {
            for (int y = 0; y < 500; y++) {
                if (is_infected(x, y, infected_cells)) {
                    int infected_neighbors = 0;
                    if (is_infected(x + 1, y, infected_cells)) infected_neighbors++;
                    if (is_infected(x - 1, y, infected_cells)) infected_neighbors++;
                    if (is_infected(x + 1, y - 1, infected_cells) && x % 2 == 0) infected_neighbors++;
                    if (is_infected(x - 1, y + 1, infected_cells) && x % 2 != 0) infected_neighbors++;

                    if (infected_neighbors < 2) {
                        recovered = false;
                    } else {
                        recovered_cells.insert({x, y});
                        newly_infected.push_back({x, y});
                    }
                } else {
                    int healthy_neighbors = 0;
                    if (is_valid(x + 1, y) && is_infected(x + 1, y, infected_cells)) healthy_neighbors++;
                    if (is_valid(x - 1, y) && is_infected(x - 1, y, infected_cells)) healthy_neighbors++;
                    if (is_valid(x + 1, y - 1) && is_infected(x + 1, y - 1, infected_cells) && x % 2 == 0) healthy_neighbors++;
                    if (is_valid(x - 1, y + 1) && is_infected(x - 1, y + 1, infected_cells) && x % 2 != 0) healthy_neighbors++;

                    if (healthy_neighbors >= 2) {
                        infected_cells.insert({x, y});
                        recovered = false;
                    }
                }
            }
        }

        if (newly_infected.empty()) {
            break;
        } else {
            k++;
        }
    }

    if (recovered) {
        cout << "RECOVERED" << endl;
        cout << k << endl;
    } else {
        cout << "SICK" << endl;
    }

    return 0;
}