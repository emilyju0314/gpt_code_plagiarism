#include <iostream>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    std::vector<int> A;

    for (int i = 0; i < q; i++) {
        int operation;
        std::cin >> operation;

        if (operation == 0) {
            int x;
            std::cin >> x;
            A.push_back(x);
        } else if (operation == 1) {
            int p;
            std::cin >> p;
            std::cout << A[p] << std::endl;
        } else if (operation == 2) {
            A.pop_back();
        }
    }

    return 0;
}