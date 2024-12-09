#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> votes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> votes[i];
    }

    int bribes = 0;
    int limak_votes = votes[0];

    std::sort(votes.begin(), votes.end(), std::greater<int>());

    while (limak_votes <= votes[1]) {
        limak_votes++;
        votes[0]--;
        bribes++;
        std::sort(votes.begin(), votes.end(), std::greater<int>());
    }

    std::cout << bribes << std::endl;

    return 0;
}