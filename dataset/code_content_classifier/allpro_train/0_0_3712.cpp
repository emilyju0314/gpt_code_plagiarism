#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        std::string record;
        std::getline(std::cin, record);

        std::stringstream ss(record);
        std::string temp;
        std::vector<char> train;

        while (getline(ss, temp, '-') || getline(ss, temp, '>')) {
            if (temp.size() == 1) {
                train.push_back(temp[0]);
            }
        }

        std::vector<char> formation(26, '-');
        char prev = train[0];
        formation[train[0] - 'a'] = train[0];
        for (int j = 1; j < train.size(); ++j) {
            char curr = train[j];
            if (std::find(formation.begin(), formation.end(), curr) == formation.end()) {
                for (int k = 0; k < formation.size(); ++k) {
                    if (formation[k] == '-') {
                        formation[k] = curr;
                        break;
                    }
                }
            }
            int prevIndex = std::find(formation.begin(), formation.end(), prev) - formation.begin();
            formation[prevIndex] = '-';
            prev = curr;
        }

        for (char c : formation) {
            if (c != '-') {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}