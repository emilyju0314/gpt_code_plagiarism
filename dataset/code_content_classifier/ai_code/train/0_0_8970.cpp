#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long day = 1;
    while (n > 0) {
        // Calculate the number of grains left after sparrows eat
        n -= day;
        if (n <= 0) {
            break;
        }
        // Add grains brought on current day
        n += m;
        day++;
    }

    cout << day << endl;

    return 0;
}