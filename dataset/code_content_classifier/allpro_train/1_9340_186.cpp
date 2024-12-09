#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int q;
    while (cin >> q && q != -1) {
        double x1 = q / 2.0;
        while (true) {
            if (abs(x1*x1*x1 - q) < 0.00001*q) {
                break;
            }
            double t1 = 3*x1*x1;
            x1 = x1 - (x1 / 3.0 - q / t1);
        }
        printf("%.06lf", x1);
        cout << endl;
    }
    return 0;
}