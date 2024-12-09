#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> messages(n);
    for (int i = 0; i < n; i++) {
        cin >> messages[i];
    }

    for (int i = 0; i < n; i++) {
        int count = 1; // Include the current message
        int idx = i;

        // Include the previous k messages
        for (int j = 1; j <= k && idx - j >= 0; j++) {
            count++;
            idx = messages[idx - j];
        }

        idx = i;

        // Include the next k messages
        for (int j = 1; j <= k && idx + j < n && messages[idx + j] != 0; j++) {
            count++;
            idx = messages[idx + j];
        }

        cout << count << " ";
    }

    return 0;
}