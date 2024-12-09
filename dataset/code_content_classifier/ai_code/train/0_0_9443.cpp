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
            int d, x;
            std::cin >> d >> x;

            if (d == 0) {
                A.insert(A.begin(), x);
            } else if (d == 1) {
                A.push_back(x);
            }
        } else if (operation == 1) {
            int p;
            std::cin >> p;
            std::cout << A[p] << std::endl;
        } else if (operation == 2) {
            int d;
            std::cin >> d;
            if (d == 0) {
                A.erase(A.begin());
            } else if (d == 1) {
                A.pop_back();
            }
        }
    }

    return 0;
}