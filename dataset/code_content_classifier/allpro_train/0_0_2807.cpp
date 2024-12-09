#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int p, q;
    std::cin >> p;
    std::vector<int> levelsX(p);
    for(int i = 0; i < p; i++) {
        std::cin >> levelsX[i];
    }

    std::cin >> q;
    std::vector<int> levelsY(q);
    for(int i = 0; i < q; i++) {
        std::cin >> levelsY[i];
    }

    std::vector<bool> passed(n+1, false);
    for(int level : levelsX) {
        passed[level] = true;
    }
    for(int level : levelsY) {
        passed[level] = true;
    }

    bool canPass = true;
    for(int i = 1; i <= n; i++) {
        if(!passed[i]) {
            canPass = false;
            break;
        }
    }

    if(canPass) {
        std::cout << "I become the guy." << std::endl;
    } else {
        std::cout << "Oh, my keyboard!" << std::endl;
    }

    return 0;
}