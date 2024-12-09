#include <iostream>
#include <vector>
#include <algorithm>

int mex(std::vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int mex = 0;
    for (int num : arr) {
        if (num == mex) {
            mex++;
        } else if (num > mex) {
            break;
        }
    }
    return mex;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int total_xor = 0;
    for (int i = 0; i < n; i++) {
        total_xor ^= arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;

        total_xor ^= x;
        arr.push_back(total_xor);
        std::cout << mex(arr) << std::endl;
    }

    return 0;
}