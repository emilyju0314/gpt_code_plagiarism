#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> requests(n);
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int totalRequests = 0;
        for (int j = i; j < n; j++) {
            totalRequests += requests[j];
            if (totalRequests > 100 * (j - i + 1)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    cout << maxLength << endl;

    return 0;
}