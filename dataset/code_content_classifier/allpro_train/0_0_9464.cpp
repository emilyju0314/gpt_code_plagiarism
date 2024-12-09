#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> longest_seq(n, 0);
    
    int current_length = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            current_length++;
            longest_seq[i] = current_length;
        } else {
            current_length = 0;
        }
    }
    
    long long total_sum = 0;
    
    for(int i = 0; i < n; i++) {
        long long current_sum = 0;
        
        for(int j = i; j < n; j++) {
            current_sum += longest_seq[j];
            total_sum += current_sum;
        }
    }
    
    cout << total_sum << endl;
    
    return 0;
}