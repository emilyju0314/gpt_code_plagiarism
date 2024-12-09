#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int H, L;
    cin >> H >> L;

    double A = (double) (L*L - H*H) / (2.0*H);
    cout << fixed << setprecision(13) << A << endl;

    return 0;
}