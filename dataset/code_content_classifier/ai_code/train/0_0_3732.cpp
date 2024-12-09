#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    std::unordered_set<std::pair<int, int>> bills;

    for (int i = 0; i < n; ++i) {
        char type;
        int x, y, h, w;
        std::cin >> type;

        if (type == '+') {
            std::cin >> x >> y;
            bills.insert({x, y});
        } else {
            std::cin >> h >> w;
            bool fit = true;
            for (const auto& bill : bills) {
                int x = bill.first;
                int y = bill.second;
                if (!((x <= h && y <= w) || (y <= h && x <= w))) {
                    fit = false;
                    break;
                }
            }
            std::cout << (fit ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}