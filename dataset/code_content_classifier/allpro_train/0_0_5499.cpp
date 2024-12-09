#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> f(n), b(m);
    std::unordered_map<int, std::vector<int>> indexMap;

    for(int i = 0; i < n; i++) {
        std::cin >> f[i];
        indexMap[f[i]].push_back(i + 1);
    }

    for(int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    bool possible = true, ambiguous = false;
    std::vector<int> a(m);

    for(int i = 0; i < m; i++) {
        if(indexMap.find(b[i]) == indexMap.end()) {
            possible = false;
            break;
        } else if(indexMap[b[i]].size() > 1) {
            ambiguous = true;
        }

        a[i] = indexMap[b[i]][0];
    }

    if(!possible) {
        std::cout << "Impossible" << std::endl;
    } else if(ambiguous) {
        std::cout << "Ambiguity" << std::endl;
    } else {
        std::cout << "Possible" << std::endl;
        for(int i = 0; i < m; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}