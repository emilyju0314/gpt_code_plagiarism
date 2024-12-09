#include <iostream>
#include <vector>

using namespace std;

struct Operation {
    bool compound;
    double interest;
    int charge;
};

int main() {
    int m;
    cin >> m;

    while (m--) {
        int initial_amount, num_years, num_operations;
        cin >> initial_amount >> num_years >> num_operations;

        vector<Operation> operations(num_operations);
        for (int i = 0; i < num_operations; i++) {
            int compound;
            double interest;
            int charge;
            cin >> compound >> interest >> charge;

            operations[i] = {compound, interest, charge};
        }

        long long max_final_amount = 0;
        for (int i = 0; i < num_operations; i++) {
            long long balance = initial_amount;
            for (int year = 0; year < num_years; year++) {
                double interest = balance * operations[i].interest;
                if (operations[i].compound) {
                    balance += (long long)interest - operations[i].charge;
                } else {
                    balance -= operations[i].charge;
                    max_final_amount = max(max_final_amount, balance + (long long)interest);
                }
            }

            if (operations[i].compound) {
                max_final_amount = max(max_final_amount, balance - operations[i].charge);
            }
        }

        cout << max_final_amount << endl;
    }

    return 0;
}