#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    unordered_map<int, int> cnt;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    int max_len = 0;
    int start_num, second_num;
    
    for(auto num : cnt) {
        if(num.second >= 4 && num.second % 2 == 0) {
            if(num.second > max_len) {
                max_len = num.second;
                start_num = num.first;
                second_num = num.first;
            }
        } else if(num.second >= 2 && num.second % 2 == 0) {
            int len = num.second;
            unordered_map<int, int> pairs;
            for(int i = 0; i < n; i++) {
                if(a[i] == num.first && pairs[a[i]] < len/2) {
                    cnt[a[i]]--;
                    pairs[a[i]]++;
                }
            }
            if(len > max_len) {
                max_len = len;
                start_num = num.first;
                second_num = num.first;
            }
        }
    }
    
    cout << max_len * 2 << endl;
    
    for(int i = 0; i < max_len; i++) {
        cout << start_num << " ";
        if(i % 2 == 1) {
            cout << second_num << " ";
        }
    }
    
    return 0;
}