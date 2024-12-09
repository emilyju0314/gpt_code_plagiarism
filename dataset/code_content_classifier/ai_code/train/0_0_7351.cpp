#include <iostream>
#include <vector>
#include <algorithm>

struct Coordinates {
    int x, y, z;
};

int surfaceArea(int s) {
    return 6 * s * s;
}

bool isConnected(std::vector<Coordinates>& cubes, int n, int k, int s) {
    // Implement a function to check if the k cubes form a connected polyhedron
    // using graph traversal algorithms
    return true; // Placeholder, implement actual logic
}

int calculateMinSurfaceArea(std::vector<Coordinates>& cubes, int n, int k, int s) {
    int minSurfaceArea = -1;
    
    // Iterate through all possible combinations of k cubes
    for (int i = 0; i <= n - k; i++) {
        if (isConnected(cubes, n, k, s)) {
            int currentSurfaceArea = 0;

            // Calculate the individual surface areas of each cube
            for (int j = i; j < i + k; j++) {
                currentSurfaceArea += surfaceArea(s);
            }

            // Calculate the connecting surfaces between cubes
            currentSurfaceArea -= 2 * (k - 1) * s * s;

            // Update the minimum surface area found so far
            if (minSurfaceArea == -1 || currentSurfaceArea < minSurfaceArea) {
                minSurfaceArea = currentSurfaceArea;
            }
        }
    }

    return minSurfaceArea;
}

int main() {
    int datasets;
    while (true) {
        std::cin >> datasets;
        if (datasets == 0) break;

        for (int i = 0; i < datasets; i++) {
            int n, k, s;
            std::cin >> n >> k >> s;

            std::vector<Coordinates> cubes(n);
            for (int j = 0; j < n; j++) {
                std::cin >> cubes[j].x >> cubes[j].y >> cubes[j].z;
            }

            int result = calculateMinSurfaceArea(cubes, n, k, s);
            std::cout << result << std::endl;
        }
    }

    return 0;
}