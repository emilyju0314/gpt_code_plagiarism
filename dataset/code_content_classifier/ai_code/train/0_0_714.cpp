#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<string> likes(n);
    for(int i = 0; i < n; i++) {
        cin >> likes[i];
    }

    int min_likes = (n + 1) / 2;
    vector<int> currencies_likes(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(likes[i][j] == '1') {
                currencies_likes[j]++;
            }
        }
    }

    string result;
    for(int j = 0; j < m; j++) {
        if(currencies_likes[j] >= min_likes) {
            result += '1';
        } else {
            result += '0';
        }
    }

    cout << result << endl;

    return 0;
}