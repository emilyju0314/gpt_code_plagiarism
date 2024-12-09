#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i];
    }

    int rest_days = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || activities[i] != activities[i-1]) {
            rest_days++;
        }
    }

    cout << n - rest_days << endl;

    return 0;
}