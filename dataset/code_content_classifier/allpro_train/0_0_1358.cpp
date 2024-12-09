#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> students(n+1);
    vector<vector<int>> boy_friends;
    vector<vector<int>> girl_friends;
    
    for(int i = 1; i <= n; i++) {
        int f, s;
        cin >> f >> s;
        students[i] = {f, s};
        if(s == 1) {
            boy_friends[f].push_back(i);
        } else {
            girl_friends[f].push_back(i);
        }
    }
    
    vector<pair<int, int>> pairs;
    int total_pairs = 0, boy_girl_pairs = 0;
    unordered_set<int> paired;
    
    for(int i = 1; i <= n; i++) {
        if(paired.find(i) != paired.end()) {
            continue;
        }
        
        if(students[i].second == 1) {
            for(int bf : boy_friends[i]) {
                if(paired.find(bf) == paired.end()) {
                    pairs.push_back({i, bf});
                    paired.insert(i);
                    paired.insert(bf);
                    total_pairs++;
                    boy_girl_pairs++;
                    break;
                }
            }
        } else {
            for(int gf : girl_friends[i]) {
                if(paired.find(gf) == paired.end()) {
                    pairs.push_back({i, gf});
                    paired.insert(i);
                    paired.insert(gf);
                    total_pairs++;
                    boy_girl_pairs++;
                    break;
                }
            }
        }
    }
    
    cout << total_pairs << " " << boy_girl_pairs << endl;
    for(auto p : pairs) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}