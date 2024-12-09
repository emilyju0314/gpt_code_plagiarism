#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;

    vector<int> count(10, 0);
    for(char c : num) {
        count[c - '0']++;
    }

    int min_sum = 0;
    string new_num = num;
    for(int i = 0; i < 10; i++) {
        if(count[i] >= k) {
            cout << min_sum << endl;
            for(int j = 0; j < n; j++) {
                cout << new_num[j];
            }
            return 0;
        }
    }

    for(int i = 0; i < 10; i++) {
        if(count[i] < k) {
            for(int j = 0; j < n; j++) {
                if(count[num[j] - '0'] <= k) {
                    min_sum += min(abs(num[j] - '0' - i), abs(i - num[j] + 10));
                    new_num[j] = i + '0';
                    count[num[j] - '0']--;
                    count[i]++;
                    if(count[i] == k) {
                        break;
                    }
                }
            }
        }
    }

    cout << min_sum << endl;
    for(char c : new_num) {
        cout << c;
    }

    return 0;
}