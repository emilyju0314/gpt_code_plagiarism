#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cashiers(n);
    for(int i=0; i<n; i++) {
        cin >> cashiers[i];
    }

    int min_time = INT_MAX;
    for(int i=0; i<n; i++) {
        int total_time = 0;
        vector<int> items(cashiers[i]);
        for(int j=0; j<cashiers[i]; j++) {
            cin >> items[j];
            total_time += items[j] * 5;
        }
        total_time += 15 * cashiers[i];
        min_time = min(min_time, total_time);
    }

    cout << min_time << endl;

    return 0;
}