#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    std::unordered_set<int> x, y;
    for(int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        x.insert(num);
    }

    for(int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        y.insert(num);
    }

    int count = 0;

    for(int xi : x) {
        for(int yj : y) {
            if(x.count(xi ^ yj)) {
                count++;
            }
        }
    }

    if(count % 2 == 0) {
        std::cout << "Karen" << std::endl;
    } else {
        std::cout << "Koyomi" << std::endl;
    }

    return 0;
}