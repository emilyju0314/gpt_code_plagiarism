#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int k, m;
    cin >> k >> m;
    
    vector<string> tickets;
    
    for(int i=0; i<=9999; i++) {
        string ticket = to_string(i);
        while(ticket.length() < 4) {
            ticket = "0" + ticket;
        }
        
        string reverse_ticket = ticket;
        reverse(reverse_ticket.begin(), reverse_ticket.end());
        tickets.push_back(ticket + reverse_ticket);
    }
    
    for(int i=0; i<m; i++) {
        cout << tickets[i] << endl;
    }
    
    return 0;
}