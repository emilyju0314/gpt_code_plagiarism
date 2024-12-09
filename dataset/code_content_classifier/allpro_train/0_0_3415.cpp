#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int maxVal = 0;

    // case 1: a*(b+c)
    int val1 = a*(b+c);
    maxVal = max(maxVal, val1);

    // case 2: (a+b)*c
    int val2 = (a+b)*c;
    maxVal = max(maxVal, val2);

    // case 3: a+b*c
    int val3 = a+b*c;
    maxVal = max(maxVal, val3);

    // case 4: a*b+c
    int val4 = a*b+c;
    maxVal = max(maxVal, val4);

    // case 5: a*(b*c)
    int val5 = a*(b*c);
    maxVal = max(maxVal, val5);

    cout << maxVal << endl;

    return 0;
}