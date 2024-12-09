#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> problems;

    int sum = 0;
    int i = 1;
    while (sum + i <= N) {
        sum += i;
        problems.push_back(i);
        i++;
    }

    if (sum < N) {
        problems.push_back(N - sum);
    }

    for (int problem : problems) {
        std::cout << problem << std::endl;
    }

    return 0;
}