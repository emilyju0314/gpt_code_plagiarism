#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, pair<int, pair<int, int>>> friends;

    string name;
    int s, taxis, pizzas, girls;
    string phone;

    for (int i = 0; i < n; i++) {
        cin >> s >> name;
        taxis = 0;
        pizzas = 0;
        girls = 0;
        
        for (int j = 0; j < s; j++) {
            cin >> phone;
            if (phone[0] == phone[1] && phone[1] == phone[3] && phone[3] == phone[4] && phone[4] == phone[6] && phone[6] == phone[7]) {
                taxis++;
            } else if (phone[0] > phone[1] && phone[1] > phone[3] && phone[3] > phone[4] && phone[4] > phone[6] && phone[6] > phone[7]) {
                pizzas++;
            } else {
                girls++;
            }
        }

        friends[name] = make_pair(taxis, make_pair(pizzas, girls));
    }

    int maxTaxis = 0, maxPizzas = 0, maxGirls = 0;

    for (auto it = friends.begin(); it != friends.end(); it++) {
        maxTaxis = max(maxTaxis, it->second.first);
        maxPizzas = max(maxPizzas, it->second.second.first);
        maxGirls = max(maxGirls, it->second.second.second);
    }

    cout << "If you want to call a taxi, you should call: ";
    for (auto it = friends.begin(); it != friends.end(); it++) {
        if (it->second.first == maxTaxis) {
            cout << it->first << ", ";
        }
    }
    cout << "." << endl;

    cout << "If you want to order a pizza, you should call: ";
    for (auto it = friends.begin(); it != friends.end(); it++) {
        if (it->second.second.first == maxPizzas) {
            cout << it->first << ", ";
        }
    }
    cout << "." << endl;

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for (auto it = friends.begin(); it != friends.end(); it++) {
        if (it->second.second.second == maxGirls) {
            cout << it->first << ", ";
        }
    }
    cout << "." << endl;

    return 0;
}