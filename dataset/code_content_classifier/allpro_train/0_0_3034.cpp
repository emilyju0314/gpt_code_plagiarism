#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> friends(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> friends[i];
    }

    std::vector<int> possible_friends;
    for (int i = 0; i <= n; ++i) {
        std::vector<int> temp_friends(friends);
        temp_friends.push_back(i);

        std::sort(temp_friends.begin(), temp_friends.end());

        bool valid = true;
        for (int j = 0; j <= n; ++j) {
            if (temp_friends[j] < j) {
                valid = false;
                break;
            }
        }

        if (valid) {
            possible_friends.push_back(i);
        }
    }

    if (possible_friends.empty()) {
        std::cout << -1 << std::endl;
    } else {
        for (int i : possible_friends) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}