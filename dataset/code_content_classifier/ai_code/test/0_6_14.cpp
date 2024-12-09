#include <iostream>
#include <vector>

using namespace std;

// Function to perform a cyclic shift on a segment of the array
void cyclicShift(vector<int>& arr, int l, int r, int d) {
    // Extract the segment to be shifted
    vector<int> segment(arr.begin() + l - 1, arr.begin() + r);
    
    // Perform the cyclic shift
    int n = segment.size();
    d %= n;
    reverse(segment.begin(), segment.end());
    reverse(segment.begin(), segment.begin() + n - d);
    reverse(segment.begin() + n - d, segment.end());
    
    // Update the original array with the shifted segment
    for (int i = l - 1, j = 0; i < r; i++, j++) {
        arr[i] = segment[j];
    }
}

// Function to sort the array using cyclic shifts
void sortArray(vector<int>& arr) {
    int n = arr.size();
    
    // Perform n cyclic shifts to sort the array
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, d = i;
        cyclicShift(arr, l, r, d);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Sort the array using cyclic shifts
        sortArray(arr);

        // Output the results
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << "1 " << n << " " << (i + 1) << endl;
        }
    }

    return 0;
}