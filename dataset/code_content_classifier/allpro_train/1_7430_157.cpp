#include <iostream>

using namespace std;

string s;
char ch;

inline bool check(int a, int b, int c)
{
    if (s[a] == s[b] && s[a] == s[c] && s[a] != 's') {
        ch = s[a];
        return true;
    }
    else
        return false;
}

int main()
{
    while (cin >> s) {
        ch = 'd';

        if (check(0, 1, 2) || check(3, 4, 5) || check(6, 7, 8)
            || check(0, 3, 6) || check(1, 4, 7) || check(2, 5, 8)
            || check(0, 4, 8) || check(2, 4, 6))
            cout << ch << endl;
        else
            cout << ch << endl;
    }

    return 0;
}