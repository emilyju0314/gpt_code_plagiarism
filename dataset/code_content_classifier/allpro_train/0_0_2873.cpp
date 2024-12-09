#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trees;
    vector<pair<int, int>> mushrooms;

    for (int i = 0; i < n; i++) {
        int ai, hi, li, ri;
        cin >> ai >> hi >> li >> ri;
        trees.push_back({ai, hi});
    }

    for (int i = 0; i < m; i++) {
        int bj, zj;
        cin >> bj >> zj;
        mushrooms.push_back({bj, zj});
    }

    double total_power = 0.0;

    for (auto mushroom : mushrooms) {
        double probability = 1.0;
        for (auto tree : trees) {
            int ai = tree.first;
            int hi = tree.second;

            if (mushroom.first >= ai - hi && mushroom.first < ai) {
                probability *= (double)(100 - tree.third) / 100;
            }
            if (mushroom.first > ai && mushroom.first <= ai + hi) {
                probability *= (double)(100 - tree.fourth) / 100;
            }
        }

        total_power += (double)mushroom.second * probability;
    }

    cout << setprecision(10) << total_power << endl;

    return 0;
}