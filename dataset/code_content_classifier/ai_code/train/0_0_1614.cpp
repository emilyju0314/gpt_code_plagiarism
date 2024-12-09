#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    long long minValue = arr[0] * arr[1] * arr[2];
    int count = 0;
    int i = 0;

    while (i+2 < n && arr[i] * arr[i+1] == minValue) {
        i++;
        count++;
    }

    std::cout << count << std::endl;

    return 0;
} 

// The code reads in the input values into a vector, sorts the vector, then iterates through to find the number of triples that have the minimum product value. It then outputs this count.