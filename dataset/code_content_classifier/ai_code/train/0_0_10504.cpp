#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> nums(2*n);
        for(int i = 0; i < 2*n; i++) {
            cin >> nums[i];
        }

        int odd_count = 0;
        for(int i = 0; i < 2*n; i++) {
            if(nums[i] % 2 == 1) {
                odd_count++;
            }
        }

        if(odd_count == n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}