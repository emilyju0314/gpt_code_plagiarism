#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string leader;
    int maxPoints = INT_MIN;

    for (int i = 0; i < n; i++) {
        string handle;
        int plus, minus, a, b, c, d, e;
        cin >> handle >> plus >> minus >> a >> b >> c >> d >> e;

        int points = plus * 100 - minus * 50 + a + b + c + d + e;

        if (points > maxPoints) {
            maxPoints = points;
            leader = handle;
        }
    }

    cout << leader << endl;

    return 0;
}