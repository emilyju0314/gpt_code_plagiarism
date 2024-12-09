#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> choices(n);
    for (int i = 0; i < n; i++) {
        cin >> choices[i];
    }

    sort(choices.begin(), choices.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x = choices[i];
            int y = choices[j];
            int a = abs(x);
            int b = abs(y);
            int min_val = min(a, b);
            int max_val = max(a, b);

            int arr_min = min(min_val, abs(x - y));
            int arr_max = max(max_val, abs(x + y));

            if (2*min_val <= max_val && arr_max <= abs(x + y) && arr_min >= abs(x - y)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}