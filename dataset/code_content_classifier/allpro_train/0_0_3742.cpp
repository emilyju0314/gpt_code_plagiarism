#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int count = 0;
    
    for (int x = A; x <= B; x++) {
        for (int y = x; y <= C; y++) {
            for (int z = y; z <= D; z++) {
                if (x + y > z) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}