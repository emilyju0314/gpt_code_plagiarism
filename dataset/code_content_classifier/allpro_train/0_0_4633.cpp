#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int max_len = 0;
    int len = 1;

    for (int i = 0; i < n - 1; i++) {
        // Check if the current range is almost constant
        if (abs(data[i] - data[i + 1]) <= 1) {
            len++;
        } else {
            max_len = max(max_len, len);
            len = 1;
        }
    }

    max_len = max(max_len, len);

    cout << max_len << endl;

    return 0;
}