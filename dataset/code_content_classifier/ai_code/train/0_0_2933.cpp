#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countRecipies(vector<string>& recipies) {
    int n = recipies.size();
    int m = recipies[0].size();
    
    vector<int> ingredients(m, 0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(recipies[i][j] == '1') {
                ingredients[j]++;
            }
        }
    }
    
    sort(ingredients.begin(), ingredients.end(), greater<int>());
    
    return ingredients[m-1];
}

int main() {
    int n, m;
    
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        }
        
        vector<string> recipies(n);
        
        for(int i=0; i<n; i++) {
            cin >> recipies[i];
        }
        
        cout << countRecipies(recipies) << endl;
    }
    
    return 0;
}