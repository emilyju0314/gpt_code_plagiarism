#include <iostream>
using namespace std;

int main() {
    int k, a, b, v;
    cin >> k >> a >> b >> v;

    int boxes = 0;
    while(a > 0) {
        int sections = min(k, b+1);
        int nuts_capacity = min(sections*v, a);
        a -= nuts_capacity;
        boxes++;
    }

    cout << boxes << endl;

    return 0;
}