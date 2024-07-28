#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

struct Order {
    string name;
    vector<string> keywords;
};

int main() {
    unordered_map<string, Order> orders;

    string input;
    getline(cin, input);

    while (input != "END") {
        istringstream iss(input);
        string operation;
        iss >> operation;

        if (operation == "CREATE") {
            Order new_order;
            iss >> new_order.name;
            string keyword;
            while (iss >> keyword) {
                new_order.keywords.push_back(keyword);
            }
            orders[new_order.name] = new_order;
        }
        else if (operation == "DELETE") {
            string order_name;
            iss >> order_name;
            orders.erase(order_name);
        }
        else if (operation == "QUERY") {
            string keyword;
            iss >> keyword;
            vector<string> result;
            for (const auto& pair : orders) {
                if (find(pair.second.keywords.begin(), pair.second.keywords.end(), keyword) != pair.second.keywords.end()) {
                    result.push_back(pair.first);
                }
            }

            cout << "Query Result for keyword " << keyword << ":" << endl;
            for (const auto& name : result) {
                cout << name << endl;
            }
        }

        getline(cin, input);
    }

    return 0;
}