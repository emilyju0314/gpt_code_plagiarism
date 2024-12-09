#include <iostream>
#include <string>
using namespace std;

string findLexicographicallySmallest(int L, string s, string t) {
    int s_len = s.length();
    int t_len = t.length();

    string smallest_string = s + t;

    while(smallest_string.length() < L) {
        if (s.compare(0, s_len, t, 0, t_len) < 0) {
            smallest_string += s;
        } else {
            smallest_string += t;
        }
    }

    return smallest_string.substr(0, L);
}

int main() {
    int N;
    cin >> N;

    string s, t;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x >> s >> t;
        cout << findLexicographicallySmallest(x, s, t) << endl;
    }

    return 0;
}