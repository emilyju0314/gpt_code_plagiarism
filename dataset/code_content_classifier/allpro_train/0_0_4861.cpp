#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Debt {
    int debtor, creditor;
    long amount;
};

vector<Debt> consolidateDebts(int n, int m, vector<Debt>& debts) {
    unordered_map<int, long> netBalance;
    for (const Debt& debt : debts) {
        netBalance[debt.debtor] -= debt.amount;
        netBalance[debt.creditor] += debt.amount;
    }

    vector<Debt> consolidatedDebts;
    for (const Debt& debt : debts) {
        long z = min(netBalance[debt.debtor], netBalance[debt.creditor]);
        if (z > 0) {
            Debt newDebt = {debt.debtor, debt.creditor, z};
            consolidatedDebts.push_back(newDebt);
            netBalance[debt.debtor] -= z;
            netBalance[debt.creditor] -= z;
        }
    }
    return consolidatedDebts;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Debt> debts(m);
    for (int i = 0; i < m; i++) {
        cin >> debts[i].debtor >> debts[i].creditor >> debts[i].amount;
    }

    vector<Debt> consolidatedDebts = consolidateDebts(n, m, debts);

    cout << consolidatedDebts.size() << endl;
    for (const Debt& debt : consolidatedDebts) {
        cout << debt.debtor << " " << debt.creditor << " " << debt.amount << endl;
    }

    return 0;
}