#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> towns(5, 0);
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        towns[a]++;
        towns[b]++;
    }

    bool possible = true;
    for (int i = 1; i <= 4; i++) {
        if (towns[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}