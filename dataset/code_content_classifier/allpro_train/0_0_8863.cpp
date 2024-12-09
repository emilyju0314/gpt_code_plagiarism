#include <iostream>
#include <vector>
using namespace std;

vector<int> b, a;
vector<vector<int>> dp;

int f(int index, int len, int h) {
    if (index == len) {
        return 1;
    }
    
    if (dp[index][len] != -1) {
        return dp[index][len];
    }
    
    for (int i = 0; i < len; i++) {
        if (a[index] + b[i] >= h) {
            int mem = b[i];
            b[i] = 0;
            int res = f(index + 1, len, h);
            b[i] = mem;
            if (res > 0) {
                dp[index][len] = 1;
                return 1;
            }
        }
    }
    
    dp[index][len] = 0;
    return 0;
}

int getAnswer(int n, int len, int h) {
    int answer = 0;
    for (int i = 0; i <= n - len; i++) {
        answer += f(i, len, h);
    }
    return answer;
}

int main() {
    int n, len, h;
    cin >> n >> len >> h;
    
    b.resize(len);
    for (int i = 0; i < len; i++) {
        cin >> b[i];
    }
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp.assign(n, vector<int>(len, -1));

    int answer = getAnswer(n, len, h);
    cout << answer << endl;

    return 0;
}