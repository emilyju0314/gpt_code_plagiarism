#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> deque;
        int inversions = 0;

        for (int i = 0; i < n; i++) {
            if (deque.empty()) {
                deque.push_back(arr[i]);
            } else {
                if (arr[i] >= deque.front()) {
                    deque.insert(deque.begin(), arr[i]);
                } else {
                    deque.push_back(arr[i]);
                    inversions += count_if(deque.begin(), deque.end(), [&](int x) { return x > arr[i]; });
                }
            }
        }

        cout << inversions << endl;
    }

    return 0;
}