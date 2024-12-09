#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int days[] = {a/3, b/2, c/2, min(a, min(b, c))};
    sort(days, days+4);

    int max_days = days[3] + days[2]*2 + days[1]*2;
    cout << max_days << endl;

    return 0;
}