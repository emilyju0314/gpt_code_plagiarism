#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int W, H, w, h, x, y;
    cin >> W >> H >> w >> h >> x >> y;

    double area_total = W * H;
    double area_consumed = w * h;

    double m = (2 * W * H - 2 * W * w - 2 * H * h + 2 * w * x + 2 * h * y) / (2 * (W - w));
    
    cout << fixed << setprecision(9) << m << endl;

    return 0;
}