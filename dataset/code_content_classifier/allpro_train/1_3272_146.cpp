#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
double x[4], y[4], a, b, c, s, r, S;
int main(void){
    // Your code here!
    for (ll i = 0; i < 3; i++) cin >> x[i] >> y[i];
    a = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
    b = sqrt(pow(x[1] - x[2], 2) + pow(y[2] - y[1], 2));
    c = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));
    s = (a + b + c) / 2;
    S = sqrt(s * (s - a) * (s - b) * (s - c));
    r = S / s;
    double lb = 0, ub = r;
    for (ll i = 0; i < 10000; i++){
        double mid = (lb + ub) / 2;
        if (max(a, max(b, c)) * (1 - mid / r) >= 2 * mid) lb = mid;
        else ub = mid;
    }
    printf("%.10lf\n",lb);
}
