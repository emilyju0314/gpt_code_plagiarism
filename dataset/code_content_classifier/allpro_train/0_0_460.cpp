#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool contains_zero(int num) {
    while (num > 0) {
        if (num % 10 == 0) {
            return true;
        }
        num /= 10;
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    
    vector<int> nums(k);
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    vector<int> chosen;
    
    for (int i = 0; i < k; i++) {
        chosen.push_back(nums[i]);
        for (int j = i + 1; j < k; j++) {
            if (contains_zero(nums[i]) || contains_zero(nums[j])) {
                chosen.push_back(nums[j]);
            }
        }
        if (chosen.size() == 3) {
            break;
        }
    }
    
    cout << chosen.size() << endl;
    for (int num : chosen) {
        cout << num << " ";
    }
    
    return 0;
}