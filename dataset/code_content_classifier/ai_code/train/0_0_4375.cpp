#include <iostream>
#include <vector>

using namespace std;

int minimumActionsToSortTrain(int n, vector<int>& cars) {
    int maxUnsorted = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i] > maxUnsorted) {
            maxUnsorted = cars[i];
        } else {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i];
    }

    int result = minimumActionsToSortTrain(n, cars);
    cout << result << endl;

    return 0;
}