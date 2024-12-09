#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int n, t; cin >> n >> t;
    int m = 1<<30, max = 0, cnt = 0;
    while (n--) {
        int a; cin >> a;
        if (a - m > max) { max = a - m; cnt = 1; }
        else if (a - m == max) cnt++;
        m = min(a, m);
    }
    cout << cnt << endl;
}
