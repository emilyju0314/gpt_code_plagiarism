#include <iostream>
#include <vector>
#include <unordered_set>

bool areRelativelyPrime(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a == 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_set<int> activeColliders;
    std::vector<int> requests(m);

    for(int i = 0; i < m; ++i) {
        char c;
        int num;
        std::cin >> c >> num;

        if(c == '+') {
            bool conflict = false;
            for(int active : activeColliders) {
                if(!areRelativelyPrime(active, num)) {
                    conflict = true;
                    std::cout << "Conflict with " << active << std::endl;
                    break;
                }
            }
            if(!conflict) {
                activeColliders.insert(num);
                std::cout << "Success" << std::endl;
            }
        } else if (c == '-') {
            if(activeColliders.find(num) != activeColliders.end()) {
                activeColliders.erase(num);
                std::cout << "Success" << std::endl;
            } else {
                std::cout << "Already off" << std::endl;
            }
        }
    }

    return 0;
}