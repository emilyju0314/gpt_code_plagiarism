#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> messages(n);
    for(int i = 0; i < n; i++) {
        cin >> messages[i];
    }

    unordered_set<int> displayedConversations;
    vector<int> order;

    for(int i = 0; i < n; i++) {
        if(displayedConversations.find(messages[i]) == displayedConversations.end()) {
            if(order.size() == k) {
                displayedConversations.erase(order.back());
                order.pop_back();
            }
            order.insert(order.begin(), messages[i]);
            displayedConversations.insert(messages[i]);
        }
    }

    cout << min((int)order.size(), k) << endl;
    for(int i = 0; i < min((int)order.size(), k); i++) {
        cout << order[i] << " ";
    }
    
    return 0;
}