#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int num[11];
    for(int i = 0; i < 10; i++) {
        cin >> num[i];
    }
    int aresult, bresult, result;
    for(int i = 0; i < 10; i++) {
        aresult = num[i] * 3;
        bresult = aresult * 5;
        result = aresult + bresult;
        if (result <= 100) {
            cout << "f(" << num[i] << ") = " << fixed << setprecision(2) << result << endl;
        } else {
            cout << "f(" << num[i] << ") = MAGNA NIMIS!" << endl;
        }
    }
    
    return 0;
}