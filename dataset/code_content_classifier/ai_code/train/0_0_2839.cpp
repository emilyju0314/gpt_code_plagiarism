#include <iostream>
#include <vector>

int main() {
    std::vector<int> countA(2, 0);
    std::vector<int> countB(2, 0);
    std::vector<int> countC(2, 0);
    std::vector<int> countD(2, 0);

    double left, right;
    while (std::cin >> left >> right) {
        if (left >= 1.1) {
            countA[0]++;
        } else if (left >= 0.6) {
            countB[0]++;
        } else if (left >= 0.2) {
            countC[0]++;
        } else {
            countD[0]++;
        }

        if (right >= 1.1) {
            countA[1]++;
        } else if (right >= 0.6) {
            countB[1]++;
        } else if (right >= 0.2) {
            countC[1]++;
        } else {
            countD[1]++;
        }
    }

    std::cout << countA[0] << " " << countA[1] << std::endl;
    std::cout << countB[0] << " " << countB[1] << std::endl;
    std::cout << countC[0] << " " << countC[1] << std::endl;
    std::cout << countD[0] << " " << countD[1] << std::endl;

    return 0;
}