#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> arr[i];
    }

    int swaps = 0;
    for (int i = 0; i < 2*n; i += 2) {
        int j = i + 1;
        while (arr[j] != arr[i]) {
            j++;
        }
        while (j > i + 1) {
            swap(arr[j], arr[j-1]);
            j--;
            swaps++;
        }
    }

    cout << swaps << endl;
    
    return 0;
}