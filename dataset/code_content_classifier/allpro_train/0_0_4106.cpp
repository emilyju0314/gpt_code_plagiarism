#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct WaterborneVehicle {
    int type;
    int capacity;
    int index;
};

bool compare(WaterborneVehicle a, WaterborneVehicle b) {
    return a.capacity > b.capacity;
}

int main() {
    int n, v;
    cin >> n >> v;

    vector<WaterborneVehicle> vehicles(n);
    for (int i = 0; i < n; i++) {
        cin >> vehicles[i].type >> vehicles[i].capacity;
        vehicles[i].index = i + 1;
    }

    sort(vehicles.begin(), vehicles.end(), compare);

    vector<int> chosenIndexes;
    int totalCapacity = 0;
    for (int i = 0; i < n; i++) {
        if (vehicles[i].type == 1) {
            if (v >= 1) {
                totalCapacity += vehicles[i].capacity;
                v--;
                chosenIndexes.push_back(vehicles[i].index);
            }
        } else {
            if (v >= 2) {
                totalCapacity += vehicles[i].capacity;
                v -= 2;
                chosenIndexes.push_back(vehicles[i].index);
            }
        }
    }

    cout << totalCapacity << endl;
    for (int i = 0; i < chosenIndexes.size(); i++) {
        cout << chosenIndexes[i] << " ";
    }

    return 0;
}