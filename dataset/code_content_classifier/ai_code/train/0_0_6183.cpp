#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, r;
int max_sum = -1;
vector<pair<int, int>> towers;
vector<pair<int, int>> possible_towers;

int calculate_sum(vector<pair<int, int>> &towers) {
    int sum = 0;
    for (int i = 0; i < towers.size(); i++) {
        for (int j = i + 1; j < towers.size(); j++) {
            sum += pow(towers[i].first - towers[j].first, 2) + pow(towers[i].second - towers[j].second, 2);
        }
    }
    return sum;
}

void build_towers(int index, int remaining) {
    if (remaining == 0) {
        int sum = calculate_sum(possible_towers);
        if (sum > max_sum) {
            max_sum = sum;
            towers = possible_towers;
        }
        return;
    }

    for (int x = -30; x <= 30; x++) {
        for (int y = -30; y <= 30; y++) {
            if (pow(x, 2) + pow(y, 2) <= pow(r, 2)) {
                possible_towers.push_back({x, y});
                build_towers(index + 1, remaining - 1);
                possible_towers.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> r;

    build_towers(0, n);

    cout << max_sum << endl;
    for (auto tower : towers) {
        cout << tower.first << " " << tower.second << endl;
    }

    return 0;
}