#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    string t = "";

    if (s[0] == 'o' && s[N-1] == 'o') {
        cout << -1 << endl;
        return 0;
    }

    if (s[0] == 'o') {
        t += "SS";
    } else {
        t += "SW";
    }

    for (int i = 1; i < N-1; i++) {
        if (s[i] == 'o') {
            if (t[i] == 'S') {
                t += "S";
            } else {
                t += "W";
            }
        } else {
            if (t[i] == 'S') {
                t += "W";
            } else {
                t += "S";
            }
        }
    }

    if (s[N-1] == 'o') {
        if (t[N-1] == t[0]) {
            cout << -1 << endl;
            return 0;
        } else {
            t += "S";
        }
    } else {
        if (t[N-1] == t[0]) {
            t += "W";
        } else {
            t += "S";
        }
    }

    cout << t << endl;

    return 0;
}