#include <iostream>
#include <algorithm>

int main() {
    int x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;

    int arr[] = {x1, x2, x3};
    std::sort(arr, arr+3);

    int min_distance = arr[2] - arr[0];

    std::cout << min_distance << std::endl;

    return 0;
}