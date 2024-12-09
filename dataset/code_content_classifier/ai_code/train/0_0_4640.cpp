#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, int> traitors;
    bool cancel = false;

    for(int i = 0; i < m; i++) {
        int k;
        std::cin >> k;

        std::vector<int> group(k);
        for(int j = 0; j < k; j++) {
            std::cin >> group[j];
        }

        for(int j = 0; j < k; j++) {
            if(traitors.count(abs(group[j])) && traitors[abs(group[j])] * group[j] < 0) {
                cancel = true;
                break;
            } else {
                traitors[abs(group[j])] = group[j] > 0 ? 1 : -1;
            }
        }
    }

    if(cancel) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}