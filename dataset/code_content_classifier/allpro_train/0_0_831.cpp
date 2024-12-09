#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Souvenir {
    int weight;
    int cost;
};

bool compareByCost(const Souvenir &a, const Souvenir &b) {
    return a.cost > b.cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Souvenir> souvenirs(n);
    for (int i = 0; i < n; i++) {
        cin >> souvenirs[i].weight >> souvenirs[i].cost;
    }

    sort(souvenirs.begin(), souvenirs.end(), compareByCost);

    int totalWeight = 0, totalCost = 0;
    for (int i = 0; i < n; i++) {
        if (totalWeight + souvenirs[i].weight <= m) {
            totalWeight += souvenirs[i].weight;
            totalCost += souvenirs[i].cost;
        } else {
            int remainingWeight = m - totalWeight;
            totalCost += souvenirs[i].cost * (remainingWeight / souvenirs[i].weight);
            break;
        }
    }

    cout << totalCost << endl;

    return 0;
}