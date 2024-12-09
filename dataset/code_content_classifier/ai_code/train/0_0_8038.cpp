#include<iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int total_charge = 0;
        for (int i = 0; i < n; i++) {
            int x, y, h, w;
            cin >> x >> y >> h >> w;
            int size = x + y + h;
            if (size <= 60) {
                if (w <= 2) {
                    total_charge += 600;
                } else if (w <= 5) {
                    total_charge += 800;
                } else if (w <= 10) {
                    total_charge += 1000;
                } else if (w <= 15) {
                    total_charge += 1200;
                } else if (w <= 20) {
                    total_charge += 1400;
                }
            } else if (size <= 80) {
                if (w <= 2) {
                    total_charge += 800;
                } else if (w <= 5) {
                    total_charge += 1000;
                } else if (w <= 10) {
                    total_charge += 1200;
                } else if (w <= 15) {
                    total_charge += 1400;
                } else if (w <= 20) {
                    total_charge += 1600;
                }
            } else if (size <= 100) {
                if (w <= 2) {
                    total_charge += 1000;
                } else if (w <= 5) {
                    total_charge += 1200;
                } else if (w <= 10) {
                    total_charge += 1400;
                } else if (w <= 15) {
                    total_charge += 1600;
                }
            } else if (size <= 120) {
                if (w <= 2) {
                    total_charge += 1200;
                } else if (w <= 5) {
                    total_charge += 1400;
                } else if (w <= 10) {
                    total_charge += 1600;
                }
            } else if (size <= 140) {
                if (w <= 2) {
                    total_charge += 1400;
                } else if (w <= 5) {
                    total_charge += 1600;
                }
            } else if (size <= 160) {
                if (w <= 2) {
                    total_charge += 1600;
                }
            }
        }
        cout << total_charge << endl;
    }
    return 0;
}