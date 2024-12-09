#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> voters;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        voters.push_back(make_pair(a, b));
    }
    
    sort(voters.begin(), voters.end(), [](pair<int, int>& x, pair<int, int>& y) {
        return x.second < y.second;
    });
    
    int bribeCost = 0;
    int votes0 = 0, maxVotes = 0;
    
    for(auto voter : voters) {
        if(voter.first == 0) {
            votes0++;
        } else {
            if(votes0 > maxVotes) {
                maxVotes = votes0;
                bribeCost += voter.second;
            } else {
                bribeCost += max(voter.second, 0);
            }
        }
    }
    
    cout << bribeCost << endl;
    
    return 0;
}