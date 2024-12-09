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

    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if ((count ^ nums[i]) > count) {
            cout << "2 ";
            count = count ^ nums[i];
        } else {
            cout << "1 ";
        }
    }

    return 0;
}