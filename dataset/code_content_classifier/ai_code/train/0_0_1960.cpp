#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int odd_sum = 0, even_sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            odd_sum += nums[i];
        } else {
            even_sum += nums[i];
        }
    }

    if (odd_sum % 2 != 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}