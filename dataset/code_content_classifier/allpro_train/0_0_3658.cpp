#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int result = n;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                result--;
            }
        }

        cout << result << endl;
    }

    return 0;
}