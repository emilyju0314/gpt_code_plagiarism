#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string shots;
    cin >> shots;

    vector<int> positions;
    int consecutiveMisses = 0;

    for (int i = 0; i < n; i++) {
        if (shots[i] == '0') {
            consecutiveMisses++;
        } else {
            if (consecutiveMisses >= b) {
                for (int j = 1; j < b; j++) {
                    positions.push_back(i - j);
                }
            }
            consecutiveMisses = 0;
        }
    }

    int remainingShots = a - positions.size() / (b - 1);

    cout << remainingShots << endl;
    for (int i = 0; i < remainingShots; i++) {
        cout << positions[i] << " ";
    }

    return 0;
}