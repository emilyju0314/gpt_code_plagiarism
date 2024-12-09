#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int totalMinutes = 22 * a;
    int hours = b / totalMinutes;
    int minutes = b % totalMinutes;

    cout << hours << " " << minutes << endl;

    return 0;
}