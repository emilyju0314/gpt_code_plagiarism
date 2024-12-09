#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    
    for (int i = 1; i < n; i++) {
        if (n % i == 0 && (n / i) * 2 > i && i * 2 != n / i) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}