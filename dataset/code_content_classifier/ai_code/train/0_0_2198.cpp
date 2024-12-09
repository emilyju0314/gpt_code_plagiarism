#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    string street;
    cin >> street;

    int numHouses = 0, numShops = 0;
    for (int i = 0; i < n; i++) {
        if (street[i] == 'H') {
            numHouses++;
        } else if (street[i] == 'S') {
            numShops++;
        }
    }

    int neededKilos = max(numHouses - numShops, 0); 
    if (t < neededKilos) {
        cout << -1 << endl;
    } else {
        cout << neededKilos << endl;
    }

    return 0;
}