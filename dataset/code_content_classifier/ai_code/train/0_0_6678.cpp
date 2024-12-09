#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, vector<int>> digits;
    for(int i = 0; i < 10; i++) {
        digits[i] = vector<int>();
    }

    for(int i = 0; i < n; i++) {
        int num = a[i];
        while(num > 0) {
            digits[num % 10].push_back(a[i]);
            num /= 10;
        }
    }

    for(int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;

        if(type == 1) {
            a[l-1] = r;
            digits.clear();
            for(int j = 0; j < 10; j++) {
                digits[j] = vector<int>();
            }
            for(int j = 0; j < n; j++) {
                int num = a[j];
                while(num > 0) {
                    digits[num % 10].push_back(a[j]);
                    num /= 10;
                }
            }
        } else {
            int ans = -1;

            for(int j = 0; j < 10; j++) {
                sort(digits[j].begin(), digits[j].end());
            }

            for(int j = l-1; j < r; j++) {
                if(ans == 0) break;

                int num = a[j];
                vector<int> nums;

                while(num > 0) {
                    nums.push_back(num % 10);
                    num /= 10;
                }

                for(int k = 0; k < nums.size(); k++) {
                    for(int l = 0; l < digits[nums[k]].size(); l++) {
                        if(digits[nums[k]][l] == a[j]) continue;
                        int candidate = digits[nums[k]][l] + a[j];
                        if(ans == -1 || candidate < ans) {
                            ans = candidate;
                        }
                    }
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}