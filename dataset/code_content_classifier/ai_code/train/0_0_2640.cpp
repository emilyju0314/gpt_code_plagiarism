#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> columns(n + 2), durabilities(n);
    for (int i = 0; i < n + 2; i++) {
        cin >> columns[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> durabilities[i];
    }

    int min_durability = 0;
    for (int i = 1; i < n + 1; i++) {
        int left_bearing = i - 1, right_bearing = i + 1;
        int supported_length = columns[right_bearing] - columns[left_bearing];

        if (supported_length > durabilities[i - 1]) {
            min_durability = max(min_durability, (supported_length - durabilities[i - 1] + 1) / 2);
        }
    }

    cout << min_durability << endl;

    return 0;
}