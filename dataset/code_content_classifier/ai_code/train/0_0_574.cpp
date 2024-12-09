#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x1, x2;
    std::cin >> n >> x1 >> x2;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<std::pair<int, int>> servers;

    for (int i = 0; i < n; i++) {
        servers.push_back({c[i], i+1});
    }

    std::sort(servers.begin(), servers.end(), std::greater<std::pair<int, int>>());

    for (int i = 1; i <= n; i++) {
        int k1 = i;
        int k2 = n - i;

        bool possible = true;

        double x1_per_server = (double)x1 / k1;
        double x2_per_server = (double)x2 / k2;

        std::vector<int> servers_used_for_s1, servers_used_for_s2;

        for (int j = 0; j < n; j++) {
            if (j < k1 && servers[j].first >= x1_per_server) {
                servers_used_for_s1.push_back(servers[j].second);
            } else if (j >= k1 && servers[j].first >= x2_per_server) {
                servers_used_for_s2.push_back(servers[j].second);
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "Yes\n";
            std::cout << k1 << " " << k2 << "\n";
            for (int server : servers_used_for_s1) {
                std::cout << server << " ";
            }
            std::cout << "\n";
            for (int server : servers_used_for_s2) {
                std::cout << server << " ";
            }
            std::cout << "\n";
            return 0;
        }
    }

    std::cout << "No\n";

    return 0;
}