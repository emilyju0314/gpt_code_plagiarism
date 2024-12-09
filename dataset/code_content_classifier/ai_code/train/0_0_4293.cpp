#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    for(int i = 1; i <= n; i++) {
        count += (m + i) / 5 - (i / 5);
    }

    cout << count << endl;

    return 0;
}