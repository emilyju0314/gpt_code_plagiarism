#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total = 0, best_sum = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    
    long long sum1 = 0;
    for(int i = 0; i < n - 1; i++) {
        sum1 += arr[i];
        if (2 * sum1 == total) {
            best_sum = sum1;
        }
    }

    cout << best_sum << endl;

    return 0;
}