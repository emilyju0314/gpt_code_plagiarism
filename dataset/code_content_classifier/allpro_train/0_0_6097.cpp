#include <iostream>
#include <map>
#include <vector>
#include <sstream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::map<std::string, std::pair<int, std::vector<int>>> residents1, residents2;

    // Parse the input for the first night
    for (int i = 0; i < k; i++) {
        std::string name;
        int room, keys;
        std::cin >> name >> room >> keys;

        std::vector<int> keyList(keys);
        for (int j = 0; j < keys; j++) {
            std::cin >> keyList[j];
        }

        residents1[name] = {room, keyList};
    }

    // Parse the input for the second night
    for (int i = 0; i < k; i++) {
        std::string name;
        int room, keys;
        std::cin >> name >> room >> keys;

        std::vector<int> keyList(keys);
        for (int j = 0; j < keys; j++) {
            std::cin >> keyList[j];
        }

        residents2[name] = {room, keyList};
    }

    // Compare the residents' positions and keys on both nights
    bool canResult = true;
    for (auto it = residents1.begin(); it != residents1.end(); it++) {
        std::string name = it->first;
        if (residents1[name] != residents2[name]) {
            canResult = false;
            break;
        }
    }

    if (canResult) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}