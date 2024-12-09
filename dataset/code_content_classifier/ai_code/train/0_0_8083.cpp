#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    string street;
    cin >> street;

    int houses = 0, shops = 0;

    for (char c : street) {
        if (c == 'H') {
            houses++;
        } else if (c == 'S') {
            shops++;
        }
    }

    if (shops >= houses) {
        cout << "0" << endl;
    } else {
        int k = houses - shops;
        int time_needed = 0;

        for (char c : street) {
            if (c == 'H') {
                time_needed++;
            } else if (c == 'S') {
                time_needed = min(time_needed + k, n);
            }

            if (time_needed > t) {
                cout << "-1" << endl;
                return 0;
            }
        }

        cout << k << endl;
    }

    return 0;
}