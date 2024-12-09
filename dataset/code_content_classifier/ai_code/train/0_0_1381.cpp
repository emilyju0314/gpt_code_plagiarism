#include <iostream>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::tuple<double, double, double>> discs;
        for (int i = 0; i < n; ++i) {
            double x, y, r;
            std::cin >> x >> y >> r;
            discs.push_back(std::make_tuple(x, y, r));
        }

        int visible = 0;
        double maxR = 0;
        for (int i = n - 1; i >= 0; --i) {
            double x = std::get<0>(discs[i]);
            double y = std::get<1>(discs[i]);
            double r = std::get<2>(discs[i]);

            if (r >= maxR) {
                ++visible;
                maxR = r;
            }
        }

        std::cout << visible << std::endl;
    }

    return 0;
}