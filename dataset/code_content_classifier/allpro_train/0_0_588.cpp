#include <iostream>
using namespace std;

int main() {
    int e1, e2, e3, e4;
    cin >> e1 >> e2 >> e3 >> e4;

    if(e1 == e2 + e3 + e4 || e2 == e1 + e3 + e4 || e3 == e1 + e2 + e4 || e4 == e1 + e2 + e3) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}