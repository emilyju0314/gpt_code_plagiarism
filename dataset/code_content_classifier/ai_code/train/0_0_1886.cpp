#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    unordered_map<int, int> freq;
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    int result = 0;
    for (auto it : freq) {
        if (it.second > it.first) {
            result += it.second - it.first;
        } else if (it.second < it.first) {
            result += it.second;
        }
    }
    
    cout << result << endl;
    
    return 0;
}