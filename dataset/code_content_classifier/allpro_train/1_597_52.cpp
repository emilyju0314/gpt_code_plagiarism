#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

int main() {
    string s;
    while(cin >> s, s != "#") {
        reverse(s.begin(), s.end());
        bitset<128> bi(s);
        bool res = true;
        int idx[7][7] = {{0, 1, 2, 4, 6, 7, 9},
                         {2, 4, 5, 7, 9, 10, 12},
                         {7, 9, 10, 12, 14, 15, 17},
                         {9, 11, 12, 14, 16, 17, 18},
                         {6, 8, 9, 11, 13, 14, 16},
                         {1, 3, 4, 6, 8, 9, 11},
                         {4, 6, 7, 9, 11, 12, 14}};
        for(int i=0; i<(1 << 19); ++i) {
            bitset<19> b2(i);
            bitset<7> center;
            for(int j=0; j<7; ++j) {
                int t = 0;
                for(int k=0; k<7; ++k) {
                    t |= (b2[idx[j][k]] << k);
                }
                center[j] = bi[t];
            }
            int t = 0;
            int idx2[7] = {0, 5, 1, 6, 4, 2, 3};
            for(int j=0; j<7; ++j) {
                t |= (center[idx2[j]] << j);
            }
            res &= (bi[t] == center[idx2[3]]);
        }
        cout << (res ? "yes" : "no") << endl;
    }
}
