#include <iostream>

using namespace std;

int main() {
    int Li, Ri, Ln, Rn;
    cin >> Li >> Ri;
    cin >> Ln >> Rn;

    int total_fingers_Isono = Li + Ri;
    int total_fingers_Nakajima = Ln + Rn;

    if(total_fingers_Isono % 2 == 0) {
        cout << "ISONO" << endl;
    } else {
        cout << "NAKAJIMA" << endl;
    }

    return 0;
}