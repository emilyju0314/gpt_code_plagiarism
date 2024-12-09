#include <bits/stdc++.h>
using namespace std;
int main()
{
    int K;
    cin >> K;
    vector<int> I(K);
    for (int i = 0; i < K; i++) {
        string s;
        cin >> s;
        I[i] = s[0] == 'm' ? 0 : s[0] == 't' ? 1 : 2;
    }
    vector<int> N(K);
    for (int i = 0; i < K; i++) {
        string s;
        cin >> s;
        N[i] = s[0] == 'm' ? 0 : s[0] == 't' ? 1 : 2;
    }
    int p1 = 0, p2 = 0;
    for (int i = 0; i < K; i++) {
        bool l1 = false, l2 = false;
        if (I[i] == 0) {
            if (N[i] == 0) {
            } else if (N[i] == 1) {
                p2 = min(p2 + 1, 5);
            } else {
                l2 = p2 == 0 ? true : false;
                l1 = p2 == 5 ? true : false;
                p2 = 0;
            }
        } else if (I[i] == 1) {
            p1 = min(p1 + 1, 5);
            if (N[i] == 0) {
            } else if (N[i] == 1) {
                p2 = min(p2 + 1, 5);
            } else {
                l2 = p2 == 0 ? true : false;
                l1 = p2 > 0 ? true : false;
                p2 = 0;
            }
        } else {
            if (N[i] == 0) {
                l1 = p1 == 0 ? true : false;
                l2 = p1 == 5 ? true : false;
            } else if (N[i] == 1) {
                p2 = min(p2 + 1, 5);
                l1 = p1 == 0 ? true : false;
                l2 = p1 > 0 ? true : false;
            } else {
                if (p1 == 0 and p2 == 0) {
                    l1 = l2 = false;
                } else if (p1 == 0 or p2 == 0) {
                    l1 = p1 == 0 ? true : false;
                    l2 = p2 == 0 ? true : false;
                } else {
                    l1 = p1 < p2;
                    l2 = p2 < p1;
                }
                p2 = 0;
            }
            p1 = 0;
        }
        if (l1 and not l2) { return (cout << "Nakajima-kun" << endl), 0; }
        if (not l1 and l2) { return (cout << "Isono-kun" << endl), 0; }
    }
    cout << "Hikiwake-kun" << endl;
    return 0;
}

