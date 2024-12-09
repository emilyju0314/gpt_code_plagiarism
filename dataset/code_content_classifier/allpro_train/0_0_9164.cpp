#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Item {
    string name;
    int price;
    Item(string n, int p) : name(n), price(p) {}
};

struct Recipe {
    string result;
    int price;
    vector<string> ingredients;
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        unordered_map<string, int> prices;
        for (int i = 0; i < n; i++) {
            string name;
            int price;
            cin >> name >> price;
            prices[name] = price;
        }
        
        int m;
        cin >> m;
        unordered_map<string, Recipe> recipes;
        for (int i = 0; i < m; i++) {
            string result;
            int k;
            cin >> result >> k;
            Recipe r;
            r.result = result;
            r.price = 0;
            for (int j = 0; j < k; j++) {
                string ingredient;
                cin >> ingredient;
                r.ingredients.push_back(ingredient);
            }
            recipes[result] = r;
        }
        
        string target;
        cin >> target;
        queue<string> q;
        q.push(target);
        unordered_map<string, int> min_prices;
        min_prices[target] = 0;
        
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            Recipe current_recipe = recipes[current];
            for (string i : current_recipe.ingredients) {
                if (!min_prices.count(i) || min_prices[i] > current_recipe.price + prices[i]) {
                    min_prices[i] = current_recipe.price + prices[i];
                    q.push(i);
                }
            }
        }
        
        cout << min_prices[target] << endl;
    }
    
    return 0;
}