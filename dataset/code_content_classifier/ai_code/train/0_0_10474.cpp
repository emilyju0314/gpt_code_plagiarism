#include <iostream>
#include <complex>
#include <vector>
#include <set>

int main() {
    int d;
    std::cin >> d;
    std::vector<int> coeff(d + 1);
    for (int i = 0; i <= d; i++) {
        std::cin >> coeff[i];
    }

    int m = 0;
    std::set<std::complex<int>> solutions;

    for (int real = -1000; real <= 1000; real++) {
        for (int img = -1000; img <= 1000; img++) {
            std::complex<int> z(real, img);
            std::complex<int> eval = coeff[d];
            for (int i = d-1; i >= 0; i--) {
                eval = eval * z + coeff[i];
            }
            if (eval == 0) {
                solutions.insert(z);
                m++;
            }
        }
    }

    std::cout << m << std::endl;
    for (const auto& sol : solutions) {
        std::cout << sol.real() << (sol.imag() < 0 ? "" : "+") << sol.imag() << "i ";
    }

    return 0;
}