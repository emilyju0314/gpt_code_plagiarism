#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int maxBeauty = 0;

    for(char c = 'a'; c <= 'b'; c++) {
        int beauty = 0;
        int cnt = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] != c) {
                cnt++;
            }
            while(cnt > k) {
                if(s[j] != c) {
                    cnt--;
                }
                j++;
            }
            beauty = max(beauty, i - j + 1);
        }
        maxBeauty = max(maxBeauty, beauty);
    }

    cout << maxBeauty << endl;

    return 0;
}