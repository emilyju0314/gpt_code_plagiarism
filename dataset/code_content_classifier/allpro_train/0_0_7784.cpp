#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int a, b;
    cin >> a >> b;

    int result1 = max(a, b);
    
    cin >> a >> b;

    int result2 = max(a, b);

    cout << result1 << " " << result2 << endl;

    return 0;
}