#include <iostream>
#include <string>

int main() {
    int n, m, a, b, c;
    std::cin >> n >> m >> a >> b >> c;

    // Initialize the tiling pattern
    std::string row1 = "###<span class=\"tex-span\">\\</span>#";
    std::string row2 = "##/<span class=\"tex-span\">\\</span>..";
    std::string row3 = "#/....";
    std::string row4 = "/.....";

    // Output the tiling scheme
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a > 0) {
                std::cout << row1 << std::endl;
                std::cout << row2 << std::endl;
                a--;
            } else if (b > 0) {
                std::cout << row3 << std::endl;
                std::cout << row4 << std::endl;
                b--;
            } else {
                if (j % 2 == 0) {
                    std::cout << row1 << std::endl;
                    std::cout << row2 << std::endl;
                } else {
                    std::cout << row3 << std::endl;
                    std::cout << row4 << std::endl;
                }
                c--;
            }
        }
    }

    return 0;
}