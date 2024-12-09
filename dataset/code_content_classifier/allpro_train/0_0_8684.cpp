#include <iostream>

using namespace std;

int main() {
    int w, h;
    cin >> w >> h;

    long long rhombi = 0;

    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= h; j++) {
            rhombi += min(i, w-i+1) * min(j, h-j+1);
        }
    }

    cout << rhombi << endl;

    return 0;
}