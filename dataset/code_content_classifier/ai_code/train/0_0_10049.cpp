#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > i+1) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}