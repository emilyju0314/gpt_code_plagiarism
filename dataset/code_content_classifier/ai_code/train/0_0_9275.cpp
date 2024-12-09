#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> figures(n);
    for(int i = 0; i < n; i++) {
        std::cin >> figures[i];
    }

    bool infinite = false;
    int distinct_points = 0;
    for(int i = 1; i < n; i++) {
        if((figures[i-1] == 1 && figures[i] == 2) || (figures[i-1] == 2 && figures[i] == 1)) {
            distinct_points += 3;
        } else if((figures[i-1] == 1 && figures[i] == 3) || (figures[i-1] == 3 && figures[i] == 1)) {
            infinite = true;
            break;
        } else if((figures[i-1] == 2 && figures[i] == 3) || (figures[i-1] == 3 && figures[i] == 2)) {
            distinct_points += 4;
        }
    }

    if(infinite) {
        std::cout << "Infinite" << std::endl;
    } else {
        std::cout << "Finite" << std::endl;
        std::cout << distinct_points << std::endl;
    }

    return 0;
}