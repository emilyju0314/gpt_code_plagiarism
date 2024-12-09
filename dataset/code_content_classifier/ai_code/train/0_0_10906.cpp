#include <iostream>
#include <cmath>

int main() {
    int N, D;
    while (true) {
        std::cin >> N >> D;
        if (N == 0 && D == 0) {
            break;
        }

        double x = 0, y = 0;
        double angle = 0;

        for (int i = 0; i < N; i++) {
            int Lspeed, Rspeed, time;
            std::cin >> Lspeed >> Rspeed >> time;

            double dt = time;
            double angleL = Lspeed / 360.0 * 2 * M_PI;
            double angleR = Rspeed / 360.0 * 2 * M_PI;

            x += (angleL + angleR) / 2 * D * cos(angle);
            y += (angleL + angleR) / 2 * D * sin(angle);

            angle += (angleR - angleL) * dt;
        }

        std::cout << std::fixed;
        std::cout.precision(5);
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    }

    return 0;
}