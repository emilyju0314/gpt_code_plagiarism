#include <iostream>
#include <unordered_set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_set<std::string> wordsPolandBall, wordsEnemyBall;

    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        wordsPolandBall.insert(word);
    }

    for (int i = 0; i < m; i++) {
        std::string word;
        std::cin >> word;
        wordsEnemyBall.insert(word);
    }

    // Determine the winner
    int totalWords = wordsPolandBall.size() + wordsEnemyBall.size();
    int intersection = 0;

    for (const std::string& word : wordsPolandBall) {
        if (wordsEnemyBall.find(word) != wordsEnemyBall.end()) {
            intersection++;
        }
    }

    if (totalWords % 2 == 0) {
        if (intersection % 2 == 0) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    } else {
        if (wordsPolandBall.size() > wordsEnemyBall.size()) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}