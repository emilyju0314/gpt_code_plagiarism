#include <iostream>

struct Quaternion {
    int x, y, z, w;
};

Quaternion multiplyQuaternions(Quaternion q1, Quaternion q2) {
    Quaternion result;
    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    return result;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            Quaternion q1, q2;
            std::cin >> q1.x >> q1.y >> q1.z >> q1.w >> q2.x >> q2.y >> q2.z >> q2.w;
            Quaternion result = multiplyQuaternions(q1, q2);
            std::cout << result.w << std::endl;
        }
    }
    return 0;
}