#include <iostream>

using namespace std;

int main() {
    int V1, V2, V3, Vm;
    cin >> V1 >> V2 >> V3 >> Vm;

    int car1 = -1, car2 = -1, car3 = -1;

    // Find possible sizes of cars
    for (int i = V3; i <= Vm; i++) {
        if (i >= 2 * V3 && i < 2 * V2 && 2 * V3 < 2 * V2) {
            car3 = i;
            car2 = 2 * V3;
            car1 = 2 * V2;
            break;
        }
    }

    // Check if valid solution was found
    if (car1 == -1 || car2 == -1 || car3 == -1) {
        cout << -1 << endl;
    } else {
        cout << car1 << endl << car2 << endl << car3 << endl;
    }

    return 0;
}