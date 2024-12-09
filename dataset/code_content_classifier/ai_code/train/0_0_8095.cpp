#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, min1, max1, min2, max2, min3, max3;
    cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;

    int sum_min = min1 + min2 + min3;
    int sum_max = max1 + max2 + max3;

    int num1 = min(max1, n - sum_min);
    int num2 = min(max2, n - num1 - min3);
    int num3 = n - num1 - num2;

    cout << num1 << " " << num2 << " " << num3 << endl;

    return 0;
}