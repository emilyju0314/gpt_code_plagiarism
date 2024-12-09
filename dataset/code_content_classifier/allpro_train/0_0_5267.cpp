#include <iostream>
#include <vector>

int main() {
    while (true) {
        int n, m;
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<int> participants(n);
        for (int i = 0; i < n; i++) {
            participants[i] = i + 1;
        }

        int current = 0;
        while (participants.size() > 1) {
            current = (current + m - 1) % participants.size();
            participants.erase(participants.begin() + current);
        }

        std::cout << participants[0] << std::endl;
    }

    return 0;
}