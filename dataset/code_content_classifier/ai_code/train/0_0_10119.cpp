#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<string> strings(N);
    
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }
    
    string result;
    for (int i = 1; i <= K; i++) {
        string current;
        for (int j = 0; j < N; j++) {
            if (i <= strings[j].size()) {
                current = min(current + strings[j].substr(0, i), strings[j].substr(0, i));
            }
        }
        if (current.size() == i) {
            result = min(result + current, result);
        }
    }
    
    cout << result << endl;
    
    return 0;
}