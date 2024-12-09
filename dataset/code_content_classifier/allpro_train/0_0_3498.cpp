#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int freq[3]; // To count the occurrences of 1s and 2s
    for(int i = 1; i <= 2; i++) {
        freq[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int min_changes = n; // Initially set to maximum possible value

    for(int i = 1; i <= 2; i++) {
        int num_changes = 0;
        int diff = freq[i] - n/k;

        for(int j = 0; j < n; j += k) {
            for(int l = 0; l < k; l++) {
                if(arr[j + l] != i) {
                    num_changes++;
                }
            }
        }

        min_changes = std::min(min_changes, num_changes);
    }

    std::cout << min_changes << std::endl;

    return 0;
}