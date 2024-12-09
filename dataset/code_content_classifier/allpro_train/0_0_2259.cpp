#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<string, int>> numbers(n);
    
    for(int i = 0; i < n; i++) {
        string num;
        int freq;
        cin >> num >> freq;
        numbers[i] = make_pair(num, freq);
    }
    
    sort(numbers.begin(), numbers.end(), compare);
    
    vector<string> speedDials;
    for(int i = 0; i < min(k, n); i++) {
        speedDials.push_back(numbers[i].first);
    }
    
    int totalPresses = 0;
    for(int i = 0; i < n; i++) {
        string num = numbers[i].first;
        int freq = numbers[i].second;
        
        int speedDial = -1;
        for(int j = 0; j < speedDials.size(); j++) {
            if(num.find(speedDials[j]) == 0) {
                speedDial = j;
                break;
            }
        }
        
        if(speedDial != -1) {
            totalPresses += (num.length() - speedDials[speedDial].length()) * freq;
        } else {
            totalPresses += num.length() * freq;
        }
    }
    
    cout << totalPresses << endl;
    
    return 0;
}