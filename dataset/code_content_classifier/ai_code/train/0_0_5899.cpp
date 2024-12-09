#include <iostream>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    while(q--) {
        int n;
        std::cin >> n;

        std::vector<int> p(n);
        for(int i = 0; i < n; i++) {
            std::cin >> p[i];
            p[i]--; // 0-indexed permutation
        }

        std::vector<int> days(n, 0);

        for(int i = 0; i < n; i++) {
            std::vector<bool> visited(n, false);
            int j = i;
            int day = 1;
            visited[j] = true;

            while(true) {
                j = p[j];
                if (visited[j]) {
                    days[i] = day;
                    break;
                }
                visited[j] = true;
                day++;
            }
        }

        for(int i = 0; i < n; i++) {
            std::cout << days[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}