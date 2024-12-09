#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t1, t2, t3, t4, t5;
    cin >> t1 >> t2 >> t3 >> t4 >> t5;

    int sum = t1 + t2 + t3 + t4 + t5;
    int minSum = sum;

    int arr[5] = {t1, t2, t3, t4, t5};
    sort(arr, arr+5);

    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 4; j++) {
            for(int k = j + 1; k < 5; k++) {
                if(arr[i] == arr[j] && arr[j] == arr[k]) {
                    minSum = min(minSum, (sum - 3*arr[i]));
                }
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = i + 1; j < 3; j++) {
            for(int k = j + 1; k < 4; k++) {
                for(int l = k + 1; l < 5; l++) {
                    if(arr[i] == arr[j] && arr[j] == arr[k]) {
                        minSum = min(minSum, (sum - 3*arr[i] - arr[l]));
                    } else if(arr[j] == arr[k] && arr[k] == arr[l]) {
                        minSum = min(minSum, (sum - 3*arr[j] - arr[i]));
                    }
                }
            }
        }
    }

    cout << minSum << "\n";

    return 0;
}