#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> frequency;
    
    for(int i = 0; i < n; i++) {
        int ti;
        cin >> ti;
        frequency[ti]++;
    }
    
    long long count = 0;
    
    for(auto it = frequency.begin(); it != frequency.end(); it++) {
        int opposite = -it->first;
        if(frequency.find(opposite) != frequency.end()) {
            count += (long long)it->second * frequency[opposite];
        }
    }
    
    cout << count/2 << endl;
    
    return 0;
}