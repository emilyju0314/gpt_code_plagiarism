#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

int main() {
    int n;
    double l, w;

    while (cin >> n >> l >> w && n > 0) {
        double r = w / 2.0; // 半徑為寬度的一半

        double angle = 2.0 * PI / n; // 每個扇形的角度

        double min_area = 0.0;
        for (int i = 0; i < n; i++) {
            // 計算切割得到的扇形面積
            double x = l / 2.0 + r * cos(i * angle + angle / 2.0);
            double y = r * sin(i * angle + angle / 2.0);
            double area = (x * r) / 2.0;

            // 更新最小面積
            if (i == 0 || area < min_area) {
                min_area = area;
            }
        }

        cout << fixed;
        cout.precision(3);
        cout << min_area << endl;
    }

    return 0;
}