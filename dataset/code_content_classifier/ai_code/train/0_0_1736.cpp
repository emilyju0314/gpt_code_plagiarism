#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long area = n * m;
    
    if (area % k != 0){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << n << " 0" << endl;
        cout << "0 " << area / k / n << endl;
    }

    return 0;
}