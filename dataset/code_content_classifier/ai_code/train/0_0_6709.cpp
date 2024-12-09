#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> appleTrees;

    for (int i = 0; i < n; i++) {
        int x, a;
        std::cin >> x >> a;
        appleTrees[x] = a;
    }

    int totalApples = 0;
    int currentPos = 0;
    
    bool goRight = true;

    while (!appleTrees.empty()) {
        if (goRight) {
            auto it = appleTrees.upper_bound(currentPos); 
            if (it == appleTrees.begin()) {
                goRight = false;
            } else {
                it--;
                totalApples += it->second;
                currentPos = it->first;
                appleTrees.erase(it);
            }
        } else {
            auto it = appleTrees.lower_bound(currentPos);
            if (it == appleTrees.end()) {
                goRight = true;
            } else {
                totalApples += it->second;
                currentPos = it->first;
                appleTrees.erase(it);
            }
        }
    }

    std::cout << totalApples << std::endl;
    
    return 0;
}