#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> count(10, 0);

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        count.assign(10, 0);

        int CP = l - 1, DP = 1;

        while(CP >= l-1 && CP <= r-1) {
            if(s[CP] >= '0' && s[CP] <= '9') {
                int digit = s[CP] - '0';
                count[digit]++;

                if(digit == 0) {
                    s.erase(CP, 1);
                    r--;
                } else {
                    s[CP] = (digit - 1) + '0';
                }

                CP += DP;
            } else if(s[CP] == '<') {
                DP = -1;
                if (CP - 1 >= l-1) {
                    s.erase(CP, 1);
                    r--;
                }
                CP += DP;
            } else if(s[CP] == '>') {
                DP = 1;
                if (CP + 1 < r) {
                    s.erase(CP, 1);
                    r--;
                }
                CP += DP;
            }
        }

        for(int j = 0; j < 10; j++) {
            cout << count[j] << " ";
        }
        cout << endl;
    }

    return 0;
}