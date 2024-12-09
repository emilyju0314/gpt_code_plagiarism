#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Truck {
    int v, c, l, r;
    int index;

    bool operator<(const Truck& other) const {
        return c > other.c; // Sort trucks by the number of people inside
    }
};

int main() {
    int n;
    cin >> n;

    vector<Truck> trucks(n);
    for (int i = 0; i < n; i++) {
        cin >> trucks[i].v >> trucks[i].c >> trucks[i].l >> trucks[i].r;
        trucks[i].index = i + 1;
    }

    set<Truck> passingTrucks;
    int totalPeople = 0;
    int maxValue = 0;

    for (int i = 0; i < n; i++) {
        if (i >= trucks[i].l) {
            passingTrucks.insert(trucks[i]);
            totalPeople += trucks[i].c;
            maxValue += trucks[i].v;
        }

        while (totalPeople > trucks[i].r) {
            Truck truckToRemove = *passingTrucks.begin();
            passingTrucks.erase(truckToRemove);
            totalPeople -= truckToRemove.c;
            maxValue -= truckToRemove.v;
        }
    }

    cout << passingTrucks.size() << endl;
    for (const Truck& truck : passingTrucks) {
        cout << truck.index << " ";
    }
    
    return 0;
}