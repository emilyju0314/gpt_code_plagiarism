#include <iostream>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    int width = n;

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        if (height > h) {
            width++;
        }
    }

    cout << width << endl;

    return 0;
}