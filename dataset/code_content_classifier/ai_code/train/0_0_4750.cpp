#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        std::cin >> scores[i];
    }

    std::sort(scores.begin(), scores.end(), std::greater<int>());

    int team_score = 0;
    for (int i = 0; i < N; i++) {
        int A = i + 1;
        if (scores[i] >= A) {
            team_score = A;
        }
    }

    std::cout << team_score << std::endl;

    return 0;
}