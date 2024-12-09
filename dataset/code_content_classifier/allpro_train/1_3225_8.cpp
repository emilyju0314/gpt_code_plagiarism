#include <bits/stdc++.h>

#define int long long

using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int p;
    cin >> p;
    while (p--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a == 1 && b == 0 && c == 0 && d == 1 && e == 0) {
            cout << 'a';
        }
        if (a == 1 && b == 1 && c == 0 && d == 2 && e == 0) {
            cout << 'b';
        }
        if (a == 2 && b == 0 && c == 0 && d == 1 && e == 1) {
            cout << 'c';
        }
        if (a == 2 && b == 1 && c == 0 && d == 1 && e == 2) {
            cout << 'd';
        }
        if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1) {
            cout << 'e';
        }
        if (a == 2 && b == 1 && c == 0 && d == 2 && e == 1) {
            cout << 'f';
        }
        if (a == 2 && b == 2 && c == 0 && d == 2 && e == 2) {
            cout << 'g';
        }
        if (a == 1 && b == 2 && c == 0 && d == 2 && e == 1) {
            cout << 'h';
        }/*
        if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1) {
            cout << 'i';
        }*/
        if (a == 1 && b == 2 && c == 0 && d == 1 && e == 2) {
            cout << 'j';
        }
        if (a == 1 && b == 0 && c == 1 && d == 2 && e == 0) {
            cout << 'k';
        }
        if (a == 1 && b == 1 && c == 1 && d == 3 && e == 0) {
            cout << 'l';
        }
        if (a == 2 && b == 0 && c == 1 && d == 2 && e == 1) {
            cout << 'm';
        }
        if (a == 2 && b == 1 && c == 1 && d == 2 && e == 2) {
            cout << 'n';
        }
        if (a == 1 && b == 1 && c == 1 && d == 2 && e == 1) {
            cout << 'o';
        }
        if (a == 2 && b == 1 && c == 1 && d == 3 && e == 1) {
            cout << 'p';
        }
        if (a == 2 && b == 2 && c == 1 && d == 3 && e == 2) {
            cout << 'q';
        }
        if (a == 1 && b == 2 && c == 1 && d == 3 && e == 1) {
            cout << 'r';
        }/*
        if (a == 1 && b == 1 && c == 1 && d == 2 && e == 1) {
            cout << 's';
        }*/
        if (a == 1 && b == 2 && c == 1 && d == 2 && e == 2) {
            cout << 't';
        }
        if (a == 1 && b == 0 && c == 2 && d == 2 && e == 1) {
            cout << 'u';
        }
        if (a == 1 && b == 1 && c == 2 && d == 3 && e == 1) {
            cout << 'v';
        }
        if (a == 1 && b == 2 && c == 1 && d == 1 && e == 3) {
            cout << 'w';
        }
        if (a == 2 && b == 0 && c == 2 && d == 2 && e == 2) {
            cout << 'x';
        }
        if (a == 2 && b == 1 && c == 2 && d == 2 && e == 3) {
            cout << 'y';
        }
        if (a == 1 && b == 1 && c == 2 && d == 2 && e == 2) {
            cout << 'z';
        }


    }

}