#include <iostream>
#include <string>

int main() {
    std::string ticket;
    std::cin >> ticket;

    int A = ticket[0] - '0';
    int B = ticket[1] - '0';
    int C = ticket[2] - '0';
    int D = ticket[3] - '0';

    for (char op1 : {'+', '-'}) {
        for (char op2 : {'+', '-'}) {
            for (char op3 : {'+', '-'}) {
                if (A + (op1 == '+' ? B: -B) + (op2 == '+' ? C: -C) + (op3 == '+' ? D: -D) == 7) {
                    std::cout << A << op1 << B << op2 << C << op3 << D << "=" << 7 << std::endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}