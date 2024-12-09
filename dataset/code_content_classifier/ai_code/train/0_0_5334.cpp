#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, vector<string>> likes;
    for (int i = 0; i < n; i++) {
        string hero1, hero2, word;
        cin >> hero1 >> word >> hero2;
        likes[hero1].push_back(hero2);
    }
    
    int a, b, c;
    cin >> a >> b >> c;
    
    vector<string> heroes = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    int min_diff = INT_MAX;
    int max_liking = 0;
    
    do {
        int exp1 = a / (likes[heroes[0]].size() + 1);
        int exp2 = b / (likes[heroes[1]].size() + 1);
        int exp3 = c / (likes[heroes[2]].size() + 1);
        
        int max_exp = max(max(exp1, max(exp2, exp3));
        int min_exp = min(min(exp1, min(exp2, exp3));
        
        min_diff = min(min_diff, max_exp - min_exp);
        
        int total_liking = 0;
        for (auto hero : heroes) {
            for (auto liked : likes[hero]) {
                if (find(heroes.begin(), heroes.end(), liked) != heroes.end()) {
                    total_liking++;
                }
            }
        }
        max_liking = max(max_liking, total_liking);
    } while (next_permutation(heroes.begin(), heroes.end()));
    
    cout << min_diff << " " << max_liking << endl;
    
    return 0;
}