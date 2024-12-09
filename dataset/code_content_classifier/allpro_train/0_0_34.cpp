#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int count = 0;
    for(int i = 0; i <= n/a; i++) {
        for(int j = 0; j <= n/b; j++) {
            int total = i*a + j*b;
            if(total <= n && (n - total) % c == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}