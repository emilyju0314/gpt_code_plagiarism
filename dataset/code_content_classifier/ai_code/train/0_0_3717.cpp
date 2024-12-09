#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    while (true) {
        int H, h, m, s;
        cin >> H >> h >> m >> s;
        if (H == 0 && h == 0 && m == 0 && s == 0) break;

        int start_time = (h * 3600 + m * 60 + s) * H;
        vector<pair<long long, long long>> time_angles = { {0, 1} };

        for (int i = 1; i < H * 3600; i++) {
            long long second_angle = i * 12;
            long long hour_angle = i % H * 3600 * 12 / H + m * 60 * 12 / 3600 + s * 12 / 60;
            long long minute_angle = m * 60 * 12 + s * 12;

            long long angle1 = abs(second_angle - hour_angle);
            long long angle2 = abs(second_angle - minute_angle);

            if (angle1 != angle2) {
                time_angles.push_back({ angle1, angle2 });
                if (time_angles.size() >= 2 && time_angles[time_angles.size() - 1] == time_angles[time_angles.size() - 2]) {
                    long long total_time = start_time + i;
                    long long hh = total_time / 3600 % H;
                    total_time %= 3600;
                    long long mm = total_time / 60;
                    long long ss = total_time % 60;

                    int common_factor = gcd(ss, 180);
                    ss /= common_factor;
                    cout << hh << " " << mm << " " << ss << " " << 180 / common_factor << endl;
                    break;
                }
            }
        }
    }

    return 0;
}