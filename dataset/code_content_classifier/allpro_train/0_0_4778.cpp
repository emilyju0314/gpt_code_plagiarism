#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> f(n);
    set<int> remaining_friends;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        if (f[i] == 0) {
            remaining_friends.insert(i);
        }
    }
    
    vector<int> gifts_given_to(n);
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            int friend_to_give = *remaining_friends.begin();
            if (friend_to_give == i) {
                friend_to_give = *remaining_friends.rbegin();
            }
            remaining_friends.erase(friend_to_give);
            gifts_given_to[i] = friend_to_give + 1;
        } else {
            gifts_given_to[i] = f[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << gifts_given_to[i] << " ";
    }
    
    return 0;
}