#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Character {
    std::string name;
    int votes;
};

bool compareByVotes(const Character& a, const Character& b) {
    return a.votes > b.votes;
}

int main() {
    int N, M, K, L;

    while (true) {
        std::cin >> N >> M >> K >> L;
        if (N == 0 && M == 0 && K == 0 && L == 0) break;

        std::unordered_map<std::string, int> characterVotes;
        for (int i = 0; i < N; i++) {
            std::string name;
            int votes;
            std::cin >> name >> votes;
            characterVotes[name] = votes;
        }

        std::vector<Character> favorites;
        for (int i = 0; i < M; i++) {
            std::string fav;
            std::cin >> fav;
            favorites.push_back({fav, characterVotes[fav]});
        }

        std::sort(favorites.begin(), favorites.end(), compareByVotes);

        int count = 0;
        for (int i = 0; i < K; i++) {
            if (i < favorites.size() && favorites[i].votes >= L) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}