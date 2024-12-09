#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minLength = n;
    for (int i = 0; i < n; i++) {
        int length = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                length++;
                i = j;
            } else if (arr[j] == arr[i] + 1) {
                length++;
                arr[i]++;
                i = j;
            }
        }
        minLength = min(minLength, length);
    }

    cout << minLength << endl;

    return 0;
}