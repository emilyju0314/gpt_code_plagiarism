#include <iostream>
#include <map>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::map<int, int> fishCount;
    int maxFishCount = 0;
    std::vector<int> maxParticipants;

    for (int i = 0; i < q; i++) {
        int participant, count;
        std::cin >> participant >> count;

        fishCount[participant] += count;

        if (fishCount[participant] > maxFishCount) {
            maxFishCount = fishCount[participant];
            maxParticipants.clear();
            maxParticipants.push_back(participant);
        } else if (fishCount[participant] == maxFishCount) {
            maxParticipants.push_back(participant);
        }

        std::cout << maxParticipants[0] << " " << maxFishCount << "\n";
    }

    return 0;
}