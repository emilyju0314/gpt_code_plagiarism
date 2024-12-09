#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// #define DEBUG


unsigned long long getint(int x[], int n){
    unsigned long long ret = 0;
    unsigned long long p[n];
    rep(i, n)
        p[i] = 1ll << i;
    rep(i, n)
        ret += x[i] * p[i];
    return ret;
}

int bitcount(int x[], int n){
    int ret = 0;
    rep(i, n)
        ret += x[i];
    return ret;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif
    const int b = 64;
    int q, x, y, bits[b];
    fill(bits, bits + b, 0);
    cin >> q;
    rep(i, q)
    {
        cin >> x;
        if (x == 0)
        {
            cin >> y;
            cout << bits[y] << endl;
        }
        else if (x == 1)
        {
            cin >> y;
            bits[y] = 1;
        }
        else if (x == 2)
        {
            cin >> y;
            bits[y] = 0;
        }
        else if (x == 3)
        {
            cin >> y;
            bits[y] = 1 - bits[y];
        }
        else if (x == 4)
        {
            cout << ( (bitcount(bits, b) == b) ? 1 : 0 ) << endl;
        }
        else if (x == 5)
        {
            cout << ( (bitcount(bits, b) > 0) ? 1 : 0 ) << endl;
        }
        else if (x == 6)
        {
            cout << ( (bitcount(bits, b) == 0) ? 1 : 0 ) << endl;
        }
        else if (x == 7)
        {
            cout << bitcount(bits, b) << endl;
        }
        else if (x == 8)
        {
            printf( "%llu\n", getint(bits, b) );
        }
    }

    return 0;
}

