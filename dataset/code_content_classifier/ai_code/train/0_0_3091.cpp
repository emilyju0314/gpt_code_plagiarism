#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double hour_angle = (H * 30.0) + (M * 0.5);
    double minute_angle = M * 6.0;

    double angle_diff = abs(hour_angle - minute_angle);

    double distance = sqrt(pow(A,2) + pow(B,2) - 2*A*B*cos(angle_diff * M_PI / 180));

    cout << distance << endl;

    return 0;
}