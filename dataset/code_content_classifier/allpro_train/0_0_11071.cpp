#include <iostream>

using namespace std;

int main() {
    int ticket_prices[4] = {6000, 4000, 3000, 2000};
    int ticket_type, ticket_count;

    for (int i = 0; i < 4; i++) {
        cin >> ticket_type >> ticket_count;
        int sales_amount = ticket_prices[ticket_type - 1] * ticket_count;
        cout << sales_amount << endl;
    }

    return 0;
}