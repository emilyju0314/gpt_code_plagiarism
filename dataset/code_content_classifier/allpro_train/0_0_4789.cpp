#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> image(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> image[i][j];
        }
    }

    int circles = 0;
    int squares = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (image[i][j] == 1) { // If pixel color is black
                int circlePixels = 0;
                for (int x = -10; x <= 10; x++) {
                    for (int y = -10; y <= 10; y++) {
                        if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n) {
                            if (image[i+x][j+y] == 1) {
                                circlePixels++;
                                image[i+x][j+y] = 0; // Mark pixel as visited
                            }
                        }
                    }
                }
                double radius = sqrt(circlePixels / M_PI);
                if (fabs(radius - round(radius)) < 0.1) { // Check if radius is close to an integer
                    circles++;
                } else {
                    squares++;
                }
            }
        }
    }

    std::cout << circles << " " << squares << std::endl;

    return 0;
}