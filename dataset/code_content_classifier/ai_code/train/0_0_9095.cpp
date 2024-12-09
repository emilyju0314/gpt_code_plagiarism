#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> juice_prices;
    juice_prices["A"] = INT_MAX;
    juice_prices["B"] = INT_MAX;
    juice_prices["C"] = INT_MAX;
    juice_prices["AB"] = INT_MAX;
    juice_prices["AC"] = INT_MAX;
    juice_prices["BC"] = INT_MAX;
    juice_prices["ABC"] = INT_MAX;
    
    int total_price = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        int price;
        string vitamins;
        cin >> price >> vitamins;
        
        juice_prices[vitamins] = min(juice_prices[vitamins], price);
        
        total_price = min(total_price, price);
    }
    
    int min_price = INT_MAX;
    
    min_price = min(min_price, juice_prices["A"] + juice_prices["B"] + juice_prices["C"]);
    min_price = min(min_price, juice_prices["AB"] + juice_prices["C"]);
    min_price = min(min_price, juice_prices["AC"] + juice_prices["B"]);
    min_price = min(min_price, juice_prices["BC"] + juice_prices["A"]);
    min_price = min(min_price, juice_prices["ABC"]);
    
    if (min_price == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << min_price << endl;
    }
    
    return 0;
}