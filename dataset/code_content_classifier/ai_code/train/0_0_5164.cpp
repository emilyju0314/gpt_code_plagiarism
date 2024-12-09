#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> scores(6);
    for(int i = 0; i < 6; i++) {
        std::cin >> scores[i];
    }

    std::sort(scores.begin(), scores.end());

    bool found = false;
    do {
        int team1 = scores[0] + scores[1] + scores[2];
        int team2 = scores[3] + scores[4] + scores[5];
        if(team1 == team2) {
            found = true;
            break;
        }
    } while(std::next_permutation(scores.begin(), scores.end()));

    if(found) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}