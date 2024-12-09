#include <iostream>
#include <vector>

using namespace std;

int num_steps_to_zero(vector<int>& arr, int n, int d) {
    vector<int> temp(n);
    int steps = 0;
    
    // Continue the process until all elements are zero or a cycle is repeating
    while (true) {
        bool all_zeros = true;
        
        for (int i = 0; i < n; i++) {
            temp[i] = arr[(i + n - d) % n] & arr[i];
            if (all_zeros && temp[i] == 1) {
                all_zeros = false; // if any element is non-zero, set the flag to false
            }
        }
        
        if (all_zeros) {
            return steps + 1; // return the number of steps if all elements are zeros
        }
        
        steps++;
        arr = temp; // update the array for the next iteration
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = num_steps_to_zero(arr, n, d);
        cout << ans << endl;
    }

    return 0;
}