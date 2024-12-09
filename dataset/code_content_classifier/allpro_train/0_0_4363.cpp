#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string description;
    cin >> description;

    int s = 0, t = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (description[i] == 'R' && description[i + 1] == 'L') {
            s = i + 1;
            t = i + 2;
            break;
        } else if (description[i] == 'L' && description[i + 1] == 'R') {
            s = i + 1;
            t = i + 2;
            break;
        }
    }

    cout << s << " " << t << endl;

    return 0;
}