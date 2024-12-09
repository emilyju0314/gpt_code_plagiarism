#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if(n <= 1)
        return 1;
    return n * factorial(n-1);
}

int main() {
    string colors;
    cin >> colors;

    int counts[6] = {};
    for(char c : colors) {
        if(c == 'R') counts[0]++;
        if(c == 'O') counts[1]++;
        if(c == 'Y') counts[2]++;
        if(c == 'G') counts[3]++;
        if(c == 'B') counts[4]++;
        if(c == 'V') counts[5]++;
    }

    sort(counts, counts+6, greater<int>());

    int res = 0;
    int total = colors.size();

    int f = factorial(total);
    for(int i=0; i<6; i++) {
        if(counts[i] == 0) break;
        f /= factorial(counts[i]);
    }

    res = f;

    cout << res << endl;

    return 0;
}