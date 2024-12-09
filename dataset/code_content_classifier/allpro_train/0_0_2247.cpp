#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

int main() {
    std::map<std::string, std::set<std::string>> handMap = {
        {"Rock", {"Scissors", "Snake", "Human", "Tree", "Wolf", "Sponge"}},
        {"Fire", {"Scissors", "Snake", "Human", "Tree", "Wolf", "Paper"}},
        {"Scissors", {"Snake", "Human", "Tree", "Wolf", "Sponge", "Paper"}},
        {"Snake", {"Human", "Tree", "Wolf", "Sponge", "Paper", "Air"}},
        {"Human", {"Tree", "Wolf", "Sponge", "Paper", "Air", "Water"}},
        {"Tree", {"Wolf", "Sponge", "Paper", "Air", "Water", "Dragon"}},
        {"Wolf", {"Sponge", "Paper", "Air", "Water", "Dragon", "Devil"}},
        {"Sponge", {"Paper", "Air", "Water", "Dragon", "Devil", "Lightning"}},
        {"Paper", {"Air", "Water", "Dragon", "Devil", "Lightning", "Gun"}},
        {"Air", {"Water", "Dragon", "Devil", "Lightning", "Gun"}},
        {"Water", {"Dragon", "Devil", "Lightning", "Gun"}},
        {"Dragon", {"Devil", "Lightning", "Gun"}},
        {"Devil", {"Lightning", "Gun"}},
        {"Lightning", {"Gun"}},
        {"Gun", {}}
    };

    int N;
    while (std::cin >> N && N != 0) {
        std::map<std::string, int> winCount;
        std::vector<std::string> hands;

        for (int i = 0; i < N; ++i) {
            std::string hand;
            std::cin >> hand;
            hands.push_back(hand);
        }

        for (const auto& h1 : hands) {
            int count = 0;
            for (const auto& h2 : hands) {
                if (h1 == h2) continue;
                if (handMap[h1].count(h2) > 0) ++count;
            }
            winCount[h1] = count;
        }

        bool draw = true;
        for (const auto& pair : winCount) {
            if (pair.second == 0) continue;
            if (pair.second == N - 1) {
                std::cout << pair.first << std::endl;
                draw = false;
                break;
            }
        }

        if (draw) std::cout << "Draw" << std::endl;
    }

    return 0;
}