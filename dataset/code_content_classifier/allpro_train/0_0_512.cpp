#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isValid(vector<pair<int, int>>& points, int a, int b) {
    int dx = points[a].first - points[b].first;
    int dy = points[a].second - points[b].second;
    double distance = sqrt(dx*dx + dy*dy);
    return distance >= 2.0;
}

void printCombination(vector<int>& comb) {
    sort(comb.begin(), comb.end());
    for(int num : comb) {
        cout << num << endl;
    }
}

void findValidCombinations(vector<pair<int, int>>& points, vector<int>& comb, int n, int k, int index) {
    if(comb.size() == k) {
        printCombination(comb);
        return;
    }
    
    for(int i=index; i<n; i++) {
        bool valid = true;
        for(int num : comb) {
            if(!isValid(points, num, i)) {
                valid = false;
                break;
            }
        }
        
        if(valid) {
            comb.push_back(i);
            findValidCombinations(points, comb, n, k, i+1);
            comb.pop_back();
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> points(N);
    
    for(int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    vector<int> comb;
    findValidCombinations(points, comb, N, K, 0);
    
    if(comb.empty()) {
        cout << "-1" << endl;
    }
    
    return 0;
}