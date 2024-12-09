#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> buckets(n);
    for (int i = 0; i < n; i++) {
        cin >> buckets[i];
    }

    int min_hours = k;
    for (int i = 0; i < n; i++) {
        if (k % buckets[i] == 0) {
            min_hours = min(min_hours, k / buckets[i]);
        }
    }

    cout << min_hours << endl;

    return 0;
}