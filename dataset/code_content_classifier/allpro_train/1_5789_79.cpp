#include <bits/stdc++.h>
using namespace std;

int solve(map<string,int>& m, string str) {
    int res = 0;
    for (int i = 0, len = str.size(); i < len; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            int now;
            if (i + 1 < len && 'a' <= str[i+1] && str[i+1] <='z') {
                auto tmp = string(str.begin() + i, str.begin() + i + 2);
                if (m.find(tmp) != m.end())
                    now = m[tmp];
                else
                    return -1;
                i++;
            } else {
                auto tmp = string(str.begin() + i, str.begin() + i + 1);
                if (m.find(tmp) != m.end())
                    now = m[tmp];
                else
                    return -1;
            }
            if (i + 1 < len && '0' <= str[i+1] && str[i+1] <= '9') {
                int j = i + 1;
                while (j < len && '0' <= str[j] && str[j] <= '9') j++;
                auto num = string(str.begin() + i + 1, str.begin() + j);
                stringstream ss;
                ss << num;
                int n;
                ss >> n;
                res += n * now;
                i = j - 1;
            } else {
                res += now;
            }
        }
        else {
            int count = 1;
            int j = i + 1;
            while (count) {
                if (str[j] == '(') count++;
                if (str[j] == ')') count--;
                j++;
            }
            auto tmp = string(str.begin() + i + 1, str.begin() + j - 1);
            int k = j;
            while (j < len && '0' <= str[j] && str[j] <= '9') j++;
            stringstream ss;
            ss << string(str.begin() + k, str.begin() + j);
            int num;
            ss >> num;
            int n = solve(m, tmp);
            if (n < 0) return -1;
            res += num * n;
            i = j - 1;
        }
    }

    return res;
}

int main() {
    map<string,int> m;
    for (string str; ; ) {
        cin >> str;
        if (str == "END_OF_FIRST_PART") break;
        int num;
        cin >> num;
        m[str] = num;
    }

    for (string str; cin >> str, str != "0"; ) {
        int ans = solve(m, str);
        if (ans < 0) cout << "UNKNOWN" << endl;
        else cout << ans << endl;
    }

    return 0;
}