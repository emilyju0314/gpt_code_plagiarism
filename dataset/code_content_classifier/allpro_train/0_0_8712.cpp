#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> seq1, seq2;
    int last_num = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > last_num) {
            seq1.push_back(arr[i]);
            last_num = arr[i];
        } else {
            seq2.push_back(arr[i]);
        }
    }

    for(int num : seq1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for(int num : seq2) {
        std::cout << num << std::endl;
    }

    return 0;
}