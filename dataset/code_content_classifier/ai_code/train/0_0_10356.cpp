#include <iostream>
using namespace std;

int main() {
    int a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;

    int count = 0;

    for(int k = 0; ; k++) {
        int val1 = a1*k + b1;
        if(val1 > R) break;
        for(int l = 0; ; l++) {
            int val2 = a2*l + b2;
            if(val2 > R) break;
            if(val1 == val2 && val1 >= L && val2 >= L) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}