#include <iostream>
#include <algorithm>

int main() {
    int k;
    std::cin >> k;

    int arr[12];
    for(int i = 0; i < 12; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr+12, std::greater<int>());

    int months = 0;
    int total = 0;
    for(int i = 0; i < 12; i++) {
        if(total >= k) {
            break;
        }
        total += arr[i];
        months++;
    }

    if(total < k) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << months << std::endl;
    }

    return 0;
}