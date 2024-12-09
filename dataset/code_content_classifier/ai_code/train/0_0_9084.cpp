#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<string> strings(N);
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            string tempA = strings[a-1].substr(b-1);
            string tempC = strings[c-1].substr(0, d);

            strings[a-1] = strings[a-1].substr(0, b-1) + strings[c-1].substr(d);
            strings[c-1] = strings[c-1].substr(0, d) + tempA;

        } else if (type == 2) {
            int a, b;
            char c;
            cin >> a >> b >> c;

            strings[a-1][b-1] = c;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << strings[i] << endl;
    }

    return 0;
}