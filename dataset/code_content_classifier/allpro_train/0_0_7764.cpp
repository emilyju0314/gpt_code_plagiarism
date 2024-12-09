#include <iostream>

using namespace std;

int main() {
    long long A, B, x, y, z;
    cin >> A >> B >> x >> y >> z;

    long long needYellow = x * 2 + y;
    long long needBlue = y + z * 3;

    long long additionalYellow = max(0LL, needYellow - A);
    long long additionalBlue = max(0LL, needBlue - B);

    cout << additionalYellow + additionalBlue << endl;

    return 0;
}