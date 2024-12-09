#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string victim1, victim2;
    std::cin >> victim1 >> victim2;

    int n;
    std::cin >> n;

    std::vector<std::string> victims;
    victims.push_back(victim1);
    victims.push_back(victim2);

    for (int i = 0; i < n; i++) {
        std::string killed, replaced;
        std::cin >> killed >> replaced;

        // Find the victim and replace it with the new person
        for (int j = 0; j < victims.size(); j++) {
            if (victims[j] == killed) {
                victims[j] = replaced;
                break;
            }
        }

        // Output the current pair of victims
        std::cout << victims[0] << " " << victims[1] << std::endl;
    }

    // Output the pair of victims for the next murder
    std::cout << victims[0] << " " << victims[1] << std::endl;

    return 0;
}