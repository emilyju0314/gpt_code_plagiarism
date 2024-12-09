#include <iostream>
using namespace std;

int main() {
    int h1, m1, s1, h2, m2, s2, h, m, s;

    for(int i=0; i<3; i++) {
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        h = h2 - h1;
        m = m2 - m1;
        s = s2 - s1;

        if(s < 0) {
            s += 60;
            m--;
        }
        if(m < 0) {
            m += 60;
            h--;
        }

        cout << h << " " << m << " " << s << endl;
    }

    return 0;
}