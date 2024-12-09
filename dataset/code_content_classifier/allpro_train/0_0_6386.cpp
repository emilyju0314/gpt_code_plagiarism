#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int total = (999 * 1000) / 2; // sum of first 999 natural numbers
    int snow_cover = b - a;
    
    cout << total - snow_cover << endl;

    return 0;
}