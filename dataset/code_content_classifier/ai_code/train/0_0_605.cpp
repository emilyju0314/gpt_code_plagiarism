#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::set<int> distinct;
    int mex = 0;

    for (int i = 0; i < n; i++) {
        distinct.insert(arr[i]);
        
        while (distinct.count(mex)) {
            mex++;
        }

        if (mex != arr[i]) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}