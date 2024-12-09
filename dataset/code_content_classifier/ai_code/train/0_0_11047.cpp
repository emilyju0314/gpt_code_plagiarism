#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> tshirt_counts(6);
    for (int i = 0; i < 6; i++) {
        std::cin >> tshirt_counts[i];
    }

    int n;
    std::cin >> n;

    std::vector<std::string> participants(n);
    for (int i = 0; i < n; i++) {
        std::cin >> participants[i];
    }

    bool possible = true;
    std::vector<std::string> result(n);

    for (int i = 0; i < n; i++) {
        std::string participant = participants[i];
        if (participant.find(',') == std::string::npos) {
            if (tshirt_counts[participant.at(0) - 'A'] > 0) {
                result[i] = participant;
                tshirt_counts[participant.at(0) - 'A']--;
            } else {
                possible = false;
            }
        } else {
            std::string size1 = participant.substr(0, participant.find(','));
            std::string size2 = participant.substr(participant.find(',') + 1);
            if (tshirt_counts[size1.at(0) - 'A'] > 0) {
                result[i] = size1;
                tshirt_counts[size1.at(0) - 'A']--;
            } else if (tshirt_counts[size2.at(0) - 'A'] > 0) {
                result[i] = size2;
                tshirt_counts[size2.at(0) - 'A']--;
            } else {
                possible = false;
            }
        }
    }

    if (possible) {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << result[i] << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}