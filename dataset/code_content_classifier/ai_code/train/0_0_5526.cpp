#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<string> problems(N);
    for(int i = 0; i < N; i++) {
        cin >> problems[i];
    }
    
    vector<int> counter(26, 0);
    
    for(int i = 0; i < N; i++) {
        counter[problems[i][0] - 'A']++;
    }
    
    int maxKUPCs = 0;
    for(int i = 0; i < 26; i++) {
        if(counter[i] >= K) {
            maxKUPCs += (counter[i] / K);
        }
    }
    
    cout << maxKUPCs << endl;
    
    return 0;
}