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

    int missingNumber = 0;
    for (int i = 0; i < n; i++) {
        missingNumber = missingNumber ^ i ^ nums[i];
    }
    missingNumber = missingNumber ^ n;

    cout << missingNumber << endl;

    return 0;
}