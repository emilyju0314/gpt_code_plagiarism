#include <iostream>
using namespace std;

int main() {
    int h1, h2, k1, k2, a, b, c, d;
    cin >> h1 >> h2;
    cin >> k1 >> k2;
    cin >> a >> b >> c >> d;
    
    int hiroshiScore = h1 * a + h2 * b + (h1 / 10) * c + (h2 / 20) * d;
    int kenjiroScore = k1 * a + k2 * b + (k1 / 10) * c + (k2 / 20) * d;
    
    if (hiroshiScore > kenjiroScore) {
        cout << "hiroshi" << endl;
    } else if (hiroshiScore < kenjiroScore) {
        cout << "kenjiro" << endl;
    } else {
        cout << "even" << endl;
    }
    
    return 0;
}