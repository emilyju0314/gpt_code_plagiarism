#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    bool possible = true;

    for (int i = 0; i < n; i++) {
        if (numbers[i] == numbers[(i + 1) % n] || abs(numbers[i] - numbers[(i + 1) % n]) != 1) {
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