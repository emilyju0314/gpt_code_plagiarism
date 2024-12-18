#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int mex = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] >= mex) {
            mex++;
        }
    }

    std::cout << mex << std::endl;

    return 0;
}