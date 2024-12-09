#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long k;
    int t;
    cin >> k >> t;

    string result = "";
    vector<int> count(16, 0);
    
    for(int i = 1; i <= 16; i++) {
        count[i-1] = i;
    }

    while(k > 0) {
        for(int i = 15; i >= 1; i--) {
            if(count[i] > t) {
                count[i] = 1;
                count[i-1]++;
            }
        }
        
        string num = "";
        for(int i = 0; i <= 15; i++) {
            for(int j = 0; j < count[i]; j++) {
                num += char(i < 10 ? '0' + i : 'a' + i - 10);
            }
        }
        
        if(k > num.size()) {
            k -= num.size();
        } else {
            result = num[k-1] + result;
            break;
        }

        count[15]++;
    }

    cout << result << endl;

    return 0;
}