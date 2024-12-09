#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> tiles(n);
    vector<int> ones, twos;
    for (int i = 0; i < n; i++) {
        cin >> tiles[i];
        if (tiles[i] == 1) {
            ones.push_back(tiles[i]);
        } else {
            twos.push_back(tiles[i]);
        }
    }

    sort(ones.begin(), ones.end());
    sort(twos.begin(), twos.end());

    if (ones.size() > 0 && twos.size() > 0) {
        if (is_prime(2 + 2)) {
            cout << "2 ";
        }
        for (int i = 0; i < ones.size(); i++) {
            cout << ones[i] << " ";
        }
        for (int i = 0; i < twos.size(); i++) {
            cout << twos[i] << " ";
        }
    } else {
        for (int i = 0; i < ones.size(); i++) {
            cout << ones[i] << " ";
        }
        for (int i = 0; i < twos.size(); i++) {
            cout << twos[i] << " ";
        }
    }

    return 0;
}