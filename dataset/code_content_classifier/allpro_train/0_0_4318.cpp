#include <iostream>
#include <vector>
#include <algorithm>

struct Player {
    int number;
    double time;
};

bool comparePlayers(Player p1, Player p2) {
    return p1.time < p2.time;
}

int main() {
    std::vector<Player> group1(8);
    std::vector<Player> group2(8);
    std::vector<Player> group3(8);

    for (int i = 0; i < 8; i++) {
        std::cin >> group1[i].number >> group1[i].time;
    }

    for (int i = 0; i < 8; i++) {
        std::cin >> group2[i].number >> group2[i].time;
    }

    for (int i = 0; i < 8; i++) {
        std::cin >> group3[i].number >> group3[i].time;
    }

    std::sort(group1.begin(), group1.end(), comparePlayers);
    std::sort(group2.begin(), group2.end(), comparePlayers);
    std::sort(group3.begin(), group3.end(), comparePlayers);

    std::cout << group1[0].number << " " << group1[0].time << std::endl;
    std::cout << group1[1].number << " " << group1[1].time << std::endl;
    std::cout << group2[0].number << " " << group2[0].time << std::endl;
    std::cout << group2[1].number << " " << group2[1].time << std::endl;
    std::cout << group3[0].number << " " << group3[0].time << std::endl;
    std::cout << group3[1].number << " " << group3[1].time << std::endl;
    
    std::vector<Player> allPlayers = {group1[2], group1[3], group2[2], group2[3], group3[2], group3[3]};
    std::sort(allPlayers.begin(), allPlayers.end(), comparePlayers);
    
    std::cout << allPlayers[0].number << " " << allPlayers[0].time << std::endl;
    std::cout << allPlayers[1].number << " " << allPlayers[1].time << std::endl;

    return 0;
}