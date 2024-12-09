#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char color = 'A';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (char)(color + (i+j)%26);
        }
        cout << endl;
    }

    return 0;
}