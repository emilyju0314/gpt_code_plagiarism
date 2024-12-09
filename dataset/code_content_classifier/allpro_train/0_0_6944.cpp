#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> arr;
        arr.push_back(x);
        arr.push_back(y);

        int diff = y - x;
        for (int i = 2; i < n; i++) {
            int next_element = arr[i-1] + diff;
            arr.push_back(next_element);
        }

        int max_element = arr[n-1];
        while (max_element > 1e9) {
            max_element -= diff;
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}