#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int result = nums[0];
    for(int i = 1; i < n; i++) {
        result = gcd(result, nums[i]);
    }
    
    if(result != 1) {
        cout << -1 << endl;
    } else {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                cout << 1 << endl;
                return 0;
            }
        }
        
        int ans = n;
        for(int i = 0; i < n; i++) {
            int temp = nums[i];
            for(int j = 0; j < i; j++) {
                temp = gcd(temp, nums[j]);
                if(temp == 1) {
                    ans = min(ans, i - j);
                }
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}