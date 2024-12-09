#include <iostream>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> degrees(n);
    int sum = n - 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i == 0 || s[i - 1] == '0') {
                std::cout << -1 << std::endl;
                return 0;
            }
            degrees[i]++;
            degrees[i - 1]++;
            sum -= 2;
        }
    }

    if (sum < 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<std::pair<int, int>> edges;
    int current_vertex = 1;
    for (int i = 0; i < n; i++) {
        while (degrees[i] > 0) {
            edges.push_back({current_vertex, i + 1});
            degrees[i]--;
            degrees[current_vertex - 1]--;
            current_vertex++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        std::cout << edges[i].first << " " << edges[i].second << std::endl;
    }

    return 0;
}