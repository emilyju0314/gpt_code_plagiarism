#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(2*n-1);

    for(int i = 0; i < 2*n-1; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int neg_count = 0;
    bool odd_neg = false;

    for(int num : arr) {
        if(num < 0) {
            neg_count++;
            if(num % 2 != 0) {
                odd_neg = true;
            }
            num = -num;
        }
        sum += num;
    }

    if(neg_count % 2 != 0 && odd_neg) {
        int min_abs = *min_element(arr.begin(), arr.end());
        sum -= 2*min_abs;
    }

    cout << sum << endl;

    return 0;
}