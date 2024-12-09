#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::map<int, int>> moments;

    for (int i = 0; i < n; i++) {
        int a, t, x;
        std::cin >> a >> t >> x;

        if (a == 1) {
            moments[t][x]++;
        } else if (a == 2) {
            moments[t][x]--;
            if (moments[t][x] == 0) {
                moments[t].erase(x);
            }
        } else if (a == 3) {
            int count = 0;
            for (auto it = moments.begin(); it != moments.end(); it++) {
                if (it->first > t) {
                    break;
                }
                count += it->second[x];
            }
            std::cout << count << std::endl;
        }
    }

    return 0;
}