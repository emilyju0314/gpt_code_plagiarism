#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> inventory(n);
    map<int, int> count;

    for (int i = 0; i < n; i++) {
        cin >> inventory[i];
        count[inventory[i]]++;
    }

    int new_number = 1;
    for (int i = 0; i < n; i++) {
        if (count[inventory[i]] > 1 || inventory[i] > n) {
            while (count[new_number] > 0) {
                new_number++;
            }
            count[inventory[i]]--;
            count[new_number]++;
            inventory[i] = new_number;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << inventory[i] << " ";
    }

    return 0;
}