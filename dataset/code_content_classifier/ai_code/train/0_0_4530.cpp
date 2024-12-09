#include <iostream>
#include <algorithm>

int main() {
    int x, y, z;
    int x1, y1, z1;
    int a[6];

    std::cin >> x >> y >> z;
    std::cin >> x1 >> y1 >> z1;
    for (int i = 0; i < 6; i++) {
        std::cin >> a[i];
    }

    // Sort the coordinates of the box
    int coordinates[3] = {x1, y1, z1};
    std::sort(coordinates, coordinates+3);

    int sum = 0;

    // Check if Vasya sees the number on the face parallel to the XZ plane
    if (x >= 0 && x <= coordinates[0] && y >= 0 && y <= coordinates[1] && z >= 0 && z <= coordinates[2]) {
        sum += a[1];
    }

    // Check if Vasya sees the number on the face parallel to the YZ plane
    if (x >= 0 && x <= coordinates[0] && y >= 0 && y <= coordinates[1] && z >= 0 && z <= coordinates[2]) {
        sum += a[5];
    }

    // Check if Vasya sees the number on the face parallel to the XY plane
    if (x >= 0 && x <= coordinates[0] && y >= 0 && y <= coordinates[1] && z >= 0 && z <= coordinates[2]) {
        sum += a[3];
    }

    std::cout << sum << std::endl;

    return 0;
}