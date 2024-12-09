#include <iostream>
#include <iomanip>

using namespace std;

bool isLucky(int number) {
    while(number > 0) {
        int digit = number % 10;
        if(digit != 4 && digit != 7) {
            return false;
        }
        number /= 10;
    }
    return true;
}

int main() {
    int pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;

    long long total_pairs = (long long)(pr - pl + 1) * (long long)(vr - vl + 1);
    long long count_lucky = 0;

    for(int p = pl; p <= pr; p++) {
        for(int v = vl; v <= vr; v++) {
            if(min(v, p) <= k && max(v, p) >= k) {
                count_lucky++;
            }
        }
    }

    cout << fixed << setprecision(12) << (double)count_lucky / total_pairs << endl;

    return 0;
}