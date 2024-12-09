#include <iostream>

int main() {
    int L, A, B, C, D;
    std::cin >> L >> A >> B >> C >> D;

    int jap_days = (A + C - 1) / C;
    int math_days = (B + D - 1) / D;

    int days_to_finish = std::max(jap_days, math_days);

    std::cout << L - days_to_finish << std::endl;

    return 0;
}