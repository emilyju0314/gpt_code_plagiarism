#include <iostream>
#include <cmath>

using namespace std;

bool areConnected(double c1_x, double c1_y, double c1_z, double v1_1_x, double v1_1_y, double v1_1_z, double v1_2_x, double v1_2_y, double v1_2_z,
                  double c2_x, double c2_y, double c2_z, double v2_1_x, double v2_1_y, double v2_1_z, double v2_2_x, double v2_2_y, double v2_2_z) {
    double dotProduct = (c2_x - c1_x) * (v1_1_x * v2_1_x + v1_1_y * v2_1_y + v1_1_z * v2_1_z) + (c2_y - c1_y) * (v1_1_x * v2_2_x + v1_1_y * v2_2_y + v1_1_z * v2_2_z) + (c2_z - c1_z) * (v1_1_x * v1_1_z + v1_1_y * v2_2_y + v1_1_z * v2_2_z);

    if(dotProduct == 0) {
        return true;
    }

    return false;
}

int main() {
    double c1_x, c1_y, c1_z, v1_1_x, v1_1_y, v1_1_z, v1_2_x, v1_2_y, v1_2_z;
    double c2_x, c2_y, c2_z, v2_1_x, v2_1_y, v2_1_z, v2_2_x, v2_2_y, v2_2_z;

    cin >> c1_x >> c1_y >> c1_z;
    cin >> v1_1_x >> v1_1_y >> v1_1_z >> v1_2_x >> v1_2_y >> v1_2_z;
    cin >> c2_x >> c2_y >> c2_z;
    cin >> v2_1_x >> v2_1_y >> v2_1_z >> v2_2_x >> v2_2_y >> v2_2_z;

    if(areConnected(c1_x, c1_y, c1_z, v1_1_x, v1_1_y, v1_1_z, v1_2_x, v1_2_y, v1_2_z, c2_x, c2_y, c2_z, v2_1_x, v2_1_y, v2_1_z, v2_2_x, v2_2_y, v2_2_z)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}