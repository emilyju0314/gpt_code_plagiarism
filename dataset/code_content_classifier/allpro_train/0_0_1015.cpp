#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, A, B;
    std::cin >> n >> A >> B;

    std::vector<int> sizes(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> sizes[i];
        sum += sizes[i];
    }

    std::sort(sizes.begin(), sizes.end(), std::greater<int>());

    int blocked = 0;
    for(int i = 1; i < n; i++) {
        if(A * sizes[0] < B * sum) {
            sum -= sizes[i];
            blocked++;
        } else {
            break;
        }
    }

    std::cout << blocked << std::endl;

    return 0;
}