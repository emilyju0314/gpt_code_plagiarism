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

    long long count = 0;
    int min_value = arr[0];
    int max_value = arr[0];
    for (int i = 0; i < n; i++) {
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
        if (min_value == max_value) {
            count += i + 1;
            min_value = arr[i];
            max_value = arr[i];
        }
    }

    cout << count << endl;

    return 0;
}