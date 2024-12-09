#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int nonDecreasing = 1;
    int nonIncreasing = 1;
    
    int minSwaps = 0;
    int prev = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] >= prev) {
            nonDecreasing++;
        } else {
            minSwaps = max(minSwaps, nonDecreasing);
            nonDecreasing = 1;
        }
        
        prev = arr[i];
    }

    minSwaps = max(minSwaps, nonDecreasing);

    prev = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= prev) {
            nonIncreasing++;
        } else {
            minSwaps = max(minSwaps, nonIncreasing);
            nonIncreasing = 1;
        }

        prev = arr[i];
    }

    minSwaps = max(minSwaps, nonIncreasing);

    cout << n - minSwaps << endl;

    return 0;
}