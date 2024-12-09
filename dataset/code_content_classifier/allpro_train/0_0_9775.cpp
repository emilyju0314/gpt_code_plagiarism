#include <iostream>
#include <string>

using namespace std;

void evaluate(string s, int idx, long long current, long long sum) {
    if(idx == s.size()) {
        sum += current;
        return;
    }
    
    for(int i = idx; i < s.size(); i++) {
        string num_str = s.substr(idx, i-idx+1);
        long long num = stoll(num_str);
        
        evaluate(s, i+1, num + current, sum);
        evaluate(s, i+1, num, sum);
    }
}

int main() {
    string S;
    cin >> S;
    
    long long sum = 0;
    
    evaluate(S, 0, 0, sum);
    
    cout << sum << endl;
    
    return 0;
}