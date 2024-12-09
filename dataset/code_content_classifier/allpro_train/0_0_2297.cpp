#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> towers(n);
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    int operations = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            operations++;
        } else {
            operations += abs(towers[i] - towers[i - 1]) + 1;
        }
    }

    cout << operations << endl;

    return 0;
}