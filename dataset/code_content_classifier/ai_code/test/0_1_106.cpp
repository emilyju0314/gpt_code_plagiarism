#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n, 1); // Initialize array with all elements as 1
        
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i-1] * 2; // Update each element to be double of the previous element
        }

        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}