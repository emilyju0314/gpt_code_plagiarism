#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int z;
    std::vector<int> cubes;

    while (std::cin >> z && z != 0) {
        for (int x = 1; x <= z; x++) {
            for (int y = 1; y <= z; y++) {
                if (x*x*x + y*y*y <= z*z*z)
                    cubes.push_back(x*x*x + y*y*y);
            }
        }

        int max_cube = *std::max_element(cubes.begin(), cubes.end());
        std::cout << z*z*z - max_cube << std::endl;
        cubes.clear();
    }

    return 0;
}