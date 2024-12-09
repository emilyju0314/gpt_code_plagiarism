#include <iostream>

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    std::cin >> a >> b;

    int lcm = (a * b) / gcd(a, b);

    int visits_to_dasha = (lcm / a) - 1;
    int visits_to_masha = (lcm / b) - 1;

    if(visits_to_dasha > visits_to_masha) {
        std::cout << "Dasha" << std::endl;
    } else if(visits_to_dasha < visits_to_masha) {
        std::cout << "Masha" << std::endl;
    } else {
        std::cout << "Equal" << std::endl;
    }

    return 0;
}