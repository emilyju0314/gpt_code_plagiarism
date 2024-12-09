#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> scores;
    std::string winner;
    int max_score = 0;

    for (int i = 0; i < n; i++) {
        std::string name;
        int score;
        std::cin >> name >> score;

        scores[name] += score;
        if (scores[name] >= max_score) {
            max_score = scores[name];
            winner = name;
        }
    }

    std::cout << winner << std::endl;

    return 0;
}