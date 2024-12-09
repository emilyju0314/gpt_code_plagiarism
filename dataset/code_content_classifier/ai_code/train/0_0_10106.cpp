#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int l = s.length();
    int count = 0;

    for (int k = 0; k < l; k++) {
        int unique_shifts = 0;

        for (int i = 1; i < l; i++) {
            int index = (i + k) % l;
            if (s[0] == s[index] && s[1] == s[(i+1+k)%l]) {
                unique_shifts++;
            }
        }

        if (unique_shifts == 1) {
            count++;
        }
    }

    double probability = (double) count / l;
    cout.precision(15);
    cout << probability << endl;

    return 0;
}