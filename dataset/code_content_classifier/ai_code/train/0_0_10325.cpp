#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int operations = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> indexes;
        // Start from the second element and make sure the array is non-decreasing
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) {
                int mex = 0;
                // Find the correct MEX value that does not belong to the array
                while (mex < n && (find(arr.begin(), arr.end(), mex) != arr.end())) {
                    mex++;
                }
                // Replace the element with MEX and update the array
                arr[i] = mex;
                operations++;
                indexes.push_back(i+1);
            }
        }

        cout << operations << endl;
        for (int i : indexes) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}