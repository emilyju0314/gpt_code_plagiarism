#include <iostream>
#include <vector>

int bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    int exchanges = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                exchanges++;
            }
        }
    }

    return exchanges;
}

int main() {
    int n;
    while(std::cin >> n) {
        if(n == 0) break;

        std::vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        int exchanges = bubbleSort(arr);
        std::cout << exchanges << std::endl;
    }

    return 0;
}